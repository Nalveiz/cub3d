/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:12:22 by musozer           #+#    #+#             */
/*   Updated: 2024/11/26 15:05:56 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_data
{
	char	*av;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;

}	t_data;


void	ft_control(t_data *data);
void	ft_err_msg(char *error_message);
void	ft_init(t_data *data, char *av);



#endif
