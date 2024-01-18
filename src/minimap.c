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
		data->minimap.minimap[a][b] = '\0';
		a++;
		c++;
	}
}

int put_minimap(t_data *data)
{
	int map_coord_x;
	int map_coord_y;

	map_coord_x = WIN_WIDTH - MINIMAP;
	map_coord_y = WIN_HEIGHT - MINIMAP;
	do_tab_minimap(data);
	printf("\n");;
	int i = 0;
	while (i < 11)
	{
		printf("%s\n", data->minimap.minimap[i]);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.fond_map.img, map_coord_x, map_coord_y);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.wall.img, map_coord_x + 2.5, map_coord_y + 2.5);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.wall.img, map_coord_x + 2.5 + (10 * 30), map_coord_y + 2.5 + (10 * 30));
	return (0);
}

