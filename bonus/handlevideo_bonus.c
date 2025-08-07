#include "fdf_bonus.h"
#include "ffmpeg.h"


void delete_old_frames()
{
    int result;

    result = system("rm -rf frames");
    if (result != 0) {
        printf("Frames are not deleted or do not exist.\n");
    }
}

void create_folder()
{
    int result;

    result = system("mkdir frames");
    if (result != 0) {
        printf("Frames folder already exists.\n");
    }
}

int create_frames(const char *fp, const char *vp, int fps)
{
    int result;
    delete_old_frames();
    create_folder();

    result = system("ffmpeg -i %s -vf fps=%d frames/frame_%%04d.png", fp, fps);
    if (result != 0) {
        printf("Error creating frames with FFmpeg.\n");
        return (-1);
    }
    else 
        printf("Frames created successfully.\n");
    return 1;
}

int open_frame(int i)
{
    int fd;
    char *num_str;

    num_str = ft_itoa(i);
    if (!num_str)
		return (printf("Memory allocation failed for num_str.\n"), -1);
    char *filename = malloc(strlen(num_str) + 18);
    if (!filename) {
        printf("Memory allocation failed for filename.\n");
        return (free(num_str), -1);
    }
    strcpy(filename, "frames/frame_");
    strcat(filename, num_str);
    strcat(filename, ".png");
    free(num_str);
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        printf("Error opening frame file: %s\n", filename);
        return (free(filename), -1);
    }
    free(filename);
    return fd;
}

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

int	read_map_file(t_fdf *fdf, int fd)
{
	int		fd;
	char	*line;
	t_point	*points;

	points = NULL;
	line = get_next_line(fd);
	fdf->height = 0;
	fdf->width = ft_get_line_length(line);
	if (fdf->width == -1 || fdf->width == 0)
		return (free(line), ft_putstr_fd("Error: Invalid map file.\n", 2), -1);
	while (line != NULL)
	{
		if (read_map_while(fdf, line, fd, &points) == -1)
			return (-1);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}


/**
    * @brief Creates frames for video processing.
    * @param fp The file path for the FFmpeg.
    * @param vp The video path for the frames.
    * @param fps The frames per second for the video.
*/
int apply_frames(const char *fp, const char *vp, int fps, t_fdf_bonus *fdf)
{
    int result;
    int fd;
    int i;
    char *line;
    t_fdf_bonus *next;

    result = create_frames(fp, vp, fps);
    if (result < 0) {
        printf("Error applying frames.\n");
        exit(EXIT_FAILURE);
        return;
    }
    i = 0;
    while(1)
    {
        fd = open_frame(i);
        if (fd < 0) {
            printf("No more frames to process.\n");
            break;
        }
        if(read_map_file(fdf->fdf, fd) < 0) {
            printf("Error reading frame file.\n");
            close(fd);
            exit(EXIT_FAILURE);
        }
        next = (t_fdf_bonus *)malloc(sizeof(t_fdf_bonus));
        if (!next) {
            printf("Memory allocation failed for next frame.\n");
            close(fd);
            exit(EXIT_FAILURE);
        }
        // ilk kaç tane frame olduğunu say sonra threadler ile linked liste olması gereken sıraya ekle;
        i++;
    }
    return 1;
}