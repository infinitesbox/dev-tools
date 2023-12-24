# Simple makefile - Dynamic Library

# Couleurs ANSI
COLOR_RESET   := \033[0m
COLOR_GREEN   := \033[32m
COLOR_YELLOW  := \033[33m

CC := clang
# Compiler flags
FLAGS := -Wall -Wextra -Werror
NAME := mathx
SRCS := main.c 
OBJS := $(SRCS:.c=.o)
LIB_PATH := ../
LIB := $(LIB_PATH)/libmathx.so
LIB_NAME := mathx

# Rule "all" to build the executable
all: _lib $(NAME)
	@echo "$(COLOR_YELLOW)Build complete: $(NAME)$(COLOR_RESET)"

# Rule to build the executable
$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) -Wl,-rpath=$(LIB_PATH) -L $(LIB_PATH) -l $(LIB_NAME)
	@echo "$(COLOR_YELLOW)Linking objects to create executable.$(COLOR_RESET)"

# Rule to compile object files
%.o: %.c 
	@$(CC) $(FLAGS) -c $< -o $@ -I $(LIB_PATH)
	@echo "$(COLOR_YELLOW)Compiling $<.$(COLOR_RESET)"

# Rule to create the static library
_lib:
	@make -C $(LIB_PATH) -f MakefileD
	@echo "$(COLOR_YELLOW)Creating static library: $(LIB)$(COLOR_RESET)"

# Rule "clean" to clean object files
clean:
	@rm -f $(OBJS)
	@echo "$(COLOR_YELLOW)Cleaned up object files and temporary directories.$(COLOR_RESET)"

# Rule "fclean" to clean all generated files
fclean: clean
	@rm -f $(NAME)
	@make clean -C $(LIB_PATH) -f MakefileD
	@echo "$(COLOR_YELLOW)Cleaned up all generated files, including the executable.$(COLOR_RESET)"

# Rule to clean and rebuild the executable
re: fclean all
	@echo "$(COLOR_YELLOW)Rebuild complete: $(NAME)$(COLOR_RESET)"

.PHONY:	all clean fclean