/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:46:48 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 19:33:06 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		load_sounds(t_window *w)
{
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	w->music = (t_sound *)malloc(sizeof(t_sound));
	w->music->m_volume = 0;
	w->music->s_volume = 50;
	w->music->reload = (Mix_Chunk **)malloc(sizeof(Mix_Chunk *) * 3);
	w->music->bgmusic = Mix_LoadMUS("./assets/sounds/svyat.mp3");
	w->music->shoot = Mix_LoadWAV("./assets/sounds/dsdshtgn.wav");
	w->music->reload[0] = Mix_LoadWAV("./assets/sounds/dsdbopn.wav");
	w->music->reload[1] = Mix_LoadWAV("./assets/sounds/dsdbcls.wav");
	w->music->reload[2] = Mix_LoadWAV("./assets/sounds/dsdbload.wav");
	volume_control(w);
	Mix_PlayMusic(w->music->bgmusic, -1);
	return (0);
}

int		volume_control(t_window *w)
{
	Mix_VolumeChunk(w->music->shoot, w->music->s_volume);
	Mix_VolumeChunk(w->music->reload[0], w->music->s_volume);
	Mix_VolumeChunk(w->music->reload[1], w->music->s_volume);
	Mix_VolumeChunk(w->music->reload[2], w->music->s_volume);
	Mix_VolumeMusic(w->music->m_volume);
	return (0);
}

void	channel_done(int channel)
{
	if (channel <= 3)
	{
		printf("channel %d done!\n", channel);
		Mix_PlayChannel(channel + 1, Mix_GetChunk(channel + 1), 0);
		Mix_ChannelFinished(channel_done);
	}
}

void	sounds_animation(t_window *w)
{
	int fraps;

	fraps = SDL_GetTicks() - w->riffle.start;
	if (w->riffle.sound_mix < 3)
	{
		if (fraps > 100 && fraps <= 400 && w->riffle.sound_mix == 0)
		{
			Mix_PlayChannel(1, w->music->reload[0], 0);
			w->riffle.sound_mix++;
		}
		else if (fraps > 400 && fraps <= 800 && w->riffle.sound_mix == 1)
		{
			Mix_PlayChannel(2, w->music->reload[1], 0);
			w->riffle.sound_mix++;
		}
		else if (fraps > 800 && fraps <= 1200 && w->riffle.sound_mix == 2)
		{
			Mix_PlayChannel(3, w->music->reload[2], 0);
			w->riffle.sound_mix++;
		}
	}
}
