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

#include "fdf.h"

int	read_files(t_fdf *fdf, char *filename)
{
	if (ft_strstr(filename, ".fdf"))
		return (read_map_file(filename, fdf), 1);
	else if (ft_strstr(filename, ".fdfs"))
		return (read_video_file(filename, fdf), 1);
	else
		return (ft_putstr_fd("Error: Unsupported file type.\n", 2), 0);
}

int	main(int argc, char *argv[])
{
	t_fdf		fdf;

	fdf.map = NULL;
	if (argc != 2)
		return (ft_putstr_fd("Usage: ./fdf <map_file>\n", 2), 1);
    // if file type is not .fdf and its .fdfs exec other read_map_file function for video
	if (read_files(&fdf, argv[1]) < 0)
		return (1);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1200, 800, "FDF Window");
	if (!fdf.mlx_ptr || !fdf.win_ptr)
		return (ft_putstr_fd("Error: Failed to initialize MLX.\n", 2), 1);
	mlx_hook(fdf.win_ptr, 17, 0, close_window, &fdf);
	mlx_hook(fdf.win_ptr, 2, 1L << 0, key_press, &fdf);
	draw_map(&fdf);
	mlx_loop(fdf.mlx_ptr);
	close_window(&fdf);
	return (0);
}
