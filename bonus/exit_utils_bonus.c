/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:42:32 by iduman            #+#    #+#             */
/*   Updated: 2025/08/20 17:42:32 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_utils(t_fdf *tmp)
{
	if (tmp->projection)
		free(tmp->projection);
	if (tmp->offset_x)
		free(tmp->offset_x);
	if (tmp->offset_y)
		free(tmp->offset_y);
	if (tmp->scale)
		free(tmp->scale);
	if (tmp->rotation)
		free(tmp->rotation);
}

static void	free_maps(t_fdf_bonus *fdf)
{
	int			i;

	i = 0;
	while (fdf)
	{
		if (fdf->fdf)
		{
			if (fdf->fdf->map)
			{
				while (i < fdf->fdf->height)
					free(fdf->fdf->map[i++]);
				free(fdf->fdf->map);
				fdf->fdf->map = NULL;
			}
			if (fdf->fdf->img)
			{
				mlx_destroy_image(fdf->fdf->mlx_ptr, fdf->fdf->img->img);
				free(fdf->fdf->img);
				fdf->fdf->img = NULL;
			}
			free(fdf->fdf);
		}
		fdf = fdf->next_frame;
	}
}

void	free_mlx(t_fdf_bonus *fdf)
{
	if (fdf->fdf->mlx_ptr)
	{
		if (fdf->fdf->win_ptr)
			mlx_destroy_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr);
		mlx_destroy_display(fdf->fdf->mlx_ptr);
		free(fdf->fdf->mlx_ptr);
		fdf->fdf->mlx_ptr = NULL;
		fdf->fdf->mlx_ptr = NULL;
	}
}

int	close_window(t_fdf_bonus *fdf)
{
	free_utils(fdf->fdf);
	free_maps(fdf);
	free_mlx(fdf);
	if (fdf->video_mode)
		free(fdf->video_mode);
	exit(0);
	return (0);
}
