/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:22:17 by iduman            #+#    #+#             */
/*   Updated: 2025/06/11 14:24:28 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ft_memmove is a function that copies n bytes from the memory area
pointed to by src to the memory area pointed to by dest,
handling overlapping memory regions safely.
for cases where the destination pointer is greater than the source pointer.
Input:
	void *dest: A pointer to the destination memory area.
	const void *src: A pointer to the source memory area.
	size_t n: The number of bytes to copy.
Output:
	void *: Returns a pointer to the destination memory area (dest).
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
		while (n--)
			((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
	return (dest);
}
