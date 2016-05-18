/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:55:18 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 17:30:15 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdlib.h>
# include "42_string.h"

# define FT_ABS(x)			(((x) < 0) ? -(x) : (x))
# define FT_MAX(a, b)		((a) < (b) ? (b) : (a))
# define FT_MIN(a, b)		((a) > (b) ? (b) : (a))
# define FREE(ptr)			(free(ptr), (ptr) = NULL)
# define ARR_SIZ_MAX(a)		(sizeof(a) / sizeof((a)[0]))

void	*ft_realloc(void *ptr, size_t size, size_t oldsize);

#endif
