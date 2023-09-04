/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:17:27 by zarslan           #+#    #+#             */
/*   Updated: 2023/03/31 23:47:14 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	map_check(t_parser_data *data, int i)
{
	int	a;
	int	y;

	y = 0;
	a = i;
	if (data->map_and_ftrs[a] != 0)
	{
		while (data->map_and_ftrs[a++])
			y++;
		data->map = (char **)ft_calloc(y + 1, sizeof(char *));
		y = 0;
		while (data->map_and_ftrs[i])
		{
			data->map[y] = ft_calloc(ft_strlen(data->map_and_ftrs[i]) + 1, \
							sizeof(char));
			ft_strcpy(data->map[y++], data->map_and_ftrs[i++]);
		}
		data->map[y] = 0;
		ft_arg_free(data->map_and_ftrs);
	}
	else
	{
		write(2, "Error\nMap Not Found!", 20);
		exit(1);
	}
}

static void	map_pos_check(t_parser_data *data)
{
	data->pos_cnt = 0;
	data->ltr_arg = 0;
	while (data->map[data->ltr_arg])
	{
		data->ltr_idx = 0;
		while (data->map[data->ltr_arg][data->ltr_idx])
		{
			if (data->map[data->ltr_arg] \
				[data->ltr_idx] == 'N')
					data->pos_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'S')
					data->pos_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'E')
					data->pos_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'W')
					data->pos_cnt++;
			data->ltr_idx++;
		}
		data->ltr_arg++;
	}
}

static void	map_letter_check(t_parser_data *data)
{
	bool	pos_ctrl;

	pos_ctrl = false;
	if (data->n_cnt == 0 && data->s_cnt == 0 && \
		data->e_cnt == 0 && data->w_cnt == 0)
	{
		write(1, "Error\nStarting Position Not Found!", 34);
		exit(1);
	}
	if (data->n_cnt > 1 || data->s_cnt > 1 || \
		data->e_cnt > 1 || data->w_cnt > 1)
	{
		write(1, "Error\nMore Than One Starting Position!", 38);
		exit(1);
	}
	map_pos_check(data);
	if (data->pos_cnt > 1)
	{
		write(1, "Error\nMore Than One Starting Position!", 38);
		exit(1);
	}
}

void	map_letter_count(t_parser_data *data)
{
	while (data->map[data->ltr_arg])
	{
		data->ltr_idx = 0;
		while (data->map[data->ltr_arg][data->ltr_idx])
		{
			if (data->map[data->ltr_arg] \
				[data->ltr_idx] == 'N')
				data->n_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'S')
				data->s_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'E')
				data->e_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'W')
				data->w_cnt++;
			data->ltr_idx++;
		}
		data->ltr_arg++;
	}
	map_letter_check(data);
}

void	map_all_check(t_parser_data *data)
{
	int	arg;
	int	idx;

	arg = 0;
	idx = 0;
	while (data->map[arg])
	{
		idx = 0;
		while (data->map[arg][idx])
		{
			if (data->map[arg][idx] == '0' || data->map[arg][idx] == 'N' || \
				data->map[arg][idx] == '1' || data->map[arg][idx] == 'S' || \
				data->map[arg][idx] == 'E' || data->map[arg][idx] == 'W')
					idx++;
			else
			{
				write(2, "Error\nUndefined Character!\n", 28);
				printf("Arg: %d\nIdx: %d\n", arg, idx);
				exit(1);
			}
		}
		arg++;
	}
}
