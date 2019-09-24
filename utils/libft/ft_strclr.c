/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:59:41 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:49:08 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;
	char	*cp_s;

	i = 0;
	cp_s = s;
	if (!s)
		return ;
	while (*cp_s++)
		i++;
	ft_memset(s, '\0', i);
}
