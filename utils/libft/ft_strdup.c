/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 02:42:10 by jhoppe            #+#    #+#             */
/*   Updated: 2018/12/21 00:17:01 by jhoppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *str)
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
		st[i] = str[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}
