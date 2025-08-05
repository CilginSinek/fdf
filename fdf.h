/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:38:02 by iduman            #+#    #+#             */
/*   Updated: 2025/08/04 17:38:02 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
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

int	read_map_file(const char *filename, t_point ***map_data);

#endif