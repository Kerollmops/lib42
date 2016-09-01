/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:52:06 by adubois           #+#    #+#             */
/*   Updated: 2016/07/26 14:14:06 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_memchr_Len0(void)
{
	char	str[] = "Hello World!";
	int		chr = 'W';
	size_t	n = 0;

	v_assert_ptr(ft_memchr(str, chr, n), ==, memchr(str, chr, n));

	VTS;
}

static void	test_01_memchr_Len1(void)
{
	char	str[] = "Hello World!";
	int		chr = 'W';
	size_t	n = 1;

	v_assert_ptr(ft_memchr(str, chr, n), ==, memchr(str, chr, n));

	VTS;
}

static void	test_02_memchr_FindFirstChar(void)
{
	char	str[] = "Hello World!";
	int		chr = 'H';
	size_t	n = 10;

	v_assert_ptr(ft_memchr(str, chr, n), ==, memchr(str, chr, n));

	VTS;
}

static void	test_03_memchr_FindNoChar(void)
{
	char	str[] = "Hello World!";
	int		chr = '*';
	size_t	n = 13;

	v_assert_ptr(ft_memchr(str, chr, n), ==, memchr(str, chr, n));

	VTS;
}

#if !defined(SANITIZE)
static void	test_04_memchr_FindNullChar(void)
{
	char	str[] = "Hello World!";
	int		chr = '\0';
	size_t	n = 25;

	v_assert_ptr(ft_memchr(str, chr, n), ==, memchr(str, chr, n));

	VTS;
}
#endif

static void	test_05_memchr_FindNullCharLongString(void)
{
	char	str[4096];
	int		chr = '\0';
	size_t	n = 4096;

	memset(str, '*', 4096);
	str[4090] = '\0';
	v_assert_ptr(ft_memchr(str, chr, n), ==, memchr(str, chr, n));

	VTS;
}

void		suite_memchr(void)
{
	test_00_memchr_Len0();
	test_01_memchr_Len1();
	test_02_memchr_FindFirstChar();
	test_03_memchr_FindNoChar();
#if !defined(SANITIZE)
	test_04_memchr_FindNullChar();
#endif
	test_05_memchr_FindNullCharLongString();

	VSS;
}
