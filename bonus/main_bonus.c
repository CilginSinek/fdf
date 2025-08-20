/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 06:30:10 by iduman            #+#    #+#             */
/*   Updated: 2025/08/20 16:15:31 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	read_files(t_fdf_bonus *fdf, const char *filename)
{
	if (strstr(filename, ".fdfs") != NULL)
	{
		*(fdf->video_mode) = 1;
		if (read_video_file(filename, fdf) != 0)
			return (close_window(fdf), 0);
		return (1);
	}
	else if (strstr(filename, ".fdf") != NULL)
	{
		*(fdf->video_mode) = 0;
		if (read_map_file(filename, fdf->fdf) == 1)
			return (close_window(fdf), 0);
		return (1);
	}
	else
	{
		ft_putstr_fd("Error: Unsupported file type.\n", 2);
		return (close_window(fdf), 0);
	}
}

void	init_fdf_bonus(t_fdf_bonus *fdf)
{
	fdf->fdf->height = 0;
	fdf->fdf->width = 0;
	fdf->fdf->rotation = ft_calloc(1, sizeof(int));
	fdf->next_frame = NULL;
	fdf->fdf->projection = ft_calloc(1, sizeof(int));
	fdf->video_mode = ft_calloc(1, sizeof(int));
	fdf->fdf->rotation = ft_calloc(1, sizeof(int));
	fdf->fdf->offset_x = ft_calloc(1, sizeof(int));
	fdf->fdf->offset_y = ft_calloc(1, sizeof(int));
	fdf->fdf->scale = ft_calloc(1, sizeof(int));
	if (!fdf->fdf->projection || !fdf->video_mode || !fdf->fdf->rotation
		|| !fdf->fdf->offset_x || !fdf->fdf->offset_y || !fdf->fdf->scale)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", 2);
		close_window(fdf);
	}
	*(fdf->fdf->offset_x) = 400;
	*(fdf->fdf->offset_y) = 300;
	*(fdf->fdf->rotation) = 0;
	*(fdf->fdf->scale) = 1;
	*(fdf->fdf->projection) = 0;
	*(fdf->video_mode) = 0;
}

static int	expose_hook(t_fdf_bonus *vars)
{
	mlx_clear_window(vars->fdf->mlx_ptr, vars->fdf->win_ptr);
	init_vision(vars);
	start_vision(vars, (void *)1);
	return (0);
}

void	init_keyhooks(t_fdf_bonus *fdf)
{
	mlx_hook(fdf->fdf->win_ptr, 17, 0, close_window, fdf);
	mlx_hook(fdf->fdf->win_ptr, 2, 1L << 0, key_press, fdf);
	mlx_expose_hook(fdf->fdf->win_ptr, expose_hook, fdf);
}

int	main(int argc, char *argv[])
{
	t_fdf_bonus		*fdf;

	if (argc != 2)
		return (ft_putstr_fd("Usage: ./fdf <map_file>\n", 2), 1);
	fdf = ft_calloc(1, sizeof(t_fdf_bonus));
	if (!fdf)
		return (ft_putstr_fd("Error: Memory allocation failed.\n", 2), 1);
	fdf->fdf = ft_calloc(1, sizeof(t_fdf));
	if (!fdf->fdf)
		return (ft_putstr_fd("Error: Memory allocation failed.\n", 2), 1);
	fdf->fdf->mlx_ptr = mlx_init();
	fdf->fdf->win_ptr = mlx_new_window(fdf->fdf->mlx_ptr,
			1200, 800, "FDF Window");
	if (!fdf->fdf->mlx_ptr || !fdf->fdf->win_ptr)
		return (ft_putstr_fd("Error: Failed to initialize MLX.\n", 2), 1);
	init_fdf_bonus(fdf);
	if (read_files(fdf, argv[1]) < 0)
		return (1);
	init_keyhooks(fdf);
	set_horizon(fdf);
	init_vision(fdf);
	mlx_loop_hook(fdf->fdf->mlx_ptr, start_vision, fdf);
	mlx_loop(fdf->fdf->mlx_ptr);
	close_window(fdf);
	return (0);
}
