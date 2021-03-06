/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_toa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/09/14 19:11:37 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Append the signed integer 'value' in base 'base' to the buffer
*/

t_buffer	*buffer_stoa(t_buffer *b, long long value, int base)
{
	char	*n;

	n = ft_stoa_base(value, base);
	buffer_cat(b, n);
	free(n);
	return (b);
}

/*
** Append the unsigned integer 'value' in base 'base' to the buffer
*/

t_buffer	*buffer_utoa(t_buffer *b, unsigned long long value, int base)
{
	char	*n;

	n = ft_utoa_base(value, base);
	buffer_cat(b, n);
	free(n);
	return (b);
}
