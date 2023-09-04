/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:58:35 by zarslan           #+#    #+#             */
/*   Updated: 2023/03/31 23:47:05 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cube.h"

void	image_put_pixel(t_image *img, int x, int y, int color)
{
	if (x < 1 || x > img->width - 1 || y < 1 || y > img->height - 1)
		return ;
	*((int *)(img->addr + (y * img->line_len) \
	+ (x * 4))) = color;
}

int	image_get_pixel(t_image *img, int x, int y)
{
	if (x < 1 || x > img->width -4 || y < 1 || y > img->height -4)
		return (0);
	return (*((int *)(img->addr + (y * img->line_len) \
	+ (x * 4))));
}

int	float_approximately(float a, float b)
{
	return (a - b < 0.001f && a - b > -0.001f);
}

int	color_dark(int color)
{
	int	r;
	int	g;
	int	b;

	r = color & 0x000000FF;
	g = (color & 0x0000FF00) >> 8;
	b = (color & 0x00FF0000) >> 16;
	return (r | (g << 8) | (b << 16));
}

void	draw_wall(t_data *data, float distance, float rate, int index)
{
	int		draw;
	float	rate_i;
	int		start;
	int		end;

	draw = (5 / distance) * (WIN_HEIGHT * 0.3f);
	rate_i = (float)data->imgs[data->active_img].height / draw;
	start = (WIN_HEIGHT - draw) / 2;
	end = 0;
	if (start < 0)
	{
		draw += start;
		end = -start;
	}
	while (draw-- > end)
		image_put_pixel(&data->screen, index, draw + start,
			color_dark(image_get_pixel(&data->imgs[data->active_img],
					data->imgs[data->active_img].width * rate,
					draw * rate_i)));
}
