/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:09:10 by musozer           #+#    #+#             */
/*   Updated: 2024/11/27 16:39:48 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	map_lenght(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->fd = open(data->av, O_RDONLY, 777);
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	data->map_len = i;
	close(data->fd);
}

void	ft_read_map(t_data *data)
{
	int		i;

	i = 0;
	map_lenght(data);
	data->fd = open(data->av, O_RDONLY, 777);
	if (data->fd == -1)
		ft_err_msg("File not found");
	data->map->map = (char **)malloc(sizeof(char *) * data->map_len + 1);
	if (!data->map->map)
		ft_err_msg("Malloc failed.");
	while (1)
	{
		data->map->map[i] = get_next_line(data->fd);
		if (!data->map->map[i])
			break ;
		i++;
	}
	close(data->fd);
	return ;
}


