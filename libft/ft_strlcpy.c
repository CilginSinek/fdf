/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:09:58 by iduman            #+#    #+#             */
/*   Updated: 2025/06/01 15:09:59 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The ft_strlcpy function copies up to size - 1 characters
from the string src to the buffer dst, 
ensuring the result is null-terminated,
and returns the length of src.
If size is zero, it does not perform any copying
and simply returns the length of src.
Input:
    void *dest: A pointer to the destination buffer.
    const void *src: A pointer to the source string.
    size_t n: The maximum number of bytes to copy.
Output:
    size_t: The total length of the string copied.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
