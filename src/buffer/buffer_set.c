#include "buffer_42.h"

t_buffer	*buffer_set(t_buffer *b, int c, size_t len)
{
	if (BUF_NEED_RESIZE(b, len))
		if (buffer_resize(b, len) == NULL)
			return (NULL);
	ft_memset(b->str + b->len, c, len);
	b->len += len;
	b->str[b->len] = 0;
	return (b);
}
