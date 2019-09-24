/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:59:17 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/18 00:02:21 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_forward(t_window *w, double dist)
{
	if (w->map.block[(int)(w->player.pos.x + w->player.dir.x *
	(dist * 4))][(int)(w->player.pos.y)] == FALSE)
		w->player.pos.x += w->player.dir.x * dist;
	if (w->map.block[(int)(w->player.pos.x)][(int)(w->player.pos.y +
	w->player.dir.y * (dist * 4))] == FALSE)
		w->player.pos.y += w->player.dir.y * dist;
}

void	move_backward(t_window *w, double dist)
{
	if (w->map.block[(int)(w->player.pos.x - w->player.dir.x *
	(dist * 4))][(int)(w->player.pos.y)] == FALSE)
		w->player.pos.x -= w->player.dir.x * dist;
	if (w->map.block[(int)(w->player.pos.x)][(int)(w->player.pos.y -
	w->player.dir.y * (dist * 4))] == FALSE)
		w->player.pos.y -= w->player.dir.y * dist;
}

void	move_left(t_window *w, double dist)
{
	if (w->map.block[(int)(w->player.pos.x - w->player.dir.y *
	(dist * 4))][(int)(w->player.pos.y)] == FALSE)
		w->player.pos.x -= w->player.dir.y * dist;
	if (w->map.block[(int)(w->player.pos.x)][(int)(w->player.pos.y +
	w->player.dir.x * (dist * 4))] == FALSE)
		w->player.pos.y += w->player.dir.x * dist;
}

void	move_right(t_window *w, double dist)
{
	if (w->map.block[(int)(w->player.pos.x + w->player.dir.y *
	(dist * 4))][(int)(w->player.pos.y)] == FALSE)
		w->player.pos.x += w->player.dir.y * dist;
	if (w->map.block[(int)(w->player.pos.x)][(int)(w->player.pos.y -
	w->player.dir.x * (dist * 4))] == FALSE)
		w->player.pos.y -= w->player.dir.x * dist;
}

void	rotate_move(t_window *w, double rotate)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = w->player.dir.x;
	old_plane_x = w->player.plane.x;
	w->player.dir.x = w->player.dir.x * cos(rotate) -
	w->player.dir.y * sin(rotate);
	w->player.dir.y = old_dir_x * sin(rotate) + w->player.dir.y * cos(-rotate);
	w->player.plane.x = w->player.plane.x * cos(rotate) -
	w->player.plane.y * sin(rotate);
	w->player.plane.y = old_plane_x * sin(rotate) +
	w->player.plane.y * cos(rotate);
}
