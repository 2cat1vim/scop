NAME	= scop
CPP	= c++
CFLAGS	= -std=c++98 -g -Wall -Wextra -Werror
LDFLAGS = -lglfw -lGL -lm

SRCS	= source/main.cpp

OBJS	= $(SRCS:.cpp=.o)

GREEN = \033[0;32m
BOLD = \033[1m
RESET = \033[0m

all: $(NAME)
	@echo ""
	@echo "$(GREEN)$(BOLD) ==== ./scop to run ====$(RESET)"
	@echo ""

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make clean

re: fclean all

.PHONY: all clean fclean re