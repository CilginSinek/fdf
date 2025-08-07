/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filehandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:45:48 by iduman            #+#    #+#             */
/*   Updated: 2025/08/05 18:04:20 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	read_map_while(t_fdf *fdf, char *line, int fd, t_point **points)
{
	if (fdf->width != ft_get_line_length(line))
		return (ep("Error: Incorrect line lengths in map file.\n",
				fdf, (void *[]){points, line}, fd));
	*points = (t_point *)ft_calloc(fdf->width + 1, sizeof(t_point));
	if (!*points)
		return (ep("Error: Memory allocation failed.\n",
				fdf, (void *[]){NULL, line}, fd));
	if (set_map_line(line, *points, fdf->height) == -1)
		return (ep("Error: Failed to set map line.\n",
				fdf, (void *[]){*points, line}, fd));
	free(line);
	if (append_2d_point_array(&(fdf->map), *points, fdf->height) == -1)
		return (ep("Error: Failed to append to map data.\n",
				fdf, (void *[]){*points, NULL}, fd));
	fdf->height++;
	return (0);
}

int	read_map_file(const char *filename, t_fdf *fdf)
{
	int		fd;
	char	*line;
	t_point	*points;

	points = NULL;
	if (ft_strnstr(filename, ".fdf", ft_strlen(filename)) == NULL)
		return (ft_putstr_fd("Error: Invalid file type. Only .fdf.\n", 2), -1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	fdf->height = 0;
	fdf->width = ft_get_line_length(line);
	if (fdf->width == -1 || fdf->width == 0)
		return (free(line), ft_putstr_fd("Error: Invalid map file.\n", 2), -1);
	while (line != NULL)
	{
		if (read_map_while(fdf, line, fd, &points) == -1)
			return (-1);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

void set_horizon(t_fdf *fdf)
{
// this func makes center and scale of the map
}
