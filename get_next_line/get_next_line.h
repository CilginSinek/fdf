/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:46:43 by iduman            #+#    #+#             */
/*   Updated: 2025/08/03 02:02:24 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../Libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strjoin_f(char *s1, char const *s2);
char	*ft_strchr_f(const char *s, int c);
char	*ft_substr_f(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy_f(char *dest, const char *src, size_t size);
char	*get_next_line(int fd);

#endif
