/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_same.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:06:29 by zarslan           #+#    #+#             */
/*   Updated: 2023/03/31 23:45:57 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	identifier_control_ea(t_parser_data *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "EA", 2) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}
}

static void	identifier_control_we(t_parser_data *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "WE", 2) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}
}

static void	identifier_control_so(t_parser_data *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "SO", 2) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}	
}

static void	identifier_control_no(t_parser_data *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "NO", 2) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}	
}

void	map_is_same_check(t_parser_data *data)
{
	identifier_control_no(data);
	identifier_control_so(data);
	identifier_control_we(data);
	identifier_control_ea(data);
	identifier_control_f(data);
	identifier_control_c(data);
}
