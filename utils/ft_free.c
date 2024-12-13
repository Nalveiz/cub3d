/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:39:44 by musozer           #+#    #+#             */
/*   Updated: 2024/12/12 21:41:36 by musozer          ###   ########.fr       */
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
// ft_free(t_data *data, char *str)
// {



// 	free(data->map->map);
// 	ft_double_free(data->txture->txtres);
// 	ft_double_free(data->txture->floor);
// 	ft_double_free(data->txture->ceiling);
// 	free(data->txture);
// 	free(data->map);
// 	free(data);
// }
