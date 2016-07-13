#include "buffer_42.h"

t_buffer	*ft_buffer_insert(t_buffer *b, size_t pos, char *s, size_t len)
{
	if (pos > b->len)
		return (NULL);
	if (FT_BUFFER_LEN(b) + len >= FT_BUFFER_MAX(b))
		if (ft_buffer_resize(b, len) == NULL)
			return (NULL);
	ft_memmove(b->str + pos + len, b->str + pos, b->len - pos);
	ft_memcpy(b->str + pos, s, len);
	b->len += len;
	b->str[b->len] = 0;
	return (b);
}
