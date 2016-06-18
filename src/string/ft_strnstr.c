/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 19:02:50 by adubois           #+#    #+#             */
/*   Updated: 2016/06/18 16:42:46 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size;
	char	*start;
	/* char	*end; */

	if (0 == (size = ft_strlen(little)))
		return ((char *)big);
	start = (char *)big;
	/* end = (char *)big + ft_strlen(big); */
	while ((big = ft_strchr(big, little[0]))
			&& (unsigned long)(big - start) + size <= len)
	{
		if (0 == ft_memcmp(big, little, size))
			return ((char *)big);
		else
			++big;
	}
	return (NULL);
}
