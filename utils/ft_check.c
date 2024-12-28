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
				break;
			}
			ft_check_txtrue(data, data->map->map[data->i]);
			data->i++;;
		}
	}
	ft_textrue_control(data, 0);
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
	if (i < 0 || i >= (int)ft_strlen(line))
		ft_err_msg("Wrong texture format");
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
	if (format)
	{
		ft_check_txture_helper(line, format, i, data);
		free(format);
	}
}

char *ft_space_trimmer(char *line)
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
static	void ft_plyr_wall_check(t_data *data, int i, int j)
{
	if (data->map->cpymap[i][j] == 'N' || data->map->cpymap[i][j] == 'S'
		|| data->map->cpymap[i][j] == 'E' || data->map->cpymap[i][j] == 'W')
		data->flag1++;
	if (data->flag1 == 1 && (data->map->cpymap[i][j] == 'N'
		|| data->map->cpymap[i][j] == 'S'
		|| data->map->cpymap[i][j] == 'E'
		|| data->map->cpymap[i][j] == 'W'))
	{
		data->plyr->x = (double)j;
		data->plyr->y = (double)i;
		data->plyr->look_pos = data->map->cpymap[i][j];
		data->map->cpymap[i][j] = '0';
		data->flag1++;
	}
}
static void	ft_char_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->cpymap[i])
	{
		j = -1;
		while (data->map->cpymap[i][++j])
		{
			ft_plyr_wall_check(data, i, j);
		}
		i++;
	}
	if (data->flag1 > 2 || data->flag1 == 0)
		ft_err_msg("wrong character !!!");
}


void	ft_textures_check(t_txture *txtrue, int i)
{
	size_t	last;

	last = ft_strlen(txtrue->txtres[i]);
	if (txtrue->txtres[i][--last] != 'm' || txtrue->txtres[i][--last] != 'p'
		|| txtrue->txtres[i][--last] != 'x' || txtrue->txtres[i][--last] != '.')
		ft_err_msg("Wrong file extension");



}

void	ft_textrue_control(t_data *data, size_t last)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		last = ft_strlen(data->txture->txtres[i]) - 2;
		data->txture->txtres[i] = ft_space_trimmer(data->txture->txtres[i]);
		data->fd = open(data->txture->txtres[i], O_RDONLY, 777);
		if (data->fd == -1)
		{
			ft_err_msg("Texture not found");
			close(data->fd);
		}
		close(data->fd);
		if (data->txture->txtres[i][--last] != 'm' || data->txture->txtres[i][--last] != 'p'
			|| data->txture->txtres[i][--last] != 'x' || data->txture->txtres[i][--last] != '.')
			ft_err_msg("Wrong file extension");
	}
	ft_comma_control(data->txture->txtres[C]);
	ft_comma_control(data->txture->txtres[F]);
	ft_rgb_control(data, ft_split(data->txture->txtres[C], ','), 1);
	ft_rgb_control(data, ft_split(data->txture->txtres[F], ','), 0);
	ft_map_check(data);
	ft_char_check(data);
}

