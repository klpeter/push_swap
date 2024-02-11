NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
MAKE_LIB = ar -rcs

SRCS = utils/a_commands.c \
		utils/b_commands.c \
		utils/double_commands.c \
		utils/error.c \
		utils/finding_nodes.c \
		utils/ft_split.c \
		utils/push_swap.c \
		utils/push_utils.c \
		utils/set_nodes.c \
		utils/small_sort.c \
		utils/stack_create.c \
		utils/swap_rotate_utils.c \
		main.c \
	
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS) 

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
