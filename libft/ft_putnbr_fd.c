/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:45:16 by iduman            #+#    #+#             */
/*   Updated: 2025/06/12 15:47:42 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the integer ’n’ to the specified file descriptor.
Input:
    int n: The integer to output.
    int fd: The file descriptor to which the integer will be written.
Output:
    None. The function writes the integer to the specified file descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	if (fd < 0)
		return ;
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd);
		nbr /= 10;
	}
	else
	{
		ft_putchar_fd(nbr + '0', fd);
	}
}
