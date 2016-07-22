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
SOURCES += ft_memset.c
SOURCES += ft_memalloc.c
SOURCES += ft_memcpy.c
SOURCES += ft_memccpy.c
SOURCES += ft_memmove.c
SOURCES += ft_memchr.c
SOURCES += ft_memcmp.c

# Stdlib
SOURCES += ft_realloc.c

# Array
SOURCES += ft_array_init.c
SOURCES += ft_array_add.c
SOURCES += ft_array_get.c
SOURCES += ft_array_resize.c
SOURCES += ft_array_set.c
SOURCES += ft_array_clear.c
SOURCES += ft_array_destroy.c
SOURCES += ft_array_insert.c
SOURCES += ft_array_copy.c
SOURCES += ft_array_new.c
SOURCES += ft_array_replace.c
SOURCES += ft_array_remove.c
SOURCES += ft_array_indexof.c
SOURCES += ft_array_strsplit.c

# Buffer
SOURCES += ft_buffer_init.c
SOURCES += ft_buffer_add.c
SOURCES += ft_buffer_resize.c
SOURCES += ft_buffer_set.c
SOURCES += ft_buffer_rewindchr.c
SOURCES += ft_buffer_rewind.c
SOURCES += ft_buffer_insert.c
SOURCES += ft_buffer_remove.c

# String
SOURCES += ft_strlen.c
SOURCES += ft_strnlen.c
SOURCES += ft_strdup.c
SOURCES += ft_strndup.c
SOURCES += ft_strsub.c
SOURCES += ft_strcpy.c
SOURCES += ft_strncpy.c
SOURCES += ft_strcat.c
SOURCES += ft_strncat.c
SOURCES += ft_strlcat.c
SOURCES += ft_strchr.c
SOURCES += ft_strrchr.c
SOURCES += ft_strstr.c
SOURCES += ft_strnstr.c

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
