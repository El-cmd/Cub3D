#include "cub3d.h"


int init_img(t_data *data)
{
	data->minimap.fond_map.img = mlx_xpm_file_to_image(data->mlx, "texture/minimap.xpm", \
	&data->minimap.fond_map.width, &data->minimap.fond_map.height);
	data->minimap.wall.img = mlx_xpm_file_to_image(data->mlx, "texture/mini_mur.xpm", \
	&data->minimap.wall.width, &data->minimap.wall.height);
	data->minimap.perso_mini.img = mlx_xpm_file_to_image(data->mlx, "texture/mini_perso.xpm", \
	&data->minimap.perso_mini.width, &data->minimap.perso_mini.height);
	if (data->minimap.fond_map.img == NULL || data->minimap.wall.img == NULL || data->minimap.perso_mini.img == NULL)
		return (error_msg("Minimap", MINIMAP_SPRITE, 1));
	return (0);
}

int mlx_win_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "jeux");
	if (data->win == NULL)
		return (1);
	return (0);
}