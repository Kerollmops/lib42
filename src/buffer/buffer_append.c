/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 12:04:13 by djean             #+#    #+#             */
/*   Updated: 2016/09/14 18:53:32 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Append to 'dst' the content of 'src'
** Return the new size of 'dst' or -1 on error
*/

t_buffer	*buffer_append(t_buffer *dst, t_buffer *src)
{
	return (buffer_ncat(dst, src->str, src->len));
}
