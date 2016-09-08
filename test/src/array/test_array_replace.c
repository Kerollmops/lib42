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

static void	test_00_array_replace_FirstItem(void)
{
	char	*rep = "firstitem";
	void	*old = (void*)0xdeadbeef;
	char	*value;
	size_t	index = 0;

	setup();

	array_replace(v, index, &rep, &old);

	// Check return value
	v_assert_ptr(NULL, !=, old);
	v_assert_ptr(str[index], ==, old);
	v_assert_str(str[index], old);

	// Check array integrity
	v_assert_size_t(5, ==, v->count);
	v_assert_size_t(8, ==, v->max);

	value = *(char**)array_get(v, 0);
	v_assert_ptr(rep, ==, value);

	value = *(char**)array_get(v, 1);
	v_assert_ptr(str[1], ==, value);

	value = *(char**)array_get(v, 2);
	v_assert_ptr(str[2], ==, value);

	value = *(char**)array_get(v, 3);
	v_assert_ptr(str[3], ==, value);

	value = *(char**)array_get(v, 4);
	v_assert_ptr(str[4], ==, value);

	value = array_get(v, 5);
	v_assert_ptr(NULL, ==, value);

	value = *(char**)array_get(v, 0);
	v_assert_str(rep, value);

	value = *(char**)array_get(v, 1);
	v_assert_str(str[1], value);

	value = *(char**)array_get(v, 2);
	v_assert_str(str[2], value);

	value = *(char**)array_get(v, 3);
	v_assert_str(str[3], value);

	value = *(char**)array_get(v, 4);
	v_assert_str(str[4], value);

	teardown();
	VTS;
}

static void	test_01_array_replace_MiddleItem(void)
{
	char	*rep = "middleitem";
	void	*old = (void*)0xdeadbeef;
	char	*value;
	size_t	index = 2;

	setup();

	array_replace(v, index, &rep, &old);

	// Check return value
	v_assert_ptr(NULL, !=, old);
	v_assert_ptr(str[index], ==, old);
	v_assert_str(str[index], old);

	// Check array integrity
	v_assert_size_t(5, ==, v->count);
	v_assert_size_t(8, ==, v->max);

	value = *(char**)array_get(v, 0);
	v_assert_ptr(str[0], ==, value);

	value = *(char**)array_get(v, 1);
	v_assert_ptr(str[1], ==, value);

	value = *(char**)array_get(v, 2);
	v_assert_ptr(rep, ==, value);

	value = *(char**)array_get(v, 3);
	v_assert_ptr(str[3], ==, value);

	value = *(char**)array_get(v, 4);
	v_assert_ptr(str[4], ==, value);

	value = array_get(v, 5);
	v_assert_ptr(NULL, ==, value);

	value = *(char**)array_get(v, 0);
	v_assert_str(str[0], value);

	value = *(char**)array_get(v, 1);
	v_assert_str(str[1], value);

	value = *(char**)array_get(v, 2);
	v_assert_str(rep, value);

	value = *(char**)array_get(v, 3);
	v_assert_str(str[3], value);

	value = *(char**)array_get(v, 4);
	v_assert_str(str[4], value);

	teardown();
	VTS;
}

static void	test_02_array_replace_LastItem(void)
{
	char	*rep = "lastitem";
	void	*old = (void*)0xdeadbeef;
	char	*value;
	size_t	index = 4;

	setup();

	array_replace(v, index, &rep, &old);

	// Check return value
	v_assert_ptr(NULL, !=, old);
	v_assert_ptr(str[index], ==, old);
	v_assert_str(str[index], old);

	// Check array integrity
	v_assert_size_t(5, ==, v->count);
	v_assert_size_t(8, ==, v->max);

	value = *(char**)array_get(v, 0);
	v_assert_ptr(str[0], ==, value);

	value = *(char**)array_get(v, 1);
	v_assert_ptr(str[1], ==, value);

	value = *(char**)array_get(v, 2);
	v_assert_ptr(str[2], ==, value);

	value = *(char**)array_get(v, 3);
	v_assert_ptr(str[3], ==, value);

	value = *(char**)array_get(v, 4);
	v_assert_ptr(rep, ==, value);

	value = array_get(v, 5);
	v_assert_ptr(NULL, ==, value);

	value = *(char**)array_get(v, 0);
	v_assert_str(str[0], value);

	value = *(char**)array_get(v, 1);
	v_assert_str(str[1], value);

	value = *(char**)array_get(v, 2);
	v_assert_str(str[2], value);

	value = *(char**)array_get(v, 3);
	v_assert_str(str[3], value);

	value = *(char**)array_get(v, 4);
	v_assert_str(rep, value);

	teardown();
	VTS;
}

static void	test_03_array_replace_OutOfRange(void)
{
	char	*rep = "outofrange";
	void	*old = (void*)0xdeadbeef;
	char	*value;
	void	*ret;
	size_t	index = 8;

	setup();

	ret = array_replace(v, index, &rep, &old);

	// Check return value
	v_assert_ptr(NULL, ==, ret);

	// Check array integrity
	v_assert_size_t(5, ==, v->count);
	v_assert_size_t(8, ==, v->max);
	for (size_t i = 0; i < v->count; ++i)
	{
		value = *(char**)array_get(v, i);
		v_assert_ptr(str[i], ==, value);
		v_assert_str(str[i], value);
	}

	teardown();
	VTS;
}

void	suite_array_replace(void)
{
	test_00_array_replace_FirstItem();
	test_01_array_replace_MiddleItem();
	test_02_array_replace_LastItem();
	test_03_array_replace_OutOfRange();

	VSS;
}
