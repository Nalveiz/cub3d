/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:22:27 by musozer           #+#    #+#             */
/*   Updated: 2024/12/03 20:06:59 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/cub3d.h"

// void ft_map_cpy(t_data *data)
// {
// 	char    *tmp;
// 	static int i;

// 	i = 0;
// 	data->map->height = data->map_len - data->i;
// 	data->map->map3d = (char **)malloc(sizeof(char *) * (data->map->height + 1));

// 	data->map->map3d[i] = ft_space_trimmer(data->map->map[data->i]);

// 	if (data->map->width < (int) ft_strlen(data->map->map3d[i]))
// 		data->map->width = (int) ft_strlen(data->map->map3d[i]);
// 	while (tmp[i] && (tmp[i] == ' '))
// 		i++;
// 	while (tmp[i])
// 	{
// 		if (tmp[i] != 'N' && tmp[i] != 'S' && tmp[i] != 'E' && tmp[i] != 'W'
// 			&& tmp[i] != '0' && tmp[i] != '1'
// 			&& tmp[i] != ' ' && tmp[i] != '\n')
// 			check++;
// 		i++;
// 	}

// }

// void ft_char_control(t_data *data, char *str)
// {
// 	data->j = 0;
// 	while (str[data->j])
// 	{
// 		if (str[data->j] == ' ' || (str[data->j] == '\n' && data->j != 0))
// 			data->j++;
// 		else if (str[data->j] == '1' && (data->flag == 0
// 			|| data->j ==data->map_len))
// 			data->j++;
// 		else if ((str[data->j] == 'N' || str[data->j] == 'S'
// 			|| str[data->j] == 'E' || str[data->j] == 'W'
// 			|| str[data->j] == '0' || str[data->j] == '1')
// 			&& data->flag == 1)
// 			data->j++;
// 		else
// 			ft_err_msg("Wrong character in map");
// 	}
// 	ft_with_check(data, str);
// }



// int	ft_map_start_check(t_data *data)
// {
// 	ft_first_check(data, data->map->map[data->i]);
// 	ft_char_control(data, data->map->map[data->i]);




// 	// char *wall;
// 	// int i;

// 	// i = 0;
// 	// wall = data->map->map[data->i];
// 	// while (wall[i])
// 	// {
// 	// 	if (wall[i] == '1')
// 	// 		i++;
// 	// 	else if (wall[i] = ' ' || (wall[i] < 14 && wall[i] > 8))
// 	// 		i++;
// 	// 	else
// 	// 		ft_err_msg("Wrong map format");
// 	// }
// 	// return (1);
// }

// ft_map_check(t_data *data)
// {
// 	while (data->map->map[data->i][data->j])
// 	{
// 		if (ft_is_blank(data->map->map[data->i]) == -1)
// 			data->i++;
// 		else if (ft_map_start_check(data->map->map[data->i]) == 1)

// 	}
// }
