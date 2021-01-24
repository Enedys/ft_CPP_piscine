NAME=template_functions

SRC=main.cpp

OBJS=$(SRC:.cpp=.o)

FLAGS=-std=c++98 -Wall -Wextra -Werror

CPP_C=clang++

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP_C) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP_C) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean