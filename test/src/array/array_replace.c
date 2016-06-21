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
	memset(&v, 0, sizeof(t_array));
}

void	test_00_array_replace_FirstItem(void)
{
	char	*rep = "firstitem";
	char	*ptr;
	size_t	ind = 0;
	setup();

	ptr = ft_array_replace(&v, ind, rep);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_str(str[ind], ptr);
	v_assert_ptr(str[ind], ==, ptr);

	// Check array integrity
	v_assert_size_t(5, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(rep, ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));

	v_assert_str(rep, ft_array_get(&v, ind));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(str[4], ft_array_get(&v, 4));

	teardown();
	VTS;
}

void	test_01_array_replace_MiddleItem(void)
{
	char	*rep = "middleitem";
	char	*ptr;
	size_t	ind = 2;
	setup();

	ptr = ft_array_replace(&v, ind, rep);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_str(str[ind], ptr);
	v_assert_ptr(str[ind], ==, ptr);

	// Check array integrity
	v_assert_size_t(5, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(rep, ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(rep, ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(str[4], ft_array_get(&v, 4));

	teardown();
	VTS;
}

void	test_02_array_replace_LastItem(void)
{
	char	*rep = "lastitem";
	char	*ptr;
	size_t	ind = 4;
	setup();

	ptr = ft_array_replace(&v, ind, rep);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_str(str[ind], ptr);
	v_assert_ptr(str[ind], ==, ptr);

	// Check array integrity
	v_assert_size_t(5, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(rep, ==, ft_array_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(rep, ft_array_get(&v, 4));

	teardown();
	VTS;
}

void	test_03_array_replace_OutOfRange(void)
{
	char	*rep = "outofrange";
	char	*ptr;
	size_t	ind = 5;
	setup();

	ptr = ft_array_replace(&v, ind, rep);

	// Check return value
	v_assert_ptr(NULL, ==, ptr);

	// Check array integrity
	v_assert_size_t(5, ==, FT_ARRAY_TOTAL(&v));
	v_assert_size_t(8, ==, FT_ARRAY_MAX(&v));

	v_assert_ptr(str[0], ==, ft_array_get(&v, 0));
	v_assert_ptr(str[1], ==, ft_array_get(&v, 1));
	v_assert_ptr(str[2], ==, ft_array_get(&v, 2));
	v_assert_ptr(str[3], ==, ft_array_get(&v, 3));
	v_assert_ptr(str[4], ==, ft_array_get(&v, 4));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 5));
	v_assert_ptr(NULL, ==, ft_array_get(&v, 6));

	v_assert_str(str[0], ft_array_get(&v, 0));
	v_assert_str(str[1], ft_array_get(&v, 1));
	v_assert_str(str[2], ft_array_get(&v, 2));
	v_assert_str(str[3], ft_array_get(&v, 3));
	v_assert_str(str[4], ft_array_get(&v, 4));

	teardown();
	VTS;
}

void	suite_array_replace(void)
{
	test_00_array_replace_FirstItem();
	test_01_array_replace_MiddleItem();
	test_02_array_replace_LastItem();
	test_03_array_replace_OutOfRange();

	VSS;
}
