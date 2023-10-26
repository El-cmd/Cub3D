/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:36:39 by alilin            #+#    #+#             */
/*   Updated: 2023/10/26 19:33:58 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_parse(t_parse *parsing)
{
	parsing->no = NULL;
	parsing->so = NULL;
	parsing->ea = NULL;
	parsing->we = NULL;
	parsing->f[0] = -1;
	parsing->f[1] = -1;
	parsing->f[2] = -1;
	parsing->c[0] = -1;
	parsing->c[1] = -1;
	parsing->c[2] = -1;
	parsing->pos = NULL;
	parsing->map = NULL;
}

void start_parsing(char **file, t_parse *parsing)
{
	int i;
	int j;

	init_parse(parsing);
	i = 0;
	while(i < ft_tablen(file))
	{
		j = 0;
		while(j < ft__strlen(file[i]) && (file[i][j] == ' ' || file[i][j] == '\t'))
			j++;
		if (file[i][j] == 'N' && file[i][j + 1] == 'O')
		else if (file[i][j] == 'S' && file[i][j + 1] == 'O')
		else if (file[i][j] == 'W' && file[i][j + 1] == 'E')
		else if (file[i][j] == 'E' && file[i][j + 1] == 'A')
		else if (file[i][j] == 'F')
		else if (file[i][j] == 'C')
		else if ((file[i][j] == 'N' && file[i][j + 1] != 'O') || (file[i][j] == 'S' && file[i][j + 1] != 'O') || (file[i][j] == 'W' && file[i][j + 1] != 'E') || (file[i][j] == 'E' && file[i][j + 1] != 'A') || (file[i][j] == '1') || (file[i][j] == '0'))
		
		
		i++;
	}
}