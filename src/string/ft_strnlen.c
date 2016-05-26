/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:47:54 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 12:51:18 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	char	*result;

	if ((result = ft_memchr(s, (int)'\0', maxlen)))
		return (result - s);
	return (maxlen);
}
