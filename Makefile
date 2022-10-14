RED	=\033[0;31m
BLUE	=\033[0;34m
WHITE	=\033[0;37m
YELLOW	=\033[0;33m

CC		= gcc
RM		= rm -rf
NAME		= cub3D
LMLX		= -framework OpenGL -framework AppKit
CFLAGS		= -Wall -Wextra -Werror
LMLX_LINUX	= -lXext -lX11 -lm -lz

LIBFT		= Librarys/libft/libft.a
MLX_LINUX	= Librarys/minilibx-linux/libmlx.a $(LMLX_LINUX)
MLX_MACOS	= Librarys/minilibx-macos/libmlx.a $(LMLX)

SOURCES =	./Sources/cub3d.c \
			./Sources/map/map.c \
			./Sources/map/map2.c \
			./Sources/map/map3.c \
			./Sources/map/map4.c \
			./Sources/map/map5.c \
			./Sources/map/map6.c \
			./Sources/utils/utils.c \
			./Sources/utils/utils2.c \
			./Sources/mlx/start_mlx.c \
			./Sources/mlx/start_mlx2.c \
			./Sources/mlx/start_mlx3.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@echo "$(YELLOW)>>>>> Libft Library Compiling <<<<<$(WHITE)"
		@make -sC ./Librarys/libft/
		@echo "$(YELLOW)>>>>> Minilibx Library Compiling <<<<<$(WHITE)"
#		FOR LINUX
		@make -sC ./Librarys/minilibx-linux/
		@echo "$(YELLOW)>>>> Cub3d Compiling <<<<<$(WHITE)"
		@$(CC) $(OBJECTS) $(LIBFT) $(MLX_LINUX) -o $(NAME)
#		FOR MAC
#		@make -sC ./Librarys/minilibx-macos/
#		@echo "$(YELLOW)>>>> Cub3d Compiling <<<<<$(WHITE)"
#		@$(CC) $(OBJECTS) $(LIBFT) $(MLX_MACOS) -o $(NAME)
		@echo "$(BLUE)>>>>> Done <<<<<$(WHITE)"

clean:
		@$(RM) $(OBJECTS)
		@make clean -sC ./Librarys/libft/
		@make clean -sC ./Librarys/minilibx-linux/
		@echo "$(RED)>>>>> Deleted <<<<<$(WHITE)"

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(LIBFT)
		@echo "$(RED)>>>>> Full Deleted <<<<<$(WHITE)"

norm:
	norminette ./Librarys/libft
	norminette ./Sources/

re: fclean all

.PHONY: all clean fclean re 
