/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldoctor <eldoctor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:57:22 by schai             #+#    #+#             */
/*   Updated: 2024/01/19 15:18:17 by eldoctor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_tab(char **tab)
{
	int i = 0;
	
	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
}

void print_map(char **tab)
{
	int i = 0;
	
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void print_tab_int(int *tab)
{
	int i = 0;
	while (i != 3)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

void print_info_map(t_data *data)
{
	printf("%d\n", data->mapdata.nb_line);
	printf("\n");
	printf("%s\n", data->mapdata.path);
	printf("\n");
	print_tab(data->mapdata.file);
	printf("\n");
	printf("%s\n", data->texturedata.north);
	printf("%s\n", data->texturedata.south);
	printf("%s\n", data->texturedata.east);
	printf("%s\n", data->texturedata.west);
	printf("\n");
	print_tab_int(data->texturedata.floor);
	print_tab_int(data->texturedata.ceiling);
	printf("\n");
	printf("%d\n", data->mapdata.height);
	printf("%d\n", data->mapdata.width);
	printf("\n");
	print_map(data->map);
}



int	error_msg(char *context, char *s, int code)
{
	ft_putstr_fd("ERROR", 2);
	if (context)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(context, 2);
	}
	if (s)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(s, 2);
	}
	return (code);
}


void	clean_exit(t_data *data, int status)
{
	if (!data)
		exit(status);
	exit(status);
}



static int parse_args(t_data *data, char **av)
{
	if (check_file(av[1], true) == FAILURE) //check le nom de largument 
		clean_exit(data, FAILURE); // just exit
	parse_mapdata(av[1], data); // malloc et et copie la TOUT le fichier map dans un tab** et compt le nb de line le fd
	if (get_file_data(data, data->mapdata.file) == FAILURE) //parse les donné des tecture et du rgb et isole la map dans un char** d'une struct
	 	return (free_data(data)); // free les data en cas d'erreur
	if (check_map(data, data->map) == FAILURE) // parse les eventuels erreurs de la map et prends la position du perso
		return (free_data(data));
	if (check_textures(&data->texturedata) == FAILURE) // check la validité des texture et convertie le rgb en hexa
		return (free_data(data));
	print_info_map(data); // print les info de la map
	return (0);
}

int init_and_parsing(int ac, t_data *data, char **av)
{
	if (ac != 2)
		return (error_msg(NULL, INV_USAGE, 1));// Mauvais nombre d'arguments
	init_data(data); //init les structure
	if (parse_args(data, av) != 0) //check erreur et collect de data
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_data data;

	if (init_and_parsing(ac, &data, av))
		return (1);
	if (mlx_win_init(&data))
		return (1);
	if (init_img(&data))
		return (1);
	routine(&data);
	mlx_loop(data.mlx);
	return (0);
}