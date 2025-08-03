/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:47:15 by iduman            #+#    #+#             */
/*   Updated: 2025/05/27 17:25:10 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Sets the first num bytes of the block of memory pointed by ptr 
to the specified value (interpreted as an unsigned char).
Input:
    *s:void -> Pointer to the block of memory to fill.
    c: int -> Value to be set. The value is passed as an int,
    but the function fills the block of memory using 
    the unsigned char conversion of this value.
    n: unsingned int -> Number of bytes to be set to the value.
Output:
    s is returned.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*src;

	src = s;
	while (n--)
		*src++ = (unsigned char)c;
	return (s);
}
