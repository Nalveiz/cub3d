/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:43:18 by musozer           #+#    #+#             */
/*   Updated: 2024/11/27 18:53:43 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init(t_data *data, char *av)
{
	data->av = av;
	data->map = (t_map *) malloc(sizeof(t_map));
	if (!data->map)
		ft_err_msg("Malloc failed");
	ft_memset(data->map->count, 0, 6);
	data->i = 0;
	data->j = 0;


}
