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
	memset(&v, 0, sizeof(t_array));
}

void	test_00_array_add_SimpleAdd(void)
{
	char	*s1 = "firstadd";

	setup();

	ft_array_add(&v, s1);

	v_assert_size_t(6, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 4));
	v_assert_ptr(s1, ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 7));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(str[4], ft_array_get(&v, 4));
	v_assert_str(s1, ft_array_get(&v, 5));

	teardown();
	VTS;
}

void	test_01_array_add_ResizeAdd(void)
{
	char	*s1 = "firstadd";
	char	*s2 = "secondadd";

	setup();

	ft_array_add(&v, s1);
	ft_array_add(&v, s2);

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

void	suite_array_add(void)
{
	test_00_array_add_SimpleAdd();
	test_01_array_add_ResizeAdd();

	VSS;
}
