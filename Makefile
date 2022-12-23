CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	get_next_line.c  get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

HEADERS = get_next_line.h

all: get_next_line

get_next_line: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o get_next_line

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f get_next_line

re: fclean all

.PHONY: all clean fclean re
