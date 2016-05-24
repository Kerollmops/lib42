/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_memmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:37:47 by adubois           #+#    #+#             */
/*   Updated: 2016/05/24 15:19:49 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	test_size_0(void)
{
	char	str1[11];
	char	str2[11];

	memset(str1, 48, 11);
	bzero(str2, 11);
	ft_memmove(str2, str1, 0);
	v_assert_str("", str2);
}

static void	test_size_1(void)
{
	char	str1[11];
	char	str2[11];

	memset(str1, 48, 11);
	bzero(str2, 11);
	ft_memmove(str2, str1, 1);
	v_assert_str("0", str2);
}

static void	test_string(void)
{
	char	*str1;
	char	str2[11];

	str1 = strdup("It works!");
	bzero(str2, 11);
	ft_memmove(str2, str1, strlen(str1));
	v_assert_str(str1, str2);
}

static void	test_string_shorter(void)
{
	char	*str1;
	char	str2[11];

	str1 = strdup("It works!");
	bzero(str2, 11);
	ft_memmove(str2, str1, strlen(str1) - 5);
	v_assert_str("It w", str2);
}

static void	test_string_long(void)
{
	char	*str1;
	char	str2[250];

	str1 = strdup("KIa4jjPwBhAdTNhod2Q IYokyuGtHsTukcF7eXmM X1GMMRyONOTF3nvVg756 L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74x");
	bzero(str2, 250);
	ft_memmove(str2, str1, strlen(str1));
	v_assert_str(str1, str2);
}

static void	test_string_long_dest_first(void)
{
	char	*str1;
	char	*str2;

	str2 = strdup("KIa4jjPwBhAdTNhod2Q IYokyuGtHsTukcF7eXmM X1GMMRyONOTF3nvVg756 L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74x");
    str1 = str2 + 62;
	ft_memmove(str2, str1, strlen(str1));
	v_assert_str("L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74xbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74x", str2);
}

static void	test_string_long_src_first(void)
{
	char	*str1;
	char	*str2;

	str1 = strdup("KIa4jjPwBhAdTNhod2Q IYokyuGtHsTukcF7eXmM X1GMMRyONOTF3nvVg756 L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol3dZii9Z 9b74x");
    str2 = str1 + 13;
	ft_memmove(str2, str1, strlen(str1) - 13);
	v_assert_str("KIa4jjPwBhAdTNhod2Q IYokyuGtHsTukcF7eXmM X1GMMRyONOTF3nvVg756 L2gUK6ite8DgGotsK7uT 5xHKqIrxa3paMM5r7v WL 4yRbouzdn0odl5ehELgN oyrGLZwXC0MSXBLbFYot YbpRY5k9v5Oq8DiwZHSG 9K8nnL2hLT38jUl0nyrV uonf1uol", str2);
}

void		suite_memmove(void)
{
	test_size_0();
	test_size_1();
	test_string();
	test_string_shorter();
	test_string_long();
	test_string_long_dest_first();
	test_string_long_src_first();

	VSS;
}
