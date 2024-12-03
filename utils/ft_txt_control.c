/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_txt_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:07:32 by musozer           #+#    #+#             */
/*   Updated: 2024/12/02 23:18:44 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int ft_value_check(int i)
{

	if (i < 0 || i > 255)
		ft_err_msg("Wrong RGB color format (0-255)");
	return i;
}
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

	i = -1;
	while (rgb[++i])
	{
		linetrim = ft_space_trimmer(rgb[i]);
		if (!linetrim || linetrim[0] == '\0')
			ft_err_msg("Wrong null color format");
		j = -1;
		while (linetrim[++j])
		{
			if ((linetrim[j] < '0' || linetrim[j] > '9'))
				ft_err_msg("Wrong color format");

		}
		if (fc == 1)
			data->txture->c[i] = ft_value_check(ft_atoi(linetrim));
		else
			data->txture->f[i] = ft_value_check(ft_atoi(linetrim));
		free(linetrim);
	}
	free(rgb);
}
// ft_rgb_format();
