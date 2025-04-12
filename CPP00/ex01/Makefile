SRCS = main.cpp \

HEADER = PhoneBook.hpp Contact.hpp \

OBJS = $(SRCS:%.cpp=%.o)

NAME = phonebook

CC = c++

FLAGS = -Wall -Wextra -Werror

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

