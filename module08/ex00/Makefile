NAME			= easyfind

DIR_SRCS		= srcs
DIR_BUILD       = .build
DIR_INCLUDES	= -I includes -I srcs/templates

SRCS			=	main.cpp 

OBJS			= $(addprefix $(DIR_BUILD)/, $(SRCS))
OBJS			:= $(OBJS:%.cpp=%.o)
SRCS			:= $(addprefix $(DIR_SRCS)/, $(SRCS))

CFLAGS          = -Wall -Werror -Wextra -std=c++98

BLINK_RED := \033[5;31m
RESET := \033[0m

# ============================================================ #
#                           RULES                              #
# ============================================================ #
all						: $(NAME)

$(NAME)         		: $(DIR_BUILD) $(OBJS)
			c++ $(OBJS) -o $(NAME)
			@echo "${BLINK_RED}The command created! Type ./$(NAME)${RESET}"

$(DIR_BUILD)/%.o		: $(DIR_SRCS)/%.cpp
			c++ $(DIR_INCLUDES) -g $(CFLAGS) -c $< -o $@ 

$(DIR_BUILD)			:
			mkdir -p $(DIR_BUILD)
			mkdir -p $(DIR_BUILD)/classes

clean					:
			rm -rf $(OBJS)
			rm -rf $(DIR_BUILD)

fclean					: clean
			rm -rf ${NAME}

re						: fclean all

valgrind				: ${NAME}
			valgrind ./$(NAME)

.PHONY					: all clean fclean re