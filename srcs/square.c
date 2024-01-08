#include "../includes/cub3D.h"

void draw_square(t_mlx *data, int x, int y, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            mlx_pixel_put(data->mlx, data->win, x + i, y + j, 0xFFFFFF); // Change 0xFFFFFF to the color you want
            j++;
        }
        i++;
    }
}

void    perso_coord(t_mlx *data)
{
    int x = 0;
    int y = 0;

    while (data->map[y])
    {
        while (data->map[y][x])
        {
            if (data->map[y][x] == 'N')
            {
                data->p_x = x;
                data->p_y = y;
                return ;
            }
            x++;
        }
        x = 0;
        y++;
    }
}


//fonction pour la minimap a finir//


//void    do_minimap(t_mlx *data)
//{
//    int x;
//    int y;
//    int px_x;
//    int px_y;
//    int n = 0;
//    int i = 0;
//
//    x = data->p_x - 5;
//    y = data->p_y - 5;
//    px_x = 1590;
//    px_y = 685;
//    
//    while (n < 10)
//    {
//        while (i < 0)
//        {
//            if (x == data->p_x && y == data->p_y)
//            {
//                mlx_put_image_to_window(data->mlx, data->win, data->perso_mappy.img, 1756, 850);
//                i++;
//                px_x += 32;
//                x++;
//            }
//            else
//            {
//                ²
//            }
//        }
//        x -= 10;
//        y++;
//        n++;
//        i = 0;
//    }
//
//}

void put_mur_mappy(t_mlx *data)
{
    int i = 0;
    int x = 1590;
    int y = 685;
    while (i < 10)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->mur_mappy.img, x, y);
        x += 32;
        i++;
    }
    x = 1590;
    i = 0;
    while (i < 10)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->mur_mappy.img, x, y);
        y += 32;
        i++;
    }
}