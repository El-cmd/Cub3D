/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:55:37 by vloth             #+#    #+#             */
/*   Updated: 2023/10/19 16:03:59 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


int	read_map(char *av)
{
	int	fd;
    int i = 0;
    char **map;

	fd = open(av, O_RDONLY);
    printf("%d\n", fd);
    map = get_next_line(fd);
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    return 1;
}