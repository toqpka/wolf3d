/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:24:11 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:50:13 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	change_dash(int *n, int *dash)
{
	if (*n < 0)
	{
		*n *= -1;
		*dash = 1;
	}
}

char		*ft_itoa(int n)
{
	int		cp_n;
	int		len;
	int		dash;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	cp_n = n;
	len = 2;
	dash = 0;
	change_dash(&n, &dash);
	while (cp_n /= 10)
		len++;
	len += dash;
	if (!(res = ft_strnew(len - 1)))
		return (NULL);
	res[len--] = '\0';
	while (len--)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
	}
	if (dash)
		res[0] = '-';
	return (res);
}
