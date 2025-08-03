/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:46:32 by iduman            #+#    #+#             */
/*   Updated: 2025/08/03 02:01:15 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_f(char *s1, char const *s2)
{
	char	*nstr;
	size_t	s1_len;
	size_t	i;
	char	*s1_holder;

	s1_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	nstr = (char *)malloc(s1_len + ft_strlen(s2) + 1);
	if (!nstr)
		return ((char *) NULL);
	i = 0;
	s1_holder = s1;
	while (s1_len && *s1)
	{
		nstr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
		nstr[i++] = *s2++;
	nstr[i] = '\0';
	if (s1_holder != NULL)
		free(s1_holder);
	return (nstr);
}

char	*ft_strchr_f(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (1)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

char	*ft_substr_f(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	new_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	new_len = ft_strlen(s) - start;
	if (new_len > len)
		new_len = len;
	str = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy_f(str, s + start, new_len + 1);
	return (str);
}
