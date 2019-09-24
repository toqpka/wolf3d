/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:51:48 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/17 23:58:47 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCTS_H
# define WOLF3D_STRUCTS_H

# define TGA					t_tga
# define IMAGE				t_image

typedef unsigned int	t_u32;
typedef unsigned char	t_u8;

typedef struct			s_rgba
{
	int				red;
	int				green;
	int				blue;
	int				alpha;
}						t_rgba;

typedef struct			s_sound
{
	Mix_Music		*bgmusic;
	Mix_Chunk		*shoot;
	Mix_Chunk		**reload;
	int				m_volume;
	int				s_volume;
}						t_sound;

typedef struct			s_image
{
	Uint32			width;
	Uint32			height;
	Uint32			length;
	Uint32			*pixels;
}						t_image;

typedef struct			s_ui_node
{
	t_image			*img;
	SDL_Rect		rect;
}						t_ui_node;

typedef struct			s_ui
{
	t_ui_node		bar;
	t_ui_node		**face;
	t_ui_node		health;
	t_ui_node		ammo;
	t_ui_node		**digit;
	t_ui_node		**letter;
	t_ui_node		menu_background;
	t_ui_node		menu_quit;
	t_ui_node		menu_pause;
	t_ui_node		menu_music;
	t_ui_node		menu_sounds;
	t_ui_node		menu_logo;
	int				position;
	t_u8			clicked;
}						t_ui;

typedef struct			s_tga
{
	t_u32			size;
	t_u8			data_type;
	t_u8			*data;
	t_u8			*ptr;
	IMAGE			*image;
}						t_tga;

typedef struct			s_texture
{
	t_ui_node		*img_c;
	Uint32			*ptr;
	Uint32			tex_x;
	Uint32			tex_y;
	Uint8			type;
	short			draw_start;
	short			draw_end;
	short			col_height;
}						t_texture;

typedef struct			s_ixy
{
	int				x;
	int				y;
}						t_ixy;

typedef struct			s_dxy
{
	double			x;
	double			y;
}						t_dxy;

typedef struct			s_mouse
{
	struct s_ixy	last;
	struct s_ixy	curr;
}						t_mouse;

typedef struct			s_frametime
{
	double			old;
	double			new;
	double			delta;
	int				framerate;
}						t_frametime;

typedef struct			s_riffle
{
	t_ui_node		**fraps;
	SDL_Rect		rect;
	unsigned int	ammo;
	double			start;
	double			end;
	t_u8			active;
	int				shoot;
	int				sound_mix;
	t_u8			busy_anim;
	int				tr;
	struct s_ixy	pos;
}						t_riffle;

typedef struct			s_map
{
	Uint32			**block;
	Uint32			width;
	Uint32			height;
	Uint32			x;
	Uint32			y;
}						t_map;

typedef struct			s_ray
{
	struct s_dxy	dir;
	struct s_dxy	pos;
	double			dist;
	struct s_dxy	delta;
	struct s_dxy	side;
	struct s_dxy	step;
	struct s_ixy	map;
	double			camera;
	double			wallx;
	double			wall_dist;
	int				hit;
	int				hit_side;
	double			floor_x_wall;
	double			floor_y_wall;
	short			draw_start;
	short			draw_end;
}						t_ray;

typedef struct			s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plane;
	double			speed;
	double			rotation;
	double			cx;
	double			cy;
	t_u8			go;
}						t_player;

typedef struct			s_controls
{
	t_u8			w;
	t_u8			a;
	t_u8			s;
	t_u8			d;
	t_u8			q;
	t_u8			e;
	t_u8			p;
}						t_controls;

typedef struct			s_window
{
	SDL_Window		*window;
	SDL_Surface		*screen;
	t_image			*screen_img;
	int				width;
	int				height;
	t_u8			power;
	t_u8			pause;
	t_u32			*ptr;
	t_ray			ray;
	t_player		player;
	t_riffle		riffle;
	t_map			map;
	t_mouse			mouse;
	t_frametime		ftime;
	t_texture		**textures;
	t_texture		**text_sky;
	t_sound			*music;
	t_ui			ui;
	t_ui_node		sky;
	SDL_Event		e;
	t_controls		controls;
	t_u8			free_cell;
	char			**raw_paths;
}						t_window;

#endif
