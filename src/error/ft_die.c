/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:35:17 by djean             #+#    #+#             */
/*   Updated: 2016/08/10 16:35:18 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_42.h"

void	ft_die(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(1);
}

void	fatal_malloc(void)
{
	ft_die(FATAL_MALLOC);
}
