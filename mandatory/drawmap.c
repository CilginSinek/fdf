/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 06:11:00 by iduman            #+#    #+#             */
/*   Updated: 2025/08/16 15:55:10 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel_to_image(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1200 || y < 0 || y >= 800)
		return ;
	dst = fdf->img->addr + (y * fdf->img->line_length + x * (
				fdf->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_line(t_point p1, t_point p2, t_fdf *fdf)
{
	int			steps;
	t_line		l;
	int			i;

	if ((abs(p2.x - p1.x) > abs(p2.y - p1.y)))
		steps = abs(p2.x - p1.x);
	else
		steps = abs(p2.y - p1.y);
	l.x = p1.x;
	l.y = p1.y;
	l.x_inc = (p2.x - p1.x) / (float)steps;
	l.y_inc = (p2.y - p1.y) / (float)steps;
	i = 0;
	while (i < steps)
	{
		if (l.x < 0 || l.x >= 1200 || l.y < 0 || l.y >= 800)
			return ;
		put_pixel_to_image(fdf, (int)l.x, (int)l.y, p1.color);
		l.x += l.x_inc;
		l.y += l.y_inc;
		i++;
	}
}

static t_point	project_point(t_point point, t_fdf *fdf)
{
	t_point	projected;

	projected.x = (point.x - point.y) * cos(30 * (M_PI / 180)
			) * fdf->scale + fdf->offset_x;
	projected.y = ((point.x + point.y) * sin(30 * (M_PI / 180)
				) - point.z) * fdf->scale + fdf->offset_y;
	projected.z = point.z;
	projected.color = point.color;
	return (projected);
}

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	p;

	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			p = project_point(fdf->map[y][x], fdf);
			put_pixel_to_image(fdf, p.x, p.y, p.color);
			if (x < fdf->width - 1)
				draw_line(project_point(fdf->map[y][x], fdf),
					project_point(fdf->map[y][x + 1], fdf), fdf);
			if (y < fdf->height - 1)
				draw_line(project_point(fdf->map[y][x], fdf),
					project_point(fdf->map[y + 1][x], fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->img, 0, 0);
}
