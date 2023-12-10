NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2 
MAKE_LIB = ar -rcs

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME) clean

$(NAME) : $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclea re

# Name = push_swap

# files = error \
		# main \
		# push \
		# push_swap \
		# reverse_rotate \
		# rotate \
		# small_sort \
		# sort_utils \
		# stack_create \
		# stack_utils \
		# swap \
		# ft_split \
		# ft_atol \
		# ft_strlen \
		

# Compiler = gcc

# CFlags = -Wall -Wextra -Werror

# OUTN = $(Library).a

# CFILES = $(files:%=%.c)

# OFILES = $(files:%=%.o)

# ARCHIVE = push_swap.a

# $(NAME): $(ARCHIVE)
# 		$(Compiler) $< -o $@

# $(ARCHIVE) : $(OFILES)
# 			ar -rcs $(ARCHIVE) $^

# $(OFILES) : $(CFILES)
# 		$(Compiler) $(CFlags) -c &< -o $@

# all: $(NAME)

# clean:
# 		rm -f $(OFILES)

# fclean: clean
# 		rm -f $(NAME)

# re: fclean all
	
# .PHONY: all, clean, fclean, re





# # name of the file
# OUTPUT = push_swap

# # define sources and objects

# FILES = main \
# 		push \
# 		push_swap \
# 		reverse_rotate \
# 		rotate \
# 		small_sort \
# 		sort_utils \
# 		stack_create \
# 		stack_utils \
# 		swap \
# 		ft_split \
# 		ft_atol \
# 		ft_strlen \
# 		error \

# SRCS = $(FILES:%=%.c)

# OBJS = $(SRCS:.c=.o)

# # compiler

# CC = gcc

# CFLAGS = -Wall -Wextra -Werror

# # creating the ojects files
# %.o : %.c
# 	$(CC) $(CFLAGS) -c $< -o $@ 

# all: $(OUTPUT) clean

# #  creating the exec file
# $(OUTPUT) : $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(OUTPUT)

# clean: 
# 	rm -f $(OBJS)

# fclean: clean
# 		rm -f $(OUTPUT)

# re: fclean all
	
# .PHONY: all, clean, fclean, re