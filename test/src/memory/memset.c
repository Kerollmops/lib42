/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:19:05 by adubois           #+#    #+#             */
/*   Updated: 2016/05/24 19:42:50 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_memset_SizeOf0(void)
{
	char	str[2];
	void	*res;

	bzero(str, 2);
	res = ft_memset(str, 48, 0);
	v_assert_ptr(res, ==, str);
	v_assert_str("", str);

	VTS;
}

static void	test_01_memset_SizeOf1(void)
{
	char	str[2];
	void	*res;

	bzero(str, 2);
	res = ft_memset(str, 48, 1);
	v_assert_ptr(res, ==, str);
	v_assert_str("0", str);

	VTS;
}

static void	test_02_memset_NullChar(void)
{
	char	str[2];
	void	*res;

	bzero(str, 2);
	str[0] = '0';
	res = ft_memset(str, 0, 1);
	v_assert_ptr(res, ==, str);
	v_assert_str("", str);

	VTS;
}

static void	test_03_memset_SameChar(void)
{
	char	str[6];
	void	*res;

	bzero(str, 6);
	res = ft_memset(str, 97, 5);
	v_assert_ptr(res, ==, str);
	v_assert_str("aaaaa", str);

	VTS;
}

static void	test_04_memset_SeveralChars(void)
{
	char	str[6];
	void	*res;

	bzero(str, 6);
	res = ft_memset(str, 97, 5);
	v_assert_ptr(res, ==, str);
	ft_memset(str + 2, 98, 2);
	v_assert_str("aabba", str);

	VTS;
}

static void	test_05_memset_NullCharInMiddle(void)
{
	char	str[6];
	void	*res;

	bzero(str, 6);
	res = ft_memset(str, 97, 5);
	v_assert_ptr(res, ==, str);
	ft_memset(str + 3, 98, 2);
	ft_memset(str + 2, 0, 1);
	v_assert_str("aa", str);

	VTS;
}

void		suite_memset(void)
{
	test_00_memset_SizeOf0();
	test_01_memset_SizeOf1();
	test_02_memset_NullChar();
	test_03_memset_SameChar();
	test_04_memset_SeveralChars();
	test_05_memset_NullCharInMiddle();

	VSS;
}
