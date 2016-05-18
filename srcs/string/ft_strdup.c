/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:14:44 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 17:29:10 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_string.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	return (ft_memcpy(str, s1, len));
}
