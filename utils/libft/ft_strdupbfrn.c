/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupbfrn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:17:30 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:48:58 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdupbfrn(const char *str)
{
	int		i;
	char	*st;

	i = 0;
	while (str[i] != '\0')
		i++;
	st = (char*)malloc(sizeof(char) * (i + 1));
	if (!st)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		st[i] = str[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}
