/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:50:31 by iduman            #+#    #+#             */
/*   Updated: 2025/06/13 15:29:00 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	strlenspc(const char *str)
{
	int	len;

	len = 0;
	while (str[len] == ' ' || (str[len] >= 9 && str[len] <= 13))
		len++;
	return (len);
}

/*
In C, atoi stands for ASCII To Integer.
The ft_atoi() is a library function in C that converts
the numbers in string form to their integer value.
To put it simply, the atoi() function accepts a string
(which represents an integer) as a parameter
and yields an integer value in return.
Input: *char
Output: int
*/
int	ft_atoi(const char *str)
{
	int			result;
	int			i;
	signed char	a;

	result = 0;
	i = 0 + strlenspc(str);
	a = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			a = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * a);
}
