/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:15:46 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 23:53:37 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	get_menu_offset_by_index(int index, int *offset_x, int *offset_y)
{
	*offset_x = WIDTH / 2 - 126;
	if (index == 0)
		*offset_y = HEIGHT / 2 - HEIGHT / 5;
	else if (index == 1)
		*offset_y = HEIGHT / 2 - HEIGHT / 8;
	else if (index == 2)
		*offset_y = HEIGHT / 2;
	else if (index == 3)
		*offset_y = HEIGHT / 2 + HEIGHT / 8;
}

void	set_bar(t_window *w, int index, int stick_pos)
{
	int			i;
	int			offset_x;
	int			offset_y;

	i = 0;
	offset_x = 0;
	offset_y = 0;
	get_menu_offset_by_index(index, &offset_x, &offset_y);
	offset_y += 15 + 20;
	w->ui.letter[1]->rect = set_rect(18, 39, offset_x, offset_y);
	render_scale(w, w->ui.letter[1]);
	w->ui.letter[2]->rect = set_rect(27, 39, offset_x
	+ w->ui.letter[1]->rect.w, offset_y);
	while (i++ < 10)
	{
		render_scale(w, w->ui.letter[2]);
		w->ui.letter[2]->rect.x += w->ui.letter[2]->rect.w - 6;
	}
	w->ui.letter[3]->rect = set_rect(18, 39, offset_x
	+ w->ui.letter[1]->rect.w + 10 * (w->ui.letter[2]->rect.w - 6), offset_y);
	render_scale(w, w->ui.letter[3]);
	w->ui.letter[4]->rect = set_rect(16, 39, offset_x
	+ w->ui.letter[1]->rect.w / 2
	+ (stick_pos / 10 * (w->ui.letter[2]->rect.w - 6)), offset_y);
	render_scale(w, w->ui.letter[4]);
}

void	event_menu(t_window *w)
{
	if (w->ui.clicked)
	{
		w->ui.clicked = FALSE;
		if (w->ui.position == 0)
			w->pause = FALSE;
		if (w->ui.position == 3)
			w->power = FALSE;
		w->ui.position = 0;
	}
}

int		shade_color(int color, double percent)
{
	int		r;
	int		g;
	int		b;
	double	delta;

	delta = percent / 100;
	r = (color >> 16 & 0xFF) * delta;
	g = (color >> 8 & 0x00FF) * delta;
	b = (color & 0x0000FF) * delta;
	return ((r << 16) | (g << 8) | b);
}

void	show_menu(t_window *w)
{
	draw_mask_backround(w);
	draw_skill(w, w->ui.position);
	get_menu_offset_by_index(0, &w->ui.menu_logo.rect.x,
	&w->ui.menu_logo.rect.y);
	w->ui.menu_logo.rect.y -= 150;
	render_image(w, &(w->ui.menu_logo));
	get_menu_offset_by_index(0, &w->ui.menu_pause.rect.x,
	&w->ui.menu_pause.rect.y);
	render_image(w, &(w->ui.menu_pause));
	get_menu_offset_by_index(1, &w->ui.menu_sounds.rect.x,
	&w->ui.menu_sounds.rect.y);
	render_image(w, &(w->ui.menu_sounds));
	set_bar(w, 1, w->music->s_volume);
	get_menu_offset_by_index(2, &w->ui.menu_music.rect.x,
	&w->ui.menu_music.rect.y);
	render_image(w, &(w->ui.menu_music));
	set_bar(w, 2, w->music->m_volume);
	get_menu_offset_by_index(3, &w->ui.menu_quit.rect.x,
	&w->ui.menu_quit.rect.y);
	render_image(w, &(w->ui.menu_quit));
	event_menu(w);
}
