NAME		= bureaucrat
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCS		= main.cpp Bureaucrat.cpp AForm.cpp \
			  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
			  PresidentialPardonForm.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) *_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
