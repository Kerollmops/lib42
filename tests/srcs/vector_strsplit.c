#include "header.h"

static t_vector	*v;

static void	teardown(void)
{
	ft_vector_clear(v);
	ft_vector_destroy(v);
	v = NULL;
}

void	test_00_ft_vector_strsplit_3ElemsSepColon(void)
{
	char	*str = "elem1:elem2:elem3";

	v = ft_vector_strsplit(str, ':');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(8, ==, FT_VECTOR_MAX(v));
	v_assert_size_t(3, ==, FT_VECTOR_TOTAL(v));
	v_assert_str("elem1", ft_vector_get(v, 0));
	v_assert_str("elem2", ft_vector_get(v, 1));
	v_assert_str("elem3", ft_vector_get(v, 2));
	v_assert_ptr(NULL, ==, ft_vector_get(v, 3));

	teardown();
	VTS;
}

void	test_01_ft_vector_strsplit_1ElemSepEndOfString(void)
{
	char	*str = "elem1";

	v = ft_vector_strsplit(str, '\0');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(8, ==, FT_VECTOR_MAX(v));
	v_assert_size_t(1, ==, FT_VECTOR_TOTAL(v));
	v_assert_str("elem1", ft_vector_get(v, 0));
	v_assert_ptr(NULL, ==, ft_vector_get(v, 1));

	teardown();
	VTS;
}

void	test_02_ft_vector_strsplit_EmptyStringSepEndOfString(void)
{
	char	*str = "";

	v = ft_vector_strsplit(str, '\0');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(8, ==, FT_VECTOR_MAX(v));
	v_assert_size_t(1, ==, FT_VECTOR_TOTAL(v));
	v_assert_str("", ft_vector_get(v, 0));
	v_assert_ptr(NULL, ==, ft_vector_get(v, 1));

	teardown();
	VTS;
}

void	test_03_ft_vector_strsplit_8ElemsSepSpace(void)
{
	char	*str = "Hello world and good morning on this day!";

	v = ft_vector_strsplit(str, ' ');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(16, ==, FT_VECTOR_MAX(v));
	v_assert_size_t(8, ==, FT_VECTOR_TOTAL(v));
	v_assert_str("Hello", ft_vector_get(v, 0));
	v_assert_str("world", ft_vector_get(v, 1));
	v_assert_str("and", ft_vector_get(v, 2));
	v_assert_str("good", ft_vector_get(v, 3));
	v_assert_str("morning", ft_vector_get(v, 4));
	v_assert_str("on", ft_vector_get(v, 5));
	v_assert_str("this", ft_vector_get(v, 6));
	v_assert_str("day!", ft_vector_get(v, 7));
	v_assert_ptr(NULL, ==, ft_vector_get(v, 8));

	teardown();
	VTS;
}

void	test_04_ft_vector_strsplit_OnlySep(void)
{
	char	*str = "///";

	v = ft_vector_strsplit(str, '/');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(8, ==, FT_VECTOR_MAX(v));
	v_assert_size_t(4, ==, FT_VECTOR_TOTAL(v));
	v_assert_str("", ft_vector_get(v, 0));
	v_assert_str("", ft_vector_get(v, 1));
	v_assert_str("", ft_vector_get(v, 2));
	v_assert_str("", ft_vector_get(v, 3));
	v_assert_ptr(NULL, ==, ft_vector_get(v, 4));

	teardown();
	VTS;
}

void	test_05_ft_vector_strsplit_SimpleStringSepSlash(void)
{
	char	*str = "a/b//c";

	v = ft_vector_strsplit(str, '/');

	v_assert_ptr(NULL, !=, v);
	v_assert_size_t(8, ==, FT_VECTOR_MAX(v));
	v_assert_size_t(4, ==, FT_VECTOR_TOTAL(v));
	v_assert_str("a", ft_vector_get(v, 0));
	v_assert_str("b", ft_vector_get(v, 1));
	v_assert_str("", ft_vector_get(v, 2));
	v_assert_str("c", ft_vector_get(v, 3));
	v_assert_ptr(NULL, ==, ft_vector_get(v, 4));

	teardown();
	VTS;
}

void	suite_ft_vector_strsplit(void)
{
	test_00_ft_vector_strsplit_3ElemsSepColon();
	test_01_ft_vector_strsplit_1ElemSepEndOfString();
	test_02_ft_vector_strsplit_EmptyStringSepEndOfString();
	test_03_ft_vector_strsplit_8ElemsSepSpace();
	test_04_ft_vector_strsplit_OnlySep();
	test_05_ft_vector_strsplit_SimpleStringSepSlash();

	VSS;
}
