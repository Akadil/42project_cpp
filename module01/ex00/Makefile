NAME			= zombie

SRCS			=	main.cpp \
					newZombie.cpp \
					randomChump.cpp \
					classes/Zombie.cpp

DIR_SRCS		= srcs
DIR_BUILD       = .build
DIR_INCLUDES	= includes

OBJS			= $(addprefix $(DIR_BUILD)/, $(SRCS))
OBJS			:= $(OBJS:%.cpp=%.o)
SRCS			:= $(addprefix $(DIR_SRCS)/, $(SRCS))

CFLAGS          = -Wall -Werror -Wextra -std=c++98

all						: $(NAME)

$(NAME)         		: $(DIR_BUILD) $(OBJS)
			c++ $(OBJS) -o $(NAME)

$(DIR_BUILD)/%.o		: $(DIR_SRCS)/%.cpp
			c++ -I $(DIR_INCLUDES) $(CFLAGS) -c $< -o $@ 

$(DIR_BUILD)			:
			mkdir -p $(DIR_BUILD)
			mkdir -p $(DIR_BUILD)/classes

clean					:
			rm -rf $(OBJS)
			rm -r $(DIR_BUILD)

fclean					: clean
			rm -rf ${NAME}

re						: fclean all

valgrind				: ${NAME}
			valgrind ./$(NAME)

.PHONY					: all clean fclean re