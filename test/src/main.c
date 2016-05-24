#include "header.h"

int	main(void)
{
	// stdlib
	suite_realloc();

	// string
	suite_strchrpos();
	suite_strrchrpos();

	// memory
	suite_memset();
	suite_bzero();
	suite_memcpy();
	suite_memccpy();
	suite_memmove();

	// buffer
	suite_buffer();
	suite_buffer_rewindchr();
	suite_buffer_rewind();

	// vector
	suite_ft_vector_add();
	suite_ft_vector_get_set();
	suite_ft_vector_copy();
	suite_ft_vector_replace();
	suite_ft_vector_remove();
	suite_ft_vector_indexof();
	suite_ft_vector_insert();
	suite_ft_vector_strsplit();

	v_full_success("Test Lib42");
	return (0);
}
