#include "cub3d.h"

void do_tab_minimap(t_data *data)
{
	int a;
	int b;
	int c;
	int d;


	a = 0;
	b = 0;
	c = (int)data->playerdata.pos_y - 5;
	d = (int)data->playerdata.pos_x - 5;
	data->minimap.minimap[5][5] = 'N';
	while (c < 0)
	{
		data->minimap.minimap[a][0] = '\0';
		c++;
		a++;
	}
	while (a < 11 && data->map[c])
	{
		b = 0;
		d = (int)data->playerdata.pos_x - 5;
		while (d < 0)
		{
			d++;
			b++;
		}
		while (b < 11)
		{
			if (data->minimap.minimap[a][b] == 'N')
			{
				b++;
				d++;
			}
			else
			{
				data->minimap.minimap[a][b] = data->map[c][d];
				b++;
				d++;
			}
		}
		//data->minimap.minimap[a][b] = '\0';
		a++;
		c++;
	}
}

void do_minimap(t_data *data)
{
	int map_coord_x;
	int map_coord_y;
	int a = 0;
	int b = 0;

	map_coord_x = WIN_WIDTH - MINIMAP + 2.5;
	map_coord_y = WIN_HEIGHT - MINIMAP + 2.5;
	while (a < 11 && data->minimap.minimap[a])
	{
		while (b < 11)
		{
			if (data->minimap.minimap[a][b] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->minimap.wall.img, map_coord_x, map_coord_y);
				b++;
				map_coord_x += 30;

			}
			else if (data->minimap.minimap[a][b] == 'N')
			{
				map_coord_x += 5;
				mlx_put_image_to_window(data->mlx, data->win, data->minimap.perso_mini.img, map_coord_x, map_coord_y + 5);
				map_coord_x += 25;
				b++;
			}
			else
			{
				map_coord_x += 30;
				b++;	
			}

		}
		map_coord_x = WIN_WIDTH - MINIMAP + 2.5;
		map_coord_y += 30;
		a++;
		b = 0;
	}
}

int put_minimap(t_data *data)
{
	int map_coord_x;
	int map_coord_y;

	map_coord_x = WIN_WIDTH - MINIMAP;
	map_coord_y = WIN_HEIGHT - MINIMAP;
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.fond_map.img, map_coord_x, map_coord_y);
	do_tab_minimap(data);
	do_minimap(data);
	return (0);
}

