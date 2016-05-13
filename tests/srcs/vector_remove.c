#include "header.h"

static t_vector	v;
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
	ft_vector_init(&v, 8);
	for (size_t i = 0; i < ARR_SIZ_MAX(str); ++i)
		ft_vector_add(&v, str[i]);
}

static void	teardown(void)
{
	FT_VECTOR_FREE(&v);
	bzero(&v, sizeof(t_vector));
}

void	test_00_ft_vector_remove_FirstItem(void)
{
	char	*ptr;
	size_t	ind = 0;
	setup();

	ptr = ft_vector_remove(&v, ind);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_str(str[ind], ptr);
	v_assert_ptr(str[ind], ==, ptr);

	// Check vector integrity
	v_assert_size_t(ARR_SIZ_MAX(str) - 1, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(16, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[1], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[5], ==, ft_vector_get(&v, 4));
	v_assert_ptr(str[6], ==, ft_vector_get(&v, 5));
	v_assert_ptr(str[7], ==, ft_vector_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 7));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 8));

	v_assert_str(str[1], ft_vector_get(&v, 0));
	v_assert_str(str[2], ft_vector_get(&v, 1));
	v_assert_str(str[3], ft_vector_get(&v, 2));
	v_assert_str(str[4], ft_vector_get(&v, 3));
	v_assert_str(str[5], ft_vector_get(&v, 4));
	v_assert_str(str[6], ft_vector_get(&v, 5));
	v_assert_str(str[7], ft_vector_get(&v, 6));

	teardown();
	VTS;
}

void	test_01_ft_vector_remove_MiddleItem(void)
{
	char	*ptr;
	size_t	ind = 3;
	setup();

	ptr = ft_vector_remove(&v, ind);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_ptr(str[ind], ==, ptr);
	v_assert_str(str[ind], ptr);

	// Check vector integrity
	v_assert_size_t(ARR_SIZ_MAX(str) - 1, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(16, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[0], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[5], ==, ft_vector_get(&v, 4));
	v_assert_ptr(str[6], ==, ft_vector_get(&v, 5));
	v_assert_ptr(str[7], ==, ft_vector_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 7));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 8));

	v_assert_str(str[0], ft_vector_get(&v, 0));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(str[2], ft_vector_get(&v, 2));
	v_assert_str(str[4], ft_vector_get(&v, 3));
	v_assert_str(str[5], ft_vector_get(&v, 4));
	v_assert_str(str[6], ft_vector_get(&v, 5));
	v_assert_str(str[7], ft_vector_get(&v, 6));

	teardown();
	VTS;
}

void	test_02_ft_vector_remove_LastItem(void)
{
	char	*ptr;
	size_t	ind = 7;
	setup();

	ptr = ft_vector_remove(&v, ind);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_ptr(str[ind], ==, ptr);
	v_assert_str(str[ind], ptr);

	// Check vector integrity
	v_assert_size_t(ARR_SIZ_MAX(str) - 1, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(16, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[0], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 4));
	v_assert_ptr(str[5], ==, ft_vector_get(&v, 5));
	v_assert_ptr(str[6], ==, ft_vector_get(&v, 6));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 7));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 8));

	v_assert_str(str[0], ft_vector_get(&v, 0));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(str[2], ft_vector_get(&v, 2));
	v_assert_str(str[3], ft_vector_get(&v, 3));
	v_assert_str(str[4], ft_vector_get(&v, 4));
	v_assert_str(str[5], ft_vector_get(&v, 5));
	v_assert_str(str[6], ft_vector_get(&v, 6));

	teardown();
	VTS;
}

void	test_03_ft_vector_remove_OutOfRange(void)
{
	char	*ptr;
	size_t	ind = 8;
	setup();

	ptr = ft_vector_remove(&v, ind);

	// Check return value
	v_assert_ptr(NULL, ==, ptr);

	// Check vector integrity
	v_assert_size_t(ARR_SIZ_MAX(str), ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(16, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[0], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 4));
	v_assert_ptr(str[5], ==, ft_vector_get(&v, 5));
	v_assert_ptr(str[6], ==, ft_vector_get(&v, 6));
	v_assert_ptr(str[7], ==, ft_vector_get(&v, 7));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 8));

	v_assert_str(str[0], ft_vector_get(&v, 0));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(str[2], ft_vector_get(&v, 2));
	v_assert_str(str[3], ft_vector_get(&v, 3));
	v_assert_str(str[4], ft_vector_get(&v, 4));
	v_assert_str(str[5], ft_vector_get(&v, 5));
	v_assert_str(str[6], ft_vector_get(&v, 6));
	v_assert_str(str[7], ft_vector_get(&v, 7));

	teardown();
	VTS;
}

void	suite_ft_vector_remove(void)
{
	test_00_ft_vector_remove_FirstItem();
	test_01_ft_vector_remove_MiddleItem();
	test_02_ft_vector_remove_LastItem();
	test_03_ft_vector_remove_OutOfRange();

	VSS;
}
