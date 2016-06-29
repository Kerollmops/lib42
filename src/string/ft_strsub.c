/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:42:36 by djean             #+#    #+#             */
/*   Updated: 2016/06/29 14:56:37 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if ((str = ft_memalloc(len + 1)))
		return (ft_memcpy(str, s + start, len));
	return (NULL);
}
