/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_same2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:07:05 by zarslan           #+#    #+#             */
/*   Updated: 2023/03/31 23:46:02 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	identifier_control_f(t_parser_data *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "F", 1) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}	
}

void	identifier_control_c(t_parser_data *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "C", 1) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}	
}

void	map_element_check(t_parser_data *data)
{
	char	**str;
	int		i;

	i = -1;
	while (data->map_ftrs[++i])
	{
		str = ft_split(data->map_ftrs[i], ' ');
		if (ft_arglen(str) != 2)
		{
			write(2, "Error\nToo Much Arguments!", 25);
			exit(1);
		}
		ft_arg_free(str);
	}
}
