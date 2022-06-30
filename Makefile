RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m


NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAG = -lmlx -lm -lXext -lX11 ./mlxl/libmlx.a

INCLUDE_M = ./include

HEADER = ./include/so_long.h
PREC_HEADER = ./include/so_long.h.gch

MAND_FILES = main.c \
		parsing_map.c \
		error_handler.c \
		initialize.c \
		check_component.c \
		get_images.c \
		render.c \
		moves.c \

FTPRINTF_DIR = printf
GETNEXTLINE_DIR = gnl

FTPRINTF_LIB = $(FTPRINTF_DIR)/ftprintf.a
GETNEXTLINE_LIB = $(GETNEXTLINE_DIR)/nextline.a

MAND_OBJ = $(MAND_FILES:%.c=%.o)

all : $(NAME)

$(NAME): $(MAND_OBJ) $(FTPRINTF_LIB) $(GETNEXTLINE_LIB)
	@$(CC) $(FLAGS) $(MAND_OBJ) $(MLX_FLAG) $(FTPRINTF_LIB)  $(GETNEXTLINE_LIB) -o $@

%.o : %.c $(HEADER)
	@$(CC) $(FLAGS) -o $@ -c $< -I$(INCLUDE_M)
	@echo "$(GREEN)" "compiling $<"

$(GETNEXTLINE_LIB):
	@$(MAKE) -C $(GETNEXTLINE_DIR)

$(FTPRINTF_LIB):
	@$(MAKE) -C $(FTPRINTF_DIR)

clean:
	@rm -rf $(MAND_OBJ) $(PREC_HEADER)
	@$(MAKE) clean -C $(FTPRINTF_DIR)
	@$(MAKE) clean -C $(GETNEXTLINE_DIR)
	@echo "$(RED)" "cleaning..."

fclean : clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(FTPRINTF_DIR)
	@$(MAKE) fclean -C $(GETNEXTLINE_DIR)
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re 
