/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:31:37 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/20 15:12:03 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			check_letter(char *str)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' &&
			str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' &&
				str[i] != '8' && str[i] != '9')
			return (1);
	}
	return (0);
}

int			count_rows_colls(t_window *w, char *path)
{
	int		fd;
	char	*tmp;
	int		buf;

	buf = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &tmp) > 0)
	{
		buf == 0 ? buf = ft_strlen(tmp) : buf;
		w->map.width = ft_strlen(tmp);
		if (buf != (int)w->map.width || check_letter(tmp))
			return (1);
		w->map.height++;
		free(tmp);
	}
	close(fd);
	if (!w->map.height)
		return (1);
	return (0);
}

int			is_correct_wall(t_window *w, Uint32 i, Uint32 j)
{
	if (i == 0 || i == w->map.height - 1 || j == 0 || j == w->map.width - 1)
	{
		if (w->map.block[i][j] < 1 || w->map.block[i][j] > 9)
			return (0);
	}
	return (1);
}

void		is_free_cell(t_window **w, Uint32 i, Uint32 j, Uint32 cell)
{
	if (((i > 0) && (i < (*w)->map.height - 1)) ||
	((j > 0) && (j < (*w)->map.width - 1)))
	{
		if (cell == 0 && (*w)->free_cell == 0)
		{
			(*w)->free_cell = 1;
			(*w)->player.pos.x = i + 0.5f;
			(*w)->player.pos.y = j + 0.5f;
		}
	}
}

int			read_map(t_window *w, char *path)
{
	int		fd;
	t_u32	i[2];
	char	*line;

	i[0] = -1;
	if (count_rows_colls(w, path))
		return (1);
	w->map.block = (t_u32 **)malloc(sizeof(t_u32 *) * w->map.height);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i[1] = -1;
		w->map.block[++i[0]] = (t_u32 *)malloc(sizeof(t_u32) * w->map.width);
		while (++i[1] < w->map.width)
		{
			w->map.block[i[0]][i[1]] = line[i[1]] - '0';
			is_free_cell(&w, i[0], i[1], w->map.block[i[0]][i[1]]);
			if (!is_correct_wall(w, i[0], i[1]))
				return (1);
		}
		free(line);
	}
	if (w->free_cell == 0)
		return (1);
	return (0);
}
