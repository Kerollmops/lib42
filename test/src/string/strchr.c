/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:42:50 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 17:53:30 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_strchr_FirstChar(void)
{
	char	str[] = "Hello World!";

	v_assert_ptr(ft_strchr(str, 'H'), ==, strchr(str, 'H'));

	VTS;
}

static void	test_01_strchr_Null(void)
{
	char	str[] = "Hello World!";

	v_assert_ptr(ft_strchr(str, 0), ==, strchr(str, 0));

	VTS;
}

static void	test_02_strchr_LongStringOneChar(void)
{
	char	str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed "
					"eu tortor porttitor nunc porttitor aliquam. Quisque a varius lorem. "
					"Suspendisse vestibulum mi1 id urna scelerisque molestie. Proin libero "
					"justo, venenatis ac ante quis, eleifend tempus tellus. Vestibulum "
					"suscipit magna in commodo condimentum. Maecenas mattis tellus augue, ";

	v_assert_ptr(ft_strchr(str, '1'), ==, strchr(str, '1'));

	VTS;
}

static void	test_03_strchr_LongStringSeveralChars(void)
{
	char	str[] = "Lorem ipsum dolor sit amet, 1consectetur adipiscing elit. Sed "
					"eu tortor porttitor nunc porttitor aliquam. Quisque a varius l1orem. "
					"Suspendisse vestibulum mi1 id urna scelerisque molestie. Proin libero "
					"justo, venenatis ac a1nte quis, eleifend tempus tellus. Vestibulum "
					"suscipit magna in comm1odo condimentum. Maecenas mattis tellus augue, ";

	v_assert_ptr(ft_strchr(str, '1'), ==, strchr(str, '1'));

	VTS;
}

void		suite_strchr(void)
{
	test_00_strchr_FirstChar();
	test_01_strchr_Null();
	test_02_strchr_LongStringOneChar();
	test_03_strchr_LongStringSeveralChars();

	VSS;
}
