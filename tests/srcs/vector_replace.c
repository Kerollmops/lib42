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

void	test_00_ft_vector_replace_FirstItem(void)
{
	char	*rep = "firstitem";
	char	*ptr;
	size_t	ind = 0;
	setup();

	ptr = ft_vector_replace(&v, ind, rep);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_str(str[ind], ptr);
	v_assert_ptr(str[ind], ==, ptr);

	// Check vector integrity
	v_assert_size_t(5, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(8, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(rep, ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 6));

	v_assert_str(rep, ft_vector_get(&v, ind));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(str[2], ft_vector_get(&v, 2));
	v_assert_str(str[3], ft_vector_get(&v, 3));
	v_assert_str(str[4], ft_vector_get(&v, 4));

	teardown();
	VTS;
}

void	test_01_ft_vector_replace_MiddleItem(void)
{
	char	*rep = "middleitem";
	char	*ptr;
	size_t	ind = 2;
	setup();

	ptr = ft_vector_replace(&v, ind, rep);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_str(str[ind], ptr);
	v_assert_ptr(str[ind], ==, ptr);

	// Check vector integrity
	v_assert_size_t(5, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(8, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[0], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(rep, ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 6));

	v_assert_str(str[0], ft_vector_get(&v, 0));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(rep, ft_vector_get(&v, 2));
	v_assert_str(str[3], ft_vector_get(&v, 3));
	v_assert_str(str[4], ft_vector_get(&v, 4));

	teardown();
	VTS;
}

void	test_02_ft_vector_replace_LastItem(void)
{
	char	*rep = "lastitem";
	char	*ptr;
	size_t	ind = 4;
	setup();

	ptr = ft_vector_replace(&v, ind, rep);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_str(str[ind], ptr);
	v_assert_ptr(str[ind], ==, ptr);

	// Check vector integrity
	v_assert_size_t(5, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(8, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[0], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 3));
	v_assert_ptr(rep, ==, ft_vector_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 6));

	v_assert_str(str[0], ft_vector_get(&v, 0));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(str[2], ft_vector_get(&v, 2));
	v_assert_str(str[3], ft_vector_get(&v, 3));
	v_assert_str(rep, ft_vector_get(&v, 4));

	teardown();
	VTS;
}

void	test_03_ft_vector_replace_OutOfRange(void)
{
	char	*rep = "outofrange";
	char	*ptr;
	size_t	ind = 5;
	setup();

	ptr = ft_vector_replace(&v, ind, rep);

	// Check return value
	v_assert_ptr(NULL, ==, ptr);

	// Check vector integrity
	v_assert_size_t(5, ==, FT_VECTOR_TOTAL(&v));
	v_assert_size_t(8, ==, FT_VECTOR_MAX(&v));

	v_assert_ptr(str[0], ==, ft_vector_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_vector_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_vector_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_vector_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_vector_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_vector_get(&v, 6));

	v_assert_str(str[0], ft_vector_get(&v, 0));
	v_assert_str(str[1], ft_vector_get(&v, 1));
	v_assert_str(str[2], ft_vector_get(&v, 2));
	v_assert_str(str[3], ft_vector_get(&v, 3));
	v_assert_str(str[4], ft_vector_get(&v, 4));

	teardown();
	VTS;
}

void	suite_ft_vector_replace(void)
{
	test_00_ft_vector_replace_FirstItem();
	test_01_ft_vector_replace_MiddleItem();
	test_02_ft_vector_replace_LastItem();
	test_03_ft_vector_replace_OutOfRange();

	VSS;
}
