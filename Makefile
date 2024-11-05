NAME = server client
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I.$(LIBFT_DIR)

SERVER_SRC = server.c minitalk_utils.c
CLIENT_SRC = client.c minitalk_utils.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBFT_DIR = libft/
LIBFT_NAME = libft.a 
LIBFT_SRC = $(LIBFT_DIR)/*.c
LIBFT_LIB = $(LIBFT_DIR)$(LIBFT_NAME)
LIBFT_INCLUDE = -I$(LIBFT_DIR)

all: $(NAME)

server: $(SERVER_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJ) $(LIBFT_LIB) -L$(LIBFT_DIR) -lft

client: $(CLIENT_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJ) $(LIBFT_LIB) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB): $(LIBFT_SRC)
	$(MAKE) -C $(LIBFT_DIR)
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
