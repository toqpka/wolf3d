/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:56:00 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:49:56 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh_mem;

	if (!(fresh_mem = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(fresh_mem, size);
	return (fresh_mem);
}
