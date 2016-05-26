/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:47:35 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 15:57:11 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_strcat_EmptyString(void)
{
	char	src[] = "";
	char	*dst = malloc(10);

	dst[0] = '*';
	dst[1] = '\0';
	v_assert_ptr(dst, ==, ft_strcat(dst, src));
	v_assert_str(dst, "*");
	free(dst);

	VTS;
}

static void	test_01_strcat_SimpleString(void)
{
	char	src[] = "World!";
	char	*dst = malloc(20);

	memcpy(dst, "Hello ", 7);;
	v_assert_ptr(dst, ==, ft_strcat(dst, src));
	v_assert_str(dst, "Hello World!");
	free(dst);

	VTS;
}

static void	test_02_strcat_LongString(void)
{
	char	src[] = "iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
					"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
					"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
					"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
					"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3";
	char	*dst = malloc(300);

	memcpy(dst, "Hello ", 7);;
	v_assert_ptr(dst, ==, ft_strcat(dst, src));
	v_assert_str(dst, "Hello iNVIVSvRyzGZuqmQo66i FjJZMkeSqQlmFVOsF1by "
						"7W4tCo99aiyrLxOggDp5 E9fN4ckgMUEs1sXvxEPn "
						"DQfAGv7N3wOJVN39hcFB PYv4inlqKOez87HVzR70 "
						"199CZPuWfYAkXhehQkU1 6Hz1QcC72HJSygDsFLHX "
						"hBbfUW4RY5FCeaXZwPPd jUus5zmEwkoh1FwCxUN3");
	free(dst);

	VTS;
}

void		suite_strcat(void)
{
	test_00_strcat_EmptyString();
	test_01_strcat_SimpleString();
	test_02_strcat_LongString();

VSS;
}
