/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:21:36 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 19:34:11 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			get_text_height(char *path)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	return (i);
}

void		load_paths_raw(t_window *w, char *path)
{
	int i;
	int fd;
	int height;

	i = 0;
	height = get_text_height(path);
	w->raw_paths = (char **)malloc(sizeof(char *) * height);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &w->raw_paths[i]) > 0)
		i++;
}

t_image		*not_found_img(void)
{
	int		x;
	int		y;
	t_image *img;

	img = (t_image *)malloc(sizeof(t_image));
	img->width = 100;
	img->height = 100;
	img->pixels = (Uint32 *)malloc(sizeof(Uint32) * img->width * img->height);
	x = 0;
	while (x < (int)img->width)
	{
		y = 0;
		while (y < (int)img->height)
		{
			if (x % 10 == y % 10)
				img->pixels[y * img->width + x] = form_color(242, 202, 39, 255);
			else
				img->pixels[y * img->width + x] = form_color(0, 0, 0, 255);
			y++;
		}
		x++;
	}
	return (img);
}
