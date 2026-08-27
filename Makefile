NAME      = scop
CPP       = c++
CC        = clang

CXXFLAGS  = -std=c++98 -g -Wall -Wextra -Werror

CFLAGS    = -g -Wall -Wextra -Werror

LDFLAGS   = -lglfw -lGL -lm

SRCS      = source/main.cpp \
            source/entity.cpp \
			source/objParser.cpp \
			source/module.cpp \
			source/shader.cpp

SRCS_C    = external/glad/glad.c

OBJS      = $(SRCS:.cpp=.o) $(SRCS_C:.c=.o)

GREEN     = \033[0;32m
BOLD      = \033[1m
RESET     = \033[0m

all: $(NAME)
	@echo ""
	@echo "$(GREEN)$(BOLD) ==== ./scop to run ====$(RESET)"
	@echo ""

%.o: %.cpp
	$(CPP) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re