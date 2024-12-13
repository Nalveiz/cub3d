/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:46:53 by musozer           #+#    #+#             */
/*   Updated: 2024/12/12 18:46:55 by musozer          ###   ########.fr       */
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



