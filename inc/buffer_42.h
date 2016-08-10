/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/08/10 16:29:36 by djean            ###   ########.fr       */
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
# include "stdlib_42.h"

# define BUFFER_INIT_SIZE		64U
# define BUFFER_GROWTH_FACTOR	2U
# define BUF_NEED_RESIZE(b, l)	(b->len + l >= b->sizemax)
# define TBUFFER_MAX(b)			((b)->sizemax)
# define TBUFFER_LEN(b)			((b)->len)
# define TBUFFER_GET(b)			((b)->str)
# define TBUFFER_FREE(b)		(free((b)->str))
# define TBUFFER_RESET(b)		{(b)->len = 0; (b)->str[0] = '\0';}
# define TBUFFER_LAST(b)		((b)->str[(b)->len - 1])
# define TBUFFER_FIRST(b)		((b)->str[0])
# define TBUFFER_ISEMPTY(b)		(!((b)->len))

t_buffer	*buffer_new(size_t size);
t_buffer	*buffer_init(t_buffer *b, size_t size);
t_buffer	*buffer_dup(const char *str);
t_buffer	*buffer_ndup(const char *str, size_t len);
t_buffer	*buffer_cat(t_buffer *b, const char *s);
t_buffer	*buffer_ncat(t_buffer *b, const char *s, size_t len);
t_buffer	*buffer_replace(t_buffer *b, const char *s);
t_buffer	*buffer_nreplace(t_buffer *b, const char *s, size_t len);
t_buffer	*buffer_resize(t_buffer *b, size_t len);
t_buffer	*buffer_insert(t_buffer *b, size_t pos, const char *s, size_t len);
size_t		buffer_remove(t_buffer *b, size_t pos, size_t size);
void		buffer_destroy(t_buffer **b);
t_buffer	*buffer_set(t_buffer *b, int c, size_t len);
int			buffer_rewind(t_buffer *b, size_t n);
size_t		buffer_rewindchr(t_buffer *b, int c);
size_t		buffer_rewindnchr(t_buffer *b, int c, size_t n);
t_buffer	*buffer_twin(t_buffer *b);
t_buffer	*buffer_merge(t_buffer *b1, t_buffer *b2);
t_buffer	*buffer_stoa(t_buffer *b, long long value, int base);
t_buffer	*buffer_utoa(t_buffer *b, unsigned long long value, int base);

size_t		buffer_trim(t_buffer *b, const char *set);
t_buffer	*buffer_fmt(t_buffer *b, const char *fmt, ...);

#endif
