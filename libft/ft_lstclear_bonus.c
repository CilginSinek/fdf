/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:36:20 by iduman            #+#    #+#             */
/*   Updated: 2025/06/12 16:32:41 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*mylist;
	t_list		tmp;

	if (!*lst || !del)
		return ;
	mylist = *lst;
	while (1)
	{
		tmp = *mylist;
		del(mylist->content);
		free(mylist);
		if (!tmp.next)
		{
			*lst = NULL;
			return ;
		}
		mylist = tmp.next;
	}
}
