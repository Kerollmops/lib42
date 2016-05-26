/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:36:38 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 13:46:06 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_strcpy_EmptyString(void)
{
	char	src[] = "";
	char	dst[10];

	v_assert_ptr(dst, ==, ft_strcpy(dst, src));
	v_assert_str(src, dst);

	VTS;
}

static void	test_01_strcpy_SimpleString(void)
{
	char	src[] = "Hello World!";
	char	dst[20];

	v_assert_ptr(dst, ==, ft_strcpy(dst, src));
	v_assert_str(src, dst);

	VTS;
}

static void	test_02_strcpy_LongString(void)
{
	char	src[] = "iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
					"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
					"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
					"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
					"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3";
	char	dst[300];

	v_assert_ptr(dst, ==, ft_strcpy(dst, src));
	v_assert_str(src, dst);

	VTS;
}

void		suite_strcpy(void)
{
	test_00_strcpy_EmptyString();
	test_01_strcpy_SimpleString();
	test_02_strcpy_LongString();

	VSS;
}
