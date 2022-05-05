# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 10:44:48 by nchabli           #+#    #+#              #
#    Updated: 2022/05/05 14:49:42 by nchabli          ###   ########.fr        #
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
NAME = libft.a

# Include
HEADER = libft.h

# chemin Sources
SA = Sources/
LIBFT = Sources/
SRCS =	$(LIBFT)ft_isalnum.c \
		$(LIBFT)ft_isprint.c \
		$(LIBFT)ft_isalpha.c \
		$(LIBFT)ft_memcpy.c \
		$(LIBFT)ft_bzero.c \
		$(LIBFT)ft_isascii.c \
		$(LIBFT)ft_memmove.c \
		$(LIBFT)ft_strlen.c \
		$(LIBFT)ft_isdigit.c \
		$(LIBFT)ft_memset.c \
		$(LIBFT)ft_strlcpy.c \
		$(LIBFT)ft_strlcat.c \
		$(LIBFT)ft_toupper.c \
		$(LIBFT)ft_tolower.c \
		$(LIBFT)ft_strchr.c \
		$(LIBFT)ft_strrchr.c \
		$(LIBFT)ft_strncmp.c \
		$(LIBFT)ft_memchr.c \
		$(LIBFT)ft_memcmp.c \
		$(LIBFT)ft_strnstr.c \
		$(LIBFT)ft_atoi.c \
		$(LIBFT)ft_calloc.c \
		$(LIBFT)ft_strdup.c \
		$(LIBFT)ft_substr.c \
		$(LIBFT)ft_strjoin.c \
		$(LIBFT)ft_strtrim.c \
		$(LIBFT)ft_split.c \
		$(LIBFT)ft_itoa.c \
		$(LIBFT)ft_strmapi.c \
		$(LIBFT)ft_putchar_fd.c \
		$(LIBFT)ft_putstr_fd.c \
		$(LIBFT)ft_putendl_fd.c \
		$(LIBFT)ft_putnbr_fd.c \
		$(LIBFT)ft_striteri.c \
		$(LIBFT)ft_convert_base.c \
		$(LIBFT)ft_convert_base2.c \
		$(LIBFT)ft_does_str_contain.c \
		$(LIBFT)ft_search_envp_path.c \
		$(LIBFT)ft_have_print.c
		

# normal Flags
CC = gcc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

all:	$(NAME)

%.o:	%.c $(HEADER)
	@clear
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)Compilation en cours...$(RESET)"
	@gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	@ar -rc $(NAME) $?
	@clear

clean:
	@$(RM) $(OBJS)
	@clear

fclean:	clean
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@rm -rf *.dSYM
	@printf "$(CYAN)'$(NAME)', all .o & libftprintf.a $(RESET)has been $(RED)deleted. 🗑️\n"

norm:
	@norminette Includes Lib_perso Makefile Sources/*.c

re : fclean all

.PHONY: all clean fclean re norm