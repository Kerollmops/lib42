/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:59:00 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 19:01:55 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_strnstr_EmptyLittle(void)
{
	char	big[] = "Hello World!";
	char	little[] = "";

	v_assert_ptr(ft_strnstr(big, little, 42), ==, strnstr(big, little, 42));

	VTS;
}

static void	test_01_strnstr_EmptyBig(void)
{
	char	big[] = "";
	char	little[] = "Hello";

	v_assert_ptr(ft_strnstr(big, little, 42), ==, strnstr(big, little, 42));

	VTS;
}

static void	test_02_strnstr_OccuresOnce(void)
{
	char	big[] = "Hello World!";
	char	little[] = "Wor";

	v_assert_ptr(ft_strnstr(big, little, 42), ==, strnstr(big, little, 42));

	VTS;
}

static void	test_03_strnstr_OccuresTwice(void)
{
	char	big[] = "Hello World! Look at this Worm.";
	char	little[] = "Wor";

	v_assert_ptr(ft_strnstr(big, little, 42), ==, strnstr(big, little, 42));

	VTS;
}

static void	test_04_strnstr_DoesNotOccure(void)
{
	char	big[] = "Hello World! Look at this Worm.";
	char	little[] = "toto";

	v_assert_ptr(ft_strnstr(big, little, 42), ==, strnstr(big, little, 42));

	VTS;
}

static void	test_05_strnstr_OccuresOnceButTooLate(void)
{
	char	big[] = "Hello World!";
	char	little[] = "Wor";

	v_assert_ptr(ft_strnstr(big, little, 5), ==, strnstr(big, little, 5));

	VTS;
}

void		suite_strnstr(void)
{
	test_00_strnstr_EmptyLittle();
	test_01_strnstr_EmptyBig();
	test_02_strnstr_OccuresOnce();
	test_03_strnstr_OccuresTwice();
	test_04_strnstr_DoesNotOccure();
	test_05_strnstr_OccuresOnceButTooLate();

	VSS;
}
