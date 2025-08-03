#include "fdf.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void print_map(t_point **map_data, int height, int width)
{
    int i, j;

    if (!map_data) {
        printf("Map data is NULL\n");
        return;
    }

    for (i = 0; i < height; i++)
    {
        if (!map_data[i]) {
            printf("Row %d is NULL\n", i);
            continue;
        }
        
        for (j = 0; j < width; j++)
        {
            printf("(%d, %d, %d, %d) ", map_data[i][j].x, map_data[i][j].y, map_data[i][j].z, map_data[i][j].color);
        }
        printf("\n");
    }
}

int	main(int argc, char *argv[])
{
    t_fdf fdf;
    t_point **map_data;


    map_data = NULL;
    if (argc != 2)
    {
        ft_putstr_fd("Usage: ./fdf <map_file>\n", 1);
        return (1);
    }
    ft_putstr_fd("FDF project started with file: ", 1);
    ft_putendl_fd(argv[1], 1);

    if (read_map_file(argv[1], &map_data) < 0)
    {
        ft_putstr_fd("Error reading map file.\n", 2);
        return (1);
    }
    fdf.map = map_data;
    fdf.width = 10;
    fdf.height = 10;
    fdf.mlx_ptr = mlx_init();
    fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 800, 600, "FDF Window");

    if (!fdf.mlx_ptr || !fdf.win_ptr)
    {
        ft_putstr_fd("Error initializing MLX.\n", 2);
        return (1);
    }
	// X'e basınca kapansın
	mlx_hook(fdf.win_ptr, 17, 0, close_window, NULL);

	// ESC tuşuna basınca da çıkmak isterseniz
	mlx_hook(fdf.win_ptr, 2, 1L << 0, close_window, NULL);
    mlx_loop(fdf.mlx_ptr);


    // Free allocated memory for map_data
    for (int i = 0; i < 10; i++)
    {
        free(map_data[i]);
    }
    free(map_data);
    return (0);
}