CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
SRC = main.cpp \
		Bureaucrat.cpp \
		PresidentialPardonForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		AForm.cpp
OBJS_DIR = obj
OBJS = $(SRC:%.cpp=$(OBJS_DIR)/%.o)

NAME = bureaucrat

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(NAME)

fclean: clean
	@$(RM) $(OBJS_DIR)

re: fclean $(NAME)

.PHONY: all clean fclean re
