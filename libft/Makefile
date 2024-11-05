NAME = libft.a

SRC_FILES = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atol.c  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_printf.c ft_print_char.c ft_print_str.c ft_print_digit.c ft_print_udigit.c ft_print_hexa.c ft_print_hexa_cap.c ft_print_ptr.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c get_next_line_utils.c get_next_line.c

OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES) 
	
%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME) $(OBJ_FILES:%.o=%.o.tmp)

re: fclean all

.PHONY: all clean fclean re
