# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 15:19:49 by aboudoun          #+#    #+#              #
#    Updated: 2022/03/22 15:29:56 by aboudoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = ft_printf.h

CFILES = ft_printf.c ft_printf_utils.c 
OFILES = $(CFILES:%.c=%.o)

CC = gcc
W = -c -Wall -Werror -Wextra
NAME = ftprintf.a

all : $(NAME)

$(NAME) : $(OFILES)
	@$(CC) $(W) $(CFILES)
	@ar -rc $(NAME) $(OFILES)
	
%.o : %.c $(HEADER)
	@$(CC) $(FLAGS) -c $^ 
clean:
	@rm -f $(OFILES) ft_printf.h.gch
fclean : clean
	@rm -f $(NAME)
re : fclean all
