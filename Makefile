NAME	=	so_long
CC		=	gcc
CFLAGS	=	
OBJS	=	$(OBJS_S)
MLX_FLAG	=	-lmlx -framework OpenGL -framework AppKit

OBJS_DIR	=	./objs/
SRCS_DIR	=	./srcs/
HEADER_DIR	=	./header/
LIBFT_DIR	=	./libft/

SRCS_S		=	main.c\
				map_get.c\
				error.c\
				get_next_line.c\
				get_next_line_utils.c\
				map_check_lwpe.c\
				map_check_c.c\
				render_start.c\
				render_go_to.c
HEADERS		=	./header/so_long.h
OBJS_S		=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS_S:.c=.o)))
LIBFT		=	./libft/libft.a

RM = rm -f

.PHONY:	all clean fclean re

all:	$(LIBFT) $(LIBMLX) $(NAME)
$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(HEADERS) $(LIBFT) $(LIBMLX) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -O3 -I$(HEADERS_DIR) -Imlx -c $< -o $@

$(LIBFT):
	make -C libft/

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(MLX_FLAG) $(LIBFT)

clean:
		$(RM) -r $(OBJS_DIR)
		make clean -C $(LIBFT_DIR) fclean

fclean: clean
		$(RM) $(NAME)
		make clean -C $(LIBFT_DIR) fclean

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

re:	fclean $(OBJS_DIR) all

