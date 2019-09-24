/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:29:19 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/20 11:28:27 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

Uint32		render_floor(t_window *w, Uint32 *pixels,
			int tex_num, double weight)
{
	Uint32		color;
	double		cur_floor_x;
	double		cur_floor_y;
	int			floor_tex_x;
	int			floor_tex_y;

	cur_floor_x = weight * w->ray.floor_x_wall
	+ (1.0 - weight) * w->ray.pos.x;
	cur_floor_y = weight * w->ray.floor_y_wall
	+ (1.0 - weight) * w->ray.pos.y;
	floor_tex_x = (int)(cur_floor_x * w->textures[tex_num]->img_c->img->width)
	% w->textures[tex_num]->img_c->img->width;
	floor_tex_y = (int)(cur_floor_y * w->textures[tex_num]->img_c->img->height)
	% w->textures[tex_num]->img_c->img->height;
	color = (pixels[w->textures[tex_num]->img_c->img->width
	* floor_tex_y + floor_tex_x] >> 1) & 8355711;
	return (color);
}

void		draw_floor(t_window *w, int tex_num, int x)
{
	Uint32		*pixels;
	int			y;
	double		weight;

	pixels = (Uint32 *)(w->textures[tex_num]->img_c->img->pixels);
	if (w->ray.draw_end < 0)
		w->ray.draw_end = w->height;
	y = w->ray.draw_end + 1;
	while (y < w->height)
	{
		weight = (w->height / (2.0 * y - w->height) / (w->ray.dist * 2.0));
		w->ptr[w->width * y + x] = render_floor(w, pixels, tex_num, weight);
		y++;
	}
}

Uint32		render_texture(t_window *w, int tex_num, unsigned int tex_width,
			unsigned int tex_height)
{
	Uint32			*pixels;
	Uint32			color;
	Uint32			d;

	pixels = (Uint32 *)(w->textures[tex_num]->img_c->img->pixels);
	w->textures[tex_num]->tex_x = (Uint32)(w->ray.wallx * tex_width);
	d = w->ray.draw_start * 256 - w->height * 128 +
	w->textures[tex_num]->col_height * 128;
	w->textures[tex_num]->tex_y = ((d * tex_height)
	/ w->textures[tex_num]->col_height) / 256;
	color = pixels[tex_width * w->textures[tex_num]->tex_y
	+ w->textures[tex_num]->tex_x];
	return (color);
}

void		render_walls(t_window *w)
{
	int				x;
	int				tex_num;

	x = 0;
	w->ray.pos.x = w->player.pos.x;
	w->ray.pos.y = w->player.pos.y;
	while (x < w->width)
	{
		raycasting(w, x);
		tex_num = get_world_side(w);
		calc_c_height(w, tex_num);
		while (w->ray.draw_start < w->ray.draw_end)
		{
			w->ptr[w->width * w->ray.draw_start + x] = render_texture(w,
			tex_num, w->textures[tex_num]->img_c->img->width,
			w->textures[tex_num]->img_c->img->height);
			w->ray.draw_start++;
		}
		cast_floor(w);
		draw_floor(w, 7, x);
		x++;
	}
}

void		draw_cycle(t_window *w)
{
	render_scale(w, &(w->sky));
	render_scale(w, &(w->ui.bar));
	render_walls(w);
	weapon_animation(w);
	ui_bar(w);
	face_animation(w);
	if (w->pause)
		show_menu(w);
	SDL_UpdateWindowSurface(w->window);
}
