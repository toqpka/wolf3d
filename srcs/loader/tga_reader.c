/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:03:24 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 23:59:38 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_u8		read_file(TGA *tga, char *path)
{
	struct stat st;
	int			fd;

	if (lstat(path, &st) == -1)
		return (open_error(path));
	tga->size = st.st_size;
	if (!(tga->data = (t_u8 *)malloc(tga->size)))
		return (mem_error(tga));
	if (!(tga->image = (IMAGE *)malloc(sizeof(IMAGE))))
		return (mem_error(tga));
	fd = open(path, O_RDONLY);
	read(fd, tga->data, tga->size);
	tga->ptr = tga->data;
	close(fd);
	return (1);
}

static t_u8		read_image_info(TGA *tga)
{
	t_u32	id_length;

	id_length = tga->ptr[0];
	tga->image->width = (tga->ptr[12] | tga->ptr[13] << 8);
	tga->image->height = (tga->ptr[14] | tga->ptr[15] << 8);
	tga->ptr += 18 + id_length;
	tga->image->length = tga->image->width * tga->image->height;
	if (!(tga->image->pixels =
		(t_u32 *)malloc(sizeof(t_u32) * tga->image->length)))
		return (mem_error(tga));
	return (1);
}

static t_u32	get_pix_values(TGA *tga)
{
	return (tga->ptr[3] << 24 | tga->ptr[2] << 16
					| tga->ptr[1] << 8 | tga->ptr[0]);
}

static void		read_data(TGA *tga)
{
	t_u32		i;
	t_u32		length;
	t_u8		type;

	i = 0;
	while (i < tga->image->length)
	{
		type = *tga->ptr & 128;
		length = (*(tga->ptr++) & 127) + 1;
		while (length-- > 0)
		{
			tga->image->pixels[i++] = get_pix_values(tga);
			if (!type || !length)
				tga->ptr += 4;
		}
	}
}

t_image			*read_tga(char *path)
{
	TGA	tga;

	tga.data = NULL;
	tga.image = NULL;
	if (!read_file(&tga, path))
		return (NULL);
	if (!read_image_info(&tga))
		return (NULL);
	read_data(&tga);
	free(tga.data);
	return (tga.image);
}
