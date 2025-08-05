/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:59:08 by iduman            #+#    #+#             */
/*   Updated: 2025/08/04 17:59:08 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_point **map_data, int height)
{
	int	i;

	i = 0;
	while(i < height)
	{
		free(map_data[i]);
		i++;
	}
	free(map_data);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf		fdf;

	fdf.map = NULL;
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <map_file>\n", 2);
		return (1);
	}
	if (read_map_file(argv[1], &fdf) < 0)
		return (1);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 800, 600, "FDF Window");
	if (!fdf.mlx_ptr || !fdf.win_ptr)
	{
		ft_putstr_fd("Error initializing MLX.\n", 2);
		return (1);
	}
	mlx_hook(fdf.win_ptr, 17, 0, close_window, NULL);
	mlx_hook(fdf.win_ptr, 2, 1L << 0, close_window, NULL);
	mlx_loop(fdf.mlx_ptr);
    return (0);
}