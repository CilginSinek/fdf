/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:37:35 by iduman            #+#    #+#             */
/*   Updated: 2025/06/01 14:54:23 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_toupper() function returns the ASCII value of
an uppercase version of the character.
If the character is not an uppercase character
then its value is returned without being changed.

Input: int as ascii
Output: int as ascii
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
