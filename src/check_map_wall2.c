/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:24:29 by zarslan           #+#    #+#             */
/*   Updated: 2023/03/31 23:47:19 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	is_wall_open(int i, char *big_line)
{
	while (big_line[i])
	{
		if (big_line[i] == '0')
		{
			write(2, "Error\nRight Vertical Wall is Wrong!", 35);
			exit(1);
		}
		i++;
	}
}

static void	rght_wll_err_msg(void)
{
	write(2, "Error\nRight Vertical Wall is Wrong!", 35);
	exit(1);
}

void	right_vertical_check(t_parser_data *data)
{
	int	size_sml;

	data->wal_chk_arg = -1;
	while (data->map[++data->wal_chk_arg] && data->map[data->wal_chk_arg + 1])
	{
		if (ft_strlen(data->map[data->wal_chk_arg]) > \
			ft_strlen(data->map[data->wal_chk_arg + 1]))
		{
			size_sml = ft_strlen(data->map[data->wal_chk_arg + 1]);
			is_wall_open(size_sml, data->map[data->wal_chk_arg]);
		}
		else if (ft_strlen(data->map[data->wal_chk_arg]) < \
				ft_strlen(data->map[data->wal_chk_arg + 1]))
		{
			size_sml = ft_strlen(data->map[data->wal_chk_arg]);
			is_wall_open(size_sml, data->map[data->wal_chk_arg + 1]);
		}
		else
		{
			size_sml = ft_strlen(data->map[data->wal_chk_arg]);
			if (data->map[data->wal_chk_arg][size_sml - 1] != '1' || \
				data->map[data->wal_chk_arg + 1][size_sml - 1] != '1')
				rght_wll_err_msg();
		}
	}
}
