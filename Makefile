NAME=fdf
NAME_BONUS=fdf_bonus
SRC= main.c utils.c filehandler.c drawmap.c exit_utils.c
SRC_BONUS= b_main_bonus.c b_video_handle_bonus.c b_map_handle_bonus.c b_utils_bonus.c
OBJ=$(SRC:.c=.o)
OBJ_BONUS=$(SRC_BONUS:.c=.o)
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
MINILIBXDIR= ./minilibx-linux
LIBFTDIR= ./libft
GET_NEXT_LINE_DIR= ./get_next_line

LIBFT=$(LIBFTDIR)/libft.a
GET_NEXT_LINE=$(GET_NEXT_LINE_DIR)/get_next_line.a
MINILIBX=$(MINILIBXDIR)/libmlx.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(GET_NEXT_LINE) $(MINILIBX)
	$(CC) $(CFLAGS) -o $@ $^  $(LIBFT) $(GET_NEXT_LINE) $(MINILIBX) -lm -lX11 -lXext -lpthread -I./bonus

$(NAME): $(OBJ) $(LIBFT) $(GET_NEXT_LINE) $(MINILIBX)
	$(CC) $(CFLAGS) -o $@ $^  $(LIBFT) $(GET_NEXT_LINE) $(MINILIBX) -lm -lX11 -lXext -lpthread

$(MINILIBX):
	make -C $(MINILIBXDIR)

$(LIBFT):
	make -C $(LIBFTDIR)

$(GET_NEXT_LINE):
	make -C $(GET_NEXT_LINE_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(LIBFTDIR) clean
	make -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFTDIR) fclean
	make -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
