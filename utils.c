#include "fdf.h"

// int close_window(t_fdf *fdf)
// {
//     if (fdf->win_ptr)
//     {
//         mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
//         fdf->win_ptr = NULL;
//     }
//     return (0);
// }

int append_2d_point_array(t_point ***map_data, t_point *new_row, int height)
{
    t_point **temp;
    int i;

    temp = (t_point **)ft_calloc((height + 1), sizeof(t_point *));
    if (!temp)
        return (-1);
    
    for (i = 0; i < height; i++)
        temp[i] = (*map_data)[i];

    temp[height] = new_row;
    free(*map_data);
    *map_data = temp;
    return (0);
}

int ft_get_line_length(char *line)
{
    char **tmp;
    int length;

    tmp = ft_split(line, ' ');
    if (!tmp)
        return (-1);
    length = 0;
    while (tmp[length] && tmp[length][0] != '\n')
        length++;
    free(tmp);
    return (length);
}

int get_color(char *value)
{
    if(ft_strchr(value, ','))
    {
        char *color_str = ft_strchr(value, ',') + 1;
        return (ft_atoi_base(color_str, "0123456789ABCDEF"));
    }
    return (0xFFFFFF); // Default color if no color specified
}

int set_map_line(char *line, t_point *point, int y)
{
    char **values;
    int i;

    values = ft_split(line, ' ');
    if (!values)
        return (-1);

    i = 0;
    while (values[i])
    {
        point[i].x = i; // Assuming x is the index
        point[i].y = y;
        point[i].z = ft_atoi(values[i]);
        point[i].color = get_color(values[i]); // Default color, can be changed later
        i++;
    }
    free(values);
    return (i); // Return number of points set
}

int read_map_file(const char *filename, t_point ***map_data)
{
    int fd;
    char *line;
    t_point *points;
    int i;
    int y;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    y = 0;
    line = get_next_line(fd);
    i = ft_get_line_length(line);
    while (line != NULL)
    {
        if(i != ft_get_line_length(line))
        {
            ft_putstr_fd("Error: Inconsistent line lengths in map file.\n", 2);
            free(line);
            close(fd);
            return (-1);
        }
        printf("Line %d: %s, length=%d\n", y, line, ft_get_line_length(line));
        points = (t_point *)ft_calloc(i + 1, sizeof(t_point));
        set_map_line(line, points, y);
        append_2d_point_array(map_data, points, y);
        for (int j = 0; j < i; j++)
            printf("Point[%d][%d]: x=%d, y=%d, z=%d, color=0x%X\n", y, j, points[j].x, points[j].y, points[j].z, points[j].color);
        free(line);
        y++;
        line = get_next_line(fd);
        printf("Next line read: %s\n", line == NULL ? "NULL" : line);
    }
    close(fd);
    return (0);
}

