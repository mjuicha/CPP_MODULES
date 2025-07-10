SRCS = Bureaucrat.cpp main.cpp

HEADER = Bureaucrat.hpp

OBJS = $(SRCS:%.cpp=%.o)

type = a.out

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(type)

$(type): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(type)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(type)

re:	fclean all

.PHONY:	all clean fclean re