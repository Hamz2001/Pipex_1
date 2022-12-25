NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror 

FUN=	pipex.c	\
outil.c	\
child.c	\
Path.c	\
split.c	\
msgErr.c	\

OBJ= $(FUN:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(FUN) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re:	fclean all