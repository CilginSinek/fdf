/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:00:47 by iduman            #+#    #+#             */
/*   Updated: 2025/08/06 21:00:47 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUX_H
# define FDF_BONUX_H
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>

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
	int		*scale;
	int		*offset_x;
	int		*offset_y;
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




#endif