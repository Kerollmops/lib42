#include "header.h"

int	main(void)
{
	// vector
	suite_ft_vector_add();
	suite_ft_vector_get_set();
	suite_ft_vector_copy();
	suite_ft_vector_replace();
	suite_ft_vector_remove();
	suite_ft_vector_indexof();
	suite_ft_vector_insert();

	v_full_success("Test Lib42");
	return (0);
}
