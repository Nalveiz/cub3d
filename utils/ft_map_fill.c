/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:14:41 by musozer           #+#    #+#             */
/*   Updated: 2024/12/22 02:01:17 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	void	ft_fill_space(t_data *data, int i, int j)
{
	char **map;

	map = data->map->map3d;
	if ((map[i][j] == '0' || map[i][j] == 'N'
		|| map[i][j] == 'S' || map[i][j] == 'E'
		|| map[i][j] == 'W')
		&& ((i -1 >= 0 && map[i -1][j] == 'B')
		|| (i +1 < data->map->height && map[i +1][j] == 'B')
		|| (j -1 >= 0 && map[i][j -1] == 'B')
		|| (j +1 < (int)ft_strlen(map[i]) && map[i][j +1] == 'B')))
		ft_err_msg("Map has empty space");
}

static	void	ft_multi_map_fill(t_data *data, int i, int j)
{
    char	**map;

	map = data->map->cpymap;
	if ((i - 1  >= 0
		&& (map[i - 1][j] != 'B'
		&& map[i - 1][j] != '1'))
		|| (j - 1 >= 0
		&& (map[i - 1][j] != 'B'
		&& map[i - 1][j] != '1'))
		|| (i + 1 < data->map->height
		&& (map[i + 1][j] != 'B'
		&& map[i + 1][j] != '1'))
		|| (j + 1 < (int)ft_strlen(map[i])
		&& (map[i][j + 1] != 'B'
		&& map[i][j + 1] != '1')))
		ft_err_msg("Multi map fill error");
}
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
}


void	ft_flood_fill(t_map *map, int x, int y)
{
	if (y < 0 || x < 0 || y >= map->height
		|| x >= (int)ft_strlen(map->cpymap[y])
		|| map->cpymap[y][x] == 'B'
		|| map->cpymap[y][x] == 'X')
		return ;
	map->cpymap[y][x] = 'X';
	ft_flood_fill(map, x, y +1);
	ft_flood_fill(map, x, y -1);
	ft_flood_fill(map, x +1, y);
	ft_flood_fill(map, x -1, y);
}
void	ft_flood_fill_chck(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->cpymap[i])
	{
		j = 0;
		while (data->map->cpymap[i][j])
		{
			if (data->map->cpymap[i][j] != 'B' && data->map->cpymap[i][j] != 'X')
			{
				if (data->map->cpymap[i][j] == '1')
					ft_multi_map_fill(data, i, j);
			}
			ft_fill_space(data, i, j);
			j++;
		}
		i++;
	}
}
