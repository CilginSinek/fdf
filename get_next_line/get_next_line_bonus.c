/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:50:20 by iduman            #+#    #+#             */
/*   Updated: 2025/08/03 02:00:10 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static char	*append_cage(int fd, char *cage)
{
	char	*tmp;
	ssize_t	read_res;

	tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (ft_strchr(cage, '\n') == NULL)
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

static char	*get_l(char *cage)
{
	char	*chr_add;
	char	*line;

	chr_add = ft_strchr(cage, '\n');
	if (chr_add == NULL)
		return (ft_substr(cage, 0, ft_strlen(cage)));
	line = ft_substr(cage, 0, chr_add - cage + 1);
	return (line);
}

static char	*get_fresh_cage(char *cage)
{
	char	*org_cage;
	char	*return_cage;

	org_cage = cage;
	cage = ft_strchr(cage, '\n');
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
	static char	*cage[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cage[fd] = append_cage(fd, cage[fd]);
	if (cage[fd] == NULL)
		return (NULL);
	if (ft_strlen(cage[fd]) == 0)
	{
		free(cage[fd]);
		cage[fd] = NULL;
		return (NULL);
	}
	line = get_l(cage[fd]);
	cage[fd] = get_fresh_cage(cage[fd]);
	return (line);
}
