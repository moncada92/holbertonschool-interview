#include "binary_trees.h"

/**
 * heap_insert -  function that insert a node in binary tree
 * @root: Pointer to the root node
 * @value: Value node
 * Return: Always 0 (Success)
 */

heap_t *heap_insert(heap_t **root, int value)
{
	int full;

	full = binary_tree_is_perfect(*root);
	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}

	if (full == 1)
		if (value > (*root)->n)
			*root = binary_tree_insert_left(*root, value);
		else
			return (binary_tree_insert_left(*root, value));
	else
	{
		if (value > (*root)->n)
			*root = binary_tree_validation(*root, value);
		else
			return (binary_tree_validation(*root, value));
	}
	return (*root);
}

/**
 * binary_tree_validation -  function that validate a binary tree node
 * @tree: Pointer to the tree node
 * @value: Value node
 * Return: Always 0 (Success)
 */
binary_tree_t *binary_tree_validation(binary_tree_t *tree, int value)
{
	int num1, num2, full, full1;

	if (tree->left && tree->right)
	{
		num1 = binary_tree_height(tree->left);
		num2 = binary_tree_height(tree->right);
		full = binary_tree_is_perfect(tree->left);
		full1 = binary_tree_is_perfect(tree->right);
		if (num1 == num2 && full1)
		{
			return (binary_tree_validation(tree->left, value));
		}
		else if (num1 == num2 && full1 == 0)
			return (binary_tree_validation(tree->right, value));
		else if (full == 0)
		{
			return (binary_tree_validation(tree->left, value));
		}
		else
			return (binary_tree_validation(tree->right, value));
	}
	else
	{
		if (tree->left == NULL)
			return (binary_tree_insert_left(tree, value));
		if (tree->right == NULL)
			return (binary_tree_insert_right(tree, value));
	}
	return (0);
}

/**
 * binary_tree_insert_left - function that inserts a node as the left-child
 *
 * @parent: node parent
 * @value: value node
 *
 * Return: binary tree
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent == NULL)
		return (NULL);
	if (value > parent->n)
	{
		if (parent->left == NULL)
		{
			node = binary_tree_node(parent, value);
			node->left = parent;
			node->parent = parent->parent;
			node->right = parent->right;
			if (parent->parent != NULL)
			{
				if (parent->parent->parent != NULL)
					parent->parent->left = node;
				else
					parent->parent->right = node;
			}
			parent->parent = node;
			parent->left = NULL;
			parent->right = NULL;
		}
		else
			node = binary_tree_insert_left(parent->left, value);
	}
	else
	{
		if (parent->left == NULL)
		{
			node = binary_tree_node(parent, value);
			parent->left = node;
		}
		else
			node = binary_tree_insert_left(parent->left, value);
	}
	return (node);
}

/**
 * binary_tree_insert_right - function that inserts a node as the right-child
 *
 * @parent: node parent
 * @value: value node
 *
 * Return: binary tree
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent == NULL)
		return (NULL);
	if (value > parent->n)
	{
		if (parent->right == NULL)
		{
			node = binary_tree_node(parent, value);
			node->right = parent;
			node->parent = parent->parent;
			node->left = parent->left;
			if (parent->parent != NULL)
				parent->parent->left = node;
			parent->left->parent = node;
			parent->parent = node;
			parent->left = NULL;
			parent->right = NULL;
		}
		else
			node = binary_tree_insert_right(parent->right, value);
	}
	else
	{
		if (parent->right == NULL)
		{
			node = binary_tree_node(parent, value);
			parent->right = node;
		}
		else
			node = binary_tree_insert_right(parent->right, value);
	}

	return (node);
}

/**
 * binary_tree_height - function that measures the height
 * of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: a size_t value
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_1, height_2;

	if (tree == NULL)
		return (0);

	height_1 = 0;
	height_2 = 0;
	if (tree->left)
		height_1 = 1;
	if (tree->right)
		height_2 = 1;

	height_2 += binary_tree_height(tree->right);
	height_1 += binary_tree_height(tree->left);
	if (height_2 > height_1)
		return (height_2);
	return (height_1);
}

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 *
 * @tree: tree
 *
 * Return: Always 0(Success)
 **/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leavesT;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	leavesT = binary_tree_leaves(tree->left) +
		binary_tree_leaves(tree->right);

	return (leavesT);
}

/**
 * binary_tree_is_perfect -  function that checks if a binary tree is perfect
 * binary tree
 *
 * @tree: tree
 *
 * Return: Always 0(Success)
 **/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leavesT = binary_tree_leaves(tree);
	int heightT = binary_tree_height(tree);
	int perfectT;
	int i, result = 1;

	for (i = 0; i < heightT; i++)
		result = 2 * result;

	perfectT = result;
	if (tree == NULL)
		return (0);

	if (leavesT == perfectT)
		return (1);
	return (0);
}
