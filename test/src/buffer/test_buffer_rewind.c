#include "header.h"

static t_buffer b;

static void	setup(void)
{
	buffer_init(&b, 120);
	buffer_ncat(&b, "Hello World!", 12);
}

static void	teardown(void)
{
	TBUFFER_FREE(&b);
}

static void	test_00_buffer_rewind_SimpleSize(void)
{
	int res;
	setup();

	res = buffer_rewind(&b, 3);
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(9, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello Wor", TBUFFER_GET(&b));
	v_assert_int(9, ==, res);

	teardown();
	VTS;
}

static void	test_01_buffer_rewind_ZeroSize(void)
{
	int res;
	setup();

	res = buffer_rewind(&b, 0);
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(12, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello World!", TBUFFER_GET(&b));
	v_assert_int(12, ==, res);

	teardown();
	VTS;
}

static void	test_02_buffer_rewind_FullSize(void)
{
	int res;
	setup();

	res = buffer_rewind(&b, 12);
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(0, ==, TBUFFER_LEN(&b));
	v_assert_str("", TBUFFER_GET(&b));
	v_assert_int(0, ==, res);

	teardown();
	VTS;
}

static void	test_03_buffer_rewind_SizeOverflow(void)
{
	int res;
	setup();

	res = buffer_rewind(&b, 42);
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(12, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello World!", TBUFFER_GET(&b));
	v_assert_int(-1, ==, res);

	teardown();
	VTS;
}

void	suite_buffer_rewind(void)
{
	test_00_buffer_rewind_SimpleSize();
	test_01_buffer_rewind_ZeroSize();
	test_02_buffer_rewind_FullSize();
	test_03_buffer_rewind_SizeOverflow();

	VSS;
}
