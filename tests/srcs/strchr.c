#include "header.h"

void	test_00_strchr_CharInMiddle(void)
{
	char *s = "Hello World!";
	char *chr;

	chr = ft_strchr(s, 'o');
	v_assert_int('o', ==, *chr);
	v_assert_str("o World!", chr);
	v_assert_ptr(s + 4, ==, chr);

	VTS;
}

void	test_01_strchr_CharAtBeginning(void)
{
	char *s = "Hello World!";
	char *chr;

	chr = ft_strchr(s, 'H');
	v_assert_int('H', ==, *chr);
	v_assert_str(s, chr);
	v_assert_ptr(s, ==, chr);

	VTS;
}

void	test_02_strchr_CharAtEnd(void)
{
	char *s = "Hello World!";
	char *chr;

	chr = ft_strchr(s, '!');
	v_assert_int('!', ==, *chr);
	v_assert_str(s + strlen(s) - 1, chr);
	v_assert_ptr(s + strlen(s) - 1, ==, chr);

	VTS;
}

void	test_03_strchr_CharNull(void)
{
	char *s = "Hello World!";
	char *chr;

	chr = ft_strchr(s, '\0');
	v_assert_int('\0', ==, *chr);
	v_assert_str(s + strlen(s), chr);
	v_assert_ptr(s + strlen(s), ==, chr);

	VTS;
}

void	test_04_strchr_CharNotFound(void)
{
	char *s = "Hello World!";
	char *chr;

	chr = ft_strchr(s, 'z');
	v_assert_ptr(NULL, ==, chr);

	VTS;
}

void	test_05_strchr_EmptyString(void)
{
	char *s = "";
	char *chr;

	chr = ft_strchr(s, 'z');
	v_assert_ptr(NULL, ==, chr);

	VTS;
}

void	test_06_strchr_EmptyStringWithNullChar(void)
{
	char *s = "";
	char *chr;

	chr = ft_strchr(s, '\0');
	v_assert_int('\0', ==, *chr);
	v_assert_str(s, chr);
	v_assert_ptr(s, ==, chr);

	VTS;
}

void	suite_strchr(void)
{
	test_00_strchr_CharInMiddle();
	test_01_strchr_CharAtBeginning();
	test_02_strchr_CharAtEnd();
	test_03_strchr_CharNull();
	test_04_strchr_CharNotFound();
	test_05_strchr_EmptyString();
	test_06_strchr_EmptyStringWithNullChar();

	VSS;
}
