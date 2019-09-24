/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:05:05 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/20 11:49:15 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	update_go(t_window *w)
{
	w->player.go = FALSE;
	(w->controls.w) ? w->player.go = TRUE : 0;
	(w->controls.a) ? w->player.go = TRUE : 0;
	(w->controls.s) ? w->player.go = TRUE : 0;
	(w->controls.d) ? w->player.go = TRUE : 0;
}

void	handle_pause_menu(t_window *w)
{
	ft_setinrange(&(w->ui.position), 0, 3);
	ft_setinrange(&(w->music->m_volume), 0, 100);
	ft_setinrange(&(w->music->s_volume), 0, 100);
	(key_action(&w->e, SDLK_DOWN, SDL_KEYDOWN)) ? w->ui.position++ : 0;
	(key_action(&w->e, SDLK_UP, SDL_KEYDOWN)) ? w->ui.position-- : 0;
	if (w->ui.position == 1)
	{
		(key_action(&w->e, SDLK_LEFT, SDL_KEYDOWN))
			? w->music->s_volume -= 10 : 0;
		(key_action(&w->e, SDLK_RIGHT, SDL_KEYDOWN))
			? w->music->s_volume += 10 : 0;
	}
	if (w->ui.position == 2)
	{
		(key_action(&w->e, SDLK_LEFT, SDL_KEYDOWN))
		? w->music->m_volume -= 10 : 0;
		(key_action(&w->e, SDLK_RIGHT, SDL_KEYDOWN))
		? w->music->m_volume += 10 : 0;
	}
	handle_key(w, SDLK_RETURN, &(w->ui.clicked));
}

void	handle_keys(t_window *w)
{
	if (key_action(&w->e, SDLK_ESCAPE, SDL_KEYDOWN))
	{
		if (w->pause)
			w->pause = FALSE;
		else
		{
			w->ui.position = 0;
			w->pause = TRUE;
		}
	}
	(key_action(&w->e, SDLK_z, SDL_KEYDOWN)) ? w->power = FALSE : 0;
	if (w->pause)
		handle_pause_menu(w);
	handle_key(w, SDLK_w, &(w->controls.w));
	handle_key(w, SDLK_a, &(w->controls.a));
	handle_key(w, SDLK_s, &(w->controls.s));
	handle_key(w, SDLK_d, &(w->controls.d));
	handle_key(w, SDLK_q, &(w->controls.q));
	handle_key(w, SDLK_e, &(w->controls.e));
	switch_key(w, SDLK_p, &(w->controls.p));
	update_go(w);
}

void	move_controls(t_window *w)
{
	while (SDL_PollEvent(&(w->e)))
	{
		if (w->e.type == SDL_MOUSEMOTION && !w->pause)
		{
			SDL_GetRelativeMouseState(&w->mouse.curr.x, NULL);
			rotate_move(w, -w->mouse.curr.x * 0.01);
		}
		handle_keys(w);
		if (w->e.button.clicks == SDL_BUTTON_LEFT && !w->pause
		&& w->e.type == SDL_MOUSEBUTTONDOWN && !w->riffle.active)
			make_shot(w);
	}
	if (!w->pause)
	{
		(w->controls.w) ? move_forward(w, w->player.speed) : 0;
		(w->controls.a) ? move_left(w, w->player.speed) : 0;
		(w->controls.s) ? move_backward(w, w->player.speed) : 0;
		(w->controls.d) ? move_right(w, w->player.speed) : 0;
		(w->controls.q) ? rotate_move(w, w->player.rotation) : 0;
		(w->controls.e) ? rotate_move(w, -w->player.rotation) : 0;
	}
}
