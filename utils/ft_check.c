/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:11:03 by musozer           #+#    #+#             */
/*   Updated: 2024/11/27 19:55:36 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Satır Satır Texture ve renk kontrolleri yapılacak

// int	ft_is_blank(char *c)
// {
// 	int	i;

// 	i = 0;
// 	while (c[i])
// 	{
//     	if (c == ' ' || c == '\t'
// 			|| c == '\v' || c == '\f' || c == '\r')
// 			i++;
// 	}
// 	if (c[i] == '\n')
// 		return (-1);
// 	return (i);
// }

// int	ft_is_space(t_data *data)
// {
// 	int	k;

// 	k = 0;
// 	while (data->map->map[k])
// 	{
// 		if (ft_is_blank(data->map->map[data->i]) == -1)
// 			k++;
// 		else
// 		{
// 			ft_check_txtrue(data, ft_is_blank(ft_is_blank(data->map->map[data->i])), k);
// 		}
// 		data->i;
// 	}



// }


// void	ft_check_txtrue(t_data *data, int i, int j)
// {
// 	if (map[j][i] == 'S' || )


// }


// void	ft_texture_check(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data->map->map[i])
// 	{
// 		if ()

// 	}

// }

void	ft_control(t_data *data)
{
	size_t	last;

	last = ft_strlen(data->av);
	if (data->av[--last] != 'b' || data->av[--last] != 'u'
		|| data->av[--last] != 'c' || data->av[--last] != '.')
		ft_err_msg("Wrong file extension");
	data->fd = open(data->av, O_RDONLY, 777);
	if (data->fd == -1)
		ft_err_msg("File not found");
	close(data->fd);
}
