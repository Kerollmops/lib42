/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:11:02 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 17:22:52 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_strlcat_EmptyString(void)
{
	char	*dst = malloc(20);

	memcpy(dst, "Hello ", 7);
	v_assert_uint(6, ==, ft_strlcat(dst, "", 20));
	v_assert_str("Hello ", dst);
	free(dst);

	VTS;
}

static void	test_01_strlcat_SimpleString(void)
{
	char	*dst = malloc(20);

	memcpy(dst, "Hello ", 7);
	v_assert_uint(12, ==, ft_strlcat(dst, "World!", 20));
	v_assert_str("Hello World!", dst);
	free(dst);

	VTS;
}

static void	test_02_strlcat_LongString(void)
{
	char	*dst = malloc(300);
	char	*src = malloc(300);

	memcpy(dst, "Hello ", 7);
	memcpy(src, "iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
				"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
				"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
				"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
				"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3", 210);
	v_assert_uint(215, ==, ft_strlcat(dst, src, 250));
	v_assert_str("Hello iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
					"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
					"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
					"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
					"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3", dst);
	free(dst);

	VTS;
}

static void	test_03_strlcat_LongStringLowerN(void)
{
	char	*dst = malloc(300);
	char	*src = malloc(300);

	memcpy(dst, "Hello ", 7);
	memcpy(src, "iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
				"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
				"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
				"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
				"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3", 210);
	v_assert_uint(215, ==, ft_strlcat(dst, src, 48));
	v_assert_str("Hello iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by", dst);
	free(dst);

	VTS;
}

static void	test_04_strlcat_SimpleStringN0(void)
{
	char	*dst = malloc(20);

	memcpy(dst, "Hello ", 7);
	v_assert_uint(12, ==, ft_strlcat(dst, "World!", 0));
	v_assert_str("Hello ", dst);
	free(dst);

	VTS;
}

void		suite_strlcat(void)
{
	test_00_strlcat_EmptyString();
	test_01_strlcat_SimpleString();
	test_02_strlcat_LongString();
	test_03_strlcat_LongStringLowerN();
	test_04_strlcat_SimpleStringN0();

	VSS;
}
