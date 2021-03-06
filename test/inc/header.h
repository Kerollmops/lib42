#ifndef TEST_LIB42_H
#define TEST_LIB42_H

#define _XOPEN_SOURCE 700
#define _DEFAUTL_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#if !defined(__APPLE__)
#include <bsd/string.h>
#endif
#include <stdint.h>
#include <stdio.h>
#include "lib42.h"
#include "vittf.h"

// Array
void	suite_array_macros(void);
void	suite_array_getset(void);
void	suite_array_indexof(void);
void	suite_array_create_node(void);
void	suite_array_add(void);
void	suite_array_replace(void);
void	suite_array_insert(void);
void	suite_array_remove(void);
void	suite_array_strsplit(void);
void	suite_array_iterator(void);
/* void	suite_array_copy(void); */

// Buffer
void	suite_buffer_macros(void);
void	suite_buffer_new(void);
void	suite_buffer_resize(void);
void	suite_buffer_dup(void);
void	suite_buffer_cat(void);
void	suite_buffer_insert(void);
void	suite_buffer_remove(void);
void	suite_buffer_set(void);
void	suite_buffer_rewind(void);
void	suite_buffer_rewindchr(void);
/* void	suite_buffer_rewindnchr(void); */
void	suite_buffer_append(void);
void	suite_buffer_replace(void);
void	suite_buffer_twin(void);
void	suite_buffer_merge(void);
void	suite_buffer_iterator(void);

// Memory
void	suite_memcpy(void);
void	suite_memccpy(void);
void	suite_memcmp(void);
void	suite_memmove(void);
void	suite_memset(void);
void	suite_memchr(void);

// Stdlib
void	suite_realloc(void);
void	suite_toa_base(void);
void	suite_next_power_of_2(void);

// String
void	suite_strlen(void);
void	suite_strnlen(void);
void	suite_strdup(void);
void	suite_strndup(void);
void	suite_strchr(void);
void	suite_strrchr(void);
void	suite_strrev(void);

// Error
void	suite_error(void);

#endif
