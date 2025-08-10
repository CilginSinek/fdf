/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:59:08 by iduman            #+#    #+#             */
/*   Updated: 2025/08/05 18:15:34 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int expose_hook(t_vars *vars)
{
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	draw_map(vars);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf		fdf;

	fdf.map = NULL;
	if (argc != 2)
		return (ft_putstr_fd("Usage: ./fdf <map_file>\n", 2), 1);
	if (read_map_file(argv[1], &fdf) < 0)
		return (1);
	//set_horizon(&fdf);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1200, 800, "FDF Window");
	if (!fdf.mlx_ptr || !fdf.win_ptr)
		return (ft_putstr_fd("Error: Failed to initialize MLX.\n", 2), 1);
	mlx_hook(fdf.win_ptr, 17, 0, close_window, &fdf);
	mlx_hook(fdf.win_ptr, 2, 1L << 0, key_press, &fdf);
	mlx_expose_hook(fdf.win_ptr, expose_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);
	close_window(&fdf);
	return (0);
}
