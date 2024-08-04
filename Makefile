NAME		= push_swap

SRCS		= push_swap.c	checker.c	free.c	split.c	utils.c	action_swap.c	action_rotate.c \
action_rotate__reverse.c action_push.c

OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= ./libft
PRINTF_DIR	= ./printf

LIBFTA		= $(LIBFT_DIR)/libft.a
LIBFTPRINTF	= $(PRINTF_DIR)/libftprintf.a

RM		= rm -f

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME): 	$(LIBFTA) $(LIBFTPRINTF) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) $(LIBFTPRINTF) -o $(NAME)

$(LIBFTA):
			@make -C $(LIBFT_DIR)

$(LIBFTPRINTF):
			@make -C $(PRINTF_DIR)

clean:
			$(RM) $(OBJS)
			@make -C $(LIBFT_DIR) clean
			@make -C $(PRINTF_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@make -C $(PRINTF_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re