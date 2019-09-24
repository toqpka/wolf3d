/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   riffle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:17:25 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 23:53:14 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			make_shot(t_window *w)
{
	if (w->riffle.ammo && !w->riffle.busy_anim)
	{
		Mix_PlayChannel(0, w->music->shoot, 0);
		w->riffle.start = SDL_GetTicks();
		w->riffle.active = TRUE;
		w->riffle.ammo--;
		w->riffle.shoot++;
		if (w->riffle.shoot == 2)
			w->riffle.sound_mix = 0;
	}
}

void			weapon_drag(t_window *w, t_ui_node *img_c)
{
	if (img_c->rect.x + img_c->rect.w / 2 >= w->width / 2 + 20)
		w->riffle.pos.x = 1;
	else if ((img_c->rect.x + img_c->rect.w / 2 <= w->width / 2 - 20))
		w->riffle.pos.x = 0;
	if (img_c->rect.x + img_c->rect.w / 2 <= w->width / 2 +
	20 && !w->riffle.pos.x)
	{
		img_c->rect.x++;
		(img_c->rect.x + img_c->rect.w / 2 <= w->width / 2) ?
		(img_c->rect.y++) : (img_c->rect.y--);
	}
	else if (img_c->rect.x + img_c->rect.w / 2 >= w->width / 2
	- 20 && w->riffle.pos.x)
	{
		img_c->rect.x--;
		(img_c->rect.x + img_c->rect.w / 2 >= w->width / 2) ?
		(img_c->rect.y++) : (img_c->rect.y--);
	}
	w->riffle.rect.x = img_c->rect.x;
	w->riffle.rect.y = img_c->rect.y;
	render_scale(w, img_c);
}

static int		form_key_by_fraps(int fraps)
{
	int key;

	key = 0;
	(fraps > 150 && fraps <= 300) ? key = 1 : 0;
	(fraps > 300 && fraps <= 450) ? key = 2 : 0;
	(fraps > 450 && fraps <= 600) ? key = 3 : 0;
	(fraps > 600 && fraps <= 750) ? key = 4 : 0;
	(fraps > 750 && fraps <= 900) ? key = 5 : 0;
	(fraps > 900 && fraps <= 1050) ? key = 6 : 0;
	(fraps > 1050 && fraps <= 1200) ? key = 7 : 0;
	(fraps > 1200 && fraps <= 1350) ? key = 8 : 0;
	return (key);
}

int				choose_fraps(t_window *w, int key)
{
	if (w->riffle.active && w->riffle.shoot <= 2)
	{
		weapon_shoot(w, key);
		if (key == 1)
		{
			w->riffle.active = FALSE;
			w->riffle.tr = 0;
		}
		return (1);
	}
	else if (w->riffle.shoot == 2)
	{
		w->riffle.busy_anim = TRUE;
		weapon_fraps(w, key);
		if (key == 8)
		{
			w->riffle.active = FALSE;
			w->riffle.busy_anim = FALSE;
			w->riffle.shoot = 0;
			w->riffle.tr = 0;
		}
		return (1);
	}
	return (0);
}

void			weapon_animation(t_window *w)
{
	int	fraps;
	int key;

	fraps = SDL_GetTicks() - w->riffle.start;
	key = form_key_by_fraps(fraps);
	if (!choose_fraps(w, key))
	{
		if (w->player.go)
		{
			if (w->riffle.tr == 0)
				re_init_riffle(w, 9 + 1);
			weapon_drag(w, w->riffle.fraps[0]);
			w->riffle.tr++;
		}
		else
			render_scale_r(w, w->riffle.fraps[0], w->riffle.rect);
	}
}
