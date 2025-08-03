/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:26:07 by iduman            #+#    #+#             */
/*   Updated: 2025/06/11 14:20:04 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memcpy function in C copies the specified 
number of bytes from one memory location to another 
memory location regardless of the type of data stored.
Where both source and destination are raw memory addresses.
The memcpy() function is optimized for copying memory chunks in 
an efficient manner and it copies memory in a byte-by-byte format.
Input:
    void *dest: A pointer to the memory location
    where the copied data will be stored.
    void *src: A pointer to the memory location
    from where the data is to be copied.
    unsigned int n: The number of bytes to be copied.
Output:
    void* : This function returns a pointer to the memory location
    where data is copied.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
