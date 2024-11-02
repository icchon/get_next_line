NAME = main
CC     = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = get_next_line.c get_next_line_utils.c main.c 
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c main.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifndef BUFFER_SIZE
BUFFER_SIZE=1000
endif

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRCS) -o $(NAME)

.c.o: 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(BONUS_OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(BONUS_SRCS) -o $(NAME)

.PHONY: all clean fclean re bonus 