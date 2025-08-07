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
	int		scale;
	int		offset_x;
	int		offset_y;
}	t_fdf;

typedef struct s_line
{
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
}	t_line;



void	free_map(t_fdf *fdf);
void	free_mlx(t_fdf *fdf);
int		close_window(t_fdf *fdf);
int		key_press(int keycode, void *param);

//void	set_horizon(t_fdf *fdf);
int		ep(char *message, t_fdf *fdf, void **free_list, int fd);
int		append_2d_point_array(t_point ***mp_d, t_point *new_row, int height);
int		ft_get_line_length(char *line);
int		get_color(char *value);
int		set_map_line(char *line, t_point *point, int y);
void	draw_map(t_fdf *fdf);

int		read_map_file(const char *filename, t_fdf *fdf);

#endif