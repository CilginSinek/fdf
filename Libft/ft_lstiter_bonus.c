/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:46:04 by iduman            #+#    #+#             */
/*   Updated: 2025/06/12 16:02:47 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*mylst;

	if (!lst || !f)
		return ;
	mylst = lst;
	while (1)
	{
		f(mylst->content);
		if (mylst->next == NULL)
			return ;
		mylst = mylst->next;
	}
}
