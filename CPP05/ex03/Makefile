SRCS = AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp Intern.cpp

HEADER = AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

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
