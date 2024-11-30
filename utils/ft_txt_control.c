/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_txt_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:07:32 by musozer           #+#    #+#             */
/*   Updated: 2024/11/30 10:25:15 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

	i = 0;
	j = 0;
	while (rgb[i])
	{
		linetrim = ft_space_trimmer(rgb[i]);
		while (linetrim[j])
		{
			if ((linetrim[j] < '0' || linetrim[j] > '9'))
				ft_err_msg("Wrong color format");
			if (j > 2)
				ft_err_msg("Wrong RGB color format");
			j++;
		}
		if (fc == 1)
			data->txture->c[i] = ft_atoi(linetrim);
		data->txture->f[i] = ft_atoi(linetrim);
		free(linetrim);
		i++;
	}
	free(rgb);
}
// ft_rgb_format();
