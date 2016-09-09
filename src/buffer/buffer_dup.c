/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:33:13 by djean             #+#    #+#             */
/*   Updated: 2016/09/09 16:42:25 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

t_buffer	*buffer_dup(const char *str)
{
	return (buffer_ndup(str, ft_strlen(str)));
}

t_buffer	*buffer_cdup(const char *str, int c)
{
	int	pos;

	pos = ft_strchrpos(str, c);
	if (pos == -1)
		return (NULL);
	return (buffer_ndup(str, (size_t)pos + 1));
}

t_buffer	*buffer_ndup(const char *str, size_t len)
{
	t_buffer	*new;
	size_t		string_len;

	new = buffer_new(len + 1);
	if (new == NULL)
		return (NULL);
	string_len = ft_strlen(str);
	len = string_len < len ? string_len : len;
	ft_memcpy(new->str, str, len);
	new->len = len;
	return (new);
}
