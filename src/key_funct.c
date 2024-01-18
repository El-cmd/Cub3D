# include "cub3d.h"

int	close_win_cross(t_data *data)
{
	mlx_loop_end (data->mlx);
	return (0);
}

int	close_win(int keysym, t_data *data)
{
	if (keysym == 65307)
		mlx_loop_end (data->mlx);
	return (0);
}

void move_p(int code, t_data *data)
{
	if (code == LEFT)
	{
		if (data->map[(int)data->playerdata.pos_y][(int)data->playerdata.pos_x - 1] != '1')
			data->playerdata.pos_x -= 1;
		return ;
	}
	if (code == RIGHT)
	{
		if (data->map[(int)data->playerdata.pos_y][(int)data->playerdata.pos_x + 1] != '1')
			data->playerdata.pos_x += 1;
		return ;
	}
	if (code == UP)
	{
		if (data->map[(int)data->playerdata.pos_y - 1][(int)data->playerdata.pos_x] != '1')
			data->playerdata.pos_y -= 1;
		return ;
	}
	if (code == DOWN)
	{
		if (data->map[(int)data->playerdata.pos_y + 1][(int)data->playerdata.pos_x] != '1')
			data->playerdata.pos_y += 1;
		return ;
	}
}

int	key_funct(int code, t_data *data)
{
	if (code == LEFT || code == RIGHT || code == UP || code == DOWN)
		move_p(code, data);
	put_img(data);
	return (0);
}

int	put_img(t_data *data)
{
	do_tab_minimap(data);
	put_minimap(data);
	do_minimap(data);
	return (0);
}

void routine(t_data *data)
{
	mlx_key_hook(data->win, key_funct, data);
	mlx_loop_hook(data->mlx, put_img, data);
	mlx_hook(data->win, 2, 1L << 0, close_win, data);
	//mlx_hook(data->win, 17, 1L << 0, close_win_cross, data); // eux option soit
}



