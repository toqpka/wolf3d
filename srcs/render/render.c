/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:58:43 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 19:33:57 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ray_cal_dist(t_window *w)
{
	while (w->ray.hit == 0)
	{
		if (w->ray.side.x < w->ray.side.y)
		{
			w->ray.side.x += w->ray.delta.x;
			w->ray.map.x += w->ray.step.x;
			w->ray.hit_side = 0;
		}
		else
		{
			w->ray.side.y += w->ray.delta.y;
			w->ray.map.y += w->ray.step.y;
			w->ray.hit_side = 1;
		}
		if (w->map.block[w->ray.map.x][w->ray.map.y] > 0)
		{
			w->ray.hit = w->map.block[w->ray.map.x][w->ray.map.y];
			if (w->ray.hit_side == 0)
				w->ray.dist = (w->ray.map.x - w->ray.pos.x + (1 - w->ray.step.x)
						/ 2) / w->ray.dir.x;
			else
				w->ray.dist = (w->ray.map.y - w->ray.pos.y + (1 - w->ray.step.y)
						/ 2) / w->ray.dir.y;
		}
	}
}

void		ray_cal_step_side(t_window *w)
{
	if (w->ray.dir.x < 0)
	{
		w->ray.step.x = -1;
		w->ray.side.x = (w->ray.pos.x - (int)w->ray.pos.x) * w->ray.delta.x;
	}
	else
	{
		w->ray.step.x = 1;
		w->ray.side.x = ((int)w->ray.pos.x + 1 - w->ray.pos.x) * w->ray.delta.x;
	}
	if (w->ray.dir.y < 0)
	{
		w->ray.step.y = -1;
		w->ray.side.y = (w->ray.pos.y - (int)w->ray.pos.y) * w->ray.delta.y;
	}
	else
	{
		w->ray.step.y = 1;
		w->ray.side.y = ((int)w->ray.pos.y + 1 - w->ray.pos.y) * w->ray.delta.y;
	}
}

void		cast_floor(t_window *w)
{
	if (w->ray.hit_side == 0 && w->ray.dir.x > 0)
	{
		w->ray.floor_x_wall = w->ray.map.x;
		w->ray.floor_y_wall = w->ray.map.y + w->ray.wallx;
	}
	else if (w->ray.hit_side == 0 && w->ray.dir.x < 0)
	{
		w->ray.floor_x_wall = w->ray.map.x + 1.0;
		w->ray.floor_y_wall = w->ray.map.y + w->ray.wallx;
	}
	else if (w->ray.hit_side == 1 && w->ray.dir.y > 0)
	{
		w->ray.floor_x_wall = w->ray.map.x + w->ray.wallx;
		w->ray.floor_y_wall = w->ray.map.y;
	}
	else
	{
		w->ray.floor_x_wall = w->ray.map.x + w->ray.wallx;
		w->ray.floor_y_wall = w->ray.map.y + 1.0;
	}
}

void		ray_init(t_window *w, int x)
{
	w->ray.map.x = (int)w->ray.pos.x;
	w->ray.map.y = (int)w->ray.pos.y;
	w->ray.camera = 2 * x / (double)w->width - 1;
	w->ray.dir.x = w->player.dir.x + w->player.plane.x * w->ray.camera;
	w->ray.dir.y = w->player.dir.y + w->player.plane.y * w->ray.camera;
	w->ray.delta.x = sqrt(1 + (w->ray.dir.y * w->ray.dir.y)
	/ (w->ray.dir.x * w->ray.dir.x));
	w->ray.delta.y = sqrt(1 + (w->ray.dir.x * w->ray.dir.x)
	/ (w->ray.dir.y * w->ray.dir.y));
	w->ray.hit = 0;
	w->ray.dist = -1;
	w->ray.hit_side = -1;
}

void		raycasting(t_window *w, int x)
{
	ray_init(w, x);
	ray_cal_step_side(w);
	ray_cal_dist(w);
	w->ray.wallx = (w->ray.hit_side ? w->ray.pos.x + w->ray.dist
	* w->ray.dir.x : w->ray.pos.y + w->ray.dist * w->ray.dir.y);
	w->ray.wallx -= floor(w->ray.wallx);
}
