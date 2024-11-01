NAME = main
CC     = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = get_next_line.c get_next_line_utils.c main.c 
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c main.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
OBJS += $(BONUS_OBJS)
endif

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

bonus:
	@make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus 