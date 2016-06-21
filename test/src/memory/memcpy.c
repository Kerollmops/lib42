/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_memcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:37:47 by adubois           #+#    #+#             */
/*   Updated: 2016/06/21 14:47:57 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_memcpy_SizeOf0(void)
{
	char	str1[11];
	char	str2[11];
	void	*res;

	memset(str1, 48, 11);
	memset(str2, 42, 10);
	str2[10] = 0;
	res = ft_memcpy(str2, str1, 0);
	v_assert_ptr(res, ==, str2);
	v_assert_str("**********", str2);

	VTS;
}

static void	test_01_memcpy_SizeOf1(void)
{
	char	str1[11];
	char	str2[11];
	void	*res;

	memset(str1, 48, 11);
	memset(str2, 0, 11);
	res = ft_memcpy(str2, str1, 1);
	v_assert_ptr(res, ==, str2);
	v_assert_str("0", str2);

	VTS;
}

static void	test_02_memcpy_FullString(void)
{
	char	*str1;
	char	str2[11];
	void	*res;

	str1 = strdup("It works!");
	memset(str2, 0, 11);
	res = ft_memcpy(str2, str1, strlen(str1));
	v_assert_ptr(res, ==, str2);
	v_assert_str(str1, str2);

	VTS;
}

static void	test_03_memcpy_PartialString(void)
{
	char	*str1;
	char	str2[11];
	void	*res;

	str1 = strdup("It works!");
	memset(str2, 0, 11);
	res = ft_memcpy(str2, str1, strlen(str1) - 5);
	v_assert_ptr(res, ==, str2);
	v_assert_str("It w", str2);

	VTS;
}

static void	test_04_memcpy_LongString(void)
{
	char	*str1;
	char	str2[250];
	void	*res;

	str1 = strdup("KIa4jjPwBhAdTNhod2Q IYokyuGtHsTukcF7eXmM X1GMMRyONOTF3nvVg756 L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74x");
	memset(str2, 0, 250);
	res = ft_memcpy(str2, str1, strlen(str1));
	v_assert_ptr(res, ==, str2);
	v_assert_str(str1, str2);

	VTS;
}

void		suite_memcpy(void)
{
	test_00_memcpy_SizeOf0();
	test_01_memcpy_SizeOf1();
	test_02_memcpy_FullString();
	test_03_memcpy_PartialString();
	test_04_memcpy_LongString();

	VSS;
}
