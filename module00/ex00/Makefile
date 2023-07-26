NAME			= megaphone

SRCS			= megaphone.cpp

SRCS_DIR		= .
BUILD_DIR       = .

OBJS			= $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS			:= $(OBJS:%.cpp=%.o)
SRCS			:= $(addprefix $(SRCS_DIR)/, $(SRCS))

CFLAGS          = -Wall -Werror -Wextra -std=c++98

all						: ${NAME}

${NAME}         		: ${OBJS}
			c++ $(OBJS) -o $(NAME)

${BUILD_DIR}/%.o		: $(SRCS_DIR)/%.cpp
			c++ ${CFLAGS} -c $< -o $@ 

clean					:
			rm -rf ${OBJS}

fclean					: clean
			rm -rf ${NAME}

re						: fclean all

valgrind				: ${NAME}
			valgrind ./$(NAME)

.PHONY					: all clean fclean re