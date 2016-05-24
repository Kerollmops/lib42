/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:19:05 by adubois           #+#    #+#             */
/*   Updated: 2016/05/24 15:19:55 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void test_empty(void)
{
    char    str[2];
 
    bzero(str, 2);
    ft_memset(str, 48, 0);
    v_assert_str("", str);
}

static void test_one_char(void)
{
    char    str[2];
 
    bzero(str, 2);
    ft_memset(str, 48, 1);
    v_assert_str("0", str);
}

static void test_one_char_null(void)
{
    char    str[2];
 
    bzero(str, 2);
    str[0] = '0';
    ft_memset(str, 0, 1);
    v_assert_str("", str);
}

static void test_five_chars(void)
{
    char    str[6];
 
    bzero(str, 6);
    ft_memset(str, 97, 5);
    v_assert_str("aaaaa", str);
}

static void test_five_chars_different(void)
{
    char    str[6];
 
    bzero(str, 6);
    ft_memset(str, 97, 5);
    ft_memset(str + 2, 98, 2);
    v_assert_str("aabba", str);
}

static void test_five_chars_different_null_middle(void)
{
    char    str[6];
 
    bzero(str, 6);
    ft_memset(str, 97, 5);
    ft_memset(str + 3, 98, 2);
    ft_memset(str + 2, 0, 1);
    v_assert_str("aa", str);
}

void		suite_memset(void)
{
    test_empty();
    test_one_char();
    test_one_char_null();
    test_five_chars();
    test_five_chars_different();
    test_five_chars_different_null_middle();

    VSS;	
}
