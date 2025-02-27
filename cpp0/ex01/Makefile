CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = phone.cpp
OBJS = $(SRCS:.cpp=.o)

EXEC = phone

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
