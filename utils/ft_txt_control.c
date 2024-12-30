/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_txt_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:07:32 by musozer           #+#    #+#             */
/*   Updated: 2024/12/29 21:20:13 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	int	ft_value_check(int i)
{
	if (i < 0 || i > 255)
		ft_err_msg("Wrong RGB color format (0-255)");
	return (i);
}

void	ft_comma_control(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		ft_err_msg("Wrong RGB color format");
}

void	ft_rgb_control(t_data *data, char **rgb, int fc)
{
	char	*linetrim;
	int		i;
	int		j;

	i = -1;
	while (rgb[++i])
	{
		linetrim = ft_space_trimmer(rgb[i]);
		if (!linetrim || linetrim[0] == '\0')
			ft_err_msg("Wrong null color format");
		j = -1;
		while (linetrim[++j])
		{
			if ((linetrim[j] < '0' || linetrim[j] > '9'))
				ft_err_msg("Wrong color format");
		}
		if (fc == 1)
			data->txture->c[i] = ft_value_check(ft_atoi(linetrim));
		else
			data->txture->f[i] = ft_value_check(ft_atoi(linetrim));
		free(linetrim);
	}
	free(rgb);
}

void	ft_wall_control(t_data *data)
{
	int			i;
	int			j;
	t_map		*map;

	map = data->map;
	i = -1;
	while (map->cpymap[++i])
	{
		j = -1;
		while (map->cpymap[i][++j])
		{
			if (map->cpymap[i][j] == '0'
				&& ((i +1 < map->height
				&& (!map->cpymap[i +1][j]
				|| j > (int)ft_strlen(map->cpymap[i +1])))
				|| (i -1 >= 0 && (!map->cpymap[i - 1][j]
				|| j > (int)ft_strlen(map->cpymap[i - 1])))))
				ft_err_msg("Map must be surrounded by walls");
		}
	}
}

void	ft_textures_check(t_txture *txtrue, int i)
{
	size_t	last;

	last = ft_strlen(txtrue->txtres[i]);
	if (txtrue->txtres[i][--last] != 'm' || txtrue->txtres[i][--last] != 'p'
		|| txtrue->txtres[i][--last] != 'x' || txtrue->txtres[i][--last] != '.')
		ft_err_msg("Wrong file extension");
}
