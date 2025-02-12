/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:49:50 by soksak            #+#    #+#             */
/*   Updated: 2024/12/26 12:19:37 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	calculate_line_height(t_data *data)
{
	if (data->rc->side == 0)
		data->rc->perp_wall_dist = data->rc->side_dist_x
			- data->rc->delta_dist_x;
	else
		data->rc->perp_wall_dist = data->rc->side_dist_y
			- data->rc->delta_dist_y;
	data->rc->line_height = (int)(SHEIGHT / data->rc->perp_wall_dist);
	data->rc->draw_start = -data->rc->line_height / 2 + SHEIGHT / 2;
	if (data->rc->draw_start < 0)
		data->rc->draw_start = 0;
	data->rc->draw_end = data->rc->line_height / 2 + SHEIGHT / 2;
	if (data->rc->draw_end >= SHEIGHT)
		data->rc->draw_end = SHEIGHT - 1;
}

static void	calculate_deltadist(t_data *data)
{
	if (data->rc->raydir_x == 0)
		data->rc->delta_dist_x = 1e30;
	else
		data->rc->delta_dist_x = fabs(1 / data->rc->raydir_x);
	if (data->rc->raydir_y == 0)
		data->rc->delta_dist_y = 1e30;
	else
		data->rc->delta_dist_y = fabs(1 / data->rc->raydir_y);
}

static void	check_hit(t_data *data)
{
	while (data->rc->hit == 0)
	{
		if (data->rc->side_dist_x < data->rc->side_dist_y)
		{
			data->rc->side_dist_x += data->rc->delta_dist_x;
			data->plyr->map_x += data->rc->step_x;
			data->rc->side = 0;
		}
		else
		{
			data->rc->side_dist_y += data->rc->delta_dist_y;
			data->plyr->map_y += data->rc->step_y;
			data->rc->side = 1;
		}
		if (data->map->map3d[data->plyr->map_y][data->plyr->map_x] == '1')
			data->rc->hit = 1;
	}
}

static void	check_raydir(t_data *data)
{
	if (data->rc->raydir_x < 0)
	{
		data->rc->step_x = -1;
		data->rc->side_dist_x = (data->plyr->x - data->plyr->map_x)
			* data->rc->delta_dist_x;
	}
	else
	{
		data->rc->step_x = 1;
		data->rc->side_dist_x = (data->plyr->map_x + 1.0 - data->plyr->x)
			* data->rc->delta_dist_x;
	}
	if (data->rc->raydir_y < 0)
	{
		data->rc->step_y = -1;
		data->rc->side_dist_y = (data->plyr->y - data->plyr->map_y)
			* data->rc->delta_dist_y;
	}
	else
	{
		data->rc->step_y = 1;
		data->rc->side_dist_y = (data->plyr->map_y + 1.0 - data->plyr->y)
			* data->rc->delta_dist_y;
	}
}

void	raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < SWIDTH)
	{
		data->rc->camera_x = 2 * x / (double)SWIDTH - 1;
		data->rc->raydir_x = data->plyr->dir_x
			+ data->rc->plane_x * data->rc->camera_x;
		data->rc->raydir_y = data->plyr->dir_y
			+ data->rc->plane_y * data->rc->camera_x;
		calculate_deltadist(data);
		check_raydir(data);
		check_hit(data);
		calculate_line_height(data);
		draw_wall(data, x);
		data->rc->hit = 0;
		data->plyr->map_x = (int)data->plyr->x;
		data->plyr->map_y = (int)data->plyr->y;
		x++;
	}
	mlx_put_image_to_window(data->game->mlx, data->game->win,
		data->txture->img, 0, 0);
}
