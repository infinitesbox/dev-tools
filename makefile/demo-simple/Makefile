# Simple makefile

# Couleurs ANSI
COLOR_RESET   := \033[0m
COLOR_GREEN   := \033[32m
COLOR_YELLOW  := \033[33m

CC := clang
# Compiler flags
CFLAGS := -Wall -Wextra -Werror
NAME := demo
SRCS := demo.c print.c
OBJS := $(SRCS:.c=.o)

# Rule "all" to build the executable
all: $(NAME)
	@echo "$(COLOR_YELLOW)Build complete: $(NAME)$(COLOR_RESET)"

# Rule to build the executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(COLOR_YELLOW)Linking objects to create executable.$(COLOR_RESET)"

# Rule to compile object files
%.o: %.c demo.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_YELLOW)Compiling $<.$(COLOR_RESET)"

# Rule "clean" to clean object files
clean:
	@rm -f $(OBJS)
	@echo "$(COLOR_YELLOW)Cleaned up object files and temporary directories.$(COLOR_RESET)"

# Rule "fclean" to clean all generated files
fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_YELLOW)Cleaned up all generated files, including the executable.$(COLOR_RESET)"

# Rule to clean and rebuild the executable
re: fclean all
	@echo "$(COLOR_YELLOW)Rebuild complete: $(NAME)$(COLOR_RESET)"

.PHONY:	all clean fclean