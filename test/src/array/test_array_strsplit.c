#include "header.h"

static t_array	*v;
static size_t	init_size = 16;

static void	teardown(void)
{
	for (size_t i = 0; i < v->count; ++i)
	{
		char	*s = *(char**)array_get(v, i);
		free(s);
	}
	array_destroy(v);
	v = NULL;
}

static void	test_00_array_strsplit_3ElemsSepColon(void)
{
	char	*str = "elem1:elem2:elem3";
	char	*value;

	v = array_strsplit(str, ':');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(init_size, ==, v->max);
	v_assert_size_t(3, ==, v->count);

	value = *(char**)array_get(v, 0);
	v_assert_str("elem1", value);

	value = *(char**)array_get(v, 1);
	v_assert_str("elem2", value);

	value = *(char**)array_get(v, 2);
	v_assert_str("elem3", value);

	v_assert_ptr(NULL, ==, array_get(v, 3));

	teardown();
	VTS;
}

static void	test_01_array_strsplit_1ElemSepEndOfString(void)
{
	char	*str = "elem1";
	char	*value;

	v = array_strsplit(str, '\0');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(init_size, ==, v->max);
	v_assert_size_t(1, ==, v->count);

	value = *(char**)array_get(v, 0);
	v_assert_str("elem1", value);

	v_assert_ptr(NULL, ==, array_get(v, 1));

	teardown();
	VTS;
}

static void	test_02_array_strsplit_EmptyStringSepEndOfString(void)
{
	char	*str = "";
	char	*value;

	v = array_strsplit(str, '\0');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(init_size, ==, v->max);
	v_assert_size_t(1, ==, v->count);

	value = *(char**)array_get(v, 0);
	v_assert_str("", value);

	v_assert_ptr(NULL, ==, array_get(v, 1));

	teardown();
	VTS;
}

static void	test_03_array_strsplit_8ElemsSepSpace(void)
{
	char	*str = "Hello world and good morning on this day!";
	char	*value;

	v = array_strsplit(str, ' ');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(init_size, ==, v->max);
	v_assert_size_t(8, ==, v->count);

	value = *(char**)array_get(v, 0);
	v_assert_str("Hello", value);

	value = *(char**)array_get(v, 1);
	v_assert_str("world", value);

	value = *(char**)array_get(v, 2);
	v_assert_str("and", value);

	value = *(char**)array_get(v, 3);
	v_assert_str("good", value);

	value = *(char**)array_get(v, 4);
	v_assert_str("morning", value);

	value = *(char**)array_get(v, 5);
	v_assert_str("on", value);

	value = *(char**)array_get(v, 6);
	v_assert_str("this", value);

	value = *(char**)array_get(v, 7);
	v_assert_str("day!", value);

	v_assert_ptr(NULL, ==, array_get(v, 8));

	teardown();
	VTS;
}

static void	test_04_array_strsplit_OnlySep(void)
{
	char	*str = "///";
	char	*value;

	v = array_strsplit(str, '/');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(init_size, ==, v->max);
	v_assert_size_t(4, ==, v->count);

	value = *(char**)array_get(v, 0);
	v_assert_str("", value);

	value = *(char**)array_get(v, 1);
	v_assert_str("", value);

	value = *(char**)array_get(v, 2);
	v_assert_str("", value);

	value = *(char**)array_get(v, 3);
	v_assert_str("", value);

	v_assert_ptr(NULL, ==, array_get(v, 4));

	teardown();
	VTS;
}

static void	test_05_array_strsplit_SimpleStringSepSlash(void)
{
	char	*str = "a/b//c";
	char	*value;

	v = array_strsplit(str, '/');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(init_size, ==, v->max);
	v_assert_size_t(4, ==, v->count);

	value = *(char**)array_get(v, 0);
	v_assert_str("a", value);

	value = *(char**)array_get(v, 1);
	v_assert_str("b", value);

	value = *(char**)array_get(v, 2);
	v_assert_str("", value);

	value = *(char**)array_get(v, 3);
	v_assert_str("c", value);

	v_assert_ptr(NULL, ==, array_get(v, 4));

	teardown();
	VTS;
}

static void	test_06_array_strsplit_SimpleStringNotFoundSep(void)
{
	char	*str = "Hello world!";
	char	*value;

	v = array_strsplit(str, 'x');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(init_size, ==, v->max);
	v_assert_size_t(1, ==, v->count);

	value = *(char**)array_get(v, 0);
	v_assert_str(str, value);

	v_assert_ptr(NULL, ==, array_get(v, 1));

	teardown();
	VTS;
}

void	suite_array_strsplit(void)
{
	test_00_array_strsplit_3ElemsSepColon();
	test_01_array_strsplit_1ElemSepEndOfString();
	test_02_array_strsplit_EmptyStringSepEndOfString();
	test_03_array_strsplit_8ElemsSepSpace();
	test_04_array_strsplit_OnlySep();
	test_05_array_strsplit_SimpleStringSepSlash();
	test_06_array_strsplit_SimpleStringNotFoundSep();

	VSS;
}
