/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:11:44 by iduman            #+#    #+#             */
/*   Updated: 2025/06/12 14:13:39 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The ft_substr function extracts a substring from the given string s,
starting at the specified index start and
extending for a maximum of len characters.
If start is greater than the length of s, an empty string is returned.
If len is greater than the remaining length of s from start,
the substring will be truncated to fit within the bounds of s.
Input:
	char const *s: Pointer to the original string.
	unsigned int start: The starting index for the substring.
	size_t len: The maximum length of the substring to extract.
Output:
	char*: Pointer to the newly allocated substring,
	or NULL if the allocation fails or if s is NULL.
	If start is greater than the length of s, an empty string is returned.
	If the allocation fails, NULL is returned.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	new_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	new_len = ft_strlen(s) - start;
	if (new_len > len)
		new_len = len;
	str = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, new_len + 1);
	return (str);
}
