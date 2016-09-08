#include "header.h"

static void	test_00_buffer_RESET_InIfStatement(void)
{
	t_buffer	*buf;

	buf = buffer_new(8);
	buffer_cat(buf, "hello");
	if (1)
		TBUFFER_RESET(buf);

	v_assert_size_t(0, ==, buf->len);
	v_assert_str("", buf->str);

	free(TBUFFER_GET(buf));
	free(buf);
	VTS;
}

static void	test_01_buffer_RESET_NotInBlockStatement(void)
{
	t_buffer	*buf;

	buf = buffer_new(8);
	buffer_cat(buf, "world");

	TBUFFER_RESET(buf);

	v_assert_size_t(0, ==, buf->len);
	v_assert_str("", buf->str);

	free(TBUFFER_GET(buf));
	free(buf);
	VTS;
}

void	suite_buffer_macros(void)
{
	test_00_buffer_RESET_InIfStatement();
	test_01_buffer_RESET_NotInBlockStatement();

	VSS;
}
