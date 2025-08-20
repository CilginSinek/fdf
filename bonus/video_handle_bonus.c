/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_handle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:42:51 by iduman            #+#    #+#             */
/*   Updated: 2025/08/20 17:42:51 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	read_map_while(t_fdf *fdf, char *line, int fd, t_point **points)
{
	if (fdf->width != ft_get_line_length(line))
		return (ep("Error: Incorrect line lengths in map file.\n",
				fdf, (void *[]){points, line}, fd));
	*points = (t_point *)calloc(fdf->width + 1, sizeof(t_point));
	if (!*points)
		return (ep("Error: Memory allocation failed.\n",
				fdf, (void *[]){NULL, line}, fd));
	if (set_map_line(line, *points, fdf->height, get_video_color) == -1)
		return (ep("Error: Failed to set map line.\n",
				fdf, (void *[]){*points, line}, fd));
	free(line);
	if (append_2d_point_array(&(fdf->map), *points, fdf->height) == -1)
		return (ep("Error: Failed to append to map data.\n",
				fdf, (void *[]){*points, NULL}, fd));
	fdf->height++;
	return (0);
}

static int	video_while(char **line, t_fdf_bonus **current_fdf,
						int fd, t_fdf_bonus **fdf)
{
	t_point	*tmp;

	tmp = NULL;
	if (ft_strchr_f(*line, '-') != NULL)
	{
		if (create_next_frame(current_fdf) < 0)
		{
			clear_frames(fdf);
			return (ep("Error: Memory allocation failed.\n", NULL,
					(void *[]){tmp, line}, fd));
		}
		*line = get_next_line(fd);
		return ('c');
	}
	if (read_map_while(current_fdf->fdf, *line, fd, &tmp) == -1)
		return (clear_frames(&fdf), -1);
	*line = get_next_line(fd);
	return (0);
}

int	read_video_file(const char *filename, t_fdf_bonus *fdf)
{
	int			fd;
	char		*line;
	t_fdf_bonus	*current_fdf;

	current_fdf = fdf;
	if (create_first_frame(current_fdf, &fd, &line) < 0)
		return (-1);
	while (line)
		if (video_while(&line, &current_fdf, fd, &fdf) < 0)
			return (-1);
	close(fd);
	return (0);
}
