#include "header.h"

static void	test_00_btree_newnode_TreeWith2Leafes(void)
{
	t_btree	*root;
	t_btree	*left;
	t_btree	*right;
	char	*sroot = "root";
	char	*sleft = "left";
	char	*sright = "right";

	root = btree_newnode(NULL, sroot);
	left = btree_newnode(root, sleft);
	right = btree_newnode(root, sright);
	root->left = left;
	root->right = right;

	v_assert_str(sroot, root->data);
	v_assert_str(sleft, left->data);
	v_assert_str(sright, right->data);

	v_assert_str(sleft, root->left->data);
	v_assert_str(sright, root->right->data);

	v_assert_str(sroot, left->parent->data);
	v_assert_str(sroot, right->parent->data);

	free(left);
	free(right);
	free(root);
	VTS;
}

void	suite_btree_new(void)
{
	test_00_btree_newnode_TreeWith2Leafes();

	VSS;
}
