SRCS = megaphone.cpp \

OBJS = $(SRCS:%.cpp=%.o)

NAME = megaphone

CC = c++

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

#https://42correction.netlify.app/
#https://github.com/arbutnar/cppModules/tree/master/Module00/ex01