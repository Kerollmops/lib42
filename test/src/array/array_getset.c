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

void	test_00_array_getMacro_FirstItem(void)
{
	void	*ptr;
	setup();

	ptr = FT_ARRAY_GET(&v, 0);
	v_assert_ptr(v.data[0], ==, ptr);
	v_assert_ptr(v.data[0], ==, FT_ARRAY_GET(&v, 0));
	v_assert_str(v.data[0], ptr);
	v_assert_str(v.data[0], FT_ARRAY_GET(&v, 0));
	FT_ARRAY_GET(&v, 0);

	teardown();
	VTS;
}

void	test_01_array_getMacro_LastItem(void)
{
	void	*ptr;
	setup();

	ptr = FT_ARRAY_GET(&v, 4);
	v_assert_ptr(v.data[4], ==, ptr);
	v_assert_ptr(v.data[4], ==, FT_ARRAY_GET(&v, 4));
	v_assert_str(v.data[4], ptr);
	v_assert_str(v.data[4], FT_ARRAY_GET(&v, 4));
	FT_ARRAY_GET(&v, 4);

	teardown();
	VTS;
}

void	test_02_array_getMacro_OutOfRange(void)
{
	void	*ptr;
	setup();

	ptr = FT_ARRAY_GET(&v, 5);
	v_assert_ptr(NULL, ==, ptr);
	v_assert_ptr(NULL, ==, FT_ARRAY_GET(&v, 5));
	FT_ARRAY_GET(&v, 5);

	teardown();
	VTS;
}

void	test_03_array_setMacro_FirstItem(void)
{
	char	*new = "newelem";
	void	*ptr;
	setup();

	ptr = FT_ARRAY_SET(&v, 0, new);
	v_assert_ptr(v.data[0], ==, ptr);
	v_assert_ptr(v.data[0], ==, new);
	v_assert_ptr(v.data[0], ==, FT_ARRAY_SET(&v, 0, new));
	v_assert_str(v.data[0], ptr);
	v_assert_str(v.data[0], new);
	v_assert_str(v.data[0], FT_ARRAY_SET(&v, 0, new));
	FT_ARRAY_SET(&v, 0, new);

	teardown();
	VTS;
}

void	test_04_array_setMacro_LastItem(void)
{
	char	*new = "newelemlast";
	void	*ptr;
	setup();

	ptr = FT_ARRAY_SET(&v, 4, new);
	v_assert_ptr(v.data[4], ==, ptr);
	v_assert_ptr(v.data[4], ==, new);
	v_assert_ptr(v.data[4], ==, FT_ARRAY_SET(&v, 4, new));
	v_assert_str(v.data[4], ptr);
	v_assert_str(v.data[4], new);
	v_assert_str(v.data[4], FT_ARRAY_SET(&v, 4, new));
	FT_ARRAY_SET(&v, 4, new);

	teardown();
	VTS;
}

void	test_05_array_setMacro_OutOfRange(void)
{
	char	*new = "newelemout";
	void	*ptr;
	setup();

	ptr = FT_ARRAY_SET(&v, 5, new);
	v_assert_ptr(NULL, ==, ptr);
	v_assert_ptr(NULL, ==, FT_ARRAY_SET(&v, 5, new));
	FT_ARRAY_SET(&v, 5, new);

	teardown();
	VTS;
}

void	suite_array_get_set(void)
{
	test_00_array_getMacro_FirstItem();
	test_01_array_getMacro_LastItem();
	test_02_array_getMacro_OutOfRange();
	test_03_array_setMacro_FirstItem();
	test_04_array_setMacro_LastItem();
	test_05_array_setMacro_OutOfRange();

	VSS;
}
