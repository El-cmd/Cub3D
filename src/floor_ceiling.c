#include "cub3d.h"

void draw_square(t_data *data, int couleur)
{
    int i;
    int j;

    i = 0;
    while (i <= 508)
    {
        j = 0;
        while (j <= 1920)
        {
            mlx_pixel_put(data->mlx, data->win, j, i, couleur); // Change 0xFFFFFF to the color you want
            j++;
        }
        i++;
    }
}

void draw_square_second(t_data *data, int couleur)
{
    int i;
    int j;

    i = 508;
    while (i <= 1016)
    {
        j = 0;
        while (j <= 1920)
        {
            mlx_pixel_put(data->mlx, data->win, j, i, couleur); // Change 0xFFFFFF to the color you want
            j++;
        }
        i++;
    }
}

void floor_ceiling(t_data *data)
{
	draw_square(data, data->texturedata.hex_ceiling);
	draw_square_second(data, data->texturedata.hex_floor);
}