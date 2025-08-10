/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 06:30:10 by iduman            #+#    #+#             */
/*   Updated: 2025/08/06 06:30:10 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	read_files(t_fdf_bonus *fdf, char *filename)
{
	if (ft_strstr(filename, ".fdf"))
	{
		*(fdf->video_mode) = 0;
		return (read_map_file(filename, fdf) == 1);
	}
	else if (ft_strstr(filename, ".fdfs"))
	{
		*(fdf->video_mode) = 1;
		return (read_video_file(filename, fdf) == 1);
	}
	else
	{
		free(fdf->video_mode);
		free(fdf->projection);
		return (ft_putstr_fd("Error: Unsupported file type.\n", 2), 0);
	}
}

void	init_fdf_bonus(t_fdf_bonus *fdf)
{
	fdf->fdf = NULL;
	fdf->next_frame = NULL;
	fdf->projection = malloc(sizeof(int));
	*fdf->projection = 0;
	fdf->video_mode = malloc(sizeof(int));
}

int expose_hook(t_vars *vars)
{
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	draw_map(vars);
	return (0);
}

void init_keyhooks(t_fdf_bonus *fdf)
{
	mlx_hook(fdf.win_ptr, 17, 0, close_window, &fdf);
	mlx_hook(fdf.win_ptr, 2, 1L << 0, key_press, &fdf);
	mlx_expose_hook(fdf.win_ptr, expose_hook, &fdf);
}

int	main(int argc, char *argv[])
{
	t_fdf_bonus		fdf;

	init_fdf_bonus(&fdf);
	if (argc != 2)
		return (ft_putstr_fd("Usage: ./fdf <map_file>\n", 2), 1);
	if (read_files(&fdf, argv[1]) < 0)
		return (1);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1200, 800, "FDF Window");
	if (!fdf.mlx_ptr || !fdf.win_ptr)
		return (ft_putstr_fd("Error: Failed to initialize MLX.\n", 2), 1);
	init_keyhooks(&fdf);
	draw_map(&fdf);
	mlx_loop(fdf.mlx_ptr);
	close_window(&fdf);
	return (0);
}
