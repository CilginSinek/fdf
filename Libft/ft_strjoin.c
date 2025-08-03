/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:45:39 by iduman            #+#    #+#             */
/*   Updated: 2025/06/18 14:11:41 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The ft_strjoin function concatenates two strings s1 and s2 into a new string.
It allocates memory for the new string,
which is the sum of the lengths of s1 and s2.
If the memory allocation fails, it returns NULL.
Input:
	char const *s1: Pointer to the first string.
	char const *s2: Pointer to the second string.
Output:
	char*: Pointer to the newly allocated
	string containing the concatenation of s1 and s2,
	or NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	len1;

	nstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!nstr)
		return ((char *) NULL);
	len1 = 0;
	while (*s1)
	{
		nstr[len1] = *s1;
		len1++;
		s1++;
	}
	while (*s2)
	{
		nstr[len1] = *s2;
		len1++;
		s2++;
	}
	nstr[len1] = '\0';
	return (nstr);
}
