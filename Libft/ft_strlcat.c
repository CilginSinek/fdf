/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:51:59 by iduman            #+#    #+#             */
/*   Updated: 2025/06/01 15:13:14 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The ft_strlcat function appends the string src to the end of dst,
up to size - 1 characters, and null-terminates the result.
If the size is less than or equal to the length of dst,
it returns size + the length of src.
Input:
	char *dst: Pointer to the destination string.
	const char *src: Pointer to the source string.
	size_t size: The size of the destination buffer.
Output:
	size_t: The total length of the string that would have been created
	if there was enough space,
	which is the length of dst plus the length of src.
	Note: The returned length is not the length of the resulting string,
	but the length it would have been if there was enough space.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
