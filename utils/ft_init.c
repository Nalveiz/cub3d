/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:43:18 by musozer           #+#    #+#             */
/*   Updated: 2024/12/13 16:30:43 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init(t_data *data, char *av)
{
	data->av = av;
	data->map = (t_map *) malloc(sizeof(t_map));
	data->plyr = (t_plyr *) malloc(sizeof(t_plyr));
	if (data->map == NULL)
		ft_err_msg("Malloc failed");
	data->map->height = 0;
	data->map->width = 0;
	data->plyr->x = 0;
	data->plyr->y = 0;
	data->ply_x = 0;
	data->ply_y = 0;
	data->flag = 0;
	data->flag1 = 0;
	data->txture = (t_txture *) malloc(sizeof(t_txture));
	data->txture->txtres = (char **) malloc(7 * sizeof(char *));
	if (!data->map || !data->txture)
		ft_err_msg("Malloc failed");
	ft_memset(data->map->count, 0, 6);
	ft_memset(data->txture->c, 0, 3);
	ft_memset(data->txture->f, 0, 3);
	data->i = 0;
	data->j = 0;


}
