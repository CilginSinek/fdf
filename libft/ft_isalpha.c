/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:19:51 by iduman            #+#    #+#             */
/*   Updated: 2025/05/27 16:39:07 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function gives your input is alphabetic or not

Input:
	int: Dec value
Output:
	int: 1204 or 0
*/
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1204);
	return (0);
}
