/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:09:57 by musozer           #+#    #+#             */
/*   Updated: 2024/11/27 16:40:40 by musozer          ###   ########.fr       */
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
	ft_control(data);
	ft_read_map(data);
	int i = 0;
	while (1)
	{
		if (!data->map->map[i])
		    break ;
		printf("%s", data->map->map[i]);
		i++;
	}
	return (0);
}
