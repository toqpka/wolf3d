/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:48:25 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/20 11:12:55 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include "libft.h"
# include "wolf3d_structs.h"
# include "wolf3d_prototypes.h"
# define WIDTH 1200
# define HEIGHT 768
# define TRUE 1
# define FALSE 0
# define FPS 60
# define TEXTURECOUNT 8
# define AMMO_X -25
# define HEALTH_X WIDTH * 5 / 32
# define DELTA_X 50
# define FRAGS_X WIDTH * 9 / 32
# define ARMOR_X WIDTH * 35 / 64
# define START_AMMO 50
# define PLAYER_GUI 120
# define UI_Y		w->height + ((HEIGHT - w->height) / 5)

#endif
