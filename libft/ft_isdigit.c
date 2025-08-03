/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:24:04 by iduman            #+#    #+#             */
/*   Updated: 2025/05/27 16:41:24 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function gives your input is a number

Input:
	int: Dec value
Output:
	int: 1 or 0
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
