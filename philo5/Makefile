NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)

%o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.out

re: fclean all

.PHONY: all clean fclean re