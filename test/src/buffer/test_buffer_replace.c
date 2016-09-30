#include "header.h"

static t_buffer	*buffer;

static void	setup(char *s, size_t len, size_t max)
{
	buffer = malloc(sizeof(t_buffer));
	buffer->str = malloc(max);
	memset(buffer->str, 0, max);
	memcpy(buffer->str, s, len);
	buffer->len = len;
	buffer->sizemax = max;
}

static void	teardown(void)
{
	free(buffer->str);
	memset(buffer, 0, sizeof(t_buffer));
	free(buffer);
}

static void	test_00_buffer_replace_BiggerString(void)
{
	char	*s = "Hello";
	size_t	len = strlen(s);
	size_t	max = 8;
	setup(s, len, max);

	char	*replace = "World!";
	size_t	lrep = strlen(replace);
	buffer_replace(buffer, replace);

	v_assert_size_t(max, ==, TBUFFER_MAX(buffer));
	v_assert_size_t(lrep, ==, TBUFFER_LEN(buffer));
	v_assert_str(replace, TBUFFER_GET(buffer));

	teardown();
	VTS;
}

static void	test_01_buffer_nreplace_BigStringNotNullTerminated(void)
{
	char	*s = "Hello";
	size_t	len = strlen(s);
	size_t	max = 8;
	setup(s, len, max);

	char	*replace = "World";
	size_t	lrep = strlen(replace);
	char	arr[501];
	for (size_t i = 0; i < 100; ++i)
		memcpy(arr + (i * lrep), replace, lrep);
	arr[500] = 'x';

	buffer_nreplace(buffer, arr, 500);

	v_assert_size_t(512, ==, TBUFFER_MAX(buffer));
	v_assert_size_t(500, ==, TBUFFER_LEN(buffer));
	arr[500] = '\0';
	v_assert_str(arr, TBUFFER_GET(buffer));

	teardown();
	VTS;
}

static void	test_02_buffer_replace_LowerString(void)
{
	char	*s = "Hello World!";
	size_t	len = strlen(s);
	size_t	max = 16;
	setup(s, len, max);

	char	*replace = "abc";
	size_t	lrep = strlen(replace);
	buffer_replace(buffer, replace);

	v_assert_size_t(16, ==, TBUFFER_MAX(buffer));
	v_assert_size_t(lrep, ==, TBUFFER_LEN(buffer));
	v_assert_str(replace, TBUFFER_GET(buffer));

	teardown();
	VTS;
}

void	suite_buffer_replace(void)
{
	test_00_buffer_replace_BiggerString();
	test_01_buffer_nreplace_BigStringNotNullTerminated();
	test_02_buffer_replace_LowerString();

	VSS;
}
