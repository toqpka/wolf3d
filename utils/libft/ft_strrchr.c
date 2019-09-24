/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:36:58 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:48:14 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*last_c;

	last_c = NULL;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (*s++ == c)
			last_c = (char *)(s - 1);
	}
	return (last_c);
}
