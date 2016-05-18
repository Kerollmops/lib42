/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:05:48 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 19:04:30 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

t_buffer	*ft_buffer_add(t_buffer *b, char *s, size_t len)
{
	if (FT_BUFFER_LEN(b) + len >= FT_BUFFER_MAX(b))
		if (ft_buffer_resize(b, len) == NULL)
			return (NULL);
	ft_memcpy(b->str + FT_BUFFER_LEN(b), s, len);
	b->len += len;
	b->str[b->len] = 0;
	return (b);
}
