NAME_CLIENT = client
NAME_SERVER = server

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
INCLUDES = -I$(LIBFT_DIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(NAME_SERVER)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re

