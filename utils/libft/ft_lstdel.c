/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:23:04 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/17 21:50:10 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (!del || !alst)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		del(((*alst)->content), (*alst)->content_size);
		free(*alst);
		*alst = temp;
	}
	*alst = NULL;
}
