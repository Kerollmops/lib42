NAME = lib42.a
CC ?= clang
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -pedantic-errors -fno-strict-aliasing

#Debug
ifeq ($(DEBUG),yes)
	CFLAGS += -g3 -O0 -fno-inline
endif

# Profile
ifeq ($(PROF),yes)
	CFLAGS += -pg
endif

# Opti
ifeq ($(PROD),yes)
	CFLAGS += -O2
endif

# Sanitize
ifeq ($(SAN),yes)
	LDFLAGS += -fsanitize=address
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

# Headers
INC_PATH = inc
INC_FILES += lib42.h
INC_FILES += typedefs_42.h
INC_FILES += structs_42.h
INC_FILES += macros_42.h
INC_FILES += memory_42.h
INC_FILES += stdlib_42.h
INC_FILES += string_42.h
INC_FILES += array_42.h
INC_FILES += buffer_42.h
INC_FILES += error_42.h

HEADERS = $(INC_FILES:%.h=$(INC_PATH)/%.h)
CFLAGS += $(addprefix -I,$(INC_PATH))

# Sources
SRC_PATH = src
SRC_SUBDIR += array
SRC_SUBDIR += string
SRC_SUBDIR += stdlib
SRC_SUBDIR += memory
SRC_SUBDIR += buffer
SRC_SUBDIR += error
vpath %.c $(addprefix $(SRC_PATH)/,$(SRC_SUBDIR))

# Memory
SOURCES += ft_memset.c ft_memalloc.c ft_memcpy.c \
		   ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c

# Stdlib
SOURCES += ft_realloc.c

# Array
SOURCES += ft_array_init.c ft_array_add.c ft_array_get.c \
		   ft_array_resize.c ft_array_set.c ft_array_clear.c \
		   ft_array_destroy.c ft_array_insert.c ft_array_copy.c \
		   ft_array_new.c ft_array_replace.c ft_array_remove.c \
		   ft_array_indexof.c ft_array_strsplit.c

# Buffer
SOURCES += ft_buffer_init.c ft_buffer_add.c ft_buffer_resize.c ft_buffer_set.c \
		   ft_buffer_rewindchr.c ft_buffer_rewind.c

# String
SOURCES += ft_strlen.c ft_strnlen.c ft_strdup.c ft_strndup.c ft_strsub.c \
			ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strchrpos.c ft_strrchrpos.c \
			ft_strstr.c ft_strnstr.c

# Error
SOURCES += ft_error.c

# Objects
OBJ_PATH = obj
OBJECTS = $(addprefix $(OBJ_PATH)/, $(SOURCES:%.c=%.o))

# Tests
TEST_PATH = test
TEST_EXEC = $(TEST_PATH)/test_lib42.out


# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

$(OBJECTS): $(HEADERS) | $(OBJ_PATH)
$(OBJECTS): $(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@-mkdir -p $@

.PHONY: all clean fclean re

clean:
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all


# Tools
.PHONY: norme ctags

norme:
	@norminette $(SRC_PATH)
	@norminette $(HEADERS)

ctags:
	ctags -R --tag-relative=yes --exclude='.git*' --exclude=test --exclude='*.o' --exclude='*dSYM' --exclude='*.pdf'

# Tests
.PHONY: check

check: re
	@$(MAKE) -C $(TEST_PATH) re
	@./$(TEST_EXEC)
