/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:09:57 by musozer           #+#    #+#             */
/*   Updated: 2025/01/02 04:41:25 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void ft_init_helper(t_data *data)
{
	int i;

	i = 0;
	while (i < 7)
	{
		data->txture->txtres[i] = NULL;
		i++;
	}
	data->wall = NULL;
	data->game = NULL;
	data->rc = NULL;
	data->txture->img = NULL;
}


static	void	ft_init(t_data *data, char *av)
{
	data->av = av;
	data->map = (t_map *) malloc(sizeof(t_map));
	data->plyr = (t_plyr *) malloc(sizeof(t_plyr));
	data->txture = (t_txture *) malloc(sizeof(t_txture));
	data->txture->txtres = (char **) malloc(7 * sizeof(char *));
	if (!data->map || !data->map || !data->txture || !data->plyr)
		ft_err_msg("Malloc failed");
	data->map->height = 0;
	data->map->width = 0;
	data->map->map = NULL;
	data->map->cpymap = NULL;
	data->map->map3d = NULL;
	data->plyr->x = 0;
	data->plyr->y = 0;
	data->flag = 0;
	data->flag1 = 0;
	data->i = 0;
	data->j = 0;
	ft_memset(data->map->count, 0, sizeof(int) * 6);
	ft_memset(data->txture->c, 0, sizeof(int) * 3);
	ft_memset(data->txture->f, 0, sizeof(int) * 3);
	ft_init_helper(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		ft_err_msg("Wrong number of arguments");
	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_err_msg("Malloc failed");
	ft_init(data, av[1]);
	ft_read_map(data);
	ft_flood_fill(data->map, data->plyr->x, data->plyr->y);
	ft_flood_fill_chck(data);
	open_window(data);
	return (0);
}
