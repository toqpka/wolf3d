/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:02:02 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:49:50 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ch_s1;
	const unsigned char	*ch_s2;

	i = 0;
	ch_s1 = (const unsigned char *)s1;
	ch_s2 = (const unsigned char *)s2;
	if (n > 0)
	{
		while (i < n)
		{
			if (ch_s1[i] != ch_s2[i])
				return ((int)(ch_s1[i] - ch_s2[i]));
			i++;
		}
	}
	return (0);
}
