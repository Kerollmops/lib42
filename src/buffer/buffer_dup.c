/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:33:13 by djean             #+#    #+#             */
/*   Updated: 2016/09/14 18:54:36 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Duplicate the string '*str' and return a buffer of it
*/

t_buffer	*buffer_dup(const char *str)
{
	return (buffer_ndup(str, ft_strlen(str)));
}

/*
** Duplicate the string '*str', up to the char 'c', and return a buffer of it
*/

t_buffer	*buffer_cdup(const char *str, int c)
{
	int	pos;

	pos = ft_strchrpos(str, c);
	if (pos == -1)
		return (NULL);
	return (buffer_ndup(str, (size_t)pos + 1));
}

/*
** Duplicate the string '*str', up to the size 'len', and return a buffer of it
*/

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
