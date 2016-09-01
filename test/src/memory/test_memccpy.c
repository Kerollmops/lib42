/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_memccpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:00:42 by adubois           #+#    #+#             */
/*   Updated: 2016/07/26 14:27:23 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_memccpy_SizeOf0(void)
{
	char	str1[11];
	char	str2[11];
	void	*ret;

	memset(str1, 48, 11);
	memset(str2, 0, 11);
	ret = ft_memccpy(str2, str1, 97, 0);
	v_assert_str("", str2);
	v_assert((unsigned long int)ret == 0);

	VTS;
}

static void	test_01_memccpy_SizeOf1(void)
{
	char	str1[11];
	char	str2[11];
	void	*ret;

	memset(str1, 48, 11);
	memset(str2, 0, 11);
	ret = ft_memccpy(str2, str1, 97, 1);
	v_assert_str("0", str2);
	v_assert((unsigned long int)ret == 0);

	VTS;
}

static void	test_02_memccpy_FullString(void)
{
	char	*str1;
	char	str2[11];
	void	*ret;

	str1 = strdup("It works!");
	memset(str2, 0, 11);
	ret = ft_memccpy(str2, str1, 48, strlen(str1));
	v_assert_str(str1, str2);
	v_assert((unsigned long int)ret == 0);

	free(str1);

	VTS;
}

static void	test_03_memccpy_PartialString(void)
{
	char	*str1;
	char	str2[11];
	void	*ret;

	str1 = strdup("It works!");
	memset(str2, 0, 11);
	ret = ft_memccpy(str2, str1, 48, strlen(str1) - 5);
	v_assert_str("It w", str2);
	v_assert((unsigned long int)ret == 0);

	free(str1);

	VTS;
}

static void	test_04_memccpy_StringWidthDelimiter(void)
{
	char	*str1;
	char	*str2;
	void	*ret;

	str1 = strdup("It works!");
	str2 = (char *)malloc(11);
	memset(str2, 0, 11);
	ret = ft_memccpy(str2, str1, 107, strlen(str1));
	v_assert_str("It wor", str2);
	v_assert((unsigned long int)ret == (unsigned long int)(str2 + 6));

	free(str1);
	free(str2);

	VTS;
}

void		suite_memccpy(void)
{
	test_00_memccpy_SizeOf0();
	test_01_memccpy_SizeOf1();
	test_02_memccpy_FullString();
	test_03_memccpy_PartialString();
	test_04_memccpy_StringWidthDelimiter();

	VSS;
}
