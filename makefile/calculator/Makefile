# This is a sample Makefile for the "calculator" project

# Couleurs ANSI
COLOR_RESET   := \033[0m
COLOR_GREEN   := \033[32m
COLOR_YELLOW  := \033[33m

CC := clang
# Compiler flags
CFLAGS := -Wall -Wextra -Werror

DIR_SRC := src
DIR_INC	:= inc
DIR_BIN := bin
DIR_LIBS := libs
DIR_TMP := tmp

LIB_MATHX_PATH := ../mathx
LIB_MATHX := $(LIB_MATHX_PATH)/libmathx.so
LIB_MATHX_NAME := mathx

# Executable name
NAME := $(DIR_BIN)/calculator

# Source files
SRCS := $(shell find $(DIR_SRC) \
	-name '*.c')

# Object files
#   patsubst: Pattern substitution function in Makefile
#   $(DIR_SRC)/%.c: Pattern for source files in $(DIR_SRC) directory
#   $(DIR_TMP)/%.o: Pattern for corresponding object files in $(DIR_TMP) directory
#   $(SRCS): List of source files found in $(DIR_SRC) using the 'find' command
#   This line creates a list of object files by replacing the source file directory
#   with the temporary directory and changing the file extension from .c to .o.
OBJS := $(patsubst $(DIR_SRC)/%.c,$(DIR_TMP)/%.o,$(SRCS))

# Rule "all" to build the executable
all: _dirs _libs $(NAME)
	@echo "$(COLOR_YELLOW)Build complete: $(NAME)$(COLOR_RESET)"

# Rule to build the executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Wl,-rpath=../$(LIB_MATHX_PATH) -L $(LIB_MATHX_PATH) -l $(LIB_MATHX_NAME)
	@echo "$(COLOR_YELLOW)Linking objects to create executable.$(COLOR_RESET)"

# Rule to compile object files
# 	@$(CC): Compiler used (clang)
# 	$(CFLAGS): Compilation flags (e.g., -Wall -Wextra -Werror)
# 	-I$(DIR_INC): Include directory for header files
# 	-c: Compile only, do not link
# 	$<: The first dependency (source file)
# 	This rule states that all .c files in $(DIR_SRC) will become .o files in $(DIR_TMP),
# 	and the object files will keep the same name as their respective source files.
#  -o $@: Output option specifying the target file (object file)
$(DIR_TMP)/%.o: $(DIR_SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC) -I $(LIB_MATHX_PATH)
	@echo "$(COLOR_YELLOW)Compiling $<.$(COLOR_RESET)"

# Rule "clean" to clean object files
clean:
	@rm -f $(OBJS)
	@rm -Rf $(DIR_TMP)
	@echo "$(COLOR_YELLOW)Cleaned up object files and temporary directories.$(COLOR_RESET)"

# Rule "fclean" to clean all generated files
fclean: clean
	@rm -Rf $(DIR_BIN)
	@rm -Rf $(DIR_LIBS)
	@echo "$(COLOR_YELLOW)Cleaned up all generated files, including the executable.$(COLOR_RESET)"

# Rule to clean and rebuild the executable
re: fclean all
	@echo "$(COLOR_YELLOW)Rebuild complete: $(NAME)$(COLOR_RESET)"

_dirs:
	$(shell mkdir -p $(DIR_BIN))
	@echo "$(COLOR_GREEN)Created bin directory.$(COLOR_RESET)"
	$(shell mkdir -p $(DIR_LIBS))
	@echo "$(COLOR_GREEN)Created libs directory.$(COLOR_RESET)"
	$(shell mkdir -p $(DIR_TMP))
	@echo "$(COLOR_GREEN)Created tmp directory.$(COLOR_RESET)"
	$(shell mkdir -p $(DIR_TMP)/menu)
	@echo "$(COLOR_GREEN)Created tmp/menu directory.$(COLOR_RESET)"


# Example de load libs
_libs:
	@mkdir -p $(DIR_LIBS)
	@make -C $(LIB_MATHX_PATH) -f MakefileD re
	@cp $(LIB_MATHX) $(DIR_LIBS)

# Declare the following targets as phony, indicating they represent actions, not files
.PHONY: all clean fclean re