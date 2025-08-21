/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 06:30:10 by iduman            #+#    #+#             */
/*   Updated: 2025/08/21 09:09:59 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	read_files(t_fdf_bonus *fdf, const char *filename)
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

static void	init_fdf_bonus(t_fdf_bonus *fdf, int p)
{
	fdf->fdf->height = 0;
	fdf->fdf->width = 0;
	fdf->fdf->rotation = ft_calloc(1, sizeof(int));
	fdf->next_frame = NULL;
	fdf->fdf->projection = ft_calloc(1, sizeof(int));
	fdf->video_mode = ft_calloc(1, sizeof(int));
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
	*(fdf->fdf->projection) = p;
	*(fdf->video_mode) = 0;
	mlx_string_put(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr,
		600, 400, 0xFFFFFF, "Loading...");
}

static int	expose_hook(t_fdf_bonus *vars)
{
	mlx_clear_window(vars->fdf->mlx_ptr, vars->fdf->win_ptr);
	init_vision(vars);
	if (*(vars->video_mode) == 0)
		start_vision(vars, (void *)1);
	return (0);
}

static void	init_keyhooks_system(t_fdf_bonus *fdf)
{
	mlx_hook(fdf->fdf->win_ptr, 17, 0, close_window, fdf);
	mlx_hook(fdf->fdf->win_ptr, 2, 1L << 0, key_press, fdf);
	mlx_expose_hook(fdf->fdf->win_ptr, expose_hook, fdf);
	set_horizon(fdf);
	init_vision(fdf);
	if (*(fdf->video_mode) == 1)
		mlx_loop_hook(fdf->fdf->mlx_ptr, start_vision, fdf);
	else
		start_vision(fdf, (void *)1);
}

int	main(int argc, char *argv[])
{
	t_fdf_bonus		*fdf;

	if (argc != 2 && argc != 3)
		return (ft_putstr_fd("Usage: ./fdf <map_file> <projection>\n", 2), 1);
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
	if (argc == 3)
		init_fdf_bonus(fdf, ft_atoi(argv[2]));
	else
		init_fdf_bonus(fdf, 0);
	if (read_files(fdf, argv[1]) < 0)
		return (1);
	init_keyhooks_system(fdf);
	mlx_loop(fdf->fdf->mlx_ptr);
	close_window(fdf);
	return (0);
}
