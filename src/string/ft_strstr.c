/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:45:23 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 18:53:46 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	len;

	if (0 == (len = ft_strlen(little)))
		return ((char *)big);
	while ((big = ft_strchr(big, little[0])))
		if (0 == ft_memcmp(big, little, len))
			return ((char *)big);
		else
			++big;
	return (NULL);
}
