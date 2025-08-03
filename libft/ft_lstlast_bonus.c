/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:18:02 by iduman            #+#    #+#             */
/*   Updated: 2025/06/12 16:31:50 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*mylst;

	if (!lst)
		return (NULL);
	mylst = lst;
	while (1)
	{
		if (!mylst->next)
			return (mylst);
		mylst = mylst->next;
	}
}
