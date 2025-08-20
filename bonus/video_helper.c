/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:41:05 by iduman            #+#    #+#             */
/*   Updated: 2025/08/20 18:41:05 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	clear_frames(t_fdf_bonus **fdf)
{
	t_fdf_bonus	*tmp;
	int			i;

	while (*fdf)
	{
		i = 0;
		tmp = *fdf;
		*fdf = (*fdf)->next_frame;
		if (tmp->fdf)
		{
			if (tmp->fdf->map)
			{
				while (i < tmp->fdf->height)
				{
					free(tmp->fdf->map[i]);
					i++;
				}
				free(tmp->fdf->map);
			}
			free(tmp->fdf);
		}
		free(tmp);
	}
}

int	create_first_frame(const char *filename, t_fdf_bonus *current_fdf,
	int *fd, char **line)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (ft_putstr_fd("Error: Could not open video file.\n", 2), -1);
	*line = get_next_line(*fd);
	if (!*line)
	{
		ft_putstr_fd("Error: Empty video file.\n", 2);
		return (-1);
	}
	current_fdf->fdf->width = ft_get_line_length(*line);
	if (current_fdf->fdf->width <= 0)
		return (free(*line),
			ft_putstr_fd("Error: Invalid video file format.\n", 2), -1);
	current_fdf->fdf->height = 0;
	return (0);
}

int	create_next_frame(t_fdf_bonus **current)
{
	t_fdf_bonus	*new_frame;

	new_frame = (t_fdf_bonus *)calloc(1, sizeof(t_fdf_bonus));
	if (!new_frame)
		return (-1);
	(*current)->next_frame = new_frame;
	new_frame->next_frame = NULL;
	new_frame->video_mode = (*current)->video_mode;
	new_frame->fdf = (t_fdf *)calloc(1, sizeof(t_fdf));
	if (!new_frame->fdf)
		return (-1);
	new_frame->fdf->mlx_ptr = (*current)->fdf->mlx_ptr;
	new_frame->fdf->win_ptr = (*current)->fdf->win_ptr;
	new_frame->fdf->width = (*current)->fdf->width;
	new_frame->fdf->height = 0;
	new_frame->fdf->offset_x = (*current)->fdf->offset_x;
	new_frame->fdf->offset_y = (*current)->fdf->offset_y;
	new_frame->fdf->scale = (*current)->fdf->scale;
	new_frame->fdf->rotation = (*current)->fdf->rotation;
	new_frame->fdf->projection = (*current)->fdf->projection;
	*current = new_frame;
	return (0);
}
