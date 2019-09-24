/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:18:28 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:49:12 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*cp_s1;

	cp_s1 = (char *)s1;
	while (*cp_s1)
		cp_s1++;
	while (*s2)
		*cp_s1++ = *s2++;
	*cp_s1++ = '\0';
	return (s1);
}
