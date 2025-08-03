#ifndef FDF_H
#define FDF_H

#include "minilibx-linux/mlx.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include <stdio.h>

typedef struct s_fdf
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     **map;
    int     width;
    int     height;
}   t_fdf;

typedef struct s_point
{
    int x;
    int y;
    int z;
    unsigned int color;
}   t_point;

int read_map_file(const char *filename, t_point ***map_data);

#endif