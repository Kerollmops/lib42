#include "header.h"

static t_array	*v;

static void	teardown(void)
{
	free(v->data);
	/* memset(v, 0, sizeof(t_array)); */
	free(v);
}

static void	test_00_TARRAY_IN_RANGE_EmptyArray(void)
{
	void	*p;
	int		ret;

	v = array_new(8, sizeof(int));

	p = v->data;
	ret = TARRAY_IN_RANGE(v, p);
	v_assert_int(0, ==, ret);

	teardown();
	VTS;
}

static void	test_01_TARRAY_IN_RANGE_FilledArray(void)
{
	void	*p;
	int		ret;
	int		value;

	v = array_new(8, sizeof(int));
	value = 3;
	array_add(v, &value);
	array_add(v, &value);
	array_add(v, &value);
	array_add(v, &value);

	v_assert_size_t(4, ==, v->count);

	// First
	p = v->data;
	ret = TARRAY_IN_RANGE(v, p);
	v_assert_int(1, ==, ret);

	// Middle
	p = (int*)v->data + 2;
	ret = TARRAY_IN_RANGE(v, p);
	v_assert_int(1, ==, ret);

	// Last
	p = (int*)v->data + 3;
	ret = TARRAY_IN_RANGE(v, p);
	v_assert_int(1, ==, ret);

	// 1 bytes beyond
	p = (int*)v->data + 4;
	ret = TARRAY_IN_RANGE(v, p);
	v_assert_int(0, ==, ret);

	// Last byte of last elem
	p = (unsigned char*)v->data + (sizeof(int) * 3) + 3;
	ret = TARRAY_IN_RANGE(v, p);
	v_assert_int(1, ==, ret);

	teardown();
	VTS;
}

void	suite_array_macros(void)
{
	test_00_TARRAY_IN_RANGE_EmptyArray();
	test_01_TARRAY_IN_RANGE_FullArray();

	VSS;
}
