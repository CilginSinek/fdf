/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:46:28 by iduman            #+#    #+#             */
/*   Updated: 2025/08/03 02:01:49 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy_f(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*append_cage(int fd, char *cage)
{
	char	*tmp;
	ssize_t	read_res;

	tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (ft_strchr_f(cage, '\n') == NULL)
	{
		read_res = read(fd, tmp, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(cage);
			free(tmp);
			return (NULL);
		}
		if (read_res == 0)
			break ;
		tmp[read_res] = '\0';
		cage = ft_strjoin_f(cage, tmp);
		if (cage == NULL)
			break ;
	}
	free(tmp);
	return (cage);
}

char	*get_l(char *cage)
{
	char	*chr_add;
	char	*line;

	chr_add = ft_strchr_f(cage, '\n');
	if (chr_add == NULL)
		return (ft_substr_f(cage, 0, ft_strlen(cage)));
	line = ft_substr_f(cage, 0, chr_add - cage + 1);
	return (line);
}

char	*get_fresh_cage(char *cage)
{
	char	*org_cage;
	char	*return_cage;

	org_cage = cage;
	cage = ft_strchr_f(cage, '\n');
	if (cage == NULL)
	{
		free(org_cage);
		return (NULL);
	}
	cage++;
	if (!cage)
		return (NULL);
	return_cage = (char *)ft_calloc(ft_strlen(cage) + 1, sizeof(char));
	if (!return_cage)
		return (NULL);
	ft_strlcpy_f(return_cage, cage, ft_strlen(cage) + 1);
	free(org_cage);
	return (return_cage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cage;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (cage)
			free(cage);
		return (NULL);
	}
	cage = append_cage(fd, cage);
	if (cage == NULL)
		return (NULL);
	if (ft_strlen(cage) == 0)
	{
		free(cage);
		cage = NULL;
		return (NULL);
	}
	line = get_l(cage);
	cage = get_fresh_cage(cage);
	return (line);
}
