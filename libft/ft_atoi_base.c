/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:51:21 by iduman            #+#    #+#             */
/*   Updated: 2025/08/05 17:51:51 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlenspc(const char *str)
{
	int	len;

	len = 0;
	while (str[len] == ' ' || (str[len] >= 9 && str[len] <= 13))
		len++;
	return (len);
}

int	get_digit(const char *base, char c)
{
	int	digit;

	digit = -1;
	if (ft_strchr(base, ft_tolower(c)))
		digit = ft_strchr(base, ft_tolower(c)) - base;
	else
		digit = ft_strchr(base, ft_toupper(c)) - base;
	return (digit);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int			result;
	int			i;
	signed char	a;
	int			digit;

	result = 0;
	i = 0 + strlenspc(str);
	a = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			a = -1;
		i++;
	}
	while (str[i] && ft_strchr(base, str[i]) != NULL)
	{
		digit = get_digit(base, str[i]);
		if (digit < 0 || digit >= (int)ft_strlen(base))
			return (0);
		result = result * ft_strlen(base) + digit;
		i++;
	}
	return (result * a);
}
