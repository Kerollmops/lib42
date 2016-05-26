/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:10:42 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 14:12:14 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(src);
	if (len < n)
	{
		ft_memcpy(dst, src, len);
		ft_bzero((dst + len), (n - len));
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
