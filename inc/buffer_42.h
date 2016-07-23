/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:51:24 by djean             #+#    #+#             */
/*   Updated: 2016/07/23 12:21:13 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_42_H
# define BUFFER_42_H

# include <stdlib.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "memory_42.h"
# include "stdlib_42.h"
# include "string_42.h"

# define BUFFER_INIT_SIZE		256UL
# define BUFFER_GROWTH_FACTOR	2UL
# define FT_BUFFER_MAX(b)		((b)->sizemax)
# define FT_BUFFER_LEN(b)		((b)->len)
# define FT_BUFFER_FREE(b)		(free((b)->str))
# define FT_BUFFER_RESET(b)		((b)->len = 0)
# define FT_BUFFER_GET(b)		((b)->str)
# define FT_BUFFER_LAST(b)		((b)->str[(b)->len - 1])
# define FT_BUFFER_FIRST(b)		((b)->str[0])

t_buffer	*ft_buffer_new(size_t size);
t_buffer	*ft_buffer_init(t_buffer *b, size_t size);
t_buffer	*ft_buffer_add(t_buffer *b, const char *s, size_t len);
t_buffer	*ft_buffer_dup(t_buffer *b);
t_buffer	*ft_buffer_resize(t_buffer *b, size_t len);
t_buffer	*ft_buffer_set(t_buffer *b, int c, size_t len);
size_t		ft_buffer_rewindchr(t_buffer *b, int c);
int			ft_buffer_rewind(t_buffer *b, size_t n);
t_buffer	*ft_buffer_insert(t_buffer *b, size_t pos, char *s, size_t len);
size_t		ft_buffer_remove(t_buffer *b, size_t pos, size_t size);

#endif
