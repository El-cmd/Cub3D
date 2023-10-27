/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:51:45 by alilin            #+#    #+#             */
/*   Updated: 2023/10/26 15:55:22 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_extension(char *av, char *comp)
{
	if (ft_strlen(av) < 4)
		return (1);
	else
	{
		if (ft_strncmp(&av[ft_strlen(av) - 4], comp, 4) != 0)
			return (1);
	}
	return (0);
}

int	preliminary_check(char *av)
{
	int		fd;

	fd = open(av, O_RDWR);
	if ((fd == -1) && (errno == EISDIR))
	{
		printf("Error first argument is a directory and not a file\n");
		exit(EXIT_FAILURE);
	}
	if (fd == -1)
	{
		printf("Error Cannot open file, or file doesn't exist\n");
		exit(EXIT_FAILURE);
	}
	if (check_extension(av, ".cub"))
	{
		printf("Error file does not have \".cub\" extention a the end\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	main_parse(char *av, t_parse *parsing)
{
	int		fd;
	char 	**file;

	fd = preliminary_check(av);
	if (fd != -1)
	{
		file = get_next_line(fd);
		if (close(fd) != 0)
		{
			free_tab(file);
			exit(EXIT_FAILURE);
		}
		start_parse(file, parsing);
		free_tab(file);
	}
	return (0);
}