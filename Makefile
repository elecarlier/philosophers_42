NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
#CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
HEADER1 = philo.h
HEADER2 = messages.h

G = "\033[32m"
Y = "\033[33m"
R = "\033[31m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

SRCS = dinner.c main.c init.c utils.c parsing.c input.c one_philo.c routine.c monitor.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER1) $(HEADER2)
	@echo $(Y)Compiling	[$<]$(X)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(UP)$(CUT)

$(NAME): $(OBJS)
	@echo $(Y)"Compiling	" [$(SRCS)]$(X)
	@echo $(G)"Created		" [$(SRCS)]$(X)
	@echo $(Y)"Compiling	" [$(NAME)]$(X)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo $(G)"Created		" [$(NAME)]$(X)

clean:
	@rm -f $(OBJS)
	@echo $(G)"Removed		" [$(OBJS)]$(X)

fclean: clean
	@rm -f $(NAME)
	@echo $(G)"Removed		" [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean re
