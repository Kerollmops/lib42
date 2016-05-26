/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:37:22 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 18:42:58 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_strstr_EmptyLittle(void)
{
	char	big[] = "Hello World!";
	char	little[] = "";

	v_assert_ptr(ft_strstr(big, little), ==, strstr(big, little));

	VTS;
}

static void	test_01_strstr_EmptyBig(void)
{
	char	big[] = "";
	char	little[] = "Hello";

	v_assert_ptr(ft_strstr(big, little), ==, strstr(big, little));

	VTS;
}

static void	test_02_strstr_OccuresOnce(void)
{
	char	big[] = "Hello World!";
	char	little[] = "Wor";

	v_assert_ptr(ft_strstr(big, little), ==, strstr(big, little));

	VTS;
}

static void	test_03_strstr_OccuresTwice(void)
{
	char	big[] = "Hello World! Look at this Worm.";
	char	little[] = "Wor";

	v_assert_ptr(ft_strstr(big, little), ==, strstr(big, little));

	VTS;
}

static void	test_04_strstr_DoesNotOccure(void)
{
	char	big[] = "Hello World! Look at this Worm.";
	char	little[] = "toto";

	v_assert_ptr(ft_strstr(big, little), ==, strstr(big, little));

	VTS;
}

void		suite_strstr(void)
{
	test_00_strstr_EmptyLittle();
	test_01_strstr_EmptyBig();
	test_02_strstr_OccuresOnce();
	test_03_strstr_OccuresTwice();
	test_04_strstr_DoesNotOccure();

	VSS;
}
