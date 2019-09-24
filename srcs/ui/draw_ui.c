/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:08:31 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 19:33:38 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_menu_background(t_window *w)
{
	int x;
	int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			set_pixel(w->screen, x, y, 0xffffff);
			y++;
		}
		x++;
	}
}

void	draw_skill(t_window *w, int index)
{
	get_menu_offset_by_index(index, &(w->ui.letter[0]->rect.x),
	&(w->ui.letter[0]->rect.y));
	w->ui.letter[0]->rect.x -= 70;
	render_image(w, w->ui.letter[0]);
}

void	draw_mask_backround(t_window *w)
{
	int x;
	int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			w->ptr[w->width * y + x] =
			shade_color(w->ptr[w->width * y + x], 40);
			y++;
		}
		x++;
	}
}

void	face_animation(t_window *w)
{
	int	fraps;

	fraps = SDL_GetTicks() - w->riffle.start;
	if (fraps % 5000 > 1500 & fraps % 5000 <= 3000)
		render_scale(w, w->ui.face[1]);
	else if (fraps % 5000 > 3000 & fraps % 5000 <= 4500)
		render_scale(w, w->ui.face[2]);
	else
		render_scale(w, w->ui.face[0]);
}
