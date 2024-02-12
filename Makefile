OBJS_DIR		=	.objs
GNL_OBJS_DIR	=	.gnl_objs
SRCS_DIR		=	src
GNL_DIR			=	get_next_line
HEADER_DIR		=	includes

PRINTF_PATH		=	./ft_printf
PRINTF			=	${PRINTF_PATH}/libftprintf.a
MLX_PATH		=	./minilibx-linux
MLX				=	${MLX_PATH}/libmlx.a

LIB				=	$(HEADER_DIR)/so_long.h
GNL_LIB			=	$(HEADER_DIR)/get_next_line.h

SRC			=	$(SRCS_DIR)/main.c \
				$(SRCS_DIR)/map.c \
				$(SRCS_DIR)/controls.c \
				$(SRCS_DIR)/utils.c \
				$(SRCS_DIR)/check_valid_path.c \
				$(SRCS_DIR)/add_graphics.c \
				$(SRCS_DIR)/update_map_utils.c \
				$(SRCS_DIR)/free_utils.c

GNL_SRC		=	$(GNL_DIR)/get_next_line.c \
				$(GNL_DIR)/get_next_line_utils.c

OBJ			=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRC))
GNL_OBJ		=	$(patsubst $(GNL_DIR)%.c, $(GNL_OBJS_DIR)%.o, $(GNL_SRC))

NAME	=	so_long
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra -I $(HEADER_DIR) -I $(MLX_PATH) -I $(PRINTF_PATH)

$(OBJS_DIR)/%.o:		$(SRCS_DIR)/%.c $(LIB)
						mkdir -p $(@D)
						$(CC) $(FLAGS) -c $< -o $@

$(GNL_OBJS_DIR)/%.o:	$(GNL_DIR)/%.c $(GNL_LIB)
						mkdir -p $(@D)
						$(CC) $(FLAGS) -c $< -o $@

all:	lib $(NAME)

lib:
		make -C $(MLX_PATH) && make -C $(PRINTF_PATH)

$(NAME):	$(OBJ) $(LIB) $(GNL_OBJ) $(GNL_LIB) $(PRINTF)
			$(CC) $(OBJ) $(GNL_OBJ) $(FLAGS) -Iminilibx-linux -lXext -lX11 -lm -lz $(MLX) $(PRINTF) -o $(NAME)

clean:
		make clean -C $(MLX_PATH)
		make clean -C $(PRINTF_PATH)
		rm -f ${OBJ} $(GNL_OBJ)
		rm -f so_long

fclean:	clean
		make fclean -C $(MLX_PATH)
		make fclean -C $(PRINTF_PATH)
		rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

