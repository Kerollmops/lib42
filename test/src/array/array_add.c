#include "header.h"

static t_array	v;
static char		*str[] = {
	"hello",
	"world",
	"and",
	"good",
	"morning",
};

static void	setup(void)
{
	array_init(&v, 8);
	v.data[0] = str[0];
	v.data[1] = str[1];
	v.data[2] = str[2];
	v.data[3] = str[3];
	v.data[4] = str[4];
	v.total = 5;
}

static void	teardown(void)
{
	free(v.data);
	memset(&v, 0, sizeof(t_array));
}

void	test_00_array_add_SimpleAdd(void)
{
	char	*s1 = "firstadd";

	setup();

	array_add(&v, s1);

	v_assert_size_t(6, ==, v.total);
	v_assert_size_t(8, ==, v.max);

	v_assert_ptr(str[0], ==, array_get(&v, 0));
	v_assert_ptr(str[1], ==, array_get(&v, 1));
	v_assert_ptr(str[2], ==, array_get(&v, 2));
	v_assert_ptr(str[3], ==, array_get(&v, 3));
	v_assert_ptr(str[4], ==, array_get(&v, 4));
	v_assert_ptr(s1, ==, array_get(&v, 5));
	v_assert_ptr(NULL, ==, array_get(&v, 6));
	v_assert_ptr(NULL, ==, array_get(&v, 7));

	v_assert_str(str[0], array_get(&v, 0));
	v_assert_str(str[1], array_get(&v, 1));
	v_assert_str(str[2], array_get(&v, 2));
	v_assert_str(str[3], array_get(&v, 3));
	v_assert_str(str[4], array_get(&v, 4));
	v_assert_str(s1, array_get(&v, 5));

	teardown();
	VTS;
}

void	test_01_array_add_ResizeAdd(void)
{
	char	*s1 = "firstadd";
	char	*s2 = "secondadd";
	char	*s3 = "tertio";

	setup();

	array_add(&v, s1);
	array_add(&v, s2);
	array_add(&v, s3);

	v_assert_size_t(8, ==, v.total);
	v_assert_size_t(16, ==, v.max);

	v_assert_ptr(str[0], ==, array_get(&v, 0));
	v_assert_ptr(str[1], ==, array_get(&v, 1));
	v_assert_ptr(str[2], ==, array_get(&v, 2));
	v_assert_ptr(str[3], ==, array_get(&v, 3));
	v_assert_ptr(str[4], ==, array_get(&v, 4));
	v_assert_ptr(s1, ==, array_get(&v, 5));
	v_assert_ptr(s2, ==, array_get(&v, 6));
	v_assert_ptr(s3, ==, array_get(&v, 7));
	v_assert_ptr(NULL, ==, array_get(&v, 8));

	v_assert_str(str[0], array_get(&v, 0));
	v_assert_str(str[1], array_get(&v, 1));
	v_assert_str(str[2], array_get(&v, 2));
	v_assert_str(str[3], array_get(&v, 3));
	v_assert_str(str[4], array_get(&v, 4));
	v_assert_str(s1, array_get(&v, 5));
	v_assert_str(s2, array_get(&v, 6));
	v_assert_str(s3, array_get(&v, 7));

	teardown();
	VTS;
}

void	suite_array_add(void)
{
	test_00_array_add_SimpleAdd();
	test_01_array_add_ResizeAdd();

	VSS;
}
