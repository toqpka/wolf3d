/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:36:02 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:47:38 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_out_line(char **s, char **line, int fd)
{
	char		*tmp;
	int			size;

	size = 0;
	while (s[fd][size] != '\n' && s[fd][size] != '\0')
		size++;
	if (s[fd][size] == '\n')
	{
		*line = ft_strdupbfrn(s[fd]);
		tmp = ft_strdup(s[fd] + size + 1);
		free(s[fd]);
		s[fd] = tmp;
	}
	else if (s[fd][size] == '\0')
	{
		*line = ft_strdupbfrn(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	static char	*s[1024];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_out_line(s, line, fd));
}
