NAME = test
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRCS = $(shell find $(SRCDIR) -name "*.c" -type f | xargs)
SRCDIR = .
OBJS = $(SRCS:.c=.o)
INCLUDE = -I .

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@echo "Done."

%.o: %.c
	@echo "Compiling Object $@..."
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "Do make clean..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Do make fclean..."
	@rm -f $ $(NAME)

re: fclean all

.PHONY: all clean fclean re
