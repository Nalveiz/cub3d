/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:19:40 by soksak            #+#    #+#             */
/*   Updated: 2024/12/21 22:41:41 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void clear_image_buffer(t_data *data, int color)
{
	int x;
	int y;

	x = 0;
	while (x < SWIDTH)
	{
		y = 0;
		while (y < SHEIGHT)
		{
			my_mlx_pixel_put(data->txture, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_swap_double(double *a, double *b)
{
	double tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	convert(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void my_mlx_pixel_put(t_txture *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->llength + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_celling_and_flor(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (x < SWIDTH)
	{
		y = 0;
		while (y < SHEIGHT)
		{
			if (y < SHEIGHT / 2)
				my_mlx_pixel_put(data->txture, x, y, convert(data->txture->c[0],
					data->txture->c[1], data->txture->c[2]));
			else
				my_mlx_pixel_put(data->txture, x, y, convert(data->txture->f[0],
					data->txture->f[1], data->txture->f[2]));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->game->mlx, data->game->win,
		data->txture->img, 0, 0);
}
