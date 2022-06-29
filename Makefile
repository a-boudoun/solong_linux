RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m


NAME = so_long
BONUS = so_long_bonus

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit


INCLUDE_B = ./bonus/include
INCLUDE_M = ./include

HEADER = ./include/so_long.h
PREC_HEADER = ./include/so_long.h.gch
BONUS_HEADER = ./bonus/include/so_long_bonus.h
BON_PREC_HEADER = bonus/include/so_long_bonus.h.gch

MAND_FILES = main.c \
		parsing_map.c \
		error_handler.c \
		initialize.c \
		check_component.c \
		get_images.c \
		render.c \
		moves.c \

BON_FILES = ./bonus/main_bonus.c \
		./bonus/parsing_map_bonus.c \
		./bonus/error_handler_bonus.c \
		./bonus/initialize_bonus.c \
		./bonus/check_component_bonus.c \
		./bonus/ft_itoa.c \
		./bonus/get_images_bonus.c \
		./bonus/render_bonus.c \
		./bonus/moves_bonus.c \

FTPRINTF_DIR = printf
GETNEXTLINE_DIR = gnl

FTPRINTF_LIB = $(FTPRINTF_DIR)/ftprintf.a
GETNEXTLINE_LIB = $(GETNEXTLINE_DIR)/nextline.a

MAND_OBJ = $(MAND_FILES:%.c=%.o)
BON_OBJ = $(BON_FILES:%bonus.c=%bonus.o)

all : $(NAME)

$(NAME): $(MAND_OBJ) $(FTPRINTF_LIB) $(GETNEXTLINE_LIB)
	@$(CC) $(FLAGS) $(MLX_FLAG) $(FTPRINTF_LIB) $(GETNEXTLINE_LIB) $(MAND_OBJ) -o $@

bonus : $(BONUS)

$(BONUS): $(BON_OBJ) $(FTPRINTF_LIB) $(GETNEXTLINE_LIB)
	@$(CC) $(FLAGS) $(MLX_FLAG) $(FTPRINTF_LIB) $(GETNEXTLINE_LIB) -o $(BONUS) $(BON_FILES)

%.o : %.c $(HEADER)
	@$(CC) -I$(INCLUDE_M) $(FLAGS) -o $@ -c $<
	@echo "$(GREEN)" "compiling $<"

%bonus.o : %bonus.c $(BONUS_HEADER)
	@$(CC) $(FLAGS) -o $@ -c $< -I$(INCLUDE_B)
	@echo "$(GREEN)" "compiling $<"


$(GETNEXTLINE_LIB):
	@$(MAKE) -C $(GETNEXTLINE_DIR)

$(FTPRINTF_LIB):
	@$(MAKE) -C $(FTPRINTF_DIR)

clean:
	@rm -rf $(MAND_OBJ) $(BON_OBJ) $(PREC_HEADER) $(BON_PREC_HEADER)
	@$(MAKE) clean -C $(FTPRINTF_DIR)
	@$(MAKE) clean -C $(GETNEXTLINE_DIR)
	@echo "$(RED)" "cleaning..."

fclean : clean
	@rm -rf $(NAME) $(BONUS)
	@$(MAKE) fclean -C $(FTPRINTF_DIR)
	@$(MAKE) fclean -C $(GETNEXTLINE_DIR)
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re bonus
