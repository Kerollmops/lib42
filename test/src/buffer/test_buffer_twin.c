#include "header.h"

static void	test_00_buffer_twin_Simple(void)
{
	t_buffer	*origin;
	t_buffer	*cp;
	char		*s = "Hello World!";
	size_t		len = strlen(s);

	origin = buffer_dup(s);
	cp = buffer_twin(origin);

	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(cp));
	v_assert_size_t(len, ==, TBUFFER_LEN(cp));
	v_assert_str(s, TBUFFER_GET(cp));
	v_assert_ptr(TBUFFER_GET(origin), !=, TBUFFER_GET(cp));
	v_assert_ptr(origin, !=, cp);

	free(TBUFFER_GET(origin));
	free(TBUFFER_GET(cp));
	free(origin);
	free(cp);
	VTS;
}

void	suite_buffer_twin(void)
{
	test_00_buffer_twin_Simple();

	VSS;
}
