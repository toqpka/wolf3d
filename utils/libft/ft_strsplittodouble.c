/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplittodouble.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:33:59 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:48:09 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_word(char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	count_words(char *s, char c)
{
	int	i;
	int	trigger;
	int	count;

	i = 0;
	count = 0;
	trigger = 0;
	while (s[i])
	{
		if (s[i] != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (s[i] == c && trigger == 1)
			trigger = 0;
		i++;
	}
	return (count);
}

double		*ft_strsplittodouble(char const *s, char c)
{
	double	*arr;
	int		i;

	if (!s || !(arr = (double *)malloc(sizeof(double )
					* count_words((char *)s, c) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			if (!(arr[i] = (double)ft_atoi(malloc_word((char *)s, c))))
			{
				free(arr);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (arr);
}
