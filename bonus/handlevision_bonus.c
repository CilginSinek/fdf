/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_handlevision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 08:07:08 by iduman            #+#    #+#             */
/*   Updated: 2025/08/15 08:07:08 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int    init_vision(t_fdf_bonus *fdf)
{
    t_fdf_bonus *tmp;

    tmp = fdf;
    while(tmp)
    {
        tmp->fdf->img = (t_img *)malloc(sizeof(t_img));
        // recursive clear leak function
        if (!tmp->fdf->img)
            return (-1);
        tmp->fdf->img->img = mlx_new_image(tmp->fdf->mlx_ptr, 1200, 800);
        tmp->fdf->img->addr = mlx_get_data_addr(tmp->fdf->img->img,
                &tmp->fdf->img->bits_per_pixel, &tmp->fdf->img->line_length,
                &tmp->fdf->img->endian);
        draw_map(tmp->fdf);
        tmp = tmp->next_frame;
    }
    return (1);
}

int rehandle_vision(t_fdf_bonus *fdf)
{
    t_fdf_bonus *tmp;

    tmp = fdf;
    while (tmp)
    {
        if (tmp->fdf->img)
        {
            mlx_destroy_image(tmp->fdf->mlx_ptr, tmp->fdf->img->img);
            tmp->fdf->img->img = mlx_new_image(tmp->fdf->mlx_ptr, 1200, 800);
            tmp->fdf->img->addr = mlx_get_data_addr(tmp->fdf->img->img,
                    &tmp->fdf->img->bits_per_pixel, &tmp->fdf->img->line_length,
                    &tmp->fdf->img->endian);
            draw_map(tmp->fdf);
        }
        tmp = tmp->next_frame;
    }
    return (1);
}

int start_vision(t_fdf_bonus *fdf)
{
    t_fdf_bonus *tmp;

    tmp = fdf;
    if(*fdf->video_mode == 1)
    {
        while (tmp != NULL)
        {
            mlx_clear_window(tmp->fdf->mlx_ptr, tmp->fdf->win_ptr);
            mlx_put_image_to_window(tmp->fdf->mlx_ptr, tmp->fdf->win_ptr, tmp->fdf->img->img, 0, 0);
            tmp = tmp->next_frame;
            usleep(66667);
            if(tmp == NULL)
                tmp = fdf;
        }
    }
    else
    {
        mlx_clear_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr);
        mlx_put_image_to_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr, fdf->fdf->img->img, 0, 0);
    }
    return (1);
}