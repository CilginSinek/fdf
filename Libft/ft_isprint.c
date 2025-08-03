/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:20 by iduman            #+#    #+#             */
/*   Updated: 2025/05/27 16:45:22 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function gives answer to your input can be printable

Input:
	int: Dec value
Output:
	int: 16384 or 0
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
