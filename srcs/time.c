/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:33:10 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/20 13:05:11 by jhoppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	count_delta_time(t_window *w)
{
	w->ftime.old = w->ftime.new;
	w->ftime.new = SDL_GetPerformanceCounter();
	w->ftime.delta = (double)((w->ftime.new - w->ftime.old)
								/ (double)SDL_GetPerformanceFrequency());
}
