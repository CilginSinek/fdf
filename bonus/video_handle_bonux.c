#include "fdf_bonus.h"

//* kopya özellikleri ana framedeki adreslerden geçireceğim;
void set_next_frame(t_fdf_bonus **fdf, t_fdf_bonus *next_frame)
{
    (*fdf)->next_frame = next_frame;
    next_frame->next_frame = NULL;

}


int read_video_file(char *filename, t_fdf_bonus *fdf)
{

    return (0);
}