#include "header.h"

void	test_00_strrchrpos_SimpleString1(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", 'H');
	v_assert_int(0, ==, ret);

	VTS;
}

void	test_01_strrchrpos_SimpleString2(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", '!');
	v_assert_int(11, ==, ret);

	VTS;
}

void	test_02_strrchrpos_CharNotFound(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", '#');
	v_assert_int(-1, ==, ret);

	VTS;
}

void	test_03_strrchrpos_TwoOccurrence(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", 'o');
	v_assert_int(7, ==, ret);

	VTS;
}

void	test_04_strrchrpos_EndOfString(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", 0);
	v_assert_int(12, ==, ret);

	VTS;
}

void	test_05_strrchrpos_SimpleString3(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", 'd');
	v_assert_int(10, ==, ret);

	VTS;
}

void	suite_strrchrpos(void)
{
	test_00_strrchrpos_SimpleString1();
	test_01_strrchrpos_SimpleString2();
	test_02_strrchrpos_CharNotFound();
	test_03_strrchrpos_TwoOccurrence();
	test_04_strrchrpos_EndOfString();
	test_05_strrchrpos_SimpleString3();

	VSS;
}
