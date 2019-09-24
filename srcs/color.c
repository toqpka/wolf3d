/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:24:05 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 20:38:30 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_pixel(SDL_Surface *surf, const int x,
			const int y, const int color)
{
	Uint32		*pixels;

	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
	{
		pixels = (Uint32 *)surf->pixels;
		pixels[y * surf->w + x] = color;
	}
}

Uint32		set_color(t_rgba rgb)
{
	return ((Uint32)((((int)rgb.alpha << 24) & 0xff000000) |
			((((int)rgb.red) << 16) & 0xff0000) |
			((((int)rgb.green) << 8) & 0xff00) |
			((int)rgb.blue)));
}

Uint32		form_color(int red, int green, int blue, int alpha)
{
	return ((Uint32)(((alpha << 24) & 0xff000000) |
			((red << 16) & 0xff0000) |
			((green << 8) & 0xff00) |
			(blue)));
}

t_rgba		inter_color(Uint32 *pixels, float x_diff, float y_diff, int w)
{
	int		index;
	t_rgba	rgba;

	index = floor(y_diff) * w + floor(x_diff);
	x_diff -= floor(x_diff);
	y_diff -= floor(y_diff);
	rgba.blue = (pixels[index] & 0xff) * (1 - x_diff) * (1 - y_diff)
			+ (pixels[index + 1] & 0xff) * (x_diff) * (1 - y_diff)
			+ (pixels[index + w] & 0xff) * (y_diff) * (1 - x_diff)
			+ (pixels[index + w + 1] & 0xff) * (x_diff * y_diff);
	rgba.green = ((pixels[index] >> 8) & 0xff) * (1 - x_diff) * (1 - y_diff)
			+ ((pixels[index + 1] >> 8) & 0xff) * (x_diff) * (1 - y_diff)
			+ ((pixels[index + w] >> 8) & 0xff) * (y_diff) * (1 - x_diff)
			+ ((pixels[index + w + 1] >> 8) & 0xff) * (x_diff * y_diff);
	rgba.red = ((pixels[index] >> 16) & 0xff) * (1 - x_diff) * (1 - y_diff)
			+ ((pixels[index + 1] >> 16) & 0xff) * (x_diff) * (1 - y_diff)
			+ ((pixels[index + w] >> 16) & 0xff) * (y_diff) * (1 - x_diff)
			+ ((pixels[index + w + 1] >> 16) & 0xff) * (x_diff * y_diff);
	rgba.alpha = ((pixels[index] >> 24) & 0xff) * (1 - x_diff) * (1 - y_diff)
			+ ((pixels[index + 1] >> 24) & 0xff) * (x_diff) * (1 - y_diff)
			+ ((pixels[index + w] >> 24) & 0xff) * (y_diff) * (1 - x_diff)
			+ ((pixels[index + w + 1] >> 24) & 0xff) * (x_diff * y_diff);
	return (rgba);
}
