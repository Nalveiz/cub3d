/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 01:54:22 by soksak            #+#    #+#             */
/*   Updated: 2025/01/02 08:24:49 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	calculate_directions(t_data *data)
{
	if (data->plyr->look_pos == 'N')
	{
		data->plyr->dir_y = -1;
		data->rc->plane_x = 0.66;
	}
	else if (data->plyr->look_pos == 'S')
	{
		data->plyr->dir_y = 1;
		data->rc->plane_x = -0.66;
	}
	else if (data->plyr->look_pos == 'W')
	{
		data->plyr->dir_x = -1;
		data->rc->plane_y = -0.66;
	}
	else if (data->plyr->look_pos == 'E')
	{
		data->plyr->dir_x = 1;
		data->rc->plane_y = 0.66;
	}
	data->plyr->x += 0.5;
	data->plyr->y += 0.5;
}

static void	ray_init(t_data *data)
{
	data->rc = malloc(sizeof(t_ray));
	data->rc->plane_x = 0;
	data->rc->plane_y = 0;
	data->plyr->dir_x = 0;
	data->plyr->dir_y = 0;
	data->plyr->map_x = (int)data->plyr->x;
	data->plyr->map_y = (int)data->plyr->y;
	data->rc->hit = 0;
	data->plyr->move_speed = 0.12;
	data->plyr->rot_speed = 0.10;
	calculate_directions(data);
	raycasting(data);
}

static void	load_walls(t_data *data, int i)
{
	int	width;
	int	height;

	data->wall->img[i] = mlx_xpm_file_to_image(data->game->mlx,
			data->txture->txtres[i], &width, &height);
	if (!data->wall->img[i])
		ft_err_msg("Texture not found");
	data->wall->addr[i] = mlx_get_data_addr(data->wall->img[i],
			&data->wall->bpp[i], &data->wall->llength[i],
			&data->wall->endian[i]);
	data->wall->width[i] = width;
	data->wall->height[i] = height;
}

static void	image_init(t_data *data)
{
	int	i;

	i = -1;
	data->wall = malloc(sizeof(t_wall));
	if (!data->wall)
		ft_err_msg("Malloc failed");
	while (++i < 4)
		load_walls(data, i);
	data->txture->img = mlx_new_image(data->game->mlx, SWIDTH, SHEIGHT);
	data->txture->addr = mlx_get_data_addr(data->txture->img,
			&data->txture->bpp, &data->txture->llength, &data->txture->endian);
}

void	open_window(t_data *data)
{
	data->game = malloc(sizeof(t_game));
	if (!data->game)
		ft_err_msg("Malloc failed");
	data->game->mlx = mlx_init();
	data->game->win = mlx_new_window(data->game->mlx, SWIDTH, SHEIGHT, "Cub3D");
	image_init(data);
	draw_celling_and_flor(data);
	ray_init(data);
	mlx_hook(data->game->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->game->win, 17, 0, close_window, data);
	mlx_loop(data->game->mlx);
}
