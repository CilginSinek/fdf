/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:01:15 by iduman            #+#    #+#             */
/*   Updated: 2025/05/27 16:40:18 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function gives your input is can be a Dec value

Input:
	int
Output:
	int: 1 or 0
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
