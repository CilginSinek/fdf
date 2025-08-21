/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:42:32 by iduman            #+#    #+#             */
/*   Updated: 2025/08/21 09:05:53 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_utils(t_fdf *tmp)
{
	if (!tmp)
		return ;
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

static void	free_map(t_fdf_bonus **fdf)
{
	int	i;

	if (!fdf || !(*fdf) || !(*fdf)->fdf)
		return ;
	i = 0;
	while (i < (*fdf)->fdf->height && (*fdf)->fdf->map[i])
	{
		free((*fdf)->fdf->map[i]);
		(*fdf)->fdf->map[i] = NULL;
		i++;
	}
	free((*fdf)->fdf->map);
	(*fdf)->fdf->map = NULL;
}

static void	free_maps(t_fdf_bonus *fdf)
{
	t_fdf_bonus	*tmp;

	if (!fdf)
		return ;
	while (fdf)
	{
		if (fdf->fdf && fdf->fdf->map)
		{
			if (fdf->fdf->map)
				free_map(&fdf);
			free(fdf->fdf);
			fdf->fdf = NULL;
		}
		tmp = fdf;
		fdf = fdf->next_frame;
		free(tmp);
	}
}

void	free_mlx_and_images(t_fdf_bonus *fdf)
{
	free_images(fdf);
	if (fdf && fdf->fdf && fdf->fdf->mlx_ptr)
	{
		if (fdf->fdf->win_ptr)
		{
			mlx_destroy_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr);
			fdf->fdf->win_ptr = NULL;
		}
		mlx_destroy_display(fdf->fdf->mlx_ptr);
		free(fdf->fdf->mlx_ptr);
		fdf->fdf->mlx_ptr = NULL;
	}
}

int	close_window(t_fdf_bonus *fdf)
{
	static int	first_call = 0;
	int			*video_mode_ptr;

	if (!fdf || first_call)
		exit(0);
	first_call = 1;
	video_mode_ptr = fdf->video_mode;
	free_utils(fdf->fdf);
	free_mlx_and_images(fdf);
	free_maps(fdf);
	if (video_mode_ptr)
		free(video_mode_ptr);
	exit(0);
	return (0);
}
