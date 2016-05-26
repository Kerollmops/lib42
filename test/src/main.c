#include "header.h"

int	main(void)
{
	// stdlib
	suite_realloc();

	// string
	suite_strlen();
	suite_strchrpos();
	suite_strrchrpos();

	// memory
	suite_memset();
	suite_bzero();
	suite_memccpy();
	suite_memcmp();
	suite_memcpy();
	suite_memchr();
	suite_memmove();

	// buffer
	suite_buffer();
	suite_buffer_rewindchr();
	suite_buffer_rewind();

	// array
	suite_array_add();
	suite_array_get_set();
	suite_array_copy();
	suite_array_replace();
	suite_array_remove();
	suite_array_indexof();
	suite_array_insert();
	suite_array_strsplit();

	v_full_success("Test Lib42");
	return (0);
}
