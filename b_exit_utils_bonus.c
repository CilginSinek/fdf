void	free_maps(t_fdf_bonus *fdf)
{
	t_fdf_bonus *tmp;
    int i;

    i = 0;
	tmp = fdf;
	while (tmp)
	{
		if (tmp->fdf->map)
		{
			while (i < tmp->fdf->height)
			{
				free(tmp->fdf->map[i]);
				i++;
			}
			free(tmp->fdf->map);
			tmp->fdf->map = NULL;
		}
        if (tmp->fdf->img)
		{
			mlx_destroy_image(tmp->fdf->mlx_ptr, tmp->fdf->img->img);
			free(tmp->fdf->img);
			tmp->fdf->img = NULL;
		}
		tmp = tmp->next_frame;
	}
}

void	free_mlx(t_fdf_bonus *fdf)
{
	if (fdf->mlx_ptr)
	{
		if (fdf->win_ptr)
			mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
		fdf->mlx_ptr = NULL;
		fdf->win_ptr = NULL;
	}
}

int	close_window(t_fdf_bonus *fdf)
{
	free_map(fdf);
	free_mlx(fdf);
	exit(0);
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_fdf	*fdf;

	if (!param)
		return (0);
	fdf = (t_fdf *)param;
	if (keycode == 65307)
		close_window(fdf);
	return (0);
}
