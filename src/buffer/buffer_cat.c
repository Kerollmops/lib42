#include "buffer_42.h"

t_buffer	*buffer_cat(t_buffer *b, const char *s)
{
	return (buffer_ncat(b, s, ft_strlen(s)));
}

t_buffer	*buffer_ncat(t_buffer *b, const char *s, size_t len)
{
	if (BUF_NEED_RESIZE(b, len))
		if (buffer_resize(b, len) == NULL)
			return (NULL);
	ft_memcpy(b->str + b->len, s, len);
	b->len += len;
	return (b);
}
