#include "header.h"

static t_vector	v;
static char		*str[] = {
	"hello",
	"world",
	"and",
	"good",
	"morning",
};

static void	setup(void)
{
	ft_vector_init(&v, 8);
	FT_VECTOR_DATA(&v)[0] = str[0];
	FT_VECTOR_DATA(&v)[1] = str[1];
	FT_VECTOR_DATA(&v)[2] = str[2];
	FT_VECTOR_DATA(&v)[3] = str[3];
	FT_VECTOR_DATA(&v)[4] = str[4];
	FT_VECTOR_TOTAL(&v) = 5;
}

static void	teardown(void)
{
	FT_VECTOR_FREE(&v);
	bzero(&v, sizeof(t_vector));
}

void	test_00_ft_vector_add_SimpleAdd(void)
{
	char	*s1 = "firstadd";

	setup();

	ft_vector_add(&v, s1);

	v_assert_size_t(6, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(8, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[0], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 4));
	v_assert_ptr(s1, ==, ft_vector_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 7));

	v_assert_str(str[0], ft_vector_get(&v, 0));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(str[2], ft_vector_get(&v, 2));
	v_assert_str(str[3], ft_vector_get(&v, 3));
	v_assert_str(str[4], ft_vector_get(&v, 4));
	v_assert_str(s1, ft_vector_get(&v, 5));

	teardown();
	VTS;
}

void	test_01_ft_vector_add_ResizeAdd(void)
{
	char	*s1 = "firstadd";
	char	*s2 = "secondadd";

	setup();

	ft_vector_add(&v, s1);
	ft_vector_add(&v, s2);

	v_assert_size_t(7, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(16, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[0], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 4));
	v_assert_ptr(s1, ==, ft_vector_get(&v, 5));
	v_assert_ptr(s2, ==, ft_vector_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 7));

	v_assert_str(str[0], ft_vector_get(&v, 0));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(str[2], ft_vector_get(&v, 2));
	v_assert_str(str[3], ft_vector_get(&v, 3));
	v_assert_str(str[4], ft_vector_get(&v, 4));
	v_assert_str(s1, ft_vector_get(&v, 5));
	v_assert_str(s2, ft_vector_get(&v, 6));

	teardown();
	VTS;
}

void	suite_ft_vector_add(void)
{
	test_00_ft_vector_add_SimpleAdd();
	test_01_ft_vector_add_ResizeAdd();

	VSS;
}
