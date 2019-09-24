/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:52:54 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:48:27 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len < len)
	{
		ft_memset(dst + src_len, '\0', len - src_len);
		return (ft_memcpy(dst, src, src_len));
	}
	else
		return (ft_memcpy(dst, src, len));
}
