/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:47:45 by alilin            #+#    #+#             */
/*   Updated: 2023/10/26 16:02:32 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <../minilibx-linux/mlx.h>
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>  

# define ESC 65307
# define LEFT 97
# define RIGHT 100
# define UP 119
# define DOWN 115

typedef struct s_mlx
{
    void            *mlx;
    void            *win;
}               t_mlx;

typedef struct  s_node
{
    char            *data;
    struct s_node   *next;
}               t_node;

typedef struct  s_parse
{
    char            *no;
    char            *so;
    char            *we;
    char            *ea;
    char            pos;
    int             f[3];
    int             c[3];
    struct s_node   *map;
}               t_parse;

int     main_parse(char *av, t_parse *parsing);
void    start_parsing(char **file, t_parse *parsing);
void    hakai(t_mlx *data);
int     key_funct(int code, t_mlx *data);
char	**get_next_line(int fd);
void	free_tab(char **file);

#endif