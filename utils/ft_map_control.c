/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:22:27 by musozer           #+#    #+#             */
/*   Updated: 2024/12/07 13:11:45 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void ft_wall_check(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] != '1')
		ft_err_msg("Wron map format");
	i = ft_strlen(line) -2;
	while (i >= 0 && line[i] == ' ')
		i--;
	if (i >= 0 && line[i] != '1')
		ft_err_msg("Wrongggg map format");
}
static void	ft_char_check(char *line, int flag)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != '0' && line[i] != '1'
			&& line[i] != ' ' && line[i] != '\n')
			ft_err_msg("Wrong ccharacter in map");
		if (flag == 0 && (line[i] != '1' && line[i] != ' ' && line[i] != '\n'))
		    ft_err_msg("Wrong map format");
		i++;
	}
}

static	void	ft_map_start_check(t_data *data, char *line)
{
	ft_char_check(line,data->flag);

	if (data->i == data->map->height)
		data->flag = 0;
	data->flag = 1;
	ft_wall_check(line);
	// eğer ki hata yoksa data->map->map[data->i] ' si free lenicek en son map free olucak
}

void	ft_map_check(t_data *data)
{
	int i;
	int j;

	j = 0;
	i = data->i;
	// burda en alttaki gereksiz satırları atlıyorum mapin gerçek uzunluğu için
	while (ft_is_blank(data->map->map[data->map_len - 1]) == -1)
		data->map_len--;
	data->map->height = data->map_len - data->i;
	// mapin ilk satırını kontrol ediyorum son satıra kadar
	while (data->map->map[data->i] && data->i < data->map_len)
	{
		if (data->map->width < (int) ft_strlen(data->map->map[data->i]))
			data->map->width = (int) ft_strlen(data->map->map[data->i]);
		ft_map_start_check(data, data->map->map[data->i]);
		data->i++;
	}
	// eğer hata yoksa map3d oluşturuluyor ve içine atılıyor
	data->map->map3d = (char **)malloc(sizeof(char *) * (data->map->height + 1));
	while (i < data->map_len)
	{
		data->map->map3d[j] = ft_strtrim(data->map->map[i], "\n");
		i++;
		j++;
	}
	// soksakım ana mantık bu şekilde yaptım sonra yine configre ederiz bundan sonra :>)
}
