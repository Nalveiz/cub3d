/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:14:41 by musozer           #+#    #+#             */
/*   Updated: 2024/12/13 19:52:06 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_cpymap_fill(t_data * data)
{
	t_map	*map;

	map = data->map;
	map->cpymap = (char **)malloc(sizeof(char *) * (data->map->height + 1));
	if (map->cpymap == NULL)
	    ft_err_msg("Malloc failed");
	data->i = -1;
	while (map->map3d[++data->i])
	{
		data->j = -1;
		while (map->map3d[data->i][++data->j])
		{
			if (map->map3d[data->i][data->j] == ' ')
				map->map3d[data->i][data->j] = 'B';
		}
		map->cpymap[data->i] = ft_strdup(map->map3d[data->i]);
	}
	printf("Player position: x = %f, y = %f\n", data->plyr->x, data->plyr->y);
	printf("%d\n", data->map->height);
	printf("naber\n");
}

void	ft_flood_fill(t_map *map, int x, int y)
{
		if (y < 0 || x < 0 || y >= map->height
		|| x >= (int)ft_strlen(map->cpymap[y])
		|| map->cpymap[y][x] == 'B'
		|| map->cpymap[y][x] == 'X')
		return ;
	map->cpymap[y][x] = 'X';
	ft_flood_fill(map, y +1, x);
	ft_flood_fill(map, y -1, x);
	ft_flood_fill(map, y, x +1);
	ft_flood_fill(map, y, x -1);
}
