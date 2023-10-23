/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:51:02 by alilin            #+#    #+#             */
/*   Updated: 2023/10/23 17:35:28 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_mlx 	data;
	// t_parse parsing;
	
	if (ac != 2)
	{
		printf("Error wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	if (main_parse(av[1]) == -1)
		return (1);

	data.mlx = mlx_init();
	data.win =  mlx_new_window(data.mlx, 400, 400, "trou de balle");
	mlx_key_hook(data.win, key_funct, &data);
	mlx_loop(data.mlx);
	hakai(&data);
	return (0);
}
