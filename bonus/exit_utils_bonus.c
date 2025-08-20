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
		free((*fdf)->fdf->map[i++]);
	free((*fdf)->fdf->map);
	(*fdf)->fdf->map = NULL;
}

static void	free_maps(t_fdf_bonus *fdf)
{
	t_fdf_bonus	*tmp;
	t_fdf		*first_fdf;

	if (!fdf)
		return ;
	first_fdf = fdf->fdf;
	while (fdf)
	{
		if (fdf->fdf && fdf->fdf == first_fdf)
		{
			if (fdf->fdf->map)
				free_map(&fdf);
			free(fdf->fdf);
			first_fdf = NULL;
		}
		tmp = fdf;
		fdf = fdf->next_frame;
		free(tmp);
	}
}

void	free_mlx_and_images(t_fdf_bonus *fdf)
{
	t_fdf_bonus	*current;

	current = fdf;
	while (current)
	{
		if (current->fdf && current->fdf->img)
		{
			if (current->fdf->img->img && current->fdf->mlx_ptr)
			{
				mlx_destroy_image(current->fdf->mlx_ptr,
					current->fdf->img->img);
				current->fdf->img->img = NULL;
			}
			free(current->fdf->img);
			current->fdf->img = NULL;
		}
		current = current->next_frame;
	}
	if (fdf && fdf->fdf && fdf->fdf->mlx_ptr)
	{
		if (fdf->fdf->win_ptr)
			mlx_destroy_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr);
		mlx_destroy_display(fdf->fdf->mlx_ptr);
	}
}

int	close_window(t_fdf_bonus *fdf)
{
	if (!fdf)
		exit(0);
	free_utils(fdf->fdf);
	free_mlx_and_images(fdf);
	free_maps(fdf);
	if (fdf->video_mode)
		free(fdf->video_mode);
	exit(0);
	return (0);
}
