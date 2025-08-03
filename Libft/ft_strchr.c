/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:51:53 by iduman            #+#    #+#             */
/*   Updated: 2025/06/01 15:14:46 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The ft_strchr function searches for the first occurrence of the character c
in the string pointed to by s. It returns a pointer to the first occurrence
of c in s, or NULL if c is not found. If c is the null character ('\0'),
the function returns a pointer to the null terminator of the string.
Input:
	const char *s: Pointer to the string to be searched.
	int c: The character to search for (passed as an int, but treated as a char).
Output:
	const char*: Pointer to the first occurrence of c in s, or
	NULL if not found.
*/
char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}
