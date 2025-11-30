NAME=BANK

CXX=c++

STD=-std=c++98

FLAGS= -Wall -Werror -Wextra

SRC= src/main.cpp \
     src/Bank.cpp

INCLUDES= -I include

OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(STD) $^ -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(STD) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
