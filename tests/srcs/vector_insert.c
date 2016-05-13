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
	for (size_t i = 0; i < ARR_SIZ_MAX(str); ++i)
		ft_vector_add(&v, str[i]);
}

static void	teardown(void)
{
	FT_VECTOR_FREE(&v);
	bzero(&v, sizeof(t_vector));
}

void	test_00_ft_vector_insert_FirstPlace(void)
{
	char	*s1 = "zut";
	setup();

	ft_vector_insert(&v, 0, s1);

	// Check vector integrity
	v_assert_size_t(6, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(8, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(s1, ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[0], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 4));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 7));

	v_assert_str(s1, ft_vector_get(&v, 0));
	v_assert_str(str[0], ft_vector_get(&v, 1));
	v_assert_str(str[1], ft_vector_get(&v, 2));
	v_assert_str(str[2], ft_vector_get(&v, 3));
	v_assert_str(str[3], ft_vector_get(&v, 4));
	v_assert_str(str[4], ft_vector_get(&v, 5));

	teardown();
	VTS;
}

void	test_01_ft_vector_insert_LastPlace(void)
{
	char	*s1 = "zut";
	setup();

	ft_vector_insert(&v, 4, s1);

	// Check vector integrity
	v_assert_size_t(6, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(8, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[0], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 3));
	v_assert_ptr(s1, ==, ft_vector_get(&v, 4));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 7));

	v_assert_str(str[0], ft_vector_get(&v, 0));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(str[2], ft_vector_get(&v, 2));
	v_assert_str(str[3], ft_vector_get(&v, 3));
	v_assert_str(s1, ft_vector_get(&v, 4));
	v_assert_str(str[4], ft_vector_get(&v, 5));

	teardown();
	VTS;
}

void	test_02_ft_vector_insert_MiddlePlace(void)
{
	char	*s1 = "zut";
	setup();

	ft_vector_insert(&v, 2, s1);

	// Check vector integrity
	v_assert_size_t(6, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(8, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[0], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(s1, ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 4));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 7));

	v_assert_str(str[0], ft_vector_get(&v, 0));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(s1, ft_vector_get(&v, 2));
	v_assert_str(str[2], ft_vector_get(&v, 3));
	v_assert_str(str[3], ft_vector_get(&v, 4));
	v_assert_str(str[4], ft_vector_get(&v, 5));

	teardown();
	VTS;
}

void	test_03_ft_vector_insert_Resize(void)
{
	char	*s1 = "zut1";
	char	*s2 = "zut2";
	setup();

	ft_vector_insert(&v, FT_VECTOR_TOTAL(&v), s1);
	ft_vector_insert(&v, FT_VECTOR_TOTAL(&v), s2);

	// Check vector integrity
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
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 8));

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

void	suite_ft_vector_insert(void)
{
	test_00_ft_vector_insert_FirstPlace();
	test_01_ft_vector_insert_LastPlace();
	test_02_ft_vector_insert_MiddlePlace();
	test_03_ft_vector_insert_Resize();

	VSS;
}
