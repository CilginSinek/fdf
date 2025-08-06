#include "fdf.h"

void	free_map(t_fdf *fdf)
{
	int		i;

	if (fdf->map)
	{
		i = 0;
		while (i < fdf->height)
		{
			free(fdf->map[i]);
			i++;
		}
		free(fdf->map);
		fdf->map = NULL;
	}
}

void	free_mlx(t_fdf *fdf)
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

int	close_window(t_fdf *fdf)
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