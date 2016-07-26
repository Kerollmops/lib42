/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:11:40 by djean             #+#    #+#             */
/*   Updated: 2016/07/26 20:47:10 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

size_t	ft_strlen(const char *s)
{
	return ((char *)ft_memchr(s, (int)'\0', ~0ULL) - s);
}

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	char	*result;

	if ((result = ft_memchr(s, (int)'\0', maxlen)))
		return (result - s);
	return (maxlen);
}
