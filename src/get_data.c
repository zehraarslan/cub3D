/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:58:46 by zarslan           #+#    #+#             */
/*   Updated: 2023/03/31 23:47:03 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cube.h"

void	alloc_map(t_data *data, char **lines)
{
	int		x;
	int		y;
	int		i;

	data->x_size = 0;
	data->y_size = 0;
	y = 0;
	while (lines[y])
	{
		x = 0;
		while (lines[y][x])
		{
			x++;
			if (data->x_size < x)
			{
				data->x_size = x;
			}
		}
		data->y_size++;
		y++;
	}
	data->map = (int **)malloc((y) * sizeof(int *));
	i = 0;
	while (i < y)
		data->map[i++] = (int *)malloc(data->x_size * sizeof(int));
}

void	get_map(t_data *data, char **lines)
{
	int		x;
	int		y;
	int		lock;

	alloc_map(data, lines);
	y = 0;
	while (y < data->y_size)
	{
		x = 0;
		lock = 0;
		while (x < data->x_size)
		{
			if (!lock && (lines[y][x] == '\n' || lines[y][x] == '\0'))
				lock = 1;
			if (lock)
				data->map[y][x] = ' ';
			else
				data->map[y][x] = lines[y][x];
			x++;
		}
		y++;
	}
}

int	get_data(t_data *data, t_map *map)
{
	get_file_args(map, data);
	get_map(data, map->data);
	return (0);
}
