/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:09:57 by musozer           #+#    #+#             */
/*   Updated: 2024/12/26 19:23:57 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"


static	void	ft_init(t_data *data, char *av)
{
	data->av = av;
	data->map = (t_map *) malloc(sizeof(t_map));
	data->plyr = (t_plyr *) malloc(sizeof(t_plyr));
	data->txture = (t_txture *) malloc(sizeof(t_txture));
	data->txture->txtres = (char **) malloc(7 * sizeof(char *)); // bunu kullandığın yerde aç
	if (!data->map || !data->map || !data->txture || !data->plyr)
		ft_err_msg("Malloc failed");
	data->map->height = 0;
	data->map->width = 0;
	data->plyr->x = 0;
	data->plyr->y = 0;
	data->ply_x = 0;
	data->ply_y = 0;
	data->flag = 0;
	data->flag1 = 0;
	ft_memset(data->map->count, 0, 6);
	ft_memset(data->txture->c, 0, 3);
	ft_memset(data->txture->f, 0, 3);
	data->i = 0;
	data->j = 0;


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
