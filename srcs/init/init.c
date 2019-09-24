/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:32:41 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/18 00:12:26 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_player(t_window *w)
{
	w->player.dir.x = -1;
	w->player.dir.y = 0;
	w->player.plane.x = 0;
	w->player.plane.y = 0.66;
	w->player.rotation = 0.05;
	w->player.speed = 0.05;
}

void	init_controls(t_window *w)
{
	w->controls.w = FALSE;
	w->controls.a = FALSE;
	w->controls.s = FALSE;
	w->controls.d = FALSE;
	w->controls.q = FALSE;
	w->controls.e = FALSE;
	w->controls.p = FALSE;
}

void	init_riffle(t_window *w)
{
	w->riffle.rect.w = w->riffle.fraps[0]->img->width * 2;
	w->riffle.rect.h = w->riffle.fraps[0]->img->height * 2;
	w->riffle.rect.x = w->width / 2 - w->riffle.rect.w / 2;
	w->riffle.rect.y = w->height - w->riffle.rect.h + 40;
}

void	init_sky(t_window *w)
{
	w->sky.rect.x = 0;
	w->sky.rect.y = 0;
	w->sky.rect.w = w->width;
	w->sky.rect.h = w->height / 2;
}

int		global_init(t_window *w)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (1);
	w->height = HEIGHT - PLAYER_GUI;
	w->width = WIDTH;
	w->map.width = 0;
	w->map.height = 0;
	w->map.x = 0;
	w->map.y = 0;
	init_player(w);
	init_controls(w);
	init_sky(w);
	w->riffle.shoot = 0;
	w->riffle.tr = 0;
	w->riffle.ammo = START_AMMO;
	w->riffle.busy_anim = FALSE;
	w->riffle.active = FALSE;
	w->riffle.pos.x = 0;
	w->riffle.pos.y = 0;
	w->power = TRUE;
	w->ui.position = 0;
	w->ui.clicked = FALSE;
	w->free_cell = 0;
	return (0);
}
