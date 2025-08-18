#include "fdf_bonus.h"

void    clear_frames(t_fdf_bonus **fdf)
{
    t_fdf_bonus *tmp;
    int i;

    while (*fdf)
    {
        i = 0;
        tmp = *fdf;
        *fdf = (*fdf)->next_frame;
        if (tmp->fdf)
        {
            if (tmp->fdf->map)
            {
                while (i < tmp->fdf->height)
                    free(tmp->fdf->map[i++]);
                free(tmp->fdf->map);
            }
            free(tmp->fdf);
        }
        free(tmp);
    }
}

int create_next_frame(t_fdf_bonus **current)
{
    t_fdf_bonus *new_frame;

    new_frame = (t_fdf_bonus *)calloc(1, sizeof(t_fdf_bonus));
    if (!new_frame)
        return (-1);
    (*current)->next_frame = new_frame;
    new_frame->next_frame = NULL;
    new_frame->projection = (*current)->projection;
    new_frame->video_mode = (*current)->video_mode;

    // Allocate memory for the fdf struct inside new_frame
    new_frame->fdf = (t_fdf *)calloc(1, sizeof(t_fdf));
    if (!new_frame->fdf)
        return (-1);
    new_frame->fdf->mlx_ptr = (*current)->fdf->mlx_ptr;
    new_frame->fdf->win_ptr = (*current)->fdf->win_ptr;
    new_frame->fdf->width = (*current)->fdf->width;
    new_frame->fdf->height = 0;
    new_frame->fdf->offset_x = (*current)->fdf->offset_x;
    new_frame->fdf->offset_y = (*current)->fdf->offset_y;
    new_frame->fdf->scale = (*current)->fdf->scale;
    new_frame->fdf->rotation = (*current)->fdf->rotation;
    *current = new_frame;
    return (0);
}

// build for video mode
// need modify ep function
static int	read_map_while(t_fdf *fdf, char *line, int fd, t_point **points)
{

	if (fdf->width != ft_get_line_length(line))
		return (ep("Error: Incorrect line lengths in map file.\n",
				fdf, (void *[]){points, line}, fd));
	*points = (t_point *)calloc(fdf->width + 1, sizeof(t_point));
	if (!*points)
		return (ep("Error: Memory allocation failed.\n",
				fdf, (void *[]){NULL, line}, fd));
	if (set_map_line(line, *points, fdf->height) == -1)
		return (ep("Error: Failed to set map line.\n",
				fdf, (void *[]){*points, line}, fd));
	free(line);
	if (append_2d_point_array(&(fdf->map), *points, fdf->height) == -1)
		return (ep("Error: Failed to append to map data.\n",
				fdf, (void *[]){*points, NULL}, fd));
	fdf->height++;
	return (0);
}


int read_video_file(const char *filename, t_fdf_bonus *fdf)
{
    int fd;
    char *line;
    t_point *tmp;
    t_fdf_bonus *current_fdf;
    int i = 1;

    current_fdf = fdf;
    tmp = NULL;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (ft_putstr_fd("Error: Could not open video file.\n", 2), -1);
    line = get_next_line(fd);
    if (!line)
        return (ft_putstr_fd("Error: Empty video file.\n", 2), -1);
    current_fdf->fdf->width = ft_get_line_length(line);
    if (current_fdf->fdf->width <= 0)
        return (free(line), ft_putstr_fd("Error: Invalid video file format.\n", 2), -1);
    current_fdf->fdf->height = 0;
    while (line)
    {
        if (ft_strchr_f(line, '-') != NULL)
        {
            printf("frame %i\n", i++);
            if (create_next_frame(&current_fdf) < 0)
            {
                clear_frames(&fdf);
                ep("Error: Memory allocation failed.\n", NULL, (void *[]){tmp, line}, fd);
            }
            line = get_next_line(fd);
            continue ;
        }
        if (read_map_while(current_fdf->fdf, line, fd, &tmp) == -1)
            return (clear_frames(&fdf), -1);

        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}