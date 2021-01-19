NAME=replace

SRC=Sed.cpp  main.cpp

OBJS=$(SRC:.cpp=.o)

FLAGS=-std=c++98 -g -Wall -Wextra -Werror

CPP_C=clang++

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP_C) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP_C) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f *.replace

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean