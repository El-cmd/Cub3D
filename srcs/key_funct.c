/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldoctor <eldoctor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:19:26 by vloth             #+#    #+#             */
/*   Updated: 2023/12/25 22:11:11 by eldoctor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	print_map(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

void find_p(t_mlx *data, int *x, int *y)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (data->map[i])
	{
		while (data->map[i][n])
		{
			if (data->map[i][n] == 'N')
			{
				*y = i;
				*x = n;
				return ;
			}
			n++;
		}
		n = 0;
		i++;
	}
}

void move_p(int code, t_mlx *data)
{
	int x;
	int y;
	find_p(data, &x, &y);
	if (code == LEFT)
	{
		if (data->map[y][x - 1] != '1')
		{
			data->map[y][x] = '0';
			data->map[y][x - 1] = 'N';
		}
		return ;
	}
	if (code == RIGHT)
	{
		if (data->map[y][x + 1] != '1')
		{
			data->map[y][x] = '0';
			data->map[y][x + 1] = 'N';
		}
		return ;
	}
	if (code == UP)
	{
		if (data->map[y - 1][x] != '1')
		{
			data->map[y][x] = '0';
			data->map[y - 1][x] = 'N';
		}
		return ;
	}
		if (code == DOWN)
	{
		if (data->map[y + 1][x] != '1')
		{
			data->map[y][x] = '0';
			data->map[y + 1][x] = 'N';
		}
		return ;
	}
}

int	key_funct(int code, t_mlx *data)
{
	if (code == ESC)
		mlx_loop_end(data->mlx);
	else if (code == LEFT || code == RIGHT || code == UP || code == DOWN)
		move_p(code, data);
	printf("%d\n", code);
	print_map(data->map);
	printf("\n");
	return (0);
}
