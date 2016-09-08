#include "header.h"

static t_array	*v;
static char		*str[] = {
	"hello",
	"world",
	"and",
	"good",
	"morning",
};

static void	setup(void)
{
	v = array_new(8, sizeof(char*));
	for (size_t i = 0; i < ARR_SIZ_MAX(str); ++i)
		array_add(v, &str[i]);
}

static void	teardown(void)
{
	free(v->data);
	memset(v, 0, sizeof(t_array));
	free(v);
}

static void	test_00_array_insert_FirstPlace(void)
{
	char	*s1 = "zut";
	char	*value;
	size_t	index = 0;

	setup();

	array_insert(v, index, &s1);

	// Check array integrity
	v_assert_size_t(6, ==, v->count);
	v_assert_size_t(8, ==, v->max);

	for (size_t i = 0, j = 0; i < v->count; ++i)
	{
		value = *(char**)array_get(v, i);
		if (i == index)
		{
			v_assert_ptr(s1, ==, value);
			v_assert_str(s1, value);
		}
		else
		{
			v_assert_ptr(str[j], ==, value);
			v_assert_str(str[j], value);
			++j;
		}
	}

	// last, unassigned
	value = array_get(v, v->count);
	v_assert_ptr(NULL, ==, value);

	teardown();
	VTS;
}

static void	test_01_array_insert_LastPlace(void)
{
	char	*s1 = "zut";
	char	*value;
	size_t	index;

	setup();

	index = v->count - 1;
	array_insert(v, index, &s1);

	// Check array integrity
	v_assert_size_t(6, ==, v->count);
	v_assert_size_t(8, ==, v->max);

	for (size_t i = 0, j = 0; i < v->count; ++i)
	{
		value = *(char**)array_get(v, i);

		if (i == index)
		{
			v_assert_ptr(s1, ==, value);
			v_assert_str(s1, value);
		}
		else
		{
			v_assert_ptr(str[j], ==, value);
			v_assert_str(str[j], value);
			++j;
		}
	}

	// last, unassigned
	value = array_get(v, v->count);
	v_assert_ptr(NULL, ==, value);

	teardown();
	VTS;
}

static void	test_02_array_insert_MiddlePlace(void)
{
	char	*s1 = "zut";
	char	*value;
	size_t	index;

	setup();

	index = v->count / 2;
	array_insert(v, index, &s1);

	// Check array integrity
	v_assert_size_t(6, ==, v->count);
	v_assert_size_t(8, ==, v->max);

	for (size_t i = 0, j = 0; i < v->count; ++i)
	{
		value = *(char**)array_get(v, i);

		if (i == index)
		{
			v_assert_ptr(s1, ==, value);
			v_assert_str(s1, value);
		}
		else
		{
			v_assert_ptr(str[j], ==, value);
			v_assert_str(str[j], value);
			++j;
		}
	}

	// last, unassigned
	value = array_get(v, v->count);
	v_assert_ptr(NULL, ==, value);

	teardown();
	VTS;
}

static void	test_03_array_insert_Resize(void)
{
	char	*s1 = "zut1";
	char	*s2 = "zut2";
	char	*s3 = "zut3";
	char	*value;
	size_t	index;

	setup();

	index = v->count;
	array_insert(v, v->count, &s1);
	array_insert(v, v->count, &s2);
	array_insert(v, v->count, &s3);

	// Check array integrity
	v_assert_size_t(8, ==, v->count);
	v_assert_size_t(16, ==, v->max);

	for (size_t i = 0; i < v->count - 3; ++i)
	{
		value = *(char**)array_get(v, i);
		v_assert_ptr(str[i], ==, value);
		v_assert_str(str[i], value);
	}

	index = v->count - 1;
	value = *(char**)array_get(v, index);
	v_assert_ptr(s3, ==, value);
	v_assert_str(s3, value);

	index = v->count - 2;
	value = *(char**)array_get(v, index);
	v_assert_ptr(s2, ==, value);
	v_assert_str(s2, value);

	index = v->count - 3;
	value = *(char**)array_get(v, index);
	v_assert_ptr(s1, ==, value);
	v_assert_str(s1, value);

	// last, unassigned
	value = array_get(v, v->count);
	v_assert_ptr(NULL, ==, value);

	teardown();
	VTS;
}

void	suite_array_insert(void)
{
	test_00_array_insert_FirstPlace();
	test_01_array_insert_LastPlace();
	test_02_array_insert_MiddlePlace();
	test_03_array_insert_Resize();

	VSS;
}
