# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 16:46:56 by kjuszko           #+#    #+#              #
#    Updated: 2024/12/18 14:03:18 by kjuszko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = src/
INCDIR = include/

SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_printf.c ft_printf_helper1.c ft_printf_helper2.c

BSRC =	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

VPATH = $(SRCDIR)

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

NAME = libft.a

BONUS = .bonus

CC = clang

CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(BONUS): $(OBJ) $(BOBJ)
	ar rcs $(NAME) $(OBJ) $(BOBJ)
	@touch $(BONUS)

bonus: $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
