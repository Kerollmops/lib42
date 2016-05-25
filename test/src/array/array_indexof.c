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
	ft_array_init(&v, 8);
	FT_ARRAY_DATA(&v)[0] = str[0];
	FT_ARRAY_DATA(&v)[1] = str[1];
	FT_ARRAY_DATA(&v)[2] = str[2];
	FT_ARRAY_DATA(&v)[3] = str[3];
	FT_ARRAY_DATA(&v)[4] = str[4];
	FT_ARRAY_TOTAL(&v) = 5;
}

static void	teardown(void)
{
	FT_ARRAY_FREE(&v);
	bzero(&v, sizeof(t_array));
}

void	test_00_array_indexof_First(void)
{
	int		index;

	setup();

	index = ft_array_indexof(&v, str[0]);
	v_assert_int(0, ==, index);
	v_assert_ptr(str[0], ==, FT_ARRAY_GET(&v, (size_t)index));
	v_assert_str(str[0], FT_ARRAY_GET(&v, (size_t)index));

	v_assert_size_t(5, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));
	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(str[4], ft_array_get(&v, 4));

	teardown();
	VTS;
}

void	test_01_array_indexof_Last(void)
{
	int		index;

	setup();

	index = ft_array_indexof(&v, str[4]);
	v_assert_int(4, ==, index);
	v_assert_ptr(str[4], ==, FT_ARRAY_GET(&v, (size_t)index));
	v_assert_str(str[4], FT_ARRAY_GET(&v, (size_t)index));

	v_assert_size_t(5, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));
	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(str[4], ft_array_get(&v, 4));

	teardown();
	VTS;
}

void	test_02_array_indexof_DoesntExist(void)
{
	int		index;

	setup();

	index = ft_array_indexof(&v, "zut");
	v_assert_int(-1, ==, index);

	v_assert_size_t(5, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));
	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(str[4], ft_array_get(&v, 4));

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
