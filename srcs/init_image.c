#include "../includes/cub3D.h"

void init_img(t_mlx *data)
{
	data->mappy.img = mlx_xpm_file_to_image(data->mlx, "texture/map.xpm", \
	&data->mappy.width, &data->mappy.height);
	data->mur_mappy.img = mlx_xpm_file_to_image(data->mlx, "texture/mur.xpm", \
	&data->mur_mappy.width, &data->mur_mappy.height);
	data->perso_mappy.img = mlx_xpm_file_to_image(data->mlx, "texture/perso.xpm", \
	&data->perso_mappy.width, &data->perso_mappy.height);
}