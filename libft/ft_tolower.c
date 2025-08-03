/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:44:04 by iduman            #+#    #+#             */
/*   Updated: 2025/06/01 14:54:13 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The tolower() function returns
the ASCII value of a lowercase version of the character.
If the character is not an uppercase character then
its value is returned without being changed.

Input: int as ascii
Output: int as ascii
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
