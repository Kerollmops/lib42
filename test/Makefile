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
SOURCES += buffer_new.c
SOURCES += buffer_resize.c
SOURCES += buffer_macros.c
SOURCES += buffer_cat.c
SOURCES += buffer_dup.c
SOURCES += buffer_insert.c
SOURCES += buffer_remove.c
SOURCES += buffer_set.c
SOURCES += buffer_rewindchr.c
SOURCES += buffer_rewind.c
SOURCES += buffer_append.c

# Memory
SOURCES += memset.c
SOURCES += memcpy.c
SOURCES += memccpy.c
SOURCES += memmove.c
SOURCES += memchr.c
# SOURCES += memcmp.c

# Stdlib
SOURCES += realloc.c
SOURCES += toa_base.c
SOURCES += next_power2.c

# String
SOURCES += strlen.c
SOURCES += strnlen.c
SOURCES += strdup.c
SOURCES += strndup.c
SOURCES += strchr.c
SOURCES += strrchr.c
SOURCES += strrev.c

# Error
SOURCES += error.c


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
