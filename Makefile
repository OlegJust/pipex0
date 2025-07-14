NAME    = pipex
BONUS   = pipex_bonus

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Iincludes

RM      = rm -f

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

SRCS    = srcs/pipex.c srcs/utils.c
OBJS    = $(SRCS:.c=.o)

SRCS_B  = srcs/pipex_bonus.c srcs/utils.c srcs/utils_bonus.c
OBJS_B  = $(SRCS_B:.c=.o)

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_B) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_B) -L$(LIBFT_DIR) -lft -o $(BONUS)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
