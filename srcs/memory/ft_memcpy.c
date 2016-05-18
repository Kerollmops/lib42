/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:03:46 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 17:31:04 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_memory.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	s;
	size_t	d;

	s = (size_t)src;
	d = (size_t)dst;
	while (n && d % sizeof(size_t) != 0)
	{
		*((unsigned char *)d++) = *((unsigned char *)s++);
		n -= 1;
	}
	while (n >= sizeof(size_t))
	{
		*(size_t*)d = *(size_t*)s;
		d += sizeof(size_t);
		s += sizeof(size_t);
		n -= sizeof(size_t);
	}
	while (n--)
		*(unsigned char *)d++ = *(unsigned char *)s++;
	return (dst);
}
