/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:59:44 by zarslan           #+#    #+#             */
/*   Updated: 2023/04/01 00:02:38 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include "../minilibx_macos/mlx.h"
# include <../libft/libft.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include"cub3d.h"
# define WIN_WIDTH 1200
# define WIN_HEIGHT 960

# define PI 3.14159f
# define ANLE_TO_RADIAN 0.0174532f

typedef struct s_map
{
	char	**data;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		x;
	int		y;
	float	ang;
	int		floor_color;
	int		ceiling_color;
}	t_map;

typedef struct s_image
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_found
{
	float	distance;
	float	rate;
}	t_found;

typedef struct s_player
{
	int		x;
	int		y;
	float	angle;
}	t_player;

typedef struct s_vector2f
{
	float	x;
	float	y;
}	t_vector2f;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
}	t_keys;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_image		screen;
	int			**map;
	int			y_size;
	int			x_size;
	int			floor_color;
	int			ceil_color;
	t_image		imgs[4];
	t_vector2f	pos;
	float		look;
	int			active_img;
	t_keys		keys;
}	t_data;

void	ft_swap(char **a, char *b);
char	*get_file(char *name);
void	free_split(char **str);
int		get_file_color(char *color_str);
void	get_file_args(t_map *map, t_data *data);
void	alloc_map(t_data *data, char **lines);
void	get_map(t_data *data, char **lines);
int		get_data(t_data *data, t_map *map);
void	image_put_pixel(t_image *img, int x, int y, int color);
int		image_get_pixel(t_image *img, int x, int y);
int		float_approximately(float a, float b);
int		color_dark(int color);
void	draw_wall(t_data *data, float distance, float rate, int index);
int		int_abs(int i);
float	float_abs(float i);
float	get_distance(t_vector2f a, t_vector2f b);
t_found	look_horizontal(t_data *data, float f_slope, int add);
t_found	look_vertical(t_data *data, float f_slope, int add);
void	look_slope(t_data *data, float slope, t_player *dir, int index);
void	raycast(t_data *data, float angle, int index);
void	fill_screen(t_data *data);
void	ft_render(t_data *data);
int		ft_collision_detect(t_data *data, t_vector2f pos);
void	ft_move(t_data *data, t_vector2f move);
int		ft_event_up(int key, t_data *data);
int		ft_event_down(int key, t_data *data);
int		get_characther_x(t_parser_data *data);
float	character_angle(t_parser_data *data);
void	get_set_map_value(t_map *map, t_parser_data *data);
void	start_data(int arc, char **arv, t_map *map, t_parser_data *data);
void	ft_start_game(t_data *data, t_map *map);
int		ft_update(t_data *data);
int		func_exit(void *tmp);
int		get_characther_y(t_parser_data *data);
#endif
