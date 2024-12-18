/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:49:50 by soksak            #+#    #+#             */
/*   Updated: 2024/12/18 14:56:28 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Işınların x ve y yönündeki gidiş yönlerinin hesaplanması
static void	calculate_deltadist(t_data *data)
{
	if (data->rc->raydir_x == 0)
		data->rc->delta_dist_x = 1e30;
	else
		data->rc->delta_dist_x = abs(1 / data->rc->raydir_x);
	if (data->rc->raydir_y == 0)
		data->rc->delta_dist_y = 1e30;
	else
		data->rc->delta_dist_y = abs(1 / data->rc->raydir_y);
}


// Işının Duvara Değmesini hesaplayan blok
// Eğer side = 1 ise ışın en son y yönünde ilerlemiştir DDA algoritmasına göre
// Eğer side = 0 ise ışın en son x yönünde ilerlemiştir DDA algoritmasına göre
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
			if (data->map->map[data->plyr->map_x][data->plyr->map_y] == '1') // Duvar Var mı diye kontrol?. Eninde Sonunda bulcak ışın bir yolunu :) // Mapx ve Mapy matrise dikkat
				data->rc->hit = 1;
		}
}

// Işınların 2D Üzerindeki Gidiş Yönünün Hesaplanması
static void check_raydir(t_data *data)
{
	if (data->rc->raydir_x < 0)
	{
		data->rc->step_x = -1; // x yönünün tersine gidiyor demek oluyor.
		data->rc->side_dist_x = (data->plyr->x - data->plyr->map_x)
			* data->rc->delta_dist_x;
	}
	else
	{
		data->rc->step_x = 1; // x yönünün pozitif yönüne gidiyor demek oluyor.
		data->rc->side_dist_x = (data->plyr->map_x + 1.0 - data->plyr->x)
			* data->rc->delta_dist_x;
	}
	if (data->rc->raydir_y < 0)
	{
		data->rc->step_y = -1; // y yönünün negatifi
		data->rc->side_dist_y = (data->plyr->y - data->plyr->map_y)
			* data->rc->delta_dist_y;
	}
	else
	{
		data->rc->step_y = 1; // y yönünün pozitifi
		data->rc->side_dist_y = (data->plyr->map_y + 1.0 - data->plyr->y)
			* data->rc->delta_dist_y;
	}
}

// Raycasting Algoritmasının Başlangıcı
void	raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < SWIDTH)
	{
		data->rc->camera_x = 2 * x / (double)SWIDTH - 1; // Ekranı x ekseninde -1 ve 1 arasında normalize ediyorum.
		data->rc->raydir_x = data->plyr->dir_x
			+ data->rc->plane_x * data->rc->camera_x; // Işınların x yönündeki gidiş yönü
		data->rc->raydir_y = data->plyr->dir_y
			+ data->rc->plane_y * data->rc->camera_x; // Işınların y yönündeki gidiş yönü
		calculate_deltadist(data);
		check_raydir(data);
		check_hit(data);
	}
}
