/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:39:44 by musozer           #+#    #+#             */
/*   Updated: 2025/01/02 04:41:43 by soksak           ###   ########.fr       */
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

static void	destory_mlx(t_data *data)
{
	int	i;

	i = 0;
	if (data->wall != NULL)
	{
		while (i < 4)
		{
			if (data->wall->img[i] != NULL)
				mlx_destroy_image(data->game->mlx, data->wall->img[i]);
			i++;
		}
		free(data->wall);
	}
	if (data->game != NULL)
	{
		if (data->game->win != NULL)
			mlx_destroy_window(data->game->mlx, data->game->win);
		if (data->game->mlx != NULL)
		{
			mlx_destroy_display(data->game->mlx);
			free(data->game->mlx);
		}
		free(data->game);
	}
}

static void	ft_free_map(t_data *data)
{
	if (data->map->map3d != NULL)
		ft_double_free(data->map->map3d);
	if (data->map->map != NULL)
		ft_double_free(data->map->map);
	if (data->map->cpymap != NULL)
		ft_double_free(data->map->cpymap);
	free(data->map);
	data->map = NULL;
}

static void	ft_free_texture(t_data *data)
{
	if (data->txture->txtres != NULL)
	{
		if (data->txture->txtres[SO] != NULL)
			free(data->txture->txtres[SO]);
		if (data->txture->txtres[NO] != NULL)
			free(data->txture->txtres[NO]);
		if (data->txture->txtres[WE] != NULL)
			free(data->txture->txtres[WE]);
		if (data->txture->txtres[EA] != NULL)
			free(data->txture->txtres[EA]);
		if (data->txture->txtres[C] != NULL)
			free(data->txture->txtres[C]);
		if (data->txture->txtres[F] != NULL)
			free(data->txture->txtres[F]);
		free(data->txture->txtres);
	}
	if (data->txture->img != NULL)
		mlx_destroy_image(data->game->mlx, data->txture->img);
	free(data->txture);
}

void	ft_free(t_data *data, char *s)
{
	ft_free_map(data);
	ft_free_texture(data);
	destory_mlx(data);
	ft_data_free(data);
	if (s != NULL)
		ft_err_msg(s);
	exit(0);
}
