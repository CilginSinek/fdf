/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:42:28 by iduman            #+#    #+#             */
/*   Updated: 2025/08/21 09:08:38 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	increase_decrease(int keycode, t_fdf_bonus *fdf)
{
	if (keycode == 65451)
		*(fdf->fdf->scale) += 1;
	else if (keycode == 65453)
		*(fdf->fdf->scale) -= 1;
	else if (keycode == 97)
		*(fdf->fdf->offset_x) += 1;
	else if (keycode == 100)
		*(fdf->fdf->offset_x) -= 1;
	else if (keycode == 115)
		*(fdf->fdf->offset_y) += 1;
	else if (keycode == 119)
		*(fdf->fdf->offset_y) -= 1;
	else if (keycode == 113)
		*(fdf->fdf->rotation) += 1;
	else if (keycode == 101)
		*(fdf->fdf->rotation) -= 1;
	else if (keycode == 112)
		*(fdf->fdf->projection) = !*(fdf->fdf->projection);
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
			(int []){65451, 65453, 97, 100, 115, 119, 113, 101, 112}))
	{
		increase_decrease(keycode, fdf);
		mlx_clear_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr);
		init_vision(fdf);
		start_vision(fdf, (void *)1);
	}
	return (0);
}
