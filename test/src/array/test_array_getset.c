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

static void	test_00_array_getset_Int(void)
{
	int	data[4] = {11, 22, 33, 44};
	setup(data, sizeof(int), ARR_SIZ_MAX(data));

	for (size_t i = 0; i < ARR_SIZ_MAX(data); ++i)
	{
		int *value = array_get(v, i);
		v_assert_int(data[i], ==, *value);
	}

	// set
	int	new = 8;
	int *value = array_get(v, 3);
	array_set(v, 3, &new);
	v_assert_int(8, ==, *value);

	teardown();
	VTS;
}

static void	test_01_array_getset_String(void)
{
	char		*data[] = {
		"hello",
		"world",
		"and",
		"good",
		"morning",
	};
	setup(data, sizeof(char*), ARR_SIZ_MAX(data));

	for (size_t i = 0; i < ARR_SIZ_MAX(data); ++i)
	{
		char	**value = array_get(v, i);
		v_assert_str(data[i], *value);
	}

	// set
	char	*s = "zut";
	array_set(v, 2, s);
	v_assert_str(s, array_get(v, 2));

	teardown();
	VTS;
}

static void	test_02_array_getset_Struct(void)
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
	setup(data, sizeof(struct s_test), ARR_SIZ_MAX(data));

	for (size_t i = 0; i < ARR_SIZ_MAX(data); ++i)
	{
		struct s_test value = *(struct s_test*)array_get(v, i);
		v_assert_ptr(data[i].e, ==, value.e);
		v_assert_int(data[i].i, ==, value.i);
		v_assert_char(data[i].c, ==, value.c);
	}

	// set
	struct s_test new = { (void*)0x1234, 1 << 31, 'X' };
	array_set(v, 0, &new);
	struct s_test value = *(struct s_test*)array_get(v, 0);
	v_assert_ptr(new.e, ==, value.e);
	v_assert_int(new.i, ==, value.i);
	v_assert_char(new.c, ==, value.c);

	teardown();
	VTS;
}

static void	test_03_array_getset_OutOfRange(void)
{
	int	data[4] = {11, 22, 33, 44};
	setup(data, sizeof(int), ARR_SIZ_MAX(data));

	v_assert_ptr(NULL, ==, array_get(v, 4));

	teardown();
	VTS;
}

void	suite_array_getset(void)
{
	test_00_array_getset_Int();
	test_01_array_getset_String();
	test_02_array_getset_Struct();
	test_03_array_getset_OutOfRange();

	VSS;
}
