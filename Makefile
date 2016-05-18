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
INC_PATH = includes
INC_FILES = buffer_42.h memory_42.h stdlib_42.h string_42.h vector_42.h

HEADERS = $(INC_FILES:%.h=$(INC_PATH)/%.h)
CFLAGS += $(addprefix -I,$(INC_PATH))

# Sources
SRC_PATH = srcs
SRC_SUBDIR = vector string stdlib memory buffer
vpath %.c $(addprefix $(SRC_PATH)/,$(SRC_SUBDIR))

# Stdlib
SOURCES += ft_realloc.c

# Memory
SOURCES += ft_memset.c ft_bzero.c ft_memalloc.c ft_memcpy.c

# String
SOURCES += ft_strlen.c ft_strdup.c ft_strsub.c ft_strnew.c \
		   ft_strchr.c ft_strrchr.c ft_strchrpos.c ft_strrchrpos.c

# Vector
SOURCES += ft_vector_init.c ft_vector_add.c ft_vector_get.c \
		   ft_vector_resize.c ft_vector_set.c ft_vector_clear.c \
		   ft_vector_destroy.c ft_vector_insert.c ft_vector_copy.c \
		   ft_vector_new.c ft_vector_replace.c ft_vector_remove.c \
		   ft_vector_indexof.c ft_vector_strsplit.c

# Buffer
SOURCES += ft_buffer_init.c ft_buffer_add.c ft_buffer_resize.c ft_buffer_set.c \
		   ft_buffer_rewindchr.c

# Objects
OBJ_PATH = obj
OBJECTS = $(addprefix $(OBJ_PATH)/, $(SOURCES:%.c=%.o))

# Tests
TEST_PATH = tests
TEST_EXEC = $(TEST_PATH)/test_lib42.out

# Benchmarks
BENCHMARKS_PATH = benchmarks
CG_OUTPUT_FILE=callgrind.output


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
	ctags -R --tag-relative=yes --exclude='.git*' --exclude=tests --exclude='*.o' --exclude='*dSYM' --exclude='*.pdf'

# Tests
.PHONY: check

check: all
	@$(MAKE) -C $(TEST_PATH) re
	@./$(TEST_EXEC)
