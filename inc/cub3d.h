/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:12:22 by musozer           #+#    #+#             */
/*   Updated: 2024/12/23 16:29:00 by soksak           ###   ########.fr       */
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
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "GNL/get_next_line.h"
# define SWIDTH 800
# define SHEIGHT 600
# define SO 0
# define NO 1
# define WE 2
# define EA 3
# define C 4
# define F 5
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363


typedef struct s_data t_data;

typedef struct s_texture
{
	char	**txtres;
	char	**floor;
	char	**ceiling;
	int		c[3];
	int		f[3];
	void	*img;
	int		bpp;
	int		llength;
	int		endian;
	char	*addr;
}	t_txture;

typedef struct s_wall
{
	void	*img[4];
	int		bpp[4];
	int		llength[4];
	int		endian[4];
	char	*addr[4];
	int		width[4];
	int		height[4];
	int		tex_x;
	int		tex_y;
	double	wall_x;
	int		direction;
}	t_wall;

typedef struct s_plyr
{
	double	x;
	char	look_pos;
	double	y;
	int		map_x;
	int		map_y;
	double	dir_x;
	double	dir_y;
	double	move_speed;
	double	rot_speed;
}	t_plyr;

typedef struct s_ray
{
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_y;
	double	raydir_x;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int 	line_height;
	int		draw_start;
	int		draw_end;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	time;
	double	oldtime;
} t_ray;


typedef struct s_map
{
	char	**map;
	int        width;
	int        height;
	char	**cpymap;
	char	**map3d;
	int		count[6];
}	t_map;

typedef struct s_game
{
	t_data	*data;
	void	*mlx;
	void	*win;

}	t_game;

typedef struct s_data
{
	char	*av;
	void	*img;
	char	*addr;
	t_game	*game;
	int		map_len;
	int		flag;
	int		flag1;
	t_map	*map;
	t_txture	*txture;
	t_plyr	*plyr;
	t_wall	*wall;
	int 	fd;
	int		i;
	int		j;
	int		ply_x;
	int		ply_y;
	t_ray	*rc;
}	t_data;




void	ft_control(t_data *data);
void	ft_err_msg(char *error_message);
void	ft_read_map(t_data *data);
void	map_lenght(t_data *data);
int		ft_is_blank(char *c);
void	ft_is_space(t_data *data);
int		ft_count_check(t_data *data);
void	ft_check_txtrue(t_data *data, char *line);
void	ft_textrue_control(t_data *data, size_t size);
char	*ft_space_trimmer(char *line);
void	ft_rgb_control(t_data *data, char **rgb, int fc);
void	ft_comma_control(char *str);
void	ft_double_free(char **str);
void	ft_map_check(t_data *data);
void	ft_cpymap_fill(t_data * data);
void	ft_flood_fill(t_map *map, int x, int y);
void	ft_flood_fill_chck(t_data *data);

// Game
void	open_window(t_data *data);
int		convert(int r, int g, int b);
void	my_mlx_pixel_put(t_txture *img, int x, int y, int color);
void	draw_celling_and_flor(t_data *data);
void	raycasting(t_data *data);
void	ft_swap_double(double *a, double *b);
void	clear_image_buffer(t_data *data, int color);
int		key_hook(int key, t_data *data);
void	draw_wall(t_data *data, int x);


#endif
