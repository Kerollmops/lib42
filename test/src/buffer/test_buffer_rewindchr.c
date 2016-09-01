#include "header.h"

static t_buffer b;

static void	setup(void)
{
	buffer_init(&b, 128);
	buffer_ncat(&b, "Hello World!", 12);
}

static void	teardown(void)
{
	TBUFFER_FREE(&b);
}

void	test_00_buffer_rewindchr_SimpleRewind(void)
{
	/* size_t res; */
	setup();

	/* res = buffer_rewindchr(&b, 'l'); */
	buffer_rewindchr(&b, 'l');
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(9, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello Wor", TBUFFER_GET(&b));

	teardown();
	VTS;
}

void	test_01_buffer_rewindchr_EndOfString(void)
{
	/* size_t res; */
	setup();

	/* res = buffer_rewindchr(&b, '\0'); */
	buffer_rewindchr(&b, '\0');
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(12, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello World!", TBUFFER_GET(&b));

	teardown();
	VTS;
}

void	test_02_buffer_rewindchr_LastChar(void)
{
	/* size_t res; */
	setup();

	/* res = buffer_rewindchr(&b, '!'); */
	buffer_rewindchr(&b, '!');
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(11, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello World", TBUFFER_GET(&b));

	teardown();
	VTS;
}

void	test_03_buffer_rewindchr_FirstChar(void)
{
	/* size_t res; */
	setup();

	/* res = buffer_rewindchr(&b, 'H'); */
	buffer_rewindchr(&b, 'H');
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(0, ==, TBUFFER_LEN(&b));
	v_assert_str("", TBUFFER_GET(&b));

	teardown();
	VTS;
}

void	test_04_buffer_rewindchr_MultipleOccurrence(void)
{
	/* size_t res; */
	setup();

	/* res = buffer_rewindchr(&b, 'o'); */
	buffer_rewindchr(&b, 'o');
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(7, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello W", TBUFFER_GET(&b));

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
