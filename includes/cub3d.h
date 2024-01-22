/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldoctor <eldoctor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:57:20 by schai             #+#    #+#             */
/*   Updated: 2024/01/20 20:36:44 by eldoctor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <../minilibx-linux/mlx.h>
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>


# define WIN_WIDTH 1920
# define WIN_HEIGHT 1016 // taille chelou de mon ecran

# define TEXTURE_SIZE 64

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif


enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};




# define INV_USAGE "cub3d <pathtomap.cub>"
# define FILE_DIR "file is a directory"
# define INV_EXTENSION "Not a .cub file"
# define INV_XPM "Not an .xpm file"
# define ERR_MALLOC "Error in allocating memory"


# define INV_FLOOR_CEILING "Invalid floor or ceiling RGB colors"
# define INV_FLOOR "Invalid floor RGB color"
# define INV_CEILING "Invalid ceiling RGB color"


# define INV_MAP "Invalid Map"
# define MAP_MISSING "Missing map"
# define MAP_NO_WALLS "Map is not surrounded by walls"
# define MAP_TOO_SMALL "Map is not at least 3 lines high"
# define MAP_LAST_ELEM "Map is not the last element in file"
# define WRONG_CHAR "Wrong char in map"
# define INV_PLAYER_POS "Invalid player position"


# define MISS_TEXTURE "Missing Textures"
# define INV_TEXTURE "Invalid Textures"
# define INV_RGB "Invalid RGB value"
# define MISS_COLOR "Missing Color"

# define MINIMAP_SPRITE "Missing Minimap sprites\n"
# define MINIMAP 335
# define MINI_PERSO 20
# define MINI_MUR 30

# define ESC 65307
// AZERTY
# define LEFT 'q'
# define RIGHT 'd'
# define UP 'z'
# define DOWN 's'

typedef struct s_mapdata
{
	int fd;
	int nb_line; // nb de ligne info inclus
	char *path;  // chemin du fichier cub
	char **file;  // tout le fichier .cub 
	int height; // hauteur de la map
	int width; // largeur de la map et de la ligne horizontale la plus grande
	int index_end_of_map; // index de la derniere ligne (vertical) de la map
}	t_mapdata;


typedef struct s_texturedata
{
	char *north;    //texture des mure  
	char *south;    //texture des mure
	char *west;    //texture des mure
	char *east;    //texture des mure
	int *floor;    // code rgb du plafond et mure
	int *ceiling;  // code rgb du plafond et mure
	int	hex_floor; //le code hexa de la couleur du sol
	int	hex_ceiling;  //le code hexa de la couleur du ciel
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texturedata;


typedef struct s_playerdata
{
	char dir;
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
} t_playerdata;

typedef struct img_data
{
    void    *img;
    int     width;
    int     height;
} t_img;

typedef struct s_minimap
{
	t_img 	fond_map;
	t_img	perso_mini;
	t_img	wall;
	char minimap[12][12];
} t_minimap;

typedef struct s_data
{
	void *mlx;
	void *win;
	int win_width;
	int win_height;
	char **map; // map rien d'autre que la map
	t_mapdata mapdata;
	t_texturedata texturedata;
	t_playerdata playerdata;
	t_minimap minimap;
}	t_data;


int	get_rgb_texture(t_texturedata *textures, char *line, int j);

void init_data(t_data *data);

int check_file(char *arg, bool state);

int	error_msg(char *context, char *s, int code);

void parse_mapdata(char *path, t_data *data);

size_t	find_longest_line(t_mapdata *map, int i);

int get_file_data(t_data *data, char **map);

int create_map(t_data *data, char **file, int i);

int	check_is_whitespace(char c);

int check_map(t_data *data, char **map_tab);

int check_textures(t_texturedata *textures);

int	free_data(t_data *data);

void	free_tab(void **tab);

int		mlx_win_init(t_data *data);

int 	init_img(t_data *data);

int put_minimap(t_data *data);

void routine(t_data *data);

void do_minimap(t_data *data);

void do_tab_minimap(t_data *data);

void	almost_free(t_data *data);

void floor_ceiling(t_data *data);

#endif