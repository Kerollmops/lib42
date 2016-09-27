/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:48:07 by djean             #+#    #+#             */
/*   Updated: 2016/09/27 11:05:34 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

char	buffer_iterator(t_buffer *b)
{
	if (b->iterator >= b->len)
	{
		b->iterator = 0;
		return ('\0');
	}
	return (b->str[b->iterator++]);
}

void	buffer_iterator_prev(t_buffer *b)
{
	if (b->iterator > 0)
		b->iterator -= 1;
}

void	buffer_iterator_next(t_buffer *b)
{
	if (b->iterator < b->len)
		b->iterator += 1;
}

void	buffer_iterator_set(t_buffer *b, size_t index)
{
	b->iterator = index;
}
