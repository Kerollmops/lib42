/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:14:45 by djean             #+#    #+#             */
/*   Updated: 2016/07/22 04:24:53 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char*)s + i);
	while (i--)
		if (s[i] == c)
			return ((char*)s + i);
	return (NULL);
}

int		ft_strrchrpos(const char *s, int c)
{
	char	*p;

	p = ft_strrchr(s, c);
	if (p == NULL)
		return (-1);
	return (p - s);
}

char	*ft_strrnchr(const char *s, int c, size_t n)
{
	size_t	i;

	i = ft_strlen(s);
	while (n--)
	{
		if (s[i] == c)
			return ((char*)s + i);
		--i;
	}
	return (NULL);
}

int		ft_strrnchrpos(const char *s, int c, size_t n)
{
	char	*p;

	p = ft_strrnchr(s, c, n);
	if (p == NULL)
		return (-1);
	return (p - s);
}
