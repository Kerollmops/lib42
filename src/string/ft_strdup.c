/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:14:44 by djean             #+#    #+#             */
/*   Updated: 2016/05/26 13:09:58 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}
