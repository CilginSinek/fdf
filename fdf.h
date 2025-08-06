/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:38:02 by iduman            #+#    #+#             */
/*   Updated: 2025/08/05 18:04:22 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_point;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	**map;
	int		width;
	int		height;
}	t_fdf;

typedef struct s_line
{
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
}	t_line;

typedef struct s_bonus_fdf
{
	t_fdf	*fdf;
	int		offset_x; // Offset for x-axis
	int		offset_y; // Offset for y-axis
	int		scale; // Scale factor for zooming
	int		angle_x; // Rotation angle around x-axis
	int		angle_y; // Rotation angle around y-axis
	int		projection; // 0 for isometric, 1 for parallel
	int		video_mode; // 0 for normal, 1 for video mode
}	t_bonus_fdf;

int		ep(char *message, t_fdf *fdf, void **free_list, int fd);
int		append_2d_point_array(t_point ***mp_d, t_point *new_row, int height);
int		ft_get_line_length(char *line);
int		get_color(char *value);
int		set_map_line(char *line, t_point *point, int y);
void	draw_map(t_fdf *fdf);

int		read_map_file(const char *filename, t_fdf *fdf);

#endif