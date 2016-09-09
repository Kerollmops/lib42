#include "header.h"

static t_buffer	*b;

static void	teardown(void)
{
	free(b->str);
	free(b);
}

static void	test_00_buffer_dup_String(void)
{
	char	*s = "Hello world";
	size_t	len = strlen(s);

	b = buffer_dup(s);

	v_assert_size_t(len, ==, b->len);
	v_assert_str(s, b->str);

	teardown();
	VTS;
}

static void	test_01_buffer_dup_EmptyString(void)
{
	char	*s = "";
	size_t	len = strlen(s);

	b = buffer_dup(s);

	v_assert_size_t(len, ==, b->len);
	v_assert_str(s, b->str);

	teardown();
	VTS;
}

static void	test_02_buffer_ndup_SimpleString(void)
{
	char	*s = "Hello World!";
	size_t	len = strlen(s);

	b = buffer_ndup(s, 5);

	v_assert_size_t(5, ==, b->len);
	v_assert_str("Hello", b->str);

	teardown();
	VTS;
}

static void	test_03_buffer_ndup_ShortenString(void)
{
	char	*s = "abc";
	size_t	len = strlen(s);

	b = buffer_ndup(s, 10);

	v_assert_size_t(11, ==, TBUFFER_MAX(b));
	v_assert_size_t(3, ==, b->len);
	v_assert_str("abc", b->str);

	teardown();
	VTS;
}

static void	test_04_buffer_ndup_ZeroLength(void)
{
	char	*s = "World!";
	size_t	len = strlen(s);

	b = buffer_ndup(s, 0);

	v_assert_size_t(0, ==, b->len);
	v_assert_str("", b->str);

	teardown();
	VTS;
}

static void	test_05_buffer_cdup_CharInString(void)
{
	char	*s = "Hello World!";
	size_t	len = strlen(s);

	b = buffer_cdup(s, 'W');

	v_assert_size_t(7, ==, b->len);
	v_assert_str("Hello W", b->str);

	teardown();
	VTS;
}

static void	test_06_buffer_cdup_CharNotInString(void)
{
	char	*s = "Hello World!";
	size_t	len = strlen(s);

	b = buffer_cdup(s, 'z');

	v_assert_ptr(NULL, ==, b);

	VTS;
}

void	suite_buffer_dup(void)
{
	test_00_buffer_dup_String();
	test_01_buffer_dup_EmptyString();
	test_02_buffer_ndup_SimpleString();
	test_03_buffer_ndup_ShortenString();
	test_04_buffer_ndup_ZeroLength();
	test_05_buffer_cdup_CharInString();
	test_06_buffer_cdup_CharNotInString();

	VSS;
}
