/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:42:28 by iduman            #+#    #+#             */
/*   Updated: 2025/08/20 17:42:28 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	increase_decrease(int keycode, t_fdf_bonus *fdf)
{
	if (keycode == 61)
		*(fdf->fdf->scale) += 1;
	else if (keycode == 45)
		*(fdf->fdf->scale) -= 1;
	else if (keycode == 65)
		*(fdf->fdf->offset_x) += 1;
	else if (keycode == 68)
		*(fdf->fdf->offset_x) -= 1;
	else if (keycode == 87)
		*(fdf->fdf->offset_y) += 1;
	else if (keycode == 83)
		*(fdf->fdf->offset_y) -= 1;
	else if (keycode == 81)
	{
		*(fdf->fdf->rotation) += 1;
		if (*(fdf->fdf->rotation) > 359)
			*(fdf->fdf->rotation) = 0;
	}
	else if (keycode == 69)
	{
		*(fdf->fdf->rotation) -= 1;
		if (*(fdf->fdf->rotation) < 0)
			*(fdf->fdf->rotation) = 359;
	}
}

static int	is_workable(int keycode, int *arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
	{
		if (arr[i] == keycode)
			return (1);
		i++;
	}
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_fdf_bonus	*fdf;

	if (!param)
		return (0);
	fdf = (t_fdf_bonus *)param;
	if (keycode == 65307)
		close_window(fdf);
	if (*fdf->video_mode == 0 && is_workable(keycode,
			(int *){61, 45, 65, 68, 87, 83, 81, 69, 0}))
	{
		increase_decrease(keycode, fdf);
		mlx_clear_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr);
		init_vision(fdf);
		start_vision(fdf, (void *)1);
	}
	return (0);
}
