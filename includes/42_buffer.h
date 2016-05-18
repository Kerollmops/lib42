/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:51:24 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 18:36:18 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include <stdlib.h>
# include "42_string.h"
# include "42_stdlib.h"

# define BUFFER_INIT_SIZE		256UL
# define BUFFER_GROWTH_FACTOR	2UL
# define FT_BUFFER_MAX(b)		((b)->sizemax)
# define FT_BUFFER_LEN(b)		((b)->len)
# define FT_BUFFER_FREE(b)		(free((b)->str))
# define FT_BUFFER_RESET(b)		((b)->len = 0)
# define FT_BUFFER_GET(b)		((b)->str)
# define FT_BUFFER_LAST(b)		((b)->str[(b)->len - 1])
# define FT_BUFFER_FIRST(b)		((b)->str[0])

typedef struct	s_buffer
{
	char	*str;
	size_t	len;
	size_t	sizemax;
}				t_buffer;

t_buffer		*ft_buffer_init(t_buffer *b, size_t size);
t_buffer		*ft_buffer_add(t_buffer *b, char *s, size_t len);
t_buffer		*ft_buffer_resize(t_buffer *b, size_t len);
t_buffer		*ft_buffer_set(t_buffer *b, int c, size_t len);
size_t			ft_buffer_rewindchr(t_buffer *b, int c);

#endif
