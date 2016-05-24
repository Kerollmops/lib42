#include "header.h"

static t_buffer b;

static void	setup(void)
{
	ft_buffer_init(&b, 128);
	ft_buffer_add(&b, "Hello World!", 12);
}

static void	teardown(void)
{
	FT_BUFFER_FREE(&b);
}

void	test_00_buffer_rewind_SimpleSize(void)
{
	int res;
	setup();

	res = ft_buffer_rewind(&b, 3);
	v_assert_size_t(128, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(9, ==, FT_BUFFER_LEN(&b));
	v_assert_str("Hello Wor", FT_BUFFER_GET(&b));
	v_assert_int(9, ==, res);

	teardown();
	VTS;
}

void	test_01_buffer_rewind_ZeroSize(void)
{
	int res;
	setup();

	res = ft_buffer_rewind(&b, 0);
	v_assert_size_t(128, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(12, ==, FT_BUFFER_LEN(&b));
	v_assert_str("Hello World!", FT_BUFFER_GET(&b));
	v_assert_int(12, ==, res);

	teardown();
	VTS;
}

void	test_02_buffer_rewind_FullSize(void)
{
	int res;
	setup();

	res = ft_buffer_rewind(&b, 12);
	v_assert_size_t(128, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(0, ==, FT_BUFFER_LEN(&b));
	v_assert_str("", FT_BUFFER_GET(&b));
	v_assert_int(0, ==, res);

	teardown();
	VTS;
}

void	test_03_buffer_rewind_SizeOverflow(void)
{
	int res;
	setup();

	res = ft_buffer_rewind(&b, 42);
	v_assert_size_t(128, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(12, ==, FT_BUFFER_LEN(&b));
	v_assert_str("Hello World!", FT_BUFFER_GET(&b));
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
