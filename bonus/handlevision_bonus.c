/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlevision_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 08:07:08 by iduman            #+#    #+#             */
/*   Updated: 2025/08/18 20:40:07 by iduman           ###   ########.fr       */
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

static void animation(t_fdf_bonus *fdf)
{
    static t_fdf_bonus *current_frame = NULL;
    
    if (!current_frame)
        current_frame = fdf;
    
    if (!current_frame->fdf || !current_frame->fdf->img || !current_frame->fdf->img->img)
    {
        printf("Error: NULL pointer in animation\n");
        return;
    }

    mlx_clear_window(current_frame->fdf->mlx_ptr, current_frame->fdf->win_ptr);
    mlx_put_image_to_window(current_frame->fdf->mlx_ptr, current_frame->fdf->win_ptr, current_frame->fdf->img->img, 0, 0);
    
    // Döngüyü doğru şekilde yönetin
    if (current_frame->next_frame)
        current_frame = current_frame->next_frame;
    else
        current_frame = fdf; // Başa dön
}

int start_vision(t_fdf_bonus *fdf)
{
    t_fdf_bonus *tmp;

    tmp = fdf;
    if (*(tmp->video_mode) == 1)
        animation(fdf);
    else
    {
        mlx_clear_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr);
        mlx_put_image_to_window(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr, fdf->fdf->img->img, 0, 0);
    }
    return (0);
}