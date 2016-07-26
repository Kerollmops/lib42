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

	array_init(&v, 8);
	array_add(&v, s1);
	array_add(&v, s2);
	array_add(&v, s3);
	array_add(&v, s4);
	array_add(&v, s5);

	cp = array_copy(&v);

	v.data[0] = NULL;
	v.count = 0;

	v_assert_ptr(NULL, !=, cp);
	v_assert_size_t(8, ==, cp->max);
	v_assert_size_t(5, ==, cp->count);
	v_assert_str(s1, array_get(cp, 0));
	v_assert_ptr(s1, ==, array_get(cp, 0));
	v_assert_str(s2, array_get(cp, 1));
	v_assert_ptr(s2, ==, array_get(cp, 1));
	v_assert_str(s3, array_get(cp, 2));
	v_assert_ptr(s3, ==, array_get(cp, 2));
	v_assert_str(s4, array_get(cp, 3));
	v_assert_ptr(s4, ==, array_get(cp, 3));
	v_assert_str(s5, array_get(cp, 4));
	v_assert_ptr(s5, ==, array_get(cp, 4));
	v_assert_ptr(NULL, ==, array_get(cp, 5));
	v_assert_ptr(NULL, ==, array_get(cp, 6));
	v_assert_ptr(NULL, ==, array_get(cp, 7));

	free(v.data);
	free(cp->data);
	free(cp);
	VTS;
}

void	suite_array_copy(void)
{
	test_00_array_copy_SimpleCopy();

	VSS;
}
