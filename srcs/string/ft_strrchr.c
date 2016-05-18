/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:14:45 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 19:04:49 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*plc;

	plc = (char *)s + ft_strlen(s);
	if ((char)c == '\0')
		return (plc);
	--plc;
	while (*plc)
		if (*plc-- == (char)c)
			return (++plc);
	return (NULL);
}
