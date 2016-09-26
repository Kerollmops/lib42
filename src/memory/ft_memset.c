#include "memory_42.h"

/*
** Set the value 'c' to the first 'len' bytes in the memory space
** pointed to by 'b'.
*/

inline static void	align_word(unsigned char **p, unsigned char c, size_t *len)
{
	while (*len > 0 && (((uintptr_t)(*p) % WORD_LEN) != 0))
	{
		**p = c;
		--(*len);
		*p += 1;
	}
}

inline static void	setblocks(unsigned long **p, unsigned long cccc, size_t *len)
{
	while (*len >= BLOCK_SIZE)
	{
		(*p)[0] = cccc;
		(*p)[1] = cccc;
		(*p)[2] = cccc;
		(*p)[3] = cccc;
		(*p)[4] = cccc;
		(*p)[5] = cccc;
		(*p)[6] = cccc;
		(*p)[7] = cccc;
		(*p) += 8;
		*len -= BLOCK_SIZE;
	}
}

inline static void	setwords(unsigned long **p, unsigned long cccc, size_t *len)
{
	while (*len >= WORD_LEN)
	{
		**p = cccc;
		(*p) += 1;
		*len -= WORD_LEN;
	}
}

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned long int	cccc;

	cccc = (unsigned char)c;
	cccc |= cccc << 24 | cccc << 16 | cccc << 8;
	cccc |= cccc << 32;
	align_word((unsigned char**)&b, (unsigned char)c, &len);
	setblocks((unsigned long**)&b, cccc, &len);
	setwords((unsigned long**)&b, cccc, &len);
	while (len--)
	{
		*(unsigned char *)b = (unsigned char)c;
		b = (unsigned char*)b + 1;
	}
	return (b);
}
