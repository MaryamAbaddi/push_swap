NAME        = push_swap

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

SRCS        = main.c list.c sort3.c \
              utils.c check_args.c check_args2.c  \
              ope1.c ope2.c ope3.c ope4.c \
              sort.c radix.c index.c list1.c \
		ft_putendl_fd.c ft_isdigit.c ft_putnbr_fd.c \


OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
