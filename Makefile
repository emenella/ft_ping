PROJECT = ft_ping
NAME = ft_ping

GCC = /bin/gcc
RM = /bin/rm
MKDIR = /bin/mkdir

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

OBJDIR = obj

SRC = main.c \

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all : $(NAME)

$(NAME) : 
	$(GCC) $(FLAGS) $(PROJECT).c -o $(NAME)

clean :
	$(RM) -rf $(OBJDIR)

fclean : clean
	$(RM) -rf $(NAME)

re : fclean all
