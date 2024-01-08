/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldoctor <eldoctor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:47:45 by alilin            #+#    #+#             */
/*   Updated: 2023/12/25 21:38:22 by eldoctor         ###   ########.fr       */
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
# define LEFT 'q'
# define RIGHT 'd'
# define UP 'z'
# define DOWN 's'

#define X_MAX 1920;
#define Y_MAX 1080;


typedef struct img_data
{
    void    *img;
    int     width;
    int     height;
} t_img;

typedef struct s_mlx
{
    void            *mlx;
    void            *win;
    char            **map;
    int             p_x;
    int             p_y;
    t_img           mappy;
    t_img           mur_mappy;
    t_img           perso_mappy;
}               t_mlx;

//typedef struct  s_node
//{
//    char            *data;
//    struct s_node   *next;
//}               t_node;

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

int     main_parse(char *av, t_parse *parsing, t_mlx *data);
//void    start_parsing(char **file, t_parse *parsing);
void    hakai(t_mlx *data);
int     key_funct(int code, t_mlx *data);
char	**get_next_line(int fd);
void	free_tab(char **file);
void    draw_square(t_mlx *data, int x, int y, int size);
void	print_map(char **str);
void    init_img(t_mlx *data);
void    put_mur_mappy(t_mlx *data);
void    perso_coord(t_mlx *data);

#endif