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
	for (size_t i = 0; i < ARR_SIZ_MAX(str); ++i)
		ft_array_add(&v, str[i]);
}

static void	teardown(void)
{
	FT_ARRAY_FREE(&v);
	bzero(&v, sizeof(t_array));
}

void	test_00_array_insert_FirstPlace(void)
{
	char	*s1 = "zut";
	setup();

	ft_array_insert(&v, 0, s1);

	// Check array integrity
	v_assert_size_t(6, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(s1, ==, ft_array_get(&v, 0));
	v_assert_ptr(str[0], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 4));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));

	v_assert_str(s1, ft_array_get(&v, 0));
	v_assert_str(str[0], ft_array_get(&v, 1));
	v_assert_str(str[1], ft_array_get(&v, 2));
	v_assert_str(str[2], ft_array_get(&v, 3));
	v_assert_str(str[3], ft_array_get(&v, 4));
	v_assert_str(str[4], ft_array_get(&v, 5));

	teardown();
	VTS;
}

void	test_01_array_insert_LastPlace(void)
{
	char	*s1 = "zut";
	setup();

	ft_array_insert(&v, 4, s1);

	// Check array integrity
	v_assert_size_t(6, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(s1, ==, ft_array_get(&v, 4));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(s1, ft_array_get(&v, 4));
	v_assert_str(str[4], ft_array_get(&v, 5));

	teardown();
	VTS;
}

void	test_02_array_insert_MiddlePlace(void)
{
	char	*s1 = "zut";
	setup();

	ft_array_insert(&v, 2, s1);

	// Check array integrity
	v_assert_size_t(6, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(s1, ==, ft_array_get(&v, 2));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 4));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(s1, ft_array_get(&v, 2));
	v_assert_str(str[2], ft_array_get(&v, 3));
	v_assert_str(str[3], ft_array_get(&v, 4));
	v_assert_str(str[4], ft_array_get(&v, 5));

	teardown();
	VTS;
}

void	test_03_array_insert_Resize(void)
{
	char	*s1 = "zut1";
	char	*s2 = "zut2";
	setup();

	ft_array_insert(&v, FT_ARRAY_TOTAL(&v), s1);
	ft_array_insert(&v, FT_ARRAY_TOTAL(&v), s2);

	// Check array integrity
	v_assert_size_t(7, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(16, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 4));
	v_assert_ptr(s1, ==, ft_array_get(&v, 5));
	v_assert_ptr(s2, ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 8));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(str[4], ft_array_get(&v, 4));
	v_assert_str(s1, ft_array_get(&v, 5));
	v_assert_str(s2, ft_array_get(&v, 6));

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
