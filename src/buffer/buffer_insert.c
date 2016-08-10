/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/08/10 16:31:05 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

t_buffer	*buffer_insert(t_buffer *b, size_t pos, const char *s, size_t len)
{
	if (pos > b->len)
		return (NULL);
	if (BUF_NEED_RESIZE(b, len))
		if (buffer_resize(b, len) == NULL)
			return (NULL);
	ft_memmove(b->str + pos + len, b->str + pos, b->len - pos);
	ft_memcpy(b->str + pos, s, len);
	b->len += len;
	b->str[b->len] = 0;
	return (b);
}
