/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:51:02 by alilin            #+#    #+#             */
/*   Updated: 2023/07/27 17:33:12 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error wrong number of arguments\n");
		return (1);
	}
	if (main_parse(av[1]) == 1)
		return (1);
	return (0);
}
