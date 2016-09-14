/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/09/14 19:10:00 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Append the char 'c', 'n' times, to the buffer
*/

t_buffer	*buffer_set(t_buffer *b, int c, size_t n)
{
	if (BUF_NEED_RESIZE(b, n))
		if (buffer_resize(b, n) == NULL)
			return (NULL);
	ft_memset(b->str + b->len, c, n);
	b->len += n;
	b->str[b->len] = 0;
	return (b);
}
