#include "header.h"

static t_array	*v;

static void	setup(void *data, size_t elem_size, size_t len)
{
	unsigned char	*p;
	unsigned char	*d;

	v = array_new(8, elem_size);
	if (data != NULL)
	{
		p = v->data;
		d = data;
		for (size_t i = 0; i < len; ++i)
			memcpy(p + (elem_size * i), d + (elem_size * i), elem_size);
		v->count = len;
	}
}

static void	teardown(void)
{
	free(v->data);
	memset(v, 0, sizeof(t_array));
	free(v);
}

static void	test_00_array_create_node_EmptyArray(void)
{
	void			*p;
	size_t			elem_size = 16;
	unsigned char	*res;

	setup(NULL, elem_size, 0);
	res = v->data;

	p = array_create_node(v);
	v_assert_ptr(res, ==, p);
	v_assert_size_t(v->count, ==, 1);

	p = array_create_node(v);
	v_assert_ptr(res + elem_size, ==, p);
	v_assert_size_t(v->count, ==, 2);

	teardown();
	VTS;
}

static void	test_01_array_create_node_ResizeArray(void)
{
	void			*p;
	size_t			elem_size = 16;
	unsigned char	*res;

	setup(NULL, elem_size, 0);

	v_assert_size_t(8, ==, TARRAY_MAX(v));
	v_assert_size_t(0, ==, TARRAY_COUNT(v));

	for (size_t i = 0; i < 10; ++i)
	{
		p = array_create_node(v);
		res = v->data;
		v_assert_ptr(res + (i * elem_size), ==, p);
		v_assert_size_t(v->count, ==, i + 1);
	}

	v_assert_size_t(16, ==, TARRAY_MAX(v));
	v_assert_size_t(10, ==, TARRAY_COUNT(v));

	teardown();
	VTS;
}

void	suite_array_create_node(void)
{
	test_00_array_create_node_EmptyArray();
	test_01_array_create_node_ResizeArray();

	VSS;
}
