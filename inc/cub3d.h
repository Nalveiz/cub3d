/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:12:22 by musozer           #+#    #+#             */
/*   Updated: 2024/11/29 22:29:10 by musozer          ###   ########.fr       */
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
# define SO 0
# define NO 1
# define WE 2
# define EA 3
# define C 4
# define F 5


typedef struct s_texture
{
	char	**txtres;
	char	**floor;
	char	**ceiling;

}	t_txture;



typedef struct s_map
{
	char	**map;
	int		count[6];
}	t_map;

typedef struct s_data
{
	char	*av;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		map_len;
	int		endian;
	t_map	*map;
	t_txture	*txture;
	int 	fd;
	int		i;
	int		j;

}	t_data;


void	ft_control(t_data *data);
void	ft_err_msg(char *error_message);
void	ft_init(t_data *data, char *av);
void	ft_read_map(t_data *data);
void	map_lenght(t_data *data);
int	ft_is_blank(char *c);
void	ft_is_space(t_data *data);
int	ft_count_check(t_data *data);
void	ft_check_txtrue(t_data *data, char *line);





#endif
