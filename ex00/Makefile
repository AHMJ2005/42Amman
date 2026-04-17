NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror -I include


SRCS = srcs/main.c \
       srcs/check/check_arg.c srcs/check/check_dict_file.c srcs/check/check_digits.c \
       srcs/dict/dict_parse.c srcs/dict/dict_new.c srcs/dict/dict_set.c \
       srcs/dict/dict_get.c srcs/dict/dict_destroy.c srcs/dict/dict_util.c \
       srcs/nbr/nbr_break.c srcs/nbr/nbr_buffer.c srcs/nbr/nbr_substr.c srcs/nbr/nbr_pad_zero.c \
       srcs/ft/ft_split.c srcs/ft/ft_strdup.c srcs/ft/ft_putstr.c srcs/ft/ft_putchar.c \
       srcs/ft/ft_strcmp.c srcs/ft/ft_atoi.c srcs/ft/ft_strlen.c srcs/ft/ft_error.c \
       srcs/ft/ft_strcpy.c srcs/ft/ft_strcat.c srcs/ft/ft_strncat.c \
       srcs/file/file_read.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
