/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:51:45 by alilin            #+#    #+#             */
/*   Updated: 2023/10/23 16:07:20 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main_parse(char *av)
{
	int		fd;
	int		i;
	char	**file;

	fd = open(av, O_RDWR);
	if ((fd == -1) && (errno == EISDIR))
	{
		printf("Error first argument is a directory and not a file\n");
		return (-1);
	}
	
	file = get_next_line(fd);
	i = 0;
    while (file[i])
    {
        printf("%s\n", file[i]);
        i++;
    }
	return (0);
}
