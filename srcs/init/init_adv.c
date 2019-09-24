/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_adv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:26:03 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/18 00:09:40 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	re_init_riffle(t_window *w, int key)
{
	if (key == 10)
		key = 0;
	w->riffle.rect.w = w->riffle.fraps[key]->img->width * 2;
	w->riffle.rect.h = w->riffle.fraps[key]->img->height * 2;
	w->riffle.rect.y = w->height - w->riffle.rect.h + 40;
	if (key == 1 || key == 2)
	{
		w->riffle.rect.y = w->height
		- (w->riffle.fraps[0]->img->height * 2) - 20;
	}
}

void	fill_ui(t_window *w)
{
	w->ui.bar.rect.w = WIDTH;
	w->ui.bar.rect.h = PLAYER_GUI;
	w->ui.bar.rect.x = 0;
	w->ui.bar.rect.y = w->height;
	w->ui.face[0]->rect.w = HEIGHT - w->height;
	w->ui.face[0]->rect.h = HEIGHT - w->height;
	w->ui.face[0]->rect.x = w->width / 2 - 64;
	w->ui.face[0]->rect.y = w->height;
	w->ui.face[2]->rect = w->ui.face[0]->rect;
	w->ui.face[1]->rect = w->ui.face[0]->rect;
}
