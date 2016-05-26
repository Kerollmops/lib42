#include "header.h"

void	test_00_ft_strrchrpos_SimpleString1(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", 'H');
	v_assert_int(0, ==, ret);

	VTS;
}

void	test_01_ft_strrchrpos_SimpleString2(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", '!');
	v_assert_int(11, ==, ret);

	VTS;
}

void	test_02_ft_strrchrpos_CharNotFound(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", '#');
	v_assert_int(-1, ==, ret);

	VTS;
}

void	test_03_ft_strrchrpos_TwoOccurrence(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", 'o');
	v_assert_int(7, ==, ret);

	VTS;
}

void	test_04_ft_strrchrpos_EndOfString(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", 0);
	v_assert_int(12, ==, ret);

	VTS;
}

void	test_05_ft_strrchrpos_SimpleString3(void)
{
	int ret;

	ret = ft_strrchrpos("Hello World!", 'd');
	v_assert_int(10, ==, ret);

	VTS;
}

void	test_06_ft_strrchrpos_EmptyString(void)
{
	int ret;

	ret = ft_strrchrpos("", 'a');
	v_assert_int(-1, ==, ret);

	VTS;
}

void	test_07_ft_strrchrpos_EmptyStringNullChar(void)
{
	int ret;

	ret = ft_strrchrpos("", '\0');
	v_assert_int(0, ==, ret);

	VTS;
}

void	suite_strrchrpos(void)
{
	test_00_ft_strrchrpos_SimpleString1();
	test_01_ft_strrchrpos_SimpleString2();
	test_02_ft_strrchrpos_CharNotFound();
	test_03_ft_strrchrpos_TwoOccurrence();
	test_04_ft_strrchrpos_EndOfString();
	test_05_ft_strrchrpos_SimpleString3();
	test_06_ft_strrchrpos_EmptyString();
	test_07_ft_strrchrpos_EmptyStringNullChar();

	VSS;
}
