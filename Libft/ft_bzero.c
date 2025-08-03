/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:10:49 by iduman            #+#    #+#             */
/*   Updated: 2025/05/27 17:25:38 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The bzero() function erases the data in the n bytes of the memory
starting at the location pointed to by s, by writing zeros (bytes
containing NULL) to that area.
Input:
    *ptr:void -> Pointer to the block of memory to fill.
    n: size_t -> Number of bytes to be set to the value.
Output:
    void returned.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*src;

	src = s;
	while (n--)
		*src++ = '\0';
}
