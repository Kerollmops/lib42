#include "header.h"

static t_array	v;
static char		*str[] = {
	"hello",
	"world",
	"and",
	"good",
	"morning",
	"string",
	"padding",
	"enable",
};

static void	setup(void)
{
	ft_array_init(&v, 8);
	for (size_t i = 0; i < ARR_SIZ_MAX(str); ++i)
		ft_array_add(&v, str[i]);
}

static void	teardown(void)
{
	FT_ARRAY_FREE(&v);
	bzero(&v, sizeof(t_array));
}

void	test_00_array_remove_FirstItem(void)
{
	char	*ptr;
	size_t	ind = 0;
	setup();

	ptr = ft_array_remove(&v, ind);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_str(str[ind], ptr);
	v_assert_ptr(str[ind], ==, ptr);

	// Check array integrity
	v_assert_size_t(ARR_SIZ_MAX(str) - 1, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(16, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[1], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[5], ==, ft_array_get(&v, 4));
	v_assert_ptr(str[6], ==, ft_array_get(&v, 5));
	v_assert_ptr(str[7], ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 8));

	v_assert_str(str[1], ft_array_get(&v, 0));
	v_assert_str(str[2], ft_array_get(&v, 1));
	v_assert_str(str[3], ft_array_get(&v, 2));
	v_assert_str(str[4], ft_array_get(&v, 3));
	v_assert_str(str[5], ft_array_get(&v, 4));
	v_assert_str(str[6], ft_array_get(&v, 5));
	v_assert_str(str[7], ft_array_get(&v, 6));

	teardown();
	VTS;
}

void	test_01_array_remove_MiddleItem(void)
{
	char	*ptr;
	size_t	ind = 3;
	setup();

	ptr = ft_array_remove(&v, ind);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_ptr(str[ind], ==, ptr);
	v_assert_str(str[ind], ptr);

	// Check array integrity
	v_assert_size_t(ARR_SIZ_MAX(str) - 1, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(16, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[5], ==, ft_array_get(&v, 4));
	v_assert_ptr(str[6], ==, ft_array_get(&v, 5));
	v_assert_ptr(str[7], ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 8));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[4], ft_array_get(&v, 3));
	v_assert_str(str[5], ft_array_get(&v, 4));
	v_assert_str(str[6], ft_array_get(&v, 5));
	v_assert_str(str[7], ft_array_get(&v, 6));

	teardown();
	VTS;
}

void	test_02_array_remove_LastItem(void)
{
	char	*ptr;
	size_t	ind = 7;
	setup();

	ptr = ft_array_remove(&v, ind);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_ptr(str[ind], ==, ptr);
	v_assert_str(str[ind], ptr);

	// Check array integrity
	v_assert_size_t(ARR_SIZ_MAX(str) - 1, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(16, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 4));
	v_assert_ptr(str[5], ==, ft_array_get(&v, 5));
	v_assert_ptr(str[6], ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 8));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(str[4], ft_array_get(&v, 4));
	v_assert_str(str[5], ft_array_get(&v, 5));
	v_assert_str(str[6], ft_array_get(&v, 6));

	teardown();
	VTS;
}

void	test_03_array_remove_OutOfRange(void)
{
	char	*ptr;
	size_t	ind = 8;
	setup();

	ptr = ft_array_remove(&v, ind);

	// Check return value
	v_assert_ptr(NULL, ==, ptr);

	// Check array integrity
	v_assert_size_t(ARR_SIZ_MAX(str), ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(16, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 4));
	v_assert_ptr(str[5], ==, ft_array_get(&v, 5));
	v_assert_ptr(str[6], ==, ft_array_get(&v, 6));
	v_assert_ptr(str[7], ==, ft_array_get(&v, 7));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 8));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(str[4], ft_array_get(&v, 4));
	v_assert_str(str[5], ft_array_get(&v, 5));
	v_assert_str(str[6], ft_array_get(&v, 6));
	v_assert_str(str[7], ft_array_get(&v, 7));

	teardown();
	VTS;
}

void	suite_array_remove(void)
{
	test_00_array_remove_FirstItem();
	test_01_array_remove_MiddleItem();
	test_02_array_remove_LastItem();
	test_03_array_remove_OutOfRange();

	VSS;
}
