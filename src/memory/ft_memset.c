/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:48:41 by adubois           #+#    #+#             */
/*   Updated: 2016/09/21 18:55:32 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

inline static void	setblock(unsigned long **p, unsigned long cccc, size_t *len)
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

inline static void	setword(unsigned long **p, unsigned long cccc, size_t *len)
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
	if (len >= (8 * WORD_LEN))
		setblock((unsigned long**)&b, cccc, &len);
	setword((unsigned long**)&b, cccc, &len);
	while (len--)
	{
		*(unsigned char *)b = (unsigned char)c;
		b = (unsigned char*)b + 1;
	}
	return (b);
}
