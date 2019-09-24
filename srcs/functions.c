/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:25:22 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 19:33:16 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_setinrange(int *num, int min, int max)
{
	if (*num > max)
		*num = max;
	else if (*num < min)
		*num = min;
}

void		scale_rect_digits(t_window *w, float scale_k)
{
	int i;

	i = 0;
	while (i < 11)
	{
		w->ui.digit[i]->rect.w = w->ui.digit[i]->img->width * scale_k;
		w->ui.digit[i]->rect.h = w->ui.digit[i]->img->height * scale_k;
		i++;
	}
}

SDL_Rect	set_rect(int w, int h, int x, int y)
{
	SDL_Rect	ret;

	ret.w = w;
	ret.h = h;
	ret.x = x;
	ret.y = y;
	return (ret);
}
