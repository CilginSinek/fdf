/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:07:27 by iduman            #+#    #+#             */
/*   Updated: 2025/08/21 09:07:44 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_images(t_fdf_bonus *fdf)
{
	while (fdf)
	{
		if (fdf->fdf && fdf->fdf->img)
		{
			if (fdf->fdf->img->img && fdf->fdf->mlx_ptr)
			{
				mlx_destroy_image(fdf->fdf->mlx_ptr,
					fdf->fdf->img->img);
				fdf->fdf->img->img = NULL;
			}
			free(fdf->fdf->img);
			fdf->fdf->img = NULL;
		}
		fdf = fdf->next_frame;
	}
}
