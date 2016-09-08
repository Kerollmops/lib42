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

static void	test_00_array_add_Int(void)
{
	int	data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	setup(NULL, sizeof(int), 0);

	for (size_t i = 0; i < ARR_SIZ_MAX(data); ++i)
	{
		int	value = data[i];
		array_add(v, &value);
		if (i < 7)
			v_assert_size_t(8, ==, TARRAY_MAX(v));
		else
			v_assert_size_t(16, ==, TARRAY_MAX(v));
		v_assert_size_t(i + 1, ==, TARRAY_COUNT(v));
		int	*res = array_get(v, i);
		v_assert_int(value, ==, *res);
	}

	teardown();
	VTS;
}

static void	test_01_array_add_String(void)
{
	char		*data[] = {
		"hello",
		"world",
		"and",
		"good",
		"morning",
	};
	setup(NULL, sizeof(char*), 0);

	for (size_t i = 0; i < ARR_SIZ_MAX(data); ++i)
	{
		char	*value = data[i];
		array_add(v, &value);
		if (i < 7)
			v_assert_size_t(8, ==, TARRAY_MAX(v));
		else
			v_assert_size_t(16, ==, TARRAY_MAX(v));
		v_assert_size_t(i + 1, ==, TARRAY_COUNT(v));
		char	**res = array_get(v, i);
		v_assert_str(value, *res);
	}

	teardown();
	VTS;
}

static void	test_02_array_add_Struct(void)
{
	struct s_test {
		void	*e;
		int		i;
		char	c;
	} data[3] = {
		{ NULL, 42, 'a' },
		{ (void*)0xdeadbeef, 8, 'z' },
		{ (void*)0xabcdef, -1, '*' },
	};
	setup(NULL, sizeof(struct s_test), 0);

	for (size_t i = 0; i < ARR_SIZ_MAX(data); ++i)
	{
		struct s_test value = data[i];
		array_add(v, &value);

		if (i < 7)
			v_assert_size_t(8, ==, TARRAY_MAX(v));
		else
			v_assert_size_t(16, ==, TARRAY_MAX(v));

		struct s_test *res = array_get(v, i);
		v_assert_ptr(value.e, ==, res->e);
		v_assert_int(value.i, ==, res->i);
		v_assert_char(value.c, ==, res->c);
	}

	teardown();
	VTS;
}

void	suite_array_add(void)
{
	test_00_array_add_Int();
	test_01_array_add_String();
	test_02_array_add_Struct();

	VSS;
}
