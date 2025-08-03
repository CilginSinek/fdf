/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:46:00 by iduman            #+#    #+#             */
/*   Updated: 2025/06/02 19:46:00 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The ft_strtrim function trims leading and trailing characters from the string s1
that are present in the set of characters specified by set.
It returns a newly allocated string that contains the trimmed version of s1.
Input:
    char const *s1: Pointer to the string to be trimmed.
    char const *set: Pointer to the set of characters to trim from s1.
Output:
    char*: Pointer to the newly allocated trimmed string,
    or NULL if the allocation fails or if s1 or set is NULL.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*trimmed;

	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1);
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *(end - 1)))
		end--;
	trimmed = ft_substr(start, 0, end - start);
	return (trimmed);
}
