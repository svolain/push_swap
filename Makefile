NAME = push_swap
LIBFTDIR = ./libft
MAKE = make
CC = cc
CFLAGS = -Wall -Wextra -Werror 
HEAD = includes/push_swap.h

SRCS = srcs/main.c \
		srcs/error_handling.c \
		srcs/stack_utils.c \
		srcs/push.c \
		srcs/rotate.c \
		srcs/swap.c \
		srcs/reverse_rotate.c \
		srcs/tiny_sort.c \
		srcs/radix_sort.c \
		srcs/sort_utils.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) all bonus -C $(LIBFTDIR) 
		@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME) 

clean:
		@rm -f $(OBJS)
		@$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
		@rm -f $(NAME)
		@rm -f libft.a
		@$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re
