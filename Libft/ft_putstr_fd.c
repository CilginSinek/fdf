/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:45:20 by iduman            #+#    #+#             */
/*   Updated: 2025/06/02 19:45:20 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the string ’s’ to the specified file descriptor.
Input:
	char *s: Pointer to the string to output.
	int fd: The file descriptor to which the string will be written.
Output:
	None. The function writes the string to the specified file descriptor.
	If s is NULL or fd is less than 0, the function does nothing.
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}
