/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:20:44 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:48:02 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bl(char c)
{
	return (c == ' ' || c == ',' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	int		str_len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str_len = ft_strlen(s) - 1;
	while (bl((char)s[i]))
		i++;
	while (bl((char)s[str_len]) && str_len > i)
		str_len--;
	if (str_len < i)
		return (ft_strdup(""));
	return (ft_strsub(s, i, str_len - i + 1));
}
