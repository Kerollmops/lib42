#include "buffer_42.h"

t_buffer	*ft_buffer_new(size_t size)
{
	t_buffer	*new;

	new = ft_memalloc(sizeof(t_buffer));
	if (new == NULL)
		return (NULL);
	return (ft_buffer_init(new, size));
}
