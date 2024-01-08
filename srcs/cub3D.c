/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldoctor <eldoctor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:51:02 by alilin            #+#    #+#             */
/*   Updated: 2023/12/25 22:59:35 by eldoctor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	main(int ac, char **av)
{
	t_mlx 	data;
	t_parse parsing;

	
	if (ac != 2)
	{
		printf("Error wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	if (main_parse(av[1], &parsing, &data) == -1)
		return (1);

	data.mlx = mlx_init();
	data.win =  mlx_new_window(data.mlx, 1920, 1080, "trou de balle");
	init_img(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.mappy.img, 1585, 680);
	put_mur_mappy(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.perso_mappy.img, 1756, 850);
	mlx_key_hook(data.win, key_funct, &data);
	mlx_loop(data.mlx);
	hakai(&data);
	return (0);
}	
