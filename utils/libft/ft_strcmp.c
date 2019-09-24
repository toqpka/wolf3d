/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:42:23 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:49:06 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;

	i = 0;
	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	while (cp_s1[i] || cp_s2[i])
	{
		if (cp_s1[i] != cp_s2[i])
			break ;
		i++;
	}
	return (cp_s1[i] - cp_s2[i]);
}
