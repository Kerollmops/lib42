/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:59:07 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 18:37:59 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_buffer.h"

t_buffer	*ft_buffer_set(t_buffer *b, int c, size_t len)
{
	if (FT_BUFFER_LEN(b) + len >= FT_BUFFER_MAX(b))
		if (ft_buffer_resize(b, len) == NULL)
			return (NULL);
	ft_memset(b->str + FT_BUFFER_LEN(b), c, len);
	b->len += len;
	b->str[b->len] = 0;
	return (b);
}
