#include "header.h"

void	test_00_strchrpos_SimpleString1(void)
{
	int ret;

	ret = ft_strchrpos("Hello World!", 'H');
	v_assert_int(0, ==, ret);

	VTS;
}

void	test_01_strchrpos_SimpleString2(void)
{
	int ret;

	ret = ft_strchrpos("Hello World!", '!');
	v_assert_int(11, ==, ret);

	VTS;
}

void	test_02_strchrpos_CharNotFound(void)
{
	int ret;

	ret = ft_strchrpos("Hello World!", '#');
	v_assert_int(-1, ==, ret);

	VTS;
}

void	test_03_strchrpos_TwoOccurrence(void)
{
	int ret;

	ret = ft_strchrpos("Hello World!", 'o');
	v_assert_int(4, ==, ret);

	VTS;
}

void	test_04_strchrpos_EndOfString(void)
{
	int ret;

	ret = ft_strchrpos("Hello World!", 0);
	v_assert_int(12, ==, ret);

	VTS;
}

void	suite_strchrpos(void)
{
	test_00_strchrpos_SimpleString1();
	test_01_strchrpos_SimpleString2();
	test_02_strchrpos_CharNotFound();
	test_03_strchrpos_TwoOccurrence();
	test_04_strchrpos_EndOfString();

	VSS;
}
