/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:45:01 by iduman            #+#    #+#             */
/*   Updated: 2025/06/12 15:29:02 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(int n)
{
	int		c;

	c = 0;
	if (n < 0)
		c++;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

/*
The ft_itoa function converts an integer n into a string representation.
It handles both positive and negative integers,
returning a dynamically allocated string.
If n is zero, it returns a string "0".
Input:
	int n: The integer to convert to a string.
Output:
	char*: A pointer to the newly allocated string representing the integer.
			The caller is responsible for freeing the allocated memory.
			If the allocation fails, NULL is returned.
*/
char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	if (n == 0)
		return (ft_strdup("0"));
	len = counter(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		num = -n;
	else
		num = n;
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
