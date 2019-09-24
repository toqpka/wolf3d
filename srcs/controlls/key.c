/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:40:02 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/20 12:38:30 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_u8	key_action(SDL_Event *ev, int32_t key_code, Uint32 press)
{
	if ((ev->type == press && ev->key.keysym.sym == key_code))
		return (TRUE);
	return (FALSE);
}

t_u8	switch_key(t_window *w, char key, t_u8 *key_tr)
{
	if (key_action(&(w->e), key, SDL_KEYDOWN))
		*key_tr = !*key_tr;
	return (*key_tr);
}

t_u8	handle_key(t_window *w, char key, t_u8 *key_tr)
{
	((SDL_QUIT == w->e.type)) ? w->power = 0 : 0;
	if (key_action(&(w->e), key, SDL_KEYDOWN))
		*key_tr = TRUE;
	else if (key_action(&w->e, key, SDL_KEYUP))
		*key_tr = FALSE;
	(key_action(&(w->e), SDLK_UP, SDL_KEYDOWN) ? (w->controls.w) = TRUE : 0);
	(key_action(&(w->e), SDLK_UP, SDL_KEYUP) ? (w->controls.w) = FALSE : 0);
	(key_action(&(w->e), SDLK_DOWN, SDL_KEYDOWN) ? (w->controls.s) = TRUE : 0);
	(key_action(&(w->e), SDLK_DOWN, SDL_KEYUP) ? (w->controls.s) = FALSE : 0);
	(key_action(&(w->e), SDLK_LEFT, SDL_KEYDOWN) ? (w->controls.a) = TRUE : 0);
	(key_action(&(w->e), SDLK_LEFT, SDL_KEYUP) ? (w->controls.a) = FALSE : 0);
	(key_action(&(w->e), SDLK_RIGHT, SDL_KEYDOWN) ? (w->controls.d) = TRUE : 0);
	(key_action(&(w->e), SDLK_RIGHT, SDL_KEYUP) ? (w->controls.d) = FALSE : 0);
	return (*key_tr);
}
