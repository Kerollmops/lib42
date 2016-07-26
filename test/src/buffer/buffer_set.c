#include "header.h"

void	test_00_buffer_set_simple(void)
{
	t_buffer b;
	char	*s = "**********";
	size_t len = strlen(s);

	buffer_init(&b, 0);
	buffer_set(&b, '*', 10);
	buffer_set(&b, '\0', 1);
	v_assert_str(s, b.str);
	v_assert_size_t(len + 1, ==, TBUFFER_LEN(&b));

	buffer_set(&b, '#', 1);
	v_assert_str(s, b.str);
	v_assert_size_t(len + 2, ==, TBUFFER_LEN(&b));

	TBUFFER_FREE(&b);
	VTS;
}

void	suite_buffer_set(void)
{
	test_00_buffer_set_simple();

	VSS;
}
