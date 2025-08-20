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

int	read_files(t_fdf_bonus *fdf,const char *filename)
{
	if (strstr(filename, ".fdfs") != NULL)
	{
		*(fdf->video_mode) = 1;
		if (read_video_file(filename, fdf) != 0)
		{
			free(fdf->fdf), free(fdf->video_mode), free(fdf->projection);
			return (0);
		}
		return (1);
	}
	else if (strstr(filename, ".fdf") != NULL)
	{
		*(fdf->video_mode) = 0;
		if(read_map_file(filename, fdf->fdf) == 1)
		{
			free(fdf->fdf), free(fdf->video_mode), free(fdf->projection);
			return (0);
		}
		return (1);
	}
	else
	{
		free(fdf->fdf);
		free(fdf->fdf->offset_x);
		free(fdf->fdf->offset_y);
		free(fdf->fdf->scale);
		free(fdf->fdf->rotation);
		free(fdf->video_mode);
		free(fdf->projection);
		return (ft_putstr_fd("Error: Unsupported file type.\n", 2), 0);
	}
}

//* rotation scale ve offsetler için calloc acılıp leak kontrolü yapılmalı
void	init_fdf_bonus(t_fdf_bonus *fdf)
{
    fdf->fdf->height = 0;
    fdf->fdf->width = 0;
	fdf->fdf->rotation = calloc(1, sizeof(int));
    fdf->next_frame = NULL;

    fdf->projection = calloc(1, sizeof(int));
    fdf->video_mode = calloc(1, sizeof(int));
	fdf->fdf->rotation = calloc(1, sizeof(int));
	fdf->fdf->offset_x = calloc(1, sizeof(int));
	fdf->fdf->offset_y = calloc(1, sizeof(int));
	fdf->fdf->scale = calloc(1, sizeof(int));
	if (!fdf->projection || !fdf->video_mode || !fdf->fdf->rotation || !fdf->fdf->offset_x || !fdf->fdf->offset_y || !fdf->fdf->scale)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", 2);
		if(fdf->projection)
			free(fdf->projection);
		if(fdf->video_mode)
			free(fdf->video_mode);
		if(fdf->fdf->rotation)
			free(fdf->fdf->rotation);
		if(fdf->fdf->offset_x)
			free(fdf->fdf->offset_x);
		if(fdf->fdf->offset_y)
			free(fdf->fdf->offset_y);
		if(fdf->fdf->scale)
			free(fdf->fdf->scale);
		free(fdf->fdf);
		exit(EXIT_FAILURE);
	}
	*(fdf->fdf->offset_x) = 400;
	*(fdf->fdf->offset_y) = 300;
	*(fdf->fdf->rotation) = 0;
	*(fdf->fdf->scale) = 1;
	*(fdf->projection) = 0;
	*(fdf->video_mode) = 0;
}

static int expose_hook(t_fdf_bonus *vars)
{
	mlx_clear_window(vars->fdf->mlx_ptr, vars->fdf->win_ptr);
	init_vision(vars);
	start_vision(vars);
	return (0);
}

void init_keyhooks(t_fdf_bonus *fdf)
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
	fdf = calloc(1, sizeof(t_fdf_bonus));
	if (!fdf)
		return (ft_putstr_fd("Error: Memory allocation failed.\n", 2), 1);
	fdf->fdf = calloc(1, sizeof(t_fdf));
	if (!fdf->fdf)
		return (ft_putstr_fd("Error: Memory allocation failed.\n", 2), 1);
	fdf->fdf->mlx_ptr = mlx_init();
	fdf->fdf->win_ptr = mlx_new_window(fdf->fdf->mlx_ptr, 1200, 800, "FDF Window");
	if (!fdf->fdf->mlx_ptr || !fdf->fdf->win_ptr)
		return (ft_putstr_fd("Error: Failed to initialize MLX.\n", 2), 1);
	mlx_string_put(fdf->fdf->mlx_ptr, fdf->fdf->win_ptr, 50, 50, 0xFFFFFF, "Loading...");
	init_fdf_bonus(fdf);
	if (read_files(fdf, argv[1]) < 0)
		return (1);
	init_keyhooks(fdf);
	printf("main1\n");
	set_horizon(fdf);
	init_vision(fdf);
	printf("main2\n");
	mlx_loop_hook(fdf->fdf->mlx_ptr, start_vision, fdf);
	printf("main3\n");
	mlx_loop(fdf->fdf->mlx_ptr);
	close_window(fdf);

	return (0);
}
