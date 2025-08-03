/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:52:06 by iduman            #+#    #+#             */
/*   Updated: 2025/06/01 15:07:46 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The ft_strncmp function compares
the first n characters of two strings str1 and str2.
If the strings are equal up to n characters, it returns 0.
If the strings differ, it returns a 
positive or negative value based on the difference.
Input:
	const char *str1: Pointer to the first string.
	const char *str2: Pointer to the second string.
	size_t n: The number of characters to compare.
Output:
	int: 
	- 0 if the first n characters of str1 and str2 are equal,
	- a positive value if str1 is greater than str2,
	- a negative value if str1 is less than str2.
*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
