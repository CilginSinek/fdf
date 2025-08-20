/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlevision_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 08:07:08 by iduman            #+#    #+#             */
/*   Updated: 2025/08/20 16:19:17 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	init_vision(t_fdf_bonus *fdf)
{
	t_fdf_bonus	*tmp;

	tmp = fdf;
	while (tmp)
	{
		tmp->fdf->img = (t_img *)malloc(sizeof(t_img));
		if (!tmp->fdf->img)
			close_window(fdf);
		tmp->fdf->img->img = mlx_new_image(tmp->fdf->mlx_ptr, 1200, 800);
		tmp->fdf->img->addr = mlx_get_data_addr(tmp->fdf->img->img,
				&tmp->fdf->img->bits_per_pixel, &tmp->fdf->img->line_length,
				&tmp->fdf->img->endian);
		draw_map(tmp->fdf);
		tmp = tmp->next_frame;
	}
	return (1);
}

static void	animation(t_fdf_bonus *fdf, char restart)
{
	static t_fdf_bonus	*current_frame;

	if (!current_frame || restart)
		current_frame = fdf;
	mlx_clear_window(current_frame->fdf->mlx_ptr, current_frame->fdf->win_ptr);
	mlx_put_image_to_window(current_frame->fdf->mlx_ptr,
		current_frame->fdf->win_ptr, current_frame->fdf->img->img, 0, 0);
	mlx_do_sync(current_frame->fdf->mlx_ptr);
	usleep(1000000 / 15);
	if (current_frame->next_frame)
		current_frame = current_frame->next_frame;
	else
		current_frame = fdf;
}

int	start_vision(t_fdf_bonus *fdf, void *r)
{
	t_fdf_bonus	*tmp;
	char		restart;

	restart = (char)r;
	tmp = fdf;
	if (*(tmp->video_mode) == 1)
		animation(fdf, restart);
	else
	{
		mlx_clear_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr);
		mlx_put_image_to_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr,
			fdf->fdf->img->img, 0, 0);
	}
	return (0);
}
