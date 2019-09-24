/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:51:32 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 19:34:05 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		load_img(t_ui_node *node, char *line)
{
	node->img = read_tga(line);
	if (node->img == NULL)
		node->img = not_found_img();
}

void		load_imgs(t_ui_node **nodes, char **lines, int start, int end)
{
	int i;

	i = 0;
	start--;
	while (start < end)
	{
		load_img(nodes[i], lines[start]);
		i++;
		start++;
	}
}

t_ui_node	**malloc_nodes(t_ui_node **nodes, int count)
{
	int i;

	i = 0;
	nodes = (t_ui_node **)malloc(sizeof(t_ui_node *) * count);
	while (i < count)
	{
		nodes[i] = (t_ui_node *)malloc(sizeof(t_ui_node));
		i++;
	}
	return (nodes);
}

void		load_textures(t_window *w, char **lines, int start, int end)
{
	int	i;

	i = 0;
	start--;
	w->textures = (t_texture **)malloc(sizeof(t_texture *) * TEXTURECOUNT);
	while (i < (end - start))
	{
		w->textures[i] = (t_texture *)malloc(sizeof(t_texture));
		w->textures[i]->img_c = (t_ui_node *)malloc(sizeof(t_ui_node));
		load_img(w->textures[i]->img_c, lines[start + i]);
		i++;
	}
}

void		load_assets(t_window *w)
{
	w->riffle.fraps = malloc_nodes(w->riffle.fraps, 10);
	load_imgs(w->riffle.fraps, w->raw_paths, 1, 10);
	w->ui.digit = malloc_nodes(w->ui.digit, 11);
	load_imgs(w->ui.digit, w->raw_paths, 11, 21);
	w->ui.letter = malloc_nodes(w->ui.letter, 5);
	load_imgs(w->ui.letter, w->raw_paths, 22, 26);
	w->ui.face = malloc_nodes(w->ui.face, 3);
	load_imgs(w->ui.face, w->raw_paths, 27, 29);
	load_textures(w, w->raw_paths, 30, 37);
	load_img(&(w->sky), w->raw_paths[38 - 1]);
	load_img(&(w->ui.bar), w->raw_paths[39 - 1]);
	load_img(&(w->ui.menu_music), w->raw_paths[40 - 1]);
	load_img(&(w->ui.menu_sounds), w->raw_paths[41 - 1]);
	load_img(&(w->ui.menu_pause), w->raw_paths[42 - 1]);
	load_img(&(w->ui.menu_quit), w->raw_paths[43 - 1]);
	load_img(&(w->ui.menu_logo), w->raw_paths[44 - 1]);
}
