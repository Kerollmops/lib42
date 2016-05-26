/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:05:18 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 16:56:01 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_strncat_EmptyString(void)
{
	char	src[] = "";
	char	*dst = malloc(20);

	dst[0] = '*';
	dst[1] = '\0';
	v_assert_ptr(dst, ==, ft_strncat(dst, src, 10));
	v_assert_str(dst, "*");
	free(dst);

	VTS;
}

static void	test_01_strncat_SimpleString(void)
{
	char	src[] = "World!";
	char	*dst = malloc(20);

	memcpy(dst, "Hello ", 7);;
	v_assert_ptr(dst, ==, ft_strncat(dst, src, 10));
	v_assert_str(dst, "Hello World!");
	free(dst);

	VTS;
}

static void	test_02_strncat_LongString(void)
{
	char	src[] = "iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
					"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
					"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
					"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
					"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3";
	char	*dst = malloc(300);

	memcpy(dst, "Hello ", 7);;
	v_assert_ptr(dst, ==, ft_strncat(dst, src, 280));
	v_assert_str(dst, "Hello iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
						"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
						"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
						"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
						"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3");
	free(dst);

	VTS;
}

static void	test_03_strncat_LongStringLowerN(void)
{
	char	src[] = "iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
					"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
					"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
					"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
					"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3";
	char	*dst = malloc(300);

	memcpy(dst, "Hello ", 7);;
	v_assert_ptr(dst, ==, ft_strncat(dst, src, 42));
	v_assert_str(dst, "Hello iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by ");
	free(dst);

	VTS;
}

static void	test_04_strncat_LongStringN0(void)
{
	char	src[] = "World!";
	char	*dst = malloc(20);

	memcpy(dst, "Hello ", 7);;
	v_assert_ptr(dst, ==, ft_strncat(dst, src, 0));
	v_assert_str(dst, "Hello ");
	free(dst);

	VTS;
}

void		suite_strncat(void)
{
	test_00_strncat_EmptyString();
	test_01_strncat_SimpleString();
	test_02_strncat_LongString();
	test_03_strncat_LongStringLowerN();
	test_04_strncat_LongStringN0();

	VSS;
}
