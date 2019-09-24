/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   riffle_fraps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:13:19 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 19:33:34 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	weapon_shoot(t_window *w, int key)
{
	SDL_Rect rect;

	re_init_riffle(w, key + 1);
	rect = w->riffle.rect;
	rect.x = w->riffle.rect.x;
	rect.y = w->riffle.rect.y + 200;
	if (key == 0)
	{
		render_scale_r(w, w->riffle.fraps[1], rect);
	}
	if (key == 1)
	{
		render_scale_r(w, w->riffle.fraps[2], rect);
	}
}

void	weapon_fraps(t_window *w, int key)
{
	re_init_riffle(w, key + 1);
	render_scale_r(w, w->riffle.fraps[key + 1], w->riffle.rect);
}
