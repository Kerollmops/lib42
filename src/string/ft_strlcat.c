/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:23:56 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 17:30:54 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	int		n;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	n = size - dst_len - 1;
	if (n < 0)
		n = 0;
	ft_memcpy(dst + dst_len, src, n);
	if (dst_len < size)
		dst[dst_len + n] = '\0';
	return (dst_len + src_len);
}
