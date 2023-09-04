NAME			=	cub3D
INC				=	./inc/
LIBFT			=	libft/libft.a


SRCS			=   src/check_map_color.c \
					src/check_map_color2.c \
					src/check_map_is_same.c \
					src/check_map_is_same2.c \
					src/check_map_path.c \
					src/check_map_wall.c \
					src/check_map_wall2.c \
					src/check_map.c \
					src/check_map2.c \
					src/cub3d_map_read.c \
					src/cub3d_utils.c \
					src/draw.c \
					src/get_data.c \
					src/get_file.c \
					src/last_file.c \
					src/look.c \
					src/main.c \
					src/mov.c \
					src/render.c


OBJS			=	$(SRCS:src/%.c=src/bin/%.o)
BIN				=	./src/bin
LIB				=	./minilibx_macos/libmlx.a

CC				=	@gcc
RM				=	@rm -rf
CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-framework OpenGL -framework AppKit

all:			$(LIB) $(LIBFT) $(NAME)

$(LIB) : 
		@make -C ./mlx

$(BIN):
	@mkdir $(BIN)

$(LIBFT):
	@make -C libft/

$(NAME):	$(BIN) $(LIBFT) $(OBJS)
			@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(MLXFLAGS) -o $(NAME) $(LIB)

clean:
			@$(RM) $(OBJS)
			@$(RM) $(BIN)
			@make clean -C libft/

fclean:			clean
				@$(RM) $(NAME)
				@make fclean -C libft/

re:				fclean $(NAME)

$(BIN)%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

.PHONY:			all clean fclean re bonus