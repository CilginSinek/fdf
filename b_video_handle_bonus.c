#include "b_fdf_bonus.h"

//* kopya özellikleri ana framedeki adreslerden geçireceğim;
void set_next_frame(t_fdf_bonus **fdf, t_fdf_bonus *next_frame)
{
    (*fdf)->next_frame = next_frame;
    next_frame->next_frame = NULL;
    next_frame->projection = (*fdf)->projection;
    next_frame->video_mode = (*fdf)->video_mode;
}

t_fdf_bonus *create_next_frame(t_fdf_bonus **fdf)
{
    t_fdf_bonus *new_frame;

    new_frame = (t_fdf_bonus *)calloc(1, sizeof(t_fdf_bonus));
    if (!new_frame)
    {
        //* free all allocated memory before exiting
        ft_putstr_fd("Error: Memory allocation failed.\n", 2);
        exit(EXIT_FAILURE);
    }
    (*fdf)->next_frame = new_frame;
    new_frame->next_frame = NULL;
    new_frame->projection = (*fdf)->projection;
    new_frame->video_mode = (*fdf)->video_mode;
    *new_frame->fdf->mlx_ptr = *(*fdf)->fdf->mlx_ptr;
    *new_frame->fdf->win_ptr = *(*fdf)->fdf->win_ptr;
    new_frame->fdf->width = (*fdf)->fdf->width;
    new_frame->fdf->height = 0;
    new_frame->fdf->offset_x = (*fdf)->fdf->offset_x;
    new_frame->fdf->offset_y = (*fdf)->fdf->offset_y;
    new_frame->fdf->scale = (*fdf)->fdf->scale;
    return (new_frame);
}

// build for video mode
// need modify ep function
static int	read_map_while(t_fdf *fdf, char *line, int fd, t_point **points)
{
	if (fdf->width != ft_get_line_length(line))
		return (ep("Error: Incorrect line lengths in map file.\n",
				fdf, (void *[]){points, line}, fd));
	*points = (t_point *)ft_calloc(fdf->width + 1, sizeof(t_point));
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

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (ft_putstr_fd("Error: Could not open video file.\n", 2), -1);
    line = get_next_line(fd);
    if (!line)
        return (ft_putstr_fd("Error: Empty video file.\n", 2), -1);
    fdf->fdf->width = ft_get_line_length(line);
    if (fdf->fdf->width <= 0)
        return (free(line), ft_putstr_fd("Error: Invalid video file format.\n", 2), -1);
    fdf->fdf->height = 0;
    while (line)
    {
        if(ft_strchr(line, '-') != NULL)
        {
            create_next_frame(&fdf);
            fdf = fdf->next_frame;
            line = get_next_line(fd);
            continue;
        }
        if(read_map_while(fdf->fdf, line, fd, &fdf->fdf->map[fdf->fdf->height]) == -1)
            return (-1);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}