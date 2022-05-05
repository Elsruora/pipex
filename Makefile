# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 10:44:48 by nchabli           #+#    #+#              #
#    Updated: 2022/05/05 14:44:18 by nchabli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Colors
GREY = \033[4;34m
RED = \033[1;31m
GREEN = \033[3;32m
YELLOW = \033[2;49;33m
BLUE = \033[4;34m
BLUEE = \033[3;34m
PURPLE = \033[3;35m
CYAN = \033[3;36m
RESET = \033[0m
ICONOK = \033[1;32m
ICONKO = \033[1;31m
CO_DELET = \033[3;31m
CO_A_OUT = \033[96m
WHITE = \033[1;49;97m

# Executable
NAME = pipex
LIBFT = libft/libft.a

# Include
HEADER = ./Includes/pipex.h

#VPATH = Sources/:Sources/engine:

# chemin Sources
SA = Sources/
UT = pipex_utils/
SRCS =	$(SA)pipex.c\
		$(SA)utils.c\
		$(SA)parsing.c
		
		
# normal Flags
CC = gcc
CF = -Wall -Werror -Wextra #-g3 -fsanitize=address
SL = -framework OpenGL -framework AppKit
CI = -I sl_inc/
AR = ar rcs
RM = rm -rf

OBJS = $(SRCS:.c=.o)

SL = -framework OpenGL -framework AppKit


all:	$(NAME)
	@make -C libft/ -r -R
	@clear
	@printf "$(GREEN)Compilation terminée !$(RESET)"

%.o:	%.c $(HEADER)
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)Compilation en cours...$(RESET)"
	@gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(SRCS) $(LIBFT)
	@$(CC) $(CF) $(CI) $(SL) $(SRCS) $(LIBFT) -o $(NAME)


${LIBFT}:
	@make -C libft/ -r -R

clean:
	$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(OBJS)
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@rm -rf *.dSYM
	@make -C libft fclean
	@clear
	@printf "$(CYAN)'$(NAME)', all.o & pipex.a $(RESET)has been $(RED)deleted. 🗑️\n$(RESET)"
	@printf "$(CYAN)'libft.a', *.o $(RESET)has been $(RED)deleted. 🗑️\n$(RESET)"

norm:
	@norminette libft/*.c Makefile Sources/*.c

re : fclean all

run :  ./pipex.a

.PHONY: all clean fclean re norm