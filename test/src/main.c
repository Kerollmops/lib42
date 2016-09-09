#include "header.h"

int	main(void)
{
	// memory
	suite_memset();
	suite_memccpy();
	/* suite_memcmp(); */
	suite_memcpy();
	suite_memchr();
	suite_memmove();

	// stdlib
	suite_realloc();
	suite_toa_base();

	// string
#if !defined(SANITIZE)
	suite_strlen();
	suite_strnlen();
	suite_strdup();
	suite_strndup();
	suite_strchr();
	suite_strrchr();
	suite_strrev();

	// buffer
	suite_buffer_cat();
	suite_buffer_insert();
	suite_buffer_append();
#endif
	suite_buffer_remove();
	suite_buffer_set();
	suite_buffer_rewindchr();
	suite_buffer_rewind();
	suite_buffer_macros();

	// array
	suite_array_macros();
	suite_array_getset();
	suite_array_indexof();
	suite_array_create_node();
	suite_array_add();
	suite_array_replace();
	suite_array_insert();
	suite_array_remove();
	/* suite_array_copy(); */
#if !defined(SANITIZE)
	suite_array_strsplit();
#endif
	suite_array_iterator();

	// error
	suite_error();

	v_full_success("Test Lib42");
	return (0);
}
