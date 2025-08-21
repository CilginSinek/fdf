/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:00:47 by iduman            #+#    #+#             */
/*   Updated: 2025/08/21 10:30:10 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_point;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	**map;
	t_img	*img;
	int		width;
	int		height;
	int		*scale;
	int		*offset_x;
	int		*offset_y;
	int		*rotation;
	int		*projection;
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
	t_fdf				*fdf;
	int					*video_mode; // 0 for normal, 1 for video mode
	struct s_fdf_bonus	*next_frame;
}	t_fdf_bonus;

void	free_images(t_fdf_bonus *fdf);
int		close_window(t_fdf_bonus *fdf);
int		key_press(int keycode, void *param);
int		ep(char *message, t_fdf *fdf, void **free_list, int fd);
int		append_2d_point_array(t_point ***mp_d, t_point *new_row, int height);
int		ft_get_line_length(char *line);
int		get_color(char *value);
int		get_video_color(char *value);
int		set_map_line(char *line, t_point *point,
			int y, int (*get_color)(char *));
int		read_map_file(const char *filename, t_fdf *fdf);
void	clear_frames(t_fdf_bonus **fdf);
int		create_first_frame(const char *filename, t_fdf_bonus *current_fdf,
			int *fd, char **line);
int		create_next_frame(t_fdf_bonus **current);
void	set_horizon(t_fdf_bonus *fdf);
int		read_video_file(const char *filename, t_fdf_bonus *fdf);
void	draw_map(t_fdf *fdf);
int		init_vision(t_fdf_bonus *fdf);
int		start_vision(t_fdf_bonus *fdf);
#endif