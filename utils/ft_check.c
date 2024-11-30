/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:11:03 by musozer           #+#    #+#             */

/*   Updated: 2024/11/30 09:07:18 by soksak           ###   ########.fr       */
/*   Updated: 2024/11/30 08:59:22 by musozer          ###   ########.fr       */
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
				break;
			}
			ft_check_txtrue(data, data->map->map[data->i]);
			data->i++;;
		}
	}
	ft_textrue_control(data);
}

static char	*my_strdup(char *s1)
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


static void	ft_check_txture_helper(char*line, char *format, int i, t_data *data)
{
	if (ft_strncmp(format, "SO", 2) == 0 && ++data->map->count[SO] == 1)
		data->txture->txtres[SO] = my_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_strncmp(format, "NO", 2) == 0 && ++data->map->count[NO] == 1)
		data->txture->txtres[NO] = my_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_strncmp(format, "WE", 2) == 0 && ++data->map->count[WE] == 1)
		data->txture->txtres[WE] = my_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_strncmp(format, "EA", 2) == 0 && ++data->map->count[EA] == 1)
		data->txture->txtres[EA] = my_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_strncmp(format, "C", 1) == 0 && ++data->map->count[C] == 1)
		data->txture->txtres[C] = my_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_strncmp(format, "F", 1) == 0 && ++data->map->count[F] == 1)
		data->txture->txtres[F] = my_strdup
			(ft_substr(line, i, (ft_strlen(line) -1)));
	else if (ft_count_check(data) == -1)
		ft_err_msg("Wrong texture format");
}


void	ft_check_txtrue(t_data *data, char *line)
{
	int		i;
	char	*format;

	i = 0;
	while (line[i] && line[i] != ' ' && !(line[i] < 14 && line[i] > 8))
		i++;
	format = ft_substr(line, 0, i);
	while (line[i] && (line[i] == ' ' || (line[i] < 14 && line[i] > 8)))
		i++;
	ft_check_txture_helper(line, format, i, data);
	free(format);
}

char *ft_space_trimmer(char *line)
{
	char	*spaces;
	char	*new_line;

	spaces = "\t\v\f\r\n ";
	new_line = ft_strtrim(line, spaces);
	free(line);
	return (new_line);
}

void	ft_textrue_control(t_data *data)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		data->txture->txtres[i] = ft_space_trimmer(data->txture->txtres[i]);
		data->fd = open(data->txture->txtres[i], O_RDONLY, 777);
		if (data->fd == -1)
		{
			ft_err_msg("Texture not found");
			close(data->fd);
		}
		close(data->fd);
		i++;
	}
	i = 0;
	while (data->txture->txtres[i])
	{
		printf("%s\n", data->txture->txtres[i]);
		printf("i = %d\n", data->i);
		i++;
	}
	ft_err_msg("Texture true");
	ft_comma_control(data->txture->txtres[C]);
	ft_comma_control(data->txture->txtres[F]);
	ft_rgb_control(data, ft_split(data->txture->txtres[C], ','), 1);
	ft_rgb_control(data, ft_split(data->txture->txtres[F], ','), 0);
}

