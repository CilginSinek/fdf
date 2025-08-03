#include "fdf.h"

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
    //print_map(map_data, 10, 10);
    // Free allocated memory for map_data
    for (int i = 0; i < 10; i++)
    {
        free(map_data[i]);
    }
    free(map_data);
    return (0);
}