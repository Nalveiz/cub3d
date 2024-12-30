/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:39:44 by musozer           #+#    #+#             */
/*   Updated: 2024/12/30 23:49:01 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_double_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
// void	ft_full_free(char *str)
// {
// 	if ()
// }

// static void	ft_free_map(t_data *data)
// {
// 	if (data->map->map3d != NULL)
// 		ft_double_free(data->map->map3d);
// 	if (data->map->map != NULL)
// 		ft_double_free(data->map->map);
// 	if (data->map->cpymap != NULL)
// 		ft_double_free(data->map->cpymap);
// 	free(data->map);
// 	data->map = NULL;
// }

// static void	ft_free_texture(t_data *data)
// {
// 	if (data->txture->txtres[SO] != NULL)
// 		free(data->txture->txtres[SO]);
// 	if (data->txture->txtres[NO] != NULL)
// 		free(data->txture->txtres[NO]);
// 	if (data->txture->txtres[WE] != NULL)
// 		free(data->txture->txtres[WE]);
// 	if (data->txture->txtres[EA] != NULL)
// 		free(data->txture->txtres[EA]);
// 	if (data->txture->floor != NULL)
// 		ft_double_free(data->txture->floor);
// 	if (data->txture->ceiling != NULL)
// 		ft_double_free(data->txture->ceiling);
// 	data->txture->ceiling = NULL;
// 	data->txture->floor = NULL;
// 	free(data->txture);
// }

// void	ft_free(t_data *data, char *s)
// {
// 	ft_mlx_free(data);
// 	free(data->key);
// 	ft_free_texture(data);
// 	ft_free_list(data);
// 	free(data->raycast);
// 	free(data->player);
// 	ft_free_map(data);
// 	free(data);
// 	data = NULL;
// 	if (s != NULL)
// 		ft_error_msg(s);
// 	exit(0);
// }
