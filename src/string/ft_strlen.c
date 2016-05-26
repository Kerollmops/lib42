/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:11:40 by djean             #+#    #+#             */
/*   Updated: 2016/05/26 12:48:21 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

size_t	ft_strlen(const char *s)
{
	return ((char *)ft_memchr(s, (int)'\0', ~0ULL) - s);
}