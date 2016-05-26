/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:48:54 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 16:51:33 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s1);
	ft_memcpy(s1 + len, s2, n);
	s1[len + n] = '\0';
	return (s1);
}
