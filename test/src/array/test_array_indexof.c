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
	v.count = 5;
}

static void	teardown(void)
{
	free(v.data);
	memset(&v, 0, sizeof(t_array));
}

void	test_00_array_indexof_First(void)
{
	int		index;

	setup();

	index = array_indexof(&v, str[0]);
	v_assert_int(0, ==, index);
	v_assert_ptr(str[0], ==, v.data[index]);
	v_assert_str(str[0], v.data[index]);

	v_assert_size_t(5, ==, v.count);
	v_assert_size_t(8, ==, v.max);
	v_assert_ptr(str[0], ==, array_get(&v, 0));
	v_assert_ptr(str[1], ==, array_get(&v, 1));
	v_assert_ptr(str[2], ==, array_get(&v, 2));
	v_assert_ptr(str[3], ==, array_get(&v, 3));
	v_assert_ptr(str[4], ==, array_get(&v, 4));
	v_assert_ptr(NULL, ==, array_get(&v, 5));
	v_assert_ptr(NULL, ==, array_get(&v, 6));
	v_assert_ptr(NULL, ==, array_get(&v, 7));

	v_assert_str(str[0], array_get(&v, 0));
	v_assert_str(str[1], array_get(&v, 1));
	v_assert_str(str[2], array_get(&v, 2));
	v_assert_str(str[3], array_get(&v, 3));
	v_assert_str(str[4], array_get(&v, 4));

	teardown();
	VTS;
}

void	test_01_array_indexof_Last(void)
{
	int		index;

	setup();

	index = array_indexof(&v, str[4]);
	v_assert_int(4, ==, index);
	v_assert_ptr(str[4], ==, v.data[index]);
	v_assert_str(str[4], v.data[index]);

	v_assert_size_t(5, ==, v.count);
	v_assert_size_t(8, ==, v.max);
	v_assert_ptr(str[0], ==, array_get(&v, 0));
	v_assert_ptr(str[1], ==, array_get(&v, 1));
	v_assert_ptr(str[2], ==, array_get(&v, 2));
	v_assert_ptr(str[3], ==, array_get(&v, 3));
	v_assert_ptr(str[4], ==, array_get(&v, 4));
	v_assert_ptr(NULL, ==, array_get(&v, 5));
	v_assert_ptr(NULL, ==, array_get(&v, 6));
	v_assert_ptr(NULL, ==, array_get(&v, 7));

	v_assert_str(str[0], array_get(&v, 0));
	v_assert_str(str[1], array_get(&v, 1));
	v_assert_str(str[2], array_get(&v, 2));
	v_assert_str(str[3], array_get(&v, 3));
	v_assert_str(str[4], array_get(&v, 4));

	teardown();
	VTS;
}

void	test_02_array_indexof_DoesntExist(void)
{
	int		index;

	setup();

	index = array_indexof(&v, "zut");
	v_assert_int(-1, ==, index);

	v_assert_size_t(5, ==, v.count);
	v_assert_size_t(8, ==, v.max);
	v_assert_ptr(str[0], ==, array_get(&v, 0));
	v_assert_ptr(str[1], ==, array_get(&v, 1));
	v_assert_ptr(str[2], ==, array_get(&v, 2));
	v_assert_ptr(str[3], ==, array_get(&v, 3));
	v_assert_ptr(str[4], ==, array_get(&v, 4));
	v_assert_ptr(NULL, ==, array_get(&v, 5));
	v_assert_ptr(NULL, ==, array_get(&v, 6));
	v_assert_ptr(NULL, ==, array_get(&v, 7));

	v_assert_str(str[0], array_get(&v, 0));
	v_assert_str(str[1], array_get(&v, 1));
	v_assert_str(str[2], array_get(&v, 2));
	v_assert_str(str[3], array_get(&v, 3));
	v_assert_str(str[4], array_get(&v, 4));

	teardown();
	VTS;
}

void	suite_array_indexof(void)
{
	test_00_array_indexof_First();
	test_01_array_indexof_Last();
	test_02_array_indexof_DoesntExist();

	VSS;
}
