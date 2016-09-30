#include "header.h"

static t_buffer	*b;
static char		*s = "abcdefghij";

// twin

static void	setup(void)
{

	b = malloc(sizeof(t_buffer));
	b->sizemax = BUFFER_INIT_SIZE;
	b->len = strlen(s);
	b->str = malloc(BUFFER_INIT_SIZE);
	memset(b->str, 0, BUFFER_INIT_SIZE);
	b->iterator = 0;
	memcpy(b->str, s, b->len);
}

static void	teardown(void)
{
	free(b->str);
	free(b);
}

static void	test_00_buffer_iterator_ToTheEnd(void)
{
	char	c;

	setup();

	for (size_t i = 0; (c = buffer_iterator(b)) != '\0'; ++i)
	{
		v_assert_char(s[i], ==, c);
		v_assert_size_t(i + 1, ==, b->iterator);
	}
	v_assert_char('\0', ==, c);
	v_assert_size_t(0, ==, b->iterator);

	teardown();
	VTS;
}

static void	test_01_buffer_iterator_Interrupted(void)
{
	char	c;

	setup();

	for (size_t i = 0; (c = buffer_iterator(b)) != '\0' && i < 5; ++i)
	{
		v_assert_char(s[i], ==, c);
		v_assert_size_t(i + 1, ==, b->iterator);
	}
	v_assert_char(s[5], ==, c);
	v_assert_size_t(6, ==, b->iterator);

	teardown();
	VTS;
}

static void	test_02_buffer_iterator_RemoveAfterIterator(void)
{
	char	c;

	setup();

	for (size_t i = 0; (c = buffer_iterator(b)) != '\0' && i < 3; ++i)
	{
		v_assert_char(s[i], ==, c);
		v_assert_size_t(i + 1, ==, b->iterator);
	}
	v_assert_char('d', ==, c);
	v_assert_size_t(4, ==, b->iterator);

	// Remove the end of the string
	buffer_remove(b, 5, 20);
	v_assert_size_t(4, ==, b->iterator);

	// next char
	c = buffer_iterator(b);
	v_assert_char('e', ==, c);
	v_assert_size_t(5, ==, b->iterator);

	// next char
	c = buffer_iterator(b);
	v_assert_char('\0', ==, c);
	v_assert_size_t(0, ==, b->iterator);

	teardown();
	VTS;
}

static void	test_03_buffer_iterator_RemoveBeforeIterator(void)
{
	char	c;

	setup();

	for (size_t i = 0; (c = buffer_iterator(b)) != '\0' && i < 5; ++i)
	{
		v_assert_char(s[i], ==, c);
		v_assert_size_t(i + 1, ==, b->iterator);
	}
	v_assert_char('f', ==, c);
	v_assert_size_t(6, ==, b->iterator);

	// Remove before the current iterator location
	buffer_remove(b, 2, 20);
	v_assert_size_t(2, ==, b->iterator);

	// next char
	c = buffer_iterator(b);
	v_assert_char('\0', ==, c);
	v_assert_size_t(0, ==, b->iterator);

	// next char
	c = buffer_iterator(b);
	v_assert_char('a', ==, c);
	v_assert_size_t(1, ==, b->iterator);

	teardown();
	VTS;
}

static void	test_04_buffer_iterator_RemoveOnIterator(void)
{
	char	c;

	setup();

	for (size_t i = 0; (c = buffer_iterator(b)) != '\0' && i < 5; ++i)
	{
		v_assert_char(s[i], ==, c);
		v_assert_size_t(i + 1, ==, b->iterator);
	}
	v_assert_char('f', ==, c);
	v_assert_size_t(6, ==, b->iterator);

	// Remove at the current iterator location
	buffer_remove(b, 6, 20);
	v_assert_size_t(6, ==, b->iterator);

	// next char
	c = buffer_iterator(b);
	v_assert_char('\0', ==, c);
	v_assert_size_t(0, ==, b->iterator);

	// next char
	c = buffer_iterator(b);
	v_assert_char('a', ==, c);
	v_assert_size_t(1, ==, b->iterator);

	teardown();
	VTS;
}

static void	test_05_buffer_iterator_RewindBeforeIterator(void)
{
	char	c;

	setup();

	for (size_t i = 0; (c = buffer_iterator(b)) != '\0' && i < 5; ++i)
	{
		v_assert_char(s[i], ==, c);
		v_assert_size_t(i + 1, ==, b->iterator);
	}
	v_assert_char('f', ==, c);
	v_assert_size_t(6, ==, b->iterator);

	// Rewind before the current iterator location
	buffer_rewind(b, 7);
	v_assert_size_t(3, ==, b->iterator);
	v_assert_size_t(b->len, ==, b->iterator);

	// next char
	c = buffer_iterator(b);
	v_assert_char('\0', ==, c);
	v_assert_size_t(0, ==, b->iterator);

	// next char
	c = buffer_iterator(b);
	v_assert_char('a', ==, c);
	v_assert_size_t(1, ==, b->iterator);

	teardown();
	VTS;
}

static void	test_06_buffer_iterator_RewindchrBeforeIterator(void)
{
	char	c;

	setup();

	for (size_t i = 0; (c = buffer_iterator(b)) != '\0' && i < 5; ++i)
	{
		v_assert_char(s[i], ==, c);
		v_assert_size_t(i + 1, ==, b->iterator);
	}
	v_assert_char('f', ==, c);
	v_assert_size_t(6, ==, b->iterator);

	// Rewind before the current iterator location
	buffer_rewindchr(b, 'c');
	v_assert_size_t(2, ==, b->iterator);
	v_assert_size_t(b->len, ==, b->iterator);

	// next char
	c = buffer_iterator(b);
	v_assert_char('\0', ==, c);
	v_assert_size_t(0, ==, b->iterator);

	// next char
	c = buffer_iterator(b);
	v_assert_char('a', ==, c);
	v_assert_size_t(1, ==, b->iterator);

	teardown();
	VTS;
}

void	suite_buffer_iterator(void)
{
	test_00_buffer_iterator_ToTheEnd();
	test_01_buffer_iterator_Interrupted();
	test_02_buffer_iterator_RemoveAfterIterator();
	test_03_buffer_iterator_RemoveBeforeIterator();
	test_04_buffer_iterator_RemoveOnIterator();
	test_05_buffer_iterator_RewindBeforeIterator();
	test_06_buffer_iterator_RewindchrBeforeIterator();

	VSS;
}
