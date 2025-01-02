/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:46:53 by musozer           #+#    #+#             */
/*   Updated: 2025/01/02 04:47:36 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_err_msg(char *error_message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	ft_data_free(t_data *data)
{
	if (data->plyr != NULL)
	{
		free(data->plyr);
		data->plyr = NULL;
	}
	if (data->rc != NULL)
	{
		free(data->rc);
		data->rc = NULL;
	}
	free(data);
}
