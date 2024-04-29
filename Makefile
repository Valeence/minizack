NAME		=	minishell

HEADER		=	./Include/

LIBFT		=	Include/libft/libft.a

CC			=	clang

CFLAGS		=	-Werror -Wall -Wextra -gdwarf-4  -I$(HEADER) #-fsanitize=address

LDFLAGS		=	-lreadline

SRCS		=	$(wildcard *.c) \
				$(wildcard Exe/*.c) \
				$(wildcard Tokenisation/*.c) \
				$(wildcard Parsing/*.c) \
				$(wildcard Builtins/*.c) \


OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LDFLAGS)

$(LIBFT):
	make -C ./Include/libft/

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

leaks: ${NAME}
	clear && valgrind --suppressions=ignore.txt -s --track-fds=yes --track-origins=yes --leak-check=full ./minishell