/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 06:11:00 by iduman            #+#    #+#             */
/*   Updated: 2025/08/06 06:11:00 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Implement Bresenham's line algorithm or similar to draw a line between p1 and p2
// This function should use the mlx_pixel_put or similar function to draw pixels on the window
// For simplicity, this is a placeholder implementation
static void	draw_line(t_point p1, t_point p2, t_fdf *fdf)
{
	int			steps;
	t_line		l;
	int			i;

	if ((abs(p2.x - p1.x) > abs(p2.y - p1.y)))
		steps = abs(p2.x - p1.x);
	else
		steps = abs(p2.y - p1.y);
	if (steps == 0)
		return ;
	l.x = p1.x;
	l.y = p1.y;
	l.x_inc = (p2.x - p1.x) / (float)steps;
	l.y_inc = (p2.y - p1.y) / (float)steps;
	i = 0;
	while (i < steps)
	{
		if (l.x < 0 || l.x >= 1200 || l.y < 0 || l.y >= 800)
			return ;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)l.x, (int)l.y, p1.color);
		l.x += l.x_inc;
		l.y += l.y_inc;
		i++;
	}
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			draw_line(fdf->map[y][x], fdf->map[y][x + 1], fdf);
			draw_line(fdf->map[y][x], fdf->map[y + 1][x], fdf);
			x++;
		}
		y++;
	}
}
