/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:17:41 by iduman            #+#    #+#             */
/*   Updated: 2025/06/01 17:57:23 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The ft_strlen function calculates the length of a string by iterating through
the characters until it reaches the null terminator ('\0').
Input:
	char const *s: Pointer to the string whose length is to be calculated.
Output:
	size_t: The length of the string, excluding the null terminator.
*/
size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (*s++)
		c++;
	return (c);
}
