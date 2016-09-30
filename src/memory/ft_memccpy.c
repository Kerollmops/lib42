#include "memory_42.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	uintptr_t	offset;
	char		*p;

	p = ft_memchr(src, c, n);
	if (p != NULL)
	{
		p += 1;
		offset = (uintptr_t)p - (uintptr_t)src;
		ft_memcpy(dest, src, offset);
		return ((char*)dest + offset);
	}
	else
	{
		ft_memcpy(dest, src, n);
		return (NULL);
	}
}
