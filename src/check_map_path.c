/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:11:01 by zarslan           #+#    #+#             */
/*   Updated: 2023/03/31 17:03:58 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	path_storage2(t_parser_data *data,	char **str)
{
	if (!ft_strncmp(str[0], "NO", 2))
	{
		data->no[0] = ft_strdup(str[0]);
		data->no[1] = ft_strdup(str[1]);
		data->no[2] = 0;
	}
	else if (!ft_strncmp(str[0], "SO", 2))
	{
		data->so[0] = ft_strdup(str[0]);
		data->so[1] = ft_strdup(str[1]);
		data->so[2] = 0;
	}
}

void	path_storage(t_parser_data *data,	char **str)
{
	path_storage2(data, str);
	if (!ft_strncmp(str[0], "WE", 2))
	{
		data->we[0] = ft_strdup(str[0]);
		data->we[1] = ft_strdup(str[1]);
		data->we[2] = 0;
	}
	else if (!ft_strncmp(str[0], "EA", 2))
	{
		data->ea[0] = ft_strdup(str[0]);
		data->ea[1] = ft_strdup(str[1]);
		data->ea[2] = 0;
	}
}

void	map_path_check(t_parser_data *data)
{
	char	**str;
	int		i;

	i = -1;
	while (data->map_ftrs[++i])
	{
		if (!ft_strncmp(data->map_ftrs[i], "NO", 2) || \
			!ft_strncmp(data->map_ftrs[i], "SO", 2) || \
			!ft_strncmp(data->map_ftrs[i], "WE", 2) || \
			!ft_strncmp(data->map_ftrs[i], "EA", 2))
		{
			str = ft_split(data->map_ftrs[i], ' ');
			if (open(str[1], O_RDWR, 0777) == -1)
			{
				write(2, "Error\nPath is Wrong!", 20);
				ft_arg_free(str);
				exit(1);
			}
			path_storage(data, str);
			ft_arg_free(str);
		}
	}
	map_rgb_check(data, i);
}
