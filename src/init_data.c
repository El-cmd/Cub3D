/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldoctor <eldoctor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:07:37 by schai             #+#    #+#             */
/*   Updated: 2024/01/14 14:41:57 by eldoctor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texturedata(t_texturedata *texturedata)
{
	texturedata->north = NULL;
	texturedata->south = NULL;
	texturedata->west = NULL;
	texturedata->east = NULL;
	texturedata->floor = 0;
	texturedata->ceiling = 0;
	texturedata->hex_floor = 0x0;
	texturedata->hex_ceiling = 0x0;
	texturedata->size = TEXTURE_SIZE;
	texturedata->step = 0.0;
	texturedata->pos = 0.0;
	texturedata->x = 0;
	texturedata->y = 0;
}

static void	init_mapdata(t_mapdata *mapdata)
{
	mapdata->fd = 0;
	mapdata->nb_line = 0;
	mapdata->path = NULL;
	mapdata->file = NULL;
	mapdata->height = 0;
	mapdata->width = 0;
	mapdata->index_end_of_map = 0;
}


static void init_playerdata(t_playerdata *playerdata)
{
	playerdata->dir = '\0';
	playerdata->pos_x = 0.0;
	playerdata->pos_y = 0.0;
	playerdata->dir_x = 0.0;
	playerdata->dir_y = 0.0;
}


void init_data(t_data *data) // init les stuctures
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	data->map = NULL;
	init_mapdata(&data->mapdata); // init la stucture des data de la map
	init_texturedata(&data->texturedata); // init la structure des data des texture
	init_playerdata(&data->playerdata); // init la stucture des data du joueur 
}