#include "header.h"

void	test_00_ft_vector_copy_SimpleCopy(void)
{
	char	*s1 = "hello";
	char	*s2 = "world";
	char	*s3 = "and";
	char	*s4 = "good";
	char	*s5 = "morning";
	t_vector v;
	t_vector *cp;

	ft_vector_init(&v, 8);
	ft_vector_add(&v, s1);
	ft_vector_add(&v, s2);
	ft_vector_add(&v, s3);
	ft_vector_add(&v, s4);
	ft_vector_add(&v, s5);
	cp = ft_vector_copy(&v);
	ft_vector_remove(&v, 0);
	ft_vector_remove(&v, 0);
	ft_vector_remove(&v, 0);
	ft_vector_remove(&v, 0);
	ft_vector_remove(&v, 0);
	v_assert_size_t(0, ==, FT_VECTOR_TOTAL(&v));
	v_assert_ptr(NULL, !=, cp);
	v_assert_size_t(8, ==, FT_VECTOR_MAX(cp));
	v_assert_size_t(5, ==, FT_VECTOR_TOTAL(cp));
	v_assert_str(s1, ft_vector_get(cp, 0));
	v_assert_ptr(s1, ==, ft_vector_get(cp, 0));
	v_assert_str(s2, ft_vector_get(cp, 1));
	v_assert_ptr(s2, ==, ft_vector_get(cp, 1));
	v_assert_str(s3, ft_vector_get(cp, 2));
	v_assert_ptr(s3, ==, ft_vector_get(cp, 2));
	v_assert_str(s4, ft_vector_get(cp, 3));
	v_assert_ptr(s4, ==, ft_vector_get(cp, 3));
	v_assert_str(s5, ft_vector_get(cp, 4));
	v_assert_ptr(s5, ==, ft_vector_get(cp, 4));
	v_assert_ptr(NULL, ==, ft_vector_get(cp, 5));
	v_assert_ptr(NULL, ==, ft_vector_get(cp, 6));
	v_assert_ptr(NULL, ==, ft_vector_get(cp, 7));

	FT_VECTOR_FREE(&v);
	FT_VECTOR_FREE(cp);
	free(cp);
	VTS;
}

void	suite_ft_vector_copy(void)
{
	test_00_ft_vector_copy_SimpleCopy();

	VSS;
}
