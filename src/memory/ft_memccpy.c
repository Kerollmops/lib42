/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:25:00 by adubois           #+#    #+#             */
/*   Updated: 2016/09/26 22:31:43 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	size;
	char	*source;

	source = (char *)src;
	size = 0;
	while (source[size] != (char)c && size != n)
		++size;
	if (size == n)
	{
		ft_memcpy(dest, src, n);
		return (NULL);
	}
	else
	{
		ft_memcpy(dest, src, size);
		return ((void *)((char *)dest + size));
	}
}
