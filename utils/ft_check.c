/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:11:03 by musozer           #+#    #+#             */
/*   Updated: 2024/11/26 15:05:31 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_control(t_data *data)
{
	size_t	last;

	last = ft_strlen(data->av);
	printf("%zu\n", last);
	if (data->av[--last] != 'b' || data->av[--last] != 'u'
		|| data->av[--last] != 'c' || data->av[--last] != '.')
		ft_err_msg("Wrong file extension");
	printf("%zu\n", last);

}
