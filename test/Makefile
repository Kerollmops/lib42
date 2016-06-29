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
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

# Headers
INC_PATH = inc
INC_FILES = header.h
HEADERS = $(INC_FILES:%.h=$(INC_PATH)/%.h)
CFLAGS += $(addprefix -I,$(INC_PATH))


# Sources
SRC_PATH = src
SRC_SUBDIR = . array buffer memory stdlib string
vpath %.c $(addprefix $(SRC_PATH)/,$(SRC_SUBDIR))
SOURCES = main.c

# Array
SOURCES += array_add.c array_copy.c array_replace.c array_remove.c \
			array_getset.c array_indexof.c array_insert.c array_strsplit.c

# Buffer
SOURCES += buffer.c buffer_rewindchr.c buffer_rewind.c

# Memory
SOURCES += memset.c memcpy.c memccpy.c memmove.c memchr.c \
			memcmp.c

# Stdlib
SOURCES += realloc.c

# String
SOURCES += strchrpos.c strrchrpos.c strlen.c strnlen.c strdup.c strndup.c \
			strcpy.c strncpy.c strcat.c strncat.c strlcat.c strchr.c \
			strrchr.c strstr.c strnstr.c


# Objects
OBJ_PATH = obj
OBJECTS = $(addprefix $(OBJ_PATH)/,$(SOURCES:%.c=%.o))


# Lib42
LIB42_PATH = ..
LIB42 = $(LIB42_PATH)/$(NAME)
CFLAGS += -I $(LIB42_PATH)/inc
LDFLAGS += -L $(LIB42_PATH) -l42

# Vittf
VITTF_PATH = vittf
CFLAGS += -I$(VITTF_PATH)

# BSD Libc
LDFLAGS += -lbsd


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
