/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:32:02 by soksak            #+#    #+#             */
/*   Updated: 2024/12/21 23:28:42 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	arrow_keys(t_data *data, int key, double old_dir_x, double old_plane_x)
{
	if (key == RIGHT)
	{
		data->plyr->dir_x = data->plyr->dir_x * cos(data->plyr->rot_speed)
			- data->plyr->dir_y * sin(data->plyr->rot_speed);
		data->plyr->dir_y = old_dir_x * sin(data->plyr->rot_speed) + data->plyr->dir_y
			* cos(data->plyr->rot_speed);
		data->rc->plane_x = data->rc->plane_x * cos(data->plyr->rot_speed)
			- data->rc->plane_y * sin(data->plyr->rot_speed);
		data->rc->plane_y = old_plane_x * sin(data->plyr->rot_speed) + data->rc->plane_y
			* cos(data->plyr->rot_speed);
	}
	else
	{
		data->plyr->dir_x = data->plyr->dir_x * cos(-data->plyr->rot_speed)
			- data->plyr->dir_y * sin(-data->plyr->rot_speed);
		data->plyr->dir_y = old_dir_x * sin(-data->plyr->rot_speed) + data->plyr->dir_y
			* cos(-data->plyr->rot_speed);
		data->rc->plane_x = data->rc->plane_x * cos(-data->plyr->rot_speed)
			- data->rc->plane_y * sin(-data->plyr->rot_speed);
		data->rc->plane_y = old_plane_x * sin(-data->plyr->rot_speed) + data->rc->plane_y
			* cos(-data->plyr->rot_speed);
	}
}

static void movement_keys_helper(t_data *data, int key, char **map)
{
	if (key == A)
	{
		if (map[(int)(data->plyr->y - data->rc->plane_y
			* data->plyr->move_speed)][(int)data->plyr->x] == '0')
			data->plyr->y -= data->rc->plane_y * data->plyr->move_speed;
		if (map[(int)data->plyr->y][(int)(data->plyr->x - data->rc->plane_x
			* data->plyr->move_speed)] == '0')
			data->plyr->x -= data->rc->plane_x * data->plyr->move_speed;
	}
	else if (key == D)
	{
		if (map[(int)(data->plyr->y + data->rc->plane_y
			* data->plyr->move_speed)][(int)data->plyr->x] == '0')
			data->plyr->y += data->rc->plane_y * data->plyr->move_speed;
		if (map[(int)data->plyr->y][(int)(data->plyr->x + data->rc->plane_x
			* data->plyr->move_speed)] == '0')
			data->plyr->x += data->rc->plane_x * data->plyr->move_speed;
	}
}

static void	movement_keys(t_data *data, int key, char **map)
{
	if (key == W)
	{
		if (map[(int)(data->plyr->y + data->plyr->dir_y
			* data->plyr->move_speed)][(int)data->plyr->x] == '0')
			data->plyr->y += data->plyr->dir_y * data->plyr->move_speed;
		if (map[(int)data->plyr->y][(int)(data->plyr->x
			+ data->plyr->dir_x * data->plyr->move_speed)] == '0')
			data->plyr->x += data->plyr->dir_x * data->plyr->move_speed;
	}
	else if (key == S)
	{
		if (map[(int)(data->plyr->y - data->plyr->dir_y
			* data->plyr->move_speed)][(int)data->plyr->x] == '0')
			data->plyr->y -= data->plyr->dir_y * data->plyr->move_speed;
		if (map[(int)data->plyr->y][(int)(data->plyr->x
			- data->plyr->dir_x * data->plyr->move_speed)] == '0')
			data->plyr->x -= data->plyr->dir_x * data->plyr->move_speed;
	}
	else if (key == A || key == D)
		movement_keys_helper(data, key, map);
}


int	key_hook(int key, t_data *data)
{
	char **map;

	map = data->map->map3d;
	if (key == W || key == S || key == A || key == D)
		movement_keys(data, key, map);
	if (key == LEFT || key == RIGHT)
		arrow_keys(data, key, data->plyr->dir_x,
			data->rc->plane_x);

	clear_image_buffer(data, convert(0, 0, 0));
	draw_celling_and_flor(data);
	raycasting(data);
	return (0);
}
