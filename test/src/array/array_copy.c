#include "header.h"

void	test_00_array_copy_SimpleCopy(void)
{
	char	*s1 = "hello";
	char	*s2 = "world";
	char	*s3 = "and";
	char	*s4 = "good";
	char	*s5 = "morning";
	t_array v;
	t_array *cp;

	ft_array_init(&v, 8);
	ft_array_add(&v, s1);
	ft_array_add(&v, s2);
	ft_array_add(&v, s3);
	ft_array_add(&v, s4);
	ft_array_add(&v, s5);
	cp = ft_array_copy(&v);
	ft_array_remove(&v, 0);
	ft_array_remove(&v, 0);
	ft_array_remove(&v, 0);
	ft_array_remove(&v, 0);
	ft_array_remove(&v, 0);
	v_assert_size_t(0, ==, FT_ARRAY_TOTAL(&v));
	v_assert_ptr(NULL, !=, cp);
	v_assert_size_t(8, ==, FT_ARRAY_MAX(cp));
	v_assert_size_t(5, ==, FT_ARRAY_TOTAL(cp));
	v_assert_str(s1, ft_array_get(cp, 0));
	v_assert_ptr(s1, ==, ft_array_get(cp, 0));
	v_assert_str(s2, ft_array_get(cp, 1));
	v_assert_ptr(s2, ==, ft_array_get(cp, 1));
	v_assert_str(s3, ft_array_get(cp, 2));
	v_assert_ptr(s3, ==, ft_array_get(cp, 2));
	v_assert_str(s4, ft_array_get(cp, 3));
	v_assert_ptr(s4, ==, ft_array_get(cp, 3));
	v_assert_str(s5, ft_array_get(cp, 4));
	v_assert_ptr(s5, ==, ft_array_get(cp, 4));
	v_assert_ptr(NULL, ==, ft_array_get(cp, 5));
	v_assert_ptr(NULL, ==, ft_array_get(cp, 6));
	v_assert_ptr(NULL, ==, ft_array_get(cp, 7));

	FT_ARRAY_FREE(&v);
	FT_ARRAY_FREE(cp);
	free(cp);
	VTS;
}

void	suite_array_copy(void)
{
	test_00_array_copy_SimpleCopy();

	VSS;
}
