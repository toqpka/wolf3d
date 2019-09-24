/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_adv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:24:05 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 19:33:48 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		calc_c_height(t_window *w, int tex_num)
{
	w->textures[tex_num]->col_height = (int)(w->height / w->ray.dist / 2);
	w->ray.draw_start = (-w->textures[tex_num]->col_height / 2 + w->height / 2);
	if (w->ray.draw_start < 0)
		w->ray.draw_start = 0;
	w->ray.draw_end = w->textures[tex_num]->col_height / 2 + w->height / 2;
	if (w->ray.draw_end >= w->height)
		w->ray.draw_end = w->height - 1;
}

int			get_world_side(t_window *w)
{
	int		tex_num;

	if ((w->ray.hit_side == 0) && w->ray.dir.x > 0)
		tex_num = w->ray.hit - 1;
	else if ((w->ray.hit_side == 0) && w->ray.dir.x <= 0)
		tex_num = w->ray.hit;
	else if ((w->ray.hit_side == 1) && w->ray.dir.y <= 0)
		tex_num = w->ray.hit + 1;
	else if ((w->ray.hit_side == 1) && w->ray.dir.y > 0)
		tex_num = w->ray.hit + 2;
	else
		tex_num = 0;
	return (tex_num);
}
