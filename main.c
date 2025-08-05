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

int	close_window(t_fdf *fdf)
{
 	int	i;

	i = 0;
	while (i < fdf->height)
	{
		free(fdf->map[i]);
		i++;
	}
	free(fdf->map);
    if (fdf->mlx_ptr)
    {
        mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
        mlx_destroy_display(fdf->mlx_ptr);
        free(fdf->mlx_ptr);
    }
    exit(0);
    return (0);
}

int key_press(int keycode, void *param)
{
	t_fdf *fdf = (t_fdf *)param;

	if (keycode == 65307) // ESC tuşu (X11)
		close_window(fdf);
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
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 800, 600, "FDF Window");
	if (!fdf.mlx_ptr || !fdf.win_ptr)
		return (ft_putstr_fd("Error: Failed to initialize MLX.\n", 2), 1);
	mlx_hook(fdf.win_ptr, 17, 0, close_window, &fdf);
	mlx_hook(fdf.win_ptr, 2, 1L << 0, key_press, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
