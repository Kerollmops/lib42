/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:57:49 by adubois           #+#    #+#             */
/*   Updated: 2016/05/26 16:02:35 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	ft_memcpy(s1 + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (s1);
}
