/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:09:57 by musozer           #+#    #+#             */
/*   Updated: 2024/12/20 16:56:37 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

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
	ft_flood_fill(data->map, data->ply_x, data->ply_y);
	ft_flood_fill_chck(data);
	int i = 0;
	while (data->map->map3d[i])
	{
		printf("%s\n", data->map->map3d[i]);
		i++;
	}
	open_window(data);
	// int i = 0;
	// while (data->map->cpymap[i])
	// {
	// 	printf("%s\n", data->map->cpymap[i]);
	// 	i++;
	// }
	// while (1)
	// {
	// 	if (!data->map->map[i])
	// 	    break ;
	// 	printf("%s", data->map->map[i]);
	// 	i++;
	// }

	return (0);
}
