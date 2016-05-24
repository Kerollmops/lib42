/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_bzero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:37:17 by adubois           #+#    #+#             */
/*   Updated: 2016/05/24 15:19:25 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void test_empty(void)
{
    char    str[2];
 
    bzero(str, 2);
    memset(str, 48, 1);
    ft_bzero(str, 0);
    v_assert_str("0", str);
}

static void test_one_char(void)
{
    char    str[2];
 
    memset(str, 48, 1);
    ft_bzero(str, 1);
    v_assert_str("", str);
}

static void test_five_chars(void)
{
    char    str[6];
 
    memset(str, 97, 6);
    bzero(str, 5);
    v_assert(str[0] == 0 && str[1] == 0 && str[2] == 0
                && str[3] == 0 && str[4] == 0 && str[5] == 97);
}

static void test_five_chars_start_middle(void)
{
    char    str[6];
 
    memset(str, 97, 5);
    ft_bzero(str + 2, 1);
    v_assert_str("aa", str);
}

void		suite_bzero(void)
{
    test_empty();
    test_one_char();
    test_five_chars();
    test_five_chars_start_middle();

    VSS;	
}
