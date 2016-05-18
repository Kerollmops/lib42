/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:14:45 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 17:29:10 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_string.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pc;

	pc = (char*)s;
	if ((char)c == '\0')
		return (pc + ft_strlen(s));
	while (*pc)
		if (*pc++ == (char)c)
			return (pc - 1);
	return (NULL);
}
