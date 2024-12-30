/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:41:15 by musozer           #+#    #+#             */
/*   Updated: 2024/12/29 16:17:50 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_is_blank(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[0] == '\n')
			return (-1);
		if (c[i] == ' ' || c[i] == '\t'
			|| c[i] == '\v' || c[i] == '\f' || c[i] == '\r')
			i++;
		else
			return (i);
	}
	return (i);
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

void	ft_is_space(t_data *data)
{
	while (data->map->map[data->i])
	{
		if (ft_is_blank(data->map->map[data->i]) == -1)
			data->i++;
		else
		{
			if (ft_count_check(data) == 0)
			{
				data->txture->txtres[6] = NULL;
				break ;
			}
			ft_check_txtrue(data, data->map->map[data->i]);
			data->i++;
		}
	}
	ft_textrue_control(data, 0);
}

char	*ft_space_trimmer(char *line)
{
	char	*spaces;
	char	*trimmed;
	char	*new_line;

	spaces = "\t\v\f\r\n ";
	trimmed = ft_strtrim(line, spaces);
	new_line = ft_strdup(trimmed);
	free(trimmed);
	free(line);
	return (new_line);
}

char	*my_strdup(char *s1)
{
	char	*dst;
	int		i;

	dst = malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	free(s1);
	return (dst);
}
