NAME=fdf
NAME_BONUS=fdf_bonus
SRC= mandatory/main.c mandatory/utils.c mandatory/filehandler.c mandatory/drawmap.c mandatory/exit_utils.c
SRC_BONUS= bonus/exit_utils_bonus.c bonus/filehandler_bonus.c bonus/handlevision_bonus.c bonus/imagehandler_bonus.c bonus/key_utils.c bonus/main_bonus.c bonus/utils1_bonus.c bonus/utils_bonus.c bonus/video_handle_bonus.c bonus/video_helper.c
OBJ=$(SRC:.c=.o)
OBJ_BONUS=$(SRC_BONUS:.c=.o)
CC=cc
CFLAGS=-Wall -Wextra -Werror
MINILIBXDIR= ./minilibx-linux
LIBFTDIR= ./libft
GET_NEXT_LINE_DIR= ./get_next_line

LIBFT=$(LIBFTDIR)/libft.a
GET_NEXT_LINE=$(GET_NEXT_LINE_DIR)/get_next_line.a
MINILIBX=$(MINILIBXDIR)/libmlx.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(GET_NEXT_LINE) $(MINILIBX)
	$(CC) $(CFLAGS) -o $@ $^  $(LIBFT) $(GET_NEXT_LINE) $(MINILIBX) -lm -lX11 -lXext

$(NAME): $(OBJ) $(LIBFT) $(GET_NEXT_LINE) $(MINILIBX)
	$(CC) $(CFLAGS) -o $@ $^  $(LIBFT) $(GET_NEXT_LINE) $(MINILIBX) -lm -lX11 -lXext

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

normlibs:
	find $(LIBFTDIR) -type f -print0 | xargs -0 norminette
	find $(GET_NEXT_LINE_DIR) -type f -print0 | xargs -0 norminette

normmandatory:
	find ./mandatory -type f -print0 | xargs -0 norminette
	@echo "Norminette checks passed"

normbonus:
	find ./bonus -type f -print0 | xargs -0 norminette
	@echo "Norminette checks passed"

norm: normmandatory normbonus normbonus normlibs
	@echo "Norminette checks passed"

re: fclean all

.PHONY: all bonus clean fclean re normmandatory normbonus normlibs norm