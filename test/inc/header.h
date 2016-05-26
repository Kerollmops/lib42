#ifndef TEST_LIB42_H
#define TEST_LIB42_H

#include "lib42.h"
#include "vittf.h"

// Array
void	suite_array_add(void);
void	suite_array_copy(void);
void	suite_array_replace(void);
void	suite_array_remove(void);
void	suite_array_get_set(void);
void	suite_array_indexof(void);
void	suite_array_insert(void);
void	suite_array_strsplit(void);

// Buffer
void	suite_buffer(void);
void	suite_buffer_rewindchr(void);
void	suite_buffer_rewind(void);

// Memory
void	suite_bzero(void);
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
void	suite_strchrpos(void);
void	suite_strrchrpos(void);

#endif