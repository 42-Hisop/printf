CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRCS= ft_printf.c \
	  ft_itoa.c	\
	  ft_itoh.c \
	  flag.c \
	  print.c

OBJS= $(SRCS:.c=.o)
NAME= libftprintf.a

$(NAME): $(OBJS)
	ar rscv $(NAME) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all
