#ifndef BTREE_42_H
# define BTREE_42_H

# include <stdlib.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "memory_42.h"

# define BTREE_ISEMPTY(t)	((t) == NULL)
# define BTREE_ISLEAF(t)	((t)->left == NULL && (t)->right == NULL)

t_btree	*btree_newnode(t_btree *parent, void *data);
void	btree_destroy(t_btree *root);

#endif
