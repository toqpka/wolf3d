/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:45:49 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/20 11:24:59 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	preset_and_load(t_window *w)
{
	w->window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	w->screen = SDL_GetWindowSurface(w->window);
	load_paths_raw(w, "./assets/raw_paths");
	load_assets(w);
	load_sounds(w);
	fill_ui(w);
	init_riffle(w);
	scale_rect_digits(w, 1.65);
	SDL_SetWindowGrab(w->window, SDL_TRUE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	Mix_AllocateChannels(4);
}

void	life_cycle(t_window *w)
{
	w->ptr = w->screen->pixels;
	draw_cycle(w);
	volume_control(w);
	sounds_animation(w);
	count_delta_time(w);
	w->player.speed = 3.0 * w->ftime.delta;
	move_controls(w);
}

int		main(int argc, char *argv[])
{
	t_window	w;

	if (argc != 2)
	{
		ft_putendl("Usage: ./wolf maps/level0");
		return (0);
	}
	global_init(&w);
	if (read_map(&w, argv[1]))
	{
		ft_putendl("Not valid map!");
		return (1);
	}
	preset_and_load(&w);
	while (w.power)
		life_cycle(&w);
	SDL_DestroyWindow(w.window);
	SDL_Quit();
	return (0);
}
