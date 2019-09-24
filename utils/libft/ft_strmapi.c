/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:14:08 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:48:35 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh_str;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(fresh_str = ft_strnew((size_t)ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		fresh_str[i] = f(i, (char)s[i]);
		i++;
	}
	return (fresh_str);
}
