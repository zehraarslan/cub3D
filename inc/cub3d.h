/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:43:15 by zarslan           #+#    #+#             */
/*   Updated: 2023/03/31 23:47:37 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1920
# define HEIGHT 1080

# define NORTH	"NO"
# define SOUTH	"SO"
# define WEST	"WE"
# define EAST	"EA"

# define FLOOR	'F'
# define CEIL	'C'

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_parser_data
{
	double	ground_x;
	double	ground_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	move_speed;
	double	rot_speed;

	char	**map_and_ftrs;
	char	*paths[4];
	char	*map_ftrs[6];
	char	**map;

	char	*no[3];
	char	*so[3];
	char	*we[3];
	char	*ea[3];

	int		floor[3];
	int		ceil[3];
	int		floor_rgb;
	int		ceil_rgb;

	int		wal_chk_idx;
	int		wal_chk_arg;
	int		ltr_arg;
	int		ltr_idx;

	int		n_cnt;
	int		s_cnt;
	int		e_cnt;
	int		w_cnt;
	int		pos_cnt;
}	t_parser_data;

void	check_map_features(t_parser_data *data);
void	map_is_same_check(t_parser_data *data);
void	map_element_check(t_parser_data *data);
void	map_path_check(t_parser_data *data);
void	map_rgb_check(t_parser_data *data, int i);
void	map_check(t_parser_data *data, int i);
void	map_wall_check(t_parser_data *data);
void	map_all_check(t_parser_data *data);
void	map_letter_count(t_parser_data *data);
void	right_vertical_check(t_parser_data *data);
void	identifier_control_f(t_parser_data *data);
void	identifier_control_c(t_parser_data *data);

int		map_format_check(char *av);
int		ft_arglen(char **arg);

void	ft_arg_free(char **str);
void	set_value(t_parser_data *data);
void	map_oprt(t_parser_data *data, char *arv);
void	rgb_storage(t_parser_data *data, char *idf, char *rgb);
void	rgb_clr_code_err_msg(void);
void	path_storage(t_parser_data *data,	char **str);
void	path_storage2(t_parser_data *data,	char **str);
char	*ft_strcpy(char *dst, const char *src);

#endif