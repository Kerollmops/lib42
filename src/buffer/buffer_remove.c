/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/09/14 18:53:11 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Remove at position 'pos' a 'size' number of bytes
** Return the numbers of bytes effectively removed
*/

size_t	buffer_remove(t_buffer *b, size_t pos, size_t size)
{
	size_t	removed;

	if (pos >= b->len)
		return (0);
	if (pos + size >= b->len)
	{
		removed = b->len - pos;
		b->len = pos;
	}
	else
	{
		removed = size;
		ft_memmove(b->str + pos, b->str + pos + size, b->len - (pos + size));
		b->len -= size;
	}
	b->str[b->len] = '\0';
	return (removed);
}
