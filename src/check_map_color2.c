/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_color2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:14:48 by zarslan           #+#    #+#             */
/*   Updated: 2023/03/31 23:45:55 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rgb_clr_code_err_msg(void)
{
	write(2, "Error\nRGB Color Code is Wrong!", 30);
	exit(1);
}

void	rgb_storage(t_parser_data *data, char *idf, char *rgb)
{
	char	**s;
	int		i;

	i = -1;
	s = ft_split(rgb, ',');
	if (ft_strncmp(idf, "F", 1) == 0)
	{
		while (++i < 3)
			data->floor[i] = ft_atoi(s[i]);
	}
	else if (ft_strncmp(idf, "C", 1) == 0)
	{
		while (++i < 3)
			data->ceil[i] = ft_atoi(s[i]);
	}
	ft_arg_free(s);
}
