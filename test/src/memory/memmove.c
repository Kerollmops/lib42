/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_memmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:37:47 by adubois           #+#    #+#             */
/*   Updated: 2016/07/26 14:25:53 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_memmove_SizeOf0(void)
{
	char	str1[11];
	char	str2[11];
	void	*res;

	memset(str1, 48, 11);
	memset(str2, 0, 11);
	res = ft_memmove(str2, str1, 0);
	v_assert_ptr(res, ==, str2);
	v_assert_str("", str2);

	VTS;
}

static void	test_01_memmove_SizeOf1(void)
{
	char	str1[11];
	char	str2[11];
	void	*res;

	memset(str1, 48, 11);
	memset(str2, 0, 11);
	res = ft_memmove(str2, str1, 1);
	v_assert_ptr(res, ==, str2);
	v_assert_str("0", str2);

	VTS;
}

static void	test_02_memmove_FullString(void)
{
	char	*str1;
	char	str2[11];
	void	*res;

	str1 = strdup("It works!");
	memset(str2, 0, 11);
	res = ft_memmove(str2, str1, strlen(str1));
	v_assert_ptr(res, ==, str2);
	v_assert_str(str1, str2);

	free(str1);

	VTS;
}

static void	test_03_memmove_PartialString(void)
{
	char	*str1;
	char	str2[11];
	void	*res;

	str1 = strdup("It works!");
	memset(str2, 0, 11);
	res = ft_memmove(str2, str1, strlen(str1) - 5);
	v_assert_ptr(res, ==, str2);
	v_assert_str("It w", str2);

	free(str1);

	VTS;
}

static void	test_04_memmove_LongString(void)
{
	char	*str1;
	char	str2[250];
	void	*res;

	str1 = strdup("KIa4jjPwBhAdTNhod2Q IYokyuGtHsTukcF7eXmM X1GMMRyONOTF3nvVg756 L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74x");
	memset(str2, 0, 250);
	res = ft_memmove(str2, str1, strlen(str1));
	v_assert_ptr(res, ==, str2);
	v_assert_str(str1, str2);

	free(str1);

	VTS;
}

static void	test_05_memmove_LongStringDestinationFirst(void)
{
	char	*str1;
	char	*str2;
	void	*res;

	str2 = strdup("KIa4jjPwBhAdTNhod2Q IYokyuGtHsTukcF7eXmM X1GMMRyONOTF3nvVg756 L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74x");
    str1 = str2 + 62;
	res = ft_memmove(str2, str1, strlen(str1));
	v_assert_ptr(res, ==, str2);
	v_assert_str("L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74xbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74x", str2);
	free(str2);

	VTS;
}

static void	test_06_memmove_LongStringSourceFirst(void)
{
	char	*str1;
	char	*str2;
	void	*res;

	str1 = strdup("KIa4jjPwBhAdTNhod2Q IYokyuGtHsTukcF7eXmM X1GMMRyONOTF3nvVg756 L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74x");
    str2 = str1 + 13;
	res = ft_memmove(str2, str1, strlen(str1) - 13);
	v_assert_ptr(res, ==, str2);
	v_assert_str("KIa4jjPwBhAdTNhod2Q IYokyuGtHsTukcF7eXmM X1GMMRyONOTF3nvVg756 L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol", str2);

	free(str1);

	VTS;
}

void		suite_memmove(void)
{
	test_00_memmove_SizeOf0();
	test_01_memmove_SizeOf1();
	test_02_memmove_FullString();
	test_03_memmove_PartialString();
	test_04_memmove_LongString();
	test_05_memmove_LongStringDestinationFirst();
	test_06_memmove_LongStringSourceFirst();

	VSS;
}
