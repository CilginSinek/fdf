/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:45:34 by iduman            #+#    #+#             */
/*   Updated: 2025/06/02 19:45:34 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The ft_strmapi function applies a function f to each character of the string s,
passing the index of the character as the first argument to f.
It returns a new string resulting from the application of f to each character
of s. The new string is dynamically allocated and must be freed by the caller.
Input:
    char const *s: Pointer to the string to be mapped.
    char (*f)(unsigned int, char): Pointer to
    the function to apply to each character.
Output:
    char*: Pointer to the newly allocated string resulting from the mapping,
    or NULL if the allocation fails or if s or f is NULL.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (i < ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
}
