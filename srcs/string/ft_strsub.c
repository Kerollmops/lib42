/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:42:36 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 17:29:10 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_string.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if ((str = ft_strnew(len)))
		return (ft_memcpy(str, s + start, len));
	return (NULL);
}
