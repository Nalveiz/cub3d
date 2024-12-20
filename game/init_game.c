/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 01:54:22 by soksak            #+#    #+#             */
/*   Updated: 2024/12/20 18:15:37 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


static void	ray_init(t_data *data)
{
	data->rc = malloc(sizeof(t_ray));
	data->rc->plane_x = 0; // Bu da Aynı Şekilde
	data->rc->plane_y = 0.66; // Camera Plane FOV için
	data->plyr->dir_x = 1; // Oyuncunun x yönündeki bakış yönü
	data->plyr->dir_y = 0; // Oyuncunun y yönündeki bakış yönü
	data->plyr->x = 4.5; // Oyuncunun x koordinatı
	data->plyr->y = 4.5; // Oyuncunun y koordinatı
	data->plyr->map_x = (int)data->plyr->x; // Oyuncunun x koordinatının tam kısmı
	data->plyr->map_y = (int)data->plyr->y; // Oyuncunun y koordinatının tam kısmı
	data->rc->time = 0; // FPS muhabbeti
	data->rc->oldtime = 0; // FPS muhabbeti
	data->rc->hit = 0;
	// side tanımlaması falan da yapabilirsin side = 0 or side = 1. Değişken Inıtıalize bazen kafayı yiyebilir aman aman :)
	raycasting(data);
}

void	open_window(t_data *data)
{
	data->game = malloc(sizeof(t_game));
	if (!data->game)
		ft_err_msg("Malloc failed");
	data->game->mlx = mlx_init();
	data->game->win = mlx_new_window(data->game->mlx, SWIDTH, SHEIGHT, "Cub3D");
	data->txture->img = mlx_new_image(data->game->mlx, SWIDTH, SHEIGHT);
	data->txture->addr = mlx_get_data_addr(data->txture->img, &data->txture->bpp,
		&data->txture->llength, &data->txture->endian);
	draw_celling_and_flor(data);
	ray_init(data);
	mlx_loop(data->game->mlx);
}

