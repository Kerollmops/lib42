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
};

static void	setup(void)
{
	array_init(&v, 8);
	/* printf("ARR_SIZ_MAX: %zu\n", ARR_SIZ_MAX(str)); */
	for (size_t i = 0; i < ARR_SIZ_MAX(str); ++i)
		array_add(&v, strdup(str[i]));
}

void	test_00_array_clear_Simple(void)
{
	setup();

	array_clear(&v);

	v_assert_size_t(8, ==, v.max);
	v_assert_size_t(0, ==, v.total);
	v_assert_ptr(NULL, ==, v.data[0]);
	v_assert_ptr(NULL, ==, v.data[1]);
	v_assert_ptr(NULL, ==, v.data[2]);
	v_assert_ptr(NULL, ==, v.data[3]);
	v_assert_ptr(NULL, ==, v.data[4]);
	v_assert_ptr(NULL, ==, v.data[5]);
	v_assert_ptr(NULL, ==, v.data[6]);
	v_assert_ptr(NULL, ==, v.data[7]);
	
	VTS;
}

void	suite_array_clear(void)
{
	test_00_array_clear_Simple();

	VSS;
}

