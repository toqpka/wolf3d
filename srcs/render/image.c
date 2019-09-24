/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:20:59 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 19:33:54 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		render_image(t_window *w, t_ui_node *img_c)
{
	Uint32 x;
	Uint32 y;
	Uint32 offset_x;
	Uint32 offset_y;

	offset_x = img_c->rect.x;
	offset_y = img_c->rect.y;
	x = 0;
	while (x < img_c->img->width)
	{
		y = 0;
		while (y < img_c->img->height)
		{
			if (((img_c->img->pixels[img_c->img->width * y + x]
			& 0xff000000) >> 24) >= 240
			&& (y + offset_y <= HEIGHT) && (x + offset_x <= WIDTH))
				w->ptr[WIDTH * (y + offset_y) + (x + offset_x)] =
				(Uint32)img_c->img->pixels[img_c->img->width * y + x];
			y++;
		}
		x++;
	}
}

void		render_scale(t_window *w, t_ui_node *img_c)
{
	if (((int)img_c->img->width != img_c->rect.w)
	|| ((int)img_c->img->height != img_c->rect.h))
		img_c->img = scale_img(img_c->img, img_c->rect);
	render_image(w, img_c);
}

void		render_scale_r(t_window *w, t_ui_node *img_c, SDL_Rect rect)
{
	if (((int)img_c->img->width != img_c->rect.w)
	|| ((int)img_c->img->height != img_c->rect.h))
	{
		img_c->img = scale_img(img_c->img, rect);
		img_c->rect = rect;
	}
	render_image(w, img_c);
}

t_ui_node	*scale(t_ui_node *img_c, int percent)
{
	if (((int)img_c->img->width != img_c->rect.w)
	|| ((int)img_c->img->height != img_c->rect.h))
	{
		img_c->rect.w *= ((float)(percent / 100));
		img_c->rect.h *= ((float)(percent / 100));
	}
	return (img_c);
}

t_image		*scale_img(t_image *img, SDL_Rect r)
{
	t_image	*new;
	float	x_ratio;
	float	y_ratio;
	int		i;
	int		j;

	x_ratio = ((float)(img->width - 1)) / r.w;
	y_ratio = ((float)(img->height - 1)) / r.h;
	new = (t_image *)malloc(sizeof(t_image));
	new->pixels = (Uint32 *)malloc(sizeof(Uint32) * r.w * r.h);
	i = -1;
	while (++i < r.h)
	{
		j = -1;
		while (++j < r.w)
		{
			new->pixels[i * r.w + j] = set_color(
				inter_color(img->pixels, x_ratio * j, y_ratio * i, img->width));
		}
	}
	new->width = r.w;
	new->height = r.h;
	free(img->pixels);
	free(img);
	return (new);
}
