/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:26:28 by iduman            #+#    #+#             */
/*   Updated: 2025/06/11 16:09:22 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Allocates memory for an array of `nmemb` elements of `size` bytes each
and initializes all bytes in the allocated memory to zero.
If the allocation fails, it returns NULL.

Input:
	size_t nmemb - number of elements
	size_t size - size of each element
Output:
	void* - pointer to the allocated memory, or NULL if allocation fails
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
