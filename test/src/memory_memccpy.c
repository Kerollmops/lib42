/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_memccpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:00:42 by adubois           #+#    #+#             */
/*   Updated: 2016/05/24 15:19:34 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	test_size_0(void)
{
	char	str1[11];
	char	str2[11];
	void	*ret;

	memset(str1, 48, 11);
	bzero(str2, 11);
	ret = ft_memccpy(str2, str1, 97, 0);
	v_assert_str("", str2);
	v_assert((unsigned long int)ret == 0);
}

static void	test_size_1(void)
{
	char	str1[11];
	char	str2[11];
	void	*ret;

	memset(str1, 48, 11);
	bzero(str2, 11);
	ret = ft_memccpy(str2, str1, 97, 1);
	v_assert_str("0", str2);
	v_assert((unsigned long int)ret == 0);
}

static void	test_string(void)
{
	char	*str1;
	char	str2[11];
	void	*ret;

	str1 = strdup("It works!");
	bzero(str2, 11);
	ret = ft_memccpy(str2, str1, 48, strlen(str1));
	v_assert_str(str1, str2);
	v_assert((unsigned long int)ret == 0);
}

static void	test_string_shorter(void)
{
	char	*str1;
	char	str2[11];
	void	*ret;

	str1 = strdup("It works!");
	bzero(str2, 11);
	ret = ft_memccpy(str2, str1, 48, strlen(str1) - 5);
	v_assert_str("It w", str2);
	v_assert((unsigned long int)ret == 0);
}

static void	test_string_delimiter(void)
{
	char	*str1;
	char	*str2;
	void	*ret;

	str1 = strdup("It works!");
	str2 = (char *)malloc(11);
	bzero(str2, 11);
	ret = ft_memccpy(str2, str1, 107, strlen(str1));
	v_assert_str("It wor", str2);
	v_assert((unsigned long int)ret == (unsigned long int)(str2 + 6));
}

void		suite_memccpy(void)
{
	test_size_0();
	test_size_1();
	test_string();
	test_string_shorter();
	test_string_delimiter();

	VSS;
}
