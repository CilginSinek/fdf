/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:51:43 by iduman            #+#    #+#             */
/*   Updated: 2025/06/01 18:06:46 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The ft_memcmp function compares the first n bytes of the memory areas
pointed to by dest and src. It returns an integer less than, equal to,
or greater than zero if the first n bytes of dest is found, respectively,
to be less than, to match, or be greater than the first n bytes of src.
If n is zero, the function returns zero.
Input:
	const void *dest: Pointer to the first memory area.
	const void *src: Pointer to the second memory area.
	size_t n: Number of bytes to compare.
Output:
	int: Result of the comparison.
*/
int	ft_memcmp(const void *dest, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
