/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:02:53 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 18:14:52 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_strrchr_FirstChar(void)
{
	char	str[] = "Hello World!";

	v_assert_ptr(ft_strrchr(str, 'H'), ==, strrchr(str, 'H'));

	VTS;
}

static void	test_01_strrchr_Null(void)
{
	char	str[] = "Hello World!";

	v_assert_ptr(ft_strrchr(str, 0), ==, strrchr(str, 0));

	VTS;
}

static void	test_02_strrchr_LongStringOneChar(void)
{
	char	str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed "
					"eu tortor porttitor nunc porttitor aliquam. Quisque a varius lorem. "
					"Suspendisse vestibulum mi1 id urna scelerisque molestie. Proin libero "
					"justo, venenatis ac ante quis, eleifend tempus tellus. Vestibulum "
					"suscipit magna in commodo condimentum. Maecenas mattis tellus augue, ";

	v_assert_ptr(ft_strrchr(str, '1'), ==, strrchr(str, '1'));

	VTS;
}

static void	test_03_strrchr_LongStringSeveralChars(void)
{
	char	str[] = "Lorem ipsum dolor sit amet, 1consectetur adipiscing elit. Sed "
					"eu tortor porttitor nunc porttitor aliquam. Quisque a varius l1orem. "
					"Suspendisse vestibulum mi1 id urna scelerisque molestie. Proin libero "
					"justo, venenatis ac a1nte quis, eleifend tempus tellus. Vestibulum "
					"suscipit magna in comm1odo condimentum. Maecenas mattis tellus augue, ";

	v_assert_ptr(ft_strrchr(str, '1'), ==, strrchr(str, '1'));

	VTS;
}

static void	test_04_strrchr_NoChar(void)
{
	char	str[] = "Hello World!";

	v_assert_ptr(ft_strrchr(str, 'z'), ==, strrchr(str, 'z'));

	VTS;
}

void		suite_strrchr(void)
{
	test_00_strrchr_FirstChar();
	test_01_strrchr_Null();
	test_02_strrchr_LongStringOneChar();
	test_03_strrchr_LongStringSeveralChars();
	test_04_strrchr_NoChar();

	VSS;
}

