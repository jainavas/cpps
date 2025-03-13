CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)

EXEC = program

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
