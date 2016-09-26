#include "header.h"

static t_buffer *b;
static char		*s = "Hello World!";
static int		len = 12;

static void	setup(void)
{
	b = buffer_dup(s);
}

static void	teardown(void)
{
	TBUFFER_FREE(b);
	free(b);
}

static void	test_00_buffer_rewindnchr_FirstChar(void)
{
	int res;
	setup();

	res = buffer_rewindnchr(b, 'l', 1);
	v_assert_int(3, ==, res);

	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(b));
	v_assert_size_t(len - res, ==, TBUFFER_LEN(b));
	v_assert_str("Hello Wor", TBUFFER_GET(b));

	teardown();
	VTS;
}

static void	test_01_buffer_rewindnchr_EndOfString(void)
{
	int 	res;
	setup();

	res = buffer_rewindnchr(b, '\0', 1);
	v_assert_int(-1, ==, res);

	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(b));
	v_assert_size_t(len, ==, TBUFFER_LEN(b));
	v_assert_str(s, TBUFFER_GET(b));

	teardown();
	VTS;
}

static void	test_02_buffer_rewindnchr_LastChar(void)
{
	int res;
	setup();

	res = buffer_rewindnchr(b, '!', 2);
	v_assert_int(1, ==, res);

	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(b));
	v_assert_size_t(len - res, ==, TBUFFER_LEN(b));
	v_assert_str("Hello World", TBUFFER_GET(b));

	teardown();
	VTS;
}

static void	test_03_buffer_rewindnchr_FirstChar(void)
{
	int	res;
	setup();

	res = buffer_rewindnchr(b, 'H', 8);
	v_assert_int(len, ==, res);

	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(b));
	v_assert_size_t(0, ==, TBUFFER_LEN(b));
	v_assert_str("", TBUFFER_GET(b));

	teardown();
	VTS;
}

static void	test_04_buffer_rewindnchr_MultipleOccurrence(void)
{
	int	res;
	setup();

	res = buffer_rewindnchr(b, 'o', 2);
	v_assert_int(8, ==, res);

	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(b));
	v_assert_size_t(len - res, ==, TBUFFER_LEN(b));
	v_assert_str("Hell", TBUFFER_GET(b));

	teardown();
	VTS;
}

static void	test_05_buffer_rewindnchr_MultipleOccurrence0Times(void)
{
	int	res;
	setup();

	res = buffer_rewindnchr(b, 'o', 0);
	v_assert_int(-1, ==, res);

	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(b));
	v_assert_size_t(len, ==, TBUFFER_LEN(b));
	v_assert_str(s, TBUFFER_GET(b));

	teardown();
	VTS;
}

static void	test_06_buffer_rewindnchr_MultipleOccurrenceNTimes(void)
{
	int	res;
	setup();

	res = buffer_rewindnchr(b, 'l', 2);
	v_assert_int(9, ==, res);

	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(b));
	v_assert_size_t(len - res, ==, TBUFFER_LEN(b));
	v_assert_str("Hel", TBUFFER_GET(b));

	teardown();
	VTS;
}

static void	test_07_buffer_rewindnchr_NotFound(void)
{
	int res;
	setup();

	res = buffer_rewindnchr(b, '#', 1);
	v_assert_int(-1, ==, res);

	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(b));
	v_assert_size_t(len, ==, TBUFFER_LEN(b));
	v_assert_str(s, TBUFFER_GET(b));

	teardown();
	VTS;
}

void	suite_buffer_rewindnchr(void)
{
	test_00_buffer_rewindnchr_FirstChar();
	test_01_buffer_rewindnchr_EndOfString();
	test_02_buffer_rewindnchr_LastChar();
	test_03_buffer_rewindnchr_FirstChar();
	test_04_buffer_rewindnchr_MultipleOccurrence();
	test_05_buffer_rewindnchr_MultipleOccurrence0Times();
	test_06_buffer_rewindnchr_MultipleOccurrenceNTimes();
	test_07_buffer_rewindnchr_NotFound();

	VSS;
}
