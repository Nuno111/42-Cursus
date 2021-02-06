/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 00:03:40 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/06 16:37:13 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst && del)
	{
		t_list *tmp;

		while (*lst != NULL)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			del(tmp->content);
			free(tmp);
		}
		lst = NULL;
	}
}
