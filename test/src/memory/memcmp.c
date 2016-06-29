/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:11:24 by adubois           #+#    #+#             */
/*   Updated: 2016/06/29 12:25:05 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_memcmp_Len0(void)
{
	char	str1[] = "Hello World!";
	char	str2[] = "Hello World!";
	size_t	n = 0;

	v_assert_int(ft_memcmp(str1, str2, n), ==, memcmp(str1, str2, n));

	VTS;
}

static void	test_01_memcmp_Len1(void)
{
	char	str1[] = "Hello World!";
	char	str2[] = "Hello World!";
	size_t	n = 1;

	v_assert_int(ft_memcmp(str1, str2, n), ==, memcmp(str1, str2, n));

	VTS;
}

static void	test_02_memcmp_SimpleString(void)
{
	char	str1[] = "Hello World!";
	char	str2[] = "Hello World!";
	size_t	n = 13;

	v_assert_int(ft_memcmp(str1, str2, n), ==, memcmp(str1, str2, n));

	VTS;
}

static void	test_03_memcmp_PartialString(void)
{
	char	str1[] = "Hello World!";
	char	str2[] = "Hello World!";
	size_t	n = 10;

	v_assert_int(ft_memcmp(str1, str2, n), ==, memcmp(str1, str2, n));

	VTS;
}

static void	test_04_memcmp_NonMatchingString(void)
{
	char	str1[] = "Hello World!";
	char	str2[] = "Hello there!";
	size_t	n = 10;

#ifdef __APPLE__
	v_assert_int(ft_memcmp(str1, str2, n), ==, memcmp(str1, str2, n));
#else
	v_assert_int(0, !=, ft_memcmp(str1, str2, n));
#endif

	VTS;
}

static void	test_05_memcmp_LongString(void)
{
	char	str1[4096];
	char	str2[4096];
	size_t	n = 4090;

	memset(str1, '*', 4096);
	memset(str2, '*', 4096);
	str1[4095] = '\0';
	str2[4095] = '\0';

	v_assert_int(ft_memcmp(str1, str2, n), ==, memcmp(str1, str2, n));

	VTS;
}

static void	test_06_memcmp_NonMatchingLongString(void)
{
	char	str1[4096];
	char	str2[4096];
	size_t	n = 4090;

	memset(str1, '*', 4096);
	memset(str2, '*', 4096);
	str1[4095] = '\0';
	str2[3095] = ' ';
	str2[4095] = '\0';

	v_assert_int(ft_memcmp(str1, str2, n), ==, memcmp(str1, str2, n));

	VTS;
}

static void	test_07_memcmp_SimpleStringFirstHigher(void)
{
	char	str1[] = "Hello World!";
	char	str2[] = "HellO World!";
	size_t	n = 10;

	v_assert_int(0, !=, ft_memcmp(str1, str2, n));

	VTS;
}

static void	test_08_memcmp_SimpleStringSecondHigher(void)
{
	char	str1[] = "Hello World!";
	char	str2[] = "Hello there!";
	size_t	n = 10;

	v_assert_int(0, !=, ft_memcmp(str1, str2, n));

	VTS;
}

void		suite_memcmp(void)
{
	test_00_memcmp_Len0();
	test_01_memcmp_Len1();
	test_02_memcmp_SimpleString();
	test_03_memcmp_PartialString();
	test_04_memcmp_NonMatchingString();
	test_05_memcmp_LongString();
	test_06_memcmp_NonMatchingLongString();
	test_07_memcmp_SimpleStringFirstHigher();
	test_08_memcmp_SimpleStringSecondHigher();

	VSS;
}
