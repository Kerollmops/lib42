#include "btree_42.h"

t_btree	*btree_newnode(t_btree *parent, void *data)
{
	t_btree	*node;

	node = ft_memalloc(sizeof(t_btree));
	if (node != NULL)
	{
		node->parent = parent;
		node->data = data;
	}
	return (node);
}
