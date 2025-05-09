SRCS = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp\

HEADER = HumanA.hpp HumanB.hpp Weapon.hpp\

OBJS = $(SRCS:%.cpp=%.o)

NAME = Brainz

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re