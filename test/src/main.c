#include "header.h"

int	main(void)
{
	// memory
	suite_memset();
	suite_memccpy();
	suite_memcmp();
	suite_memcpy();
	suite_memchr();
	suite_memmove();

	// stdlib
	suite_realloc();

	// string
#if !defined(SANITIZE)
	suite_strlen();
	suite_strnlen();
	suite_strdup();
	suite_strndup();
	suite_strcpy();
	suite_strncpy();
	suite_strchr();
	suite_strcat();
	suite_strncat();
	suite_strlcat();
	suite_strrchr();
	suite_strstr();
	suite_strnstr();
#endif

	// buffer
	suite_buffer();
	suite_buffer_rewindchr();
	suite_buffer_rewind();

	// array
	suite_array_add();
	suite_array_insert();
	suite_array_indexof();
	suite_array_replace();
	suite_array_remove();
	suite_array_clear();
	suite_array_copy();
#if !defined(SANITIZE)
	suite_array_strsplit();
#endif
	suite_array_iterator();

	// error
	suite_error();

	v_full_success("Test Lib42");
	return (0);
}
