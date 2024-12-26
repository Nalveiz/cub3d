/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:12:46 by soksak            #+#    #+#             */
/*   Updated: 2024/12/26 12:11:53 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	calculate_image_value(t_data *data)
{
	if (data->rc->side == 0)
		data->wall->wall_x = data->plyr->y
			+ data->rc->perp_wall_dist * data->rc->raydir_y;
	else
		data->wall->wall_x = data->plyr->x
			+ data->rc->perp_wall_dist * data->rc->raydir_x;
	data->wall->wall_x -= floor(data->wall->wall_x);
	data->wall->tex_x = (int)(data->wall->wall_x
			* (double)data->wall->width[data->wall->direction]);
	if (data->rc->side == 0 && data->rc->raydir_x > 0)
		data->wall->tex_x = data->wall->width[data->wall->direction]
			- data->wall->tex_x - 1;
	if (data->rc->side == 1 && data->rc->raydir_y < 0)
		data->wall->tex_x = data->wall->width[data->wall->direction]
			- data->wall->tex_x - 1;
}

static int	find_direction(t_data *data)
{
	if (data->rc->side == 0)
	{
		if (data->rc->raydir_x < 0)
			return (WE);
		else
			return (EA);
	}
	else
	{
		if (data->rc->raydir_y < 0)
			return (NO);
		else
			return (SO);
	}
}

void	draw_wall(t_data *data, int x)
{
	int		y;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;

	y = data->rc->draw_start;
	data->wall->direction = find_direction(data);
	calculate_image_value(data);
	step = 1.0 * data->wall->height[data->wall->direction]
		/ data->rc->line_height;
	tex_pos = (data->rc->draw_start - SHEIGHT / 2
			+ data->rc->line_height / 2) * step;
	while (y < data->rc->draw_end)
	{
		tex_y = (int)tex_pos & (data->wall->height[data->wall->direction] - 1);
		tex_pos += step;
		color = *(int *)(data->wall->addr[data->wall->direction]
				+ (tex_y * data->wall->llength[data->wall->direction])
				+ (data->wall->tex_x
					* (data->wall->bpp[data->wall->direction] / 8)));
		my_mlx_pixel_put(data->txture, x, y, color);
		y++;
	}
}
