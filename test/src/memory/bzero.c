/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_bzero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:37:17 by adubois           #+#    #+#             */
/*   Updated: 2016/05/24 19:47:06 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	test_00_bzero_SizeOf0(void)
{
	char	str[2];

	bzero(str, 2);
	memset(str, 48, 1);
	ft_bzero(str, 0);
	v_assert_str("0", str);

	VTS;
}

static void	test_01_bzero_SizeOf1(void)
{
	char	str[2];

	memset(str, 48, 1);
	ft_bzero(str, 1);
	v_assert_str("", str);

	VTS;
}

static void	test_02_bzero_SizeOf5(void)
{
	char	str[6];

	memset(str, 97, 6);
	bzero(str, 5);
	v_assert(str[0] == 0 && str[1] == 0 && str[2] == 0
			&& str[3] == 0 && str[4] == 0 && str[5] == 97);

	VTS;
}

static void	test_03_bzero_SizeOf1OnMiddle(void)
{
	char	str[6];

	memset(str, 97, 5);
	ft_bzero(str + 2, 1);
	v_assert_str("aa", str);

	VTS;
}

void		suite_bzero(void)
{
	test_00_bzero_SizeOf0();
	test_01_bzero_SizeOf1();
	test_02_bzero_SizeOf5();
	test_03_bzero_SizeOf1OnMiddle();

	VSS;	
}
