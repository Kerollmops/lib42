#include "header.h"

static t_array	*v;

static void	teardown(void)
{
	array_clear(v);
	array_destroy(v);
	v = NULL;
}

void	test_00_array_strsplit_3ElemsSepColon(void)
{
	char	*str = "elem1:elem2:elem3";

	v = array_strsplit(str, ':');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(8, ==, v->max);
	v_assert_size_t(3, ==, v->count);
	v_assert_str("elem1", array_get(v, 0));
	v_assert_str("elem2", array_get(v, 1));
	v_assert_str("elem3", array_get(v, 2));
	v_assert_ptr(NULL, ==, array_get(v, 3));

	teardown();
	VTS;
}

void	test_01_array_strsplit_1ElemSepEndOfString(void)
{
	char	*str = "elem1";

	v = array_strsplit(str, '\0');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(8, ==, v->max);
	v_assert_size_t(1, ==, v->count);
	v_assert_str("elem1", array_get(v, 0));
	v_assert_ptr(NULL, ==, array_get(v, 1));

	teardown();
	VTS;
}

void	test_02_array_strsplit_EmptyStringSepEndOfString(void)
{
	char	*str = "";

	v = array_strsplit(str, '\0');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(8, ==, v->max);
	v_assert_size_t(1, ==, v->count);
	v_assert_str("", array_get(v, 0));
	v_assert_ptr(NULL, ==, array_get(v, 1));

	teardown();
	VTS;
}

void	test_03_array_strsplit_8ElemsSepSpace(void)
{
	char	*str = "Hello world and good morning on this day!";

	v = array_strsplit(str, ' ');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(16, ==, v->max);
	v_assert_size_t(8, ==, v->count);
	v_assert_str("Hello", array_get(v, 0));
	v_assert_str("world", array_get(v, 1));
	v_assert_str("and", array_get(v, 2));
	v_assert_str("good", array_get(v, 3));
	v_assert_str("morning", array_get(v, 4));
	v_assert_str("on", array_get(v, 5));
	v_assert_str("this", array_get(v, 6));
	v_assert_str("day!", array_get(v, 7));
	v_assert_ptr(NULL, ==, array_get(v, 8));

	teardown();
	VTS;
}

void	test_04_array_strsplit_OnlySep(void)
{
	char	*str = "///";

	v = array_strsplit(str, '/');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(8, ==, v->max);
	v_assert_size_t(4, ==, v->count);
	v_assert_str("", array_get(v, 0));
	v_assert_str("", array_get(v, 1));
	v_assert_str("", array_get(v, 2));
	v_assert_str("", array_get(v, 3));
	v_assert_ptr(NULL, ==, array_get(v, 4));

	teardown();
	VTS;
}

void	test_05_array_strsplit_SimpleStringSepSlash(void)
{
	char	*str = "a/b//c";

	v = array_strsplit(str, '/');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(8, ==, v->max);
	v_assert_size_t(4, ==, v->count);
	v_assert_str("a", array_get(v, 0));
	v_assert_str("b", array_get(v, 1));
	v_assert_str("", array_get(v, 2));
	v_assert_str("c", array_get(v, 3));
	v_assert_ptr(NULL, ==, array_get(v, 4));

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

	VSS;
}
