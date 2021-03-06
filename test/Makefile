NAME = test_lib42.out
CC ?= clang
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -pedantic-errors -Wno-unused-variable -Wno-unused-function

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
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -DSANITIZE
endif

# Headers
INC_PATH = inc
INC_FILES = header.h
HEADERS = $(INC_FILES:%.h=$(INC_PATH)/%.h)
CFLAGS += $(addprefix -I,$(INC_PATH))


# Sources
SRC_PATH = src
SRC_SUBDIR = . array buffer memory stdlib string error
vpath %.c $(addprefix $(SRC_PATH)/,$(SRC_SUBDIR))
SOURCES = main.c

# Array
SOURCES += test_array_macros.c
SOURCES += test_array_getset.c
SOURCES += test_array_indexof.c
SOURCES += test_array_create_node.c
SOURCES += test_array_add.c
SOURCES += test_array_replace.c
SOURCES += test_array_insert.c
SOURCES += test_array_remove.c
SOURCES += test_array_strsplit.c
# SOURCES += test_array_copy.c
SOURCES += test_array_iterator.c

# Buffer
SOURCES += test_buffer_new.c
SOURCES += test_buffer_resize.c
SOURCES += test_buffer_macros.c
SOURCES += test_buffer_cat.c
SOURCES += test_buffer_dup.c
SOURCES += test_buffer_insert.c
SOURCES += test_buffer_remove.c
SOURCES += test_buffer_set.c
SOURCES += test_buffer_rewind.c
SOURCES += test_buffer_rewindchr.c
# SOURCES += test_buffer_rewindnchr.c
SOURCES += test_buffer_append.c
SOURCES += test_buffer_replace.c
SOURCES += test_buffer_twin.c
SOURCES += test_buffer_merge.c
SOURCES += test_buffer_iterator.c

# Memory
SOURCES += test_memset.c
SOURCES += test_memcpy.c
SOURCES += test_memccpy.c
SOURCES += test_memmove.c
SOURCES += test_memchr.c
SOURCES += test_memcmp.c

# Stdlib
SOURCES += test_realloc.c
SOURCES += test_toa_base.c
SOURCES += test_next_power2.c

# String
SOURCES += test_strlen.c
SOURCES += test_strnlen.c
SOURCES += test_strdup.c
SOURCES += test_strndup.c
SOURCES += test_strchr.c
SOURCES += test_strrchr.c
SOURCES += test_strrev.c

# Error
SOURCES += test_error.c


# Objects
OBJ_PATH = obj
OBJECTS = $(addprefix $(OBJ_PATH)/,$(SOURCES:%.c=%.o))


# Lib42
LIB42_PATH = ..
LIB42 = $(LIB42_PATH)/lib42.a
CFLAGS += -I $(LIB42_PATH)/inc
LDFLAGS += -L $(LIB42_PATH) -l42

# Vittf
VITTF_PATH = vittf
CFLAGS += -I$(VITTF_PATH)

# BSD Libc
UNAME_S := $(shell uname -s)
ifneq ($(UNAME_S), Darwin)
	LDFLAGS += -lbsd
endif




# Rules
.PHONY: all

all: $(NAME)

$(LIB42):
	$(MAKE) -C $(LIB42_PATH) all

$(NAME): $(OBJECTS) | $(LIB42)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJECTS): $(HEADERS) | $(OBJ_PATH)
$(OBJECTS): $(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@-mkdir -p $@

.PHONY: clean fclean re

clean:
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all


# Submodule
.PHONY: sub-update sub-init

sub-init:
	git submodule update --init

sub-update:
	git submodule update --remote


# Tools
.PHONY: norme valgrind ctags clean-tools

norme:
	@norminette $(SRC_PATH)
	@norminette $(INC_PATH)

valgrind:
	valgrind --leak-check=full ./$(NAME)

callgrind:
	valgrind --tool=callgrind ./$(NAME)
	callgrind_annotate callgrind*.out

ctags:
	ctags -R --tag-relative=yes --exclude='.git*' --exclude='test' --exclude='*.o' --exclude='*dSYM' --exclude='doc'

clean-tools:
	$(RM) -r *.dSYM/
