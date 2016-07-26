#ifndef TEST_LIB42_H
#define TEST_LIB42_H

#define _XOPEN_SOURCE 700
#define _DEFAUTL_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <bsd/string.h>
#include "lib42.h"
#include "vittf.h"

// Array
void	suite_array_add(void);
void	suite_array_insert(void);
void	suite_array_indexof(void);
void	suite_array_set(void);
void	suite_array_remove(void);
void	suite_array_destroy(void);
void	suite_array_clear(void);
void	suite_array_reset(void);
void	suite_array_copy(void);
void	suite_array_strsplit(void);
void	suite_array_iterator(void);

// Buffer
void	suite_buffer(void);
void	suite_buffer_rewindchr(void);
void	suite_buffer_rewind(void);

// Memory
void	suite_memcpy(void);
void	suite_memccpy(void);
void	suite_memcmp(void);
void	suite_memmove(void);
void	suite_memset(void);
void	suite_memchr(void);

// Stdlib
void	suite_realloc(void);

// String
void	suite_strlen(void);
void	suite_strnlen(void);
void	suite_strdup(void);
void	suite_strndup(void);
void	suite_strcpy(void);
void	suite_strncpy(void);
void	suite_strcat(void);
void	suite_strncat(void);
void	suite_strlcat(void);
void	suite_strchr(void);
void	suite_strrchr(void);
void	suite_strstr(void);
void	suite_strnstr(void);

// Error
void	suite_error(void);

#endif
