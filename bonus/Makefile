RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

BONUS = so_long_bonus

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAG = -lmlx -lm -lXext -lX11 ../mlxl/libmlx.a


INCLUDE_B = ./include

BONUS_HEADER = ./include/so_long_bonus.h
BON_PREC_HEADER = ./include/so_long_bonus.h.gch

BON_FILES = main_bonus.c \
		parsing_map_bonus.c \
		error_handler_bonus.c \
		initialize_bonus.c \
		check_component_bonus.c \
		get_images_bonus.c \
		render_bonus.c \
		moves_bonus.c \

FTPRINTF_DIR = ../printf
GETNEXTLINE_DIR = ../gnl

FTPRINTF_LIB = $(FTPRINTF_DIR)/ftprintf.a
GETNEXTLINE_LIB = $(GETNEXTLINE_DIR)/nextline.a

MAND_OBJ = $(MAND_FILES:%.c=%.o)
BON_OBJ = $(BON_FILES:%bonus.c=%bonus.o)

all : $(BONUS)

$(BONUS): $(BON_OBJ) $(FTPRINTF_LIB) $(GETNEXTLINE_LIB)
	@$(CC) $(FLAGS) $(BON_OBJ) $(MLX_FLAG) $(FTPRINTF_LIB) $(GETNEXTLINE_LIB) -o $(BONUS)


%bonus.o : %bonus.c $(BONUS_HEADER)
	@$(CC) -I$(INCLUDE_B) $(FLAGS) -o $@ -c $<
	@echo "$(GREEN)" "compiling $<"


$(GETNEXTLINE_LIB):
	@$(MAKE) -C $(GETNEXTLINE_DIR)

$(FTPRINTF_LIB):
	@$(MAKE) -C $(FTPRINTF_DIR)

clean:
	@rm -rf $(BON_OBJ) $(BON_PREC_HEADER)
	@$(MAKE) clean -C $(FTPRINTF_DIR)
	@$(MAKE) clean -C $(GETNEXTLINE_DIR)
	@echo "$(RED)" "cleaning..."

fclean : clean
	@rm -rf $(BONUS)
	@$(MAKE) fclean -C $(FTPRINTF_DIR)
	@$(MAKE) fclean -C $(GETNEXTLINE_DIR)
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re bonus
