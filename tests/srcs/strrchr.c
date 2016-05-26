#include "header.h"

void	test_00_strrchr_CharInMiddle(void)
{
	char *s = "Hello World!";
	char *chr;

	chr = ft_strrchr(s, 'o');
	v_assert_ptr(s + 7, ==, chr);
	v_assert_str("orld!", chr);
	v_assert_int('o', ==, *chr);

	VTS;
}

void	test_01_strrchr_CharAtBeginning(void)
{
	char *s = "Hello World!";
	char *chr;

	chr = ft_strrchr(s, 'H');
	v_assert_ptr(s, ==, chr);
	v_assert_str(s, chr);
	v_assert_int('H', ==, *chr);

	VTS;
}

void	test_02_strrchr_CharAtEnd(void)
{
	char *s = "Hello World!";
	char *chr;

	chr = ft_strrchr(s, '!');
	v_assert_ptr(s + strlen(s) - 1, ==, chr);
	v_assert_str(s + strlen(s) - 1, chr);
	v_assert_int('!', ==, *chr);

	VTS;
}

void	test_03_strrchr_CharNull(void)
{
	char *s = "Hello World!";
	char *chr;

	chr = ft_strrchr(s, '\0');
	v_assert_ptr(s + strlen(s), ==, chr);
	v_assert_str(s + strlen(s), chr);
	v_assert_int('\0', ==, *chr);

	VTS;
}

void	test_04_strrchr_CharNotFound(void)
{
	char *s = "Hello World!";
	char *chr;

	chr = ft_strrchr(s, 'z');
	v_assert_ptr(NULL, ==, chr);

	VTS;
}

void	test_05_strrchr_EmptyString(void)
{
	char *s = "";
	char *chr;

	chr = ft_strrchr(s, 'z');
	v_assert_ptr(NULL, ==, chr);

	VTS;
}

void	test_06_strrchr_EmptyStringWithNullChar(void)
{
	char *s = "";
	char *chr;

	chr = ft_strrchr(s, '\0');
	v_assert_ptr(s, ==, chr);
	v_assert_str(s, chr);
	v_assert_int('\0', ==, *chr);

	VTS;
}

void	suite_strrchr(void)
{
	test_00_strrchr_CharInMiddle();
	test_01_strrchr_CharAtBeginning();
	test_02_strrchr_CharAtEnd();
	test_03_strrchr_CharNull();
	test_04_strrchr_CharNotFound();
	test_05_strrchr_EmptyString();
	test_06_strrchr_EmptyStringWithNullChar();

	VSS;
}
