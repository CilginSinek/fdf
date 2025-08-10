/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:00:47 by iduman            #+#    #+#             */
/*   Updated: 2025/08/10 20:47:42 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <string.h>

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_point;

typedef struct s_fdf
{
	void	**mlx_ptr;
	void	**win_ptr;
	t_point	**map;
	int		width;
	int		height;
	int		*scale;
	int		*offset_x;
	int		*offset_y;
	int		*rotation;
}	t_fdf;

typedef struct s_line
{
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
}	t_line;

typedef struct s_fdf_bonus
{
	t_fdf	*fdf;
	int		*projection; // 0 for isometric, 1 for parallel
	int		*video_mode; // 0 for normal, 1 for video mode
    struct s_fdf_bonus	*next_frame;
}	t_fdf_bonus;

int		ep(char *message, t_fdf *fdf, void **free_list, int fd);
int		append_2d_point_array(t_point ***mp_d, t_point *new_row, int height);
int		ft_get_line_length(char *line);
int		get_color(char *value);
int		set_map_line(char *line, t_point *point, int y);
int		read_map_file(const char *filename, t_fdf *fdf);
int read_video_file(const char *filename, t_fdf_bonus *fdf);
#endif