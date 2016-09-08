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
# SOURCES += ft_memcmp.c

# Stdlib
SOURCES += ft_realloc.c
SOURCES += ft_toa_base.c

# Array
SOURCES += array_new.c
SOURCES += array_resize.c
SOURCES += array_getset.c
SOURCES += array_indexof.c
SOURCES += array_create_node.c
SOURCES += array_add.c
SOURCES += array_replace.c
SOURCES += array_insert.c
SOURCES += array_reset.c
SOURCES += array_destroy.c
SOURCES += array_remove.c
SOURCES += array_delete.c
SOURCES += array_strsplit.c
SOURCES += array_iter.c

# Buffer
SOURCES += buffer_cat.c
SOURCES += buffer_destroy.c
SOURCES += buffer_insert.c
SOURCES += buffer_merge.c
SOURCES += buffer_new.c
SOURCES += buffer_remove.c
SOURCES += buffer_replace.c
SOURCES += buffer_resize.c
SOURCES += buffer_rewind.c
SOURCES += buffer_set.c
SOURCES += buffer_toa.c
SOURCES += buffer_twin.c
SOURCES += buffer_append.c

# String
SOURCES += ft_strlen.c
SOURCES += ft_strdup.c
SOURCES += ft_strsub.c
SOURCES += ft_strchr.c
SOURCES += ft_strrchr.c
SOURCES += ft_strrev.c

# Error
SOURCES += ft_error.c
SOURCES += ft_die.c

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
