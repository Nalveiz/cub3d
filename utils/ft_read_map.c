/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:09:10 by musozer           #+#    #+#             */
/*   Updated: 2024/11/29 23:37:34 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_control(t_data *data)
{
	size_t	last;

	last = ft_strlen(data->av);
	if (data->av[--last] != 'b' || data->av[--last] != 'u'
		|| data->av[--last] != 'c' || data->av[--last] != '.')
		ft_err_msg("Wrong file extension");
	data->fd = open(data->av, O_RDONLY, 777);
	if (data->fd == -1)
		ft_err_msg("File not found");
	close(data->fd);
}

void	map_lenght(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->fd = open(data->av, O_RDONLY, 777);
	if (data->fd == -1)
		ft_err_msg("File not found");
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
	ft_control(data);
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
	ft_is_space(data);
}


