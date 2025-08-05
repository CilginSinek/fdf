/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:59:04 by iduman            #+#    #+#             */
/*   Updated: 2025/08/04 17:59:04 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	error_prepare(char *message, void *free_list, int free_size, int fd)
{

}



int append_2d_point_array(t_point ***map_data, t_point *new_row, int height)
{
    t_point **temp;
    int i;

    if (!*map_data)
    {
        *map_data = (t_point **)ft_calloc(1, sizeof(t_point *));
        if (!*map_data)
            return (-1);
        (*map_data)[0] = new_row;
        return (0);
    }
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
    int i;

    tmp = ft_split(line, ' ');
    if (!tmp)
        return (-1);
    length = 0;
    while (tmp[length] && tmp[length][0] != '\n')
        length++;
    i = 0;
    while(tmp[i]) // Free remaining values
    {
        free(tmp[i]);
        i++;
    }
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
    return (0xFFFFFF);
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
    i = 0;
    while (values[i]) // Free remaining values
    {
        free(values[i]);
        i++;
    }
    free(values);
    return (i); // Return number of points set
}

int read_map_file(const char *filename, fdf_t *fdf)
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
    fdf->width = i;
    while (line != NULL)
    {
        if(i != ft_get_line_length(line))
        {
            ft_putstr_fd("Error: Inconsistent line lengths in map file.\n", 2);
            if(*fdf->map)
            {
                for (int j = 0; j < y; j++)
                    free(fdf->map[j]);
                free(fdf->map);
            }
            free(line);
            close(fd);
            return (-1);
        }
        points = (t_point *)ft_calloc(i + 1, sizeof(t_point));
        if(!points)
        {
            ft_putstr_fd("Error: Memory allocation failed.\n", 2);
            if(*fdf->map)
            {
                for (int j = 0; j < y; j++)
                    free(fdf->map[j]);
                free(fdf->map);
            }
            free(line);
            close(fd);
            return (-1);
        }
        if(set_map_line(line, points, y) == -1)
        {
            ft_putstr_fd("Error: Failed to set map line.\n", 2);
            free(points);
            if(*fdf->map)
            {
                for (int j = 0; j < y; j++)
                    free(fdf->map[j]);
                free(fdf->map);
            }
            free(line);
            close(fd);
            return (-1);
        }
        free(line);
        if(append_2d_point_array(&(fdf->map), points, y) == -1)
        {
            ft_putstr_fd("Error: Failed to append to map data.\n", 2);
            free(points);
            if(*fdf->map)
            {
                for (int j = 0; j < y; j++)
                    free(fdf->map[j]);
                free(fdf->map);
            }
            close(fd);
            return (-1);
        }
        y++;
        line = get_next_line(fd);
    }
    fdf->height = y;
    close(fd);
    return (0);
}

//* En son free kısımlarını otomatik fonksiyon olarak yazacaktım