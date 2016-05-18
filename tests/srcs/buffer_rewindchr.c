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

void	test_00_buffer_rewindchr_SimpleRewind(void)
{
	size_t res;
	setup();

	res = ft_buffer_rewindchr(&b, 'l');
	v_assert_size_t(128, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(9, ==, FT_BUFFER_LEN(&b));
	v_assert_str("Hello Wor", FT_BUFFER_GET(&b));

	teardown();
	VTS;
}

void	test_01_buffer_rewindchr_EndOfString(void)
{
	size_t res;
	setup();

	res = ft_buffer_rewindchr(&b, '\0');
	v_assert_size_t(128, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(12, ==, FT_BUFFER_LEN(&b));
	v_assert_str("Hello World!", FT_BUFFER_GET(&b));

	teardown();
	VTS;
}

void	test_02_buffer_rewindchr_LastChar(void)
{
	size_t res;
	setup();

	res = ft_buffer_rewindchr(&b, '!');
	v_assert_size_t(128, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(11, ==, FT_BUFFER_LEN(&b));
	v_assert_str("Hello World", FT_BUFFER_GET(&b));

	teardown();
	VTS;
}

void	test_03_buffer_rewindchr_FirstChar(void)
{
	size_t res;
	setup();

	res = ft_buffer_rewindchr(&b, 'H');
	v_assert_size_t(128, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(0, ==, FT_BUFFER_LEN(&b));
	v_assert_str("", FT_BUFFER_GET(&b));

	teardown();
	VTS;
}

void	test_04_buffer_rewindchr_MultipleOccurrence(void)
{
	size_t res;
	setup();

	res = ft_buffer_rewindchr(&b, 'o');
	v_assert_size_t(128, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(7, ==, FT_BUFFER_LEN(&b));
	v_assert_str("Hello W", FT_BUFFER_GET(&b));

	teardown();
	VTS;
}

void	suite_buffer_rewindchr(void)
{
	test_00_buffer_rewindchr_SimpleRewind();
	test_01_buffer_rewindchr_EndOfString();
	test_02_buffer_rewindchr_LastChar();
	test_03_buffer_rewindchr_FirstChar();
	test_04_buffer_rewindchr_MultipleOccurrence();

	VSS;
}
