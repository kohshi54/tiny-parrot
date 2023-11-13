NAME = tiny-parrot
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11
DEPFLAGS = -MMD -MP -MF $(DEP_DIR)$*.d

SRC_DIR		= src/
OBJ_DIR		= obj/
DEP_DIR		= dep/
SRCS = main.cpp register.cpp decode.cpp format.cpp execute.cpp memory.cpp
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.cpp=%.o))
DEPS = $(addprefix $(DEP_DIR), $(SRCS:%.cpp=%.d))

INCLUDES = -I./include
vpath %.cpp $(SRC_DIR)

all :  $(OBJ_DIR) $(DEP_DIR) $(NAME)

$(OBJ_DIR) $(DEP_DIR) :
	@mkdir -p $@

ifdef DEBUG
$(OBJ_DIR)%.o: %.cpp
	$(CC) -DDEBUG $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@
else
$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@
endif

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS) $(DEPS) $(DEP_DIR) $(OBJ_DIR)
	rm -rf build

fclean : clean
	rm -f $(NAME)

re : fclean all

debug :
	@make DEBUG=1

-include $(DEPS)

.PHONY : clean fclean re all test debug