/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:11:03 by musozer           #+#    #+#             */
/*   Updated: 2024/11/29 23:53:41 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//Satır Satır Texture ve renk kontrolleri yapılacak

int	ft_is_blank(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
    	if (c[i] == ' ' || c[i] == '\t'
			|| c[i] == '\v' || c[i] == '\f' || c[i] == '\r')
			i++;
		else if (c[i] == '\n')
			return (-1);
		else
			return (i);
	}
	return (i);
}

void	ft_is_space(t_data *data)
{
	while (data->map->map[data->i])
	{
		if (ft_is_blank(data->map->map[data->i]) == -1)
			data->i++;
		else
		{
			ft_check_txtrue(data, data->map->map[data->i]);
			data->i++;;
		}
	}
}

int	ft_count_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->map->count[i] != 1)
			return (-1);
		i++;
	}
	return (0);
}


void	ft_check_txtrue(t_data *data, char *line)
{
	int		i;
	char	*format;

	i = 0;
	while (line[i] && line[i] != ' ' && !(line[i] < 14 && line[i] > 8))
		i++;
	format = ft_substr(line, 0, i);
	while (line[i] && line[i] == ' ' && (line[i] < 14 && line[i] > 8))
		i++;
	if (ft_strncmp(format, "SO", 2) == 0 && ++data->map->count[SO])
		data->txture->txtres[SO] = ft_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_strncmp(format, "NO", 2) == 0 && ++data->map->count[NO])
		data->txture->txtres[NO] = ft_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_strncmp(format, "WE", 2) == 0 && ++data->map->count[WE])
		data->txture->txtres[WE] = ft_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_strncmp(format, "EA", 2) == 0 && ++data->map->count[EA])
		data->txture->txtres[EA] = ft_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_strncmp(format, "C", 2) == 0 && ++data->map->count[C])
		data->txture->txtres[C] = ft_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_strncmp(format, "F", 2) == 0 && ++data->map->count[F])
		data->txture->txtres[F] = ft_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_count_check(data) == -1)
		ft_err_msg("Wrong texture format");
	else
		//texture formatı doğru harita kontrolü yapılsın
		ft_err_msg("true texture format");

	return ;
}


