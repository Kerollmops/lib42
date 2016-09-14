/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/09/14 18:54:05 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Concatene the string '*s' to the buffer '*b'
*/

t_buffer	*buffer_cat(t_buffer *b, const char *s)
{
	return (buffer_ncat(b, s, ft_strlen(s)));
}

/*
** Concatene the string '*s', of size 'len', to the buffer '*b'
*/

t_buffer	*buffer_ncat(t_buffer *b, const char *s, size_t len)
{
	if (BUF_NEED_RESIZE(b, len))
		if (buffer_resize(b, len) == NULL)
			return (NULL);
	ft_memcpy(b->str + b->len, s, len);
	b->len += len;
	return (b);
}
