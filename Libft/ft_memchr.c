/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:51:33 by iduman            #+#    #+#             */
/*   Updated: 2025/06/11 16:26:00 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Searches for the first occurrence of the byte `c` in
the first `n` bytes of the memory area pointed to by `s`.
If the byte is found, it returns a pointer to the byte.
If the byte is not found, it returns NULL.
Input:
	const void *s - pointer to the memory area to search
	int c - byte to search for
	size_t n - number of bytes to search
Output:
	void* - pointer to the first occurrence of `c` in `s`, or
	NULL if not found
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == ch)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
