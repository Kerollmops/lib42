/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:10:42 by adubois           #+#    #+#             */
/*   Updated: 2016/06/29 12:10:01 by leonhart         ###   ########.fr       */
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
		ft_memset((dst + len), 0, (n - len));
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
