/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:03:37 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 14:24:42 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_strncpy_EmptyString(void)
{
	char	src[] = "";
	char	*dst = malloc(42);

	v_assert_ptr(dst, ==, ft_strncpy(dst, src, 42));
	v_assert_str(src, dst);
	free(dst);

	VTS;
}

static void	test_01_strncpy_SimpleString(void)
{
	char	src[] = "Hello World!";
	char	*dst = malloc(42);

	v_assert_ptr(dst, ==, ft_strncpy(dst, src, 42));
	v_assert_str(src, dst);
	free(dst);

	VTS;
}

static void	test_02_strncpy_LongString(void)
{
	char	src[] = "iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
					"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
					"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
					"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
					"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3";
	char	*dst = malloc(300);

	v_assert_ptr(dst, ==, ft_strncpy(dst, src, 300));
	v_assert_str(src, dst);
	free(dst);

	VTS;
}

static void	test_03_strncpy_LongStringLowerN(void)
{
	char	src[] = "iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
					"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
					"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
					"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
					"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3";
	char	*dst = malloc(300);

	dst[42] = '*';
	dst[43] = '\0';
	v_assert_ptr(dst, ==, ft_strncpy(dst, src, 42));
	v_assert_str("iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by *", dst);
	free(dst);

	VTS;
}

static void	test_04_strncpy_SimpleStringN0(void)
{
	char	src[] = "Hello World!";
	char	*dst = malloc(42);

	dst[0] = '\0';
	v_assert_ptr(dst, ==, ft_strncpy(dst, src, 0));
	v_assert_str("", dst);
	free(dst);

	VTS;
}

void		suite_strncpy(void)
{
	test_00_strncpy_EmptyString();
	test_01_strncpy_SimpleString();
	test_02_strncpy_LongString();
	test_03_strncpy_LongStringLowerN();
	test_04_strncpy_SimpleStringN0();

	VSS;
}
