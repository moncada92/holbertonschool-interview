#include "binary_trees.h"
/**
 * heap_insert - change the heap
 *
 * @root: Pointer to the heap
 * @value: value of the new node
 *
 * Return: new node inserted
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;
	size_t size = 0, height = 0, min = 0, comp = 0;

	if (root == NULL)
		return (NULL);

	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;

	if (*root == NULL)
	{
		*root = new;
		return (new);
	}

	size = sizeHeightMiMxLv(*root, 0, 0);
	height = sizeHeightMiMxLv(*root, 1, 0);
	min = sizeHeightMiMxLv(NULL, 2, height + 1);
	comp = sizeHeightMiMxLv(*root, 5, 0);

	heap_max(root, &new, height, size, min, comp);
	changeParent(&new);
	return (new);
}
/**
 * heap_max - insert in perfect order
 *
 * @pa: pointer to the parent
 * @nw: pointer to the new node
 * @h: height
 * @s: size
 * @mi: min size
 * @cmp: is complete
 *
 * Return: new node inserted
 */
void heap_max(heap_t **pa, heap_t **nw, size_t h, size_t s,
	      size_t mi, size_t cmp)
{
	size_t fullR = 0, fullL = 0;

	fullL = sizeHeightMiMxLv((*pa)->left, 5, 0);
	fullR = sizeHeightMiMxLv((*pa)->right, 5, 0);

	if (fullL == 0 && fullR == 0)
	{
		(*nw)->parent = *pa;
		(*pa)->left = *nw;
		return;
	} else if (fullL == 1 && fullR == 0 && (*pa)->right == NULL)
	{
		(*nw)->parent = *pa;
		(*pa)->right = *nw;
		return;
	}

	if (s - (mi - 1) < mi / 2 || cmp == 1)
	{
		s = sizeHeightMiMxLv((*pa)->left, 0, 0);
		h = sizeHeightMiMxLv((*pa)->left, 1, 0);
		mi = sizeHeightMiMxLv(NULL, 2, h + 1);
		cmp = sizeHeightMiMxLv((*pa)->left, 5, 0);
		heap_max(&(*pa)->left, nw, h, s, mi, cmp);
		return;
	}
	else
	{
		s = sizeHeightMiMxLv((*pa)->right, 0, 0);
		h = sizeHeightMiMxLv((*pa)->right, 1, 0);
		mi = sizeHeightMiMxLv(NULL, 2, h + 1);
		cmp = sizeHeightMiMxLv((*pa)->right, 5, 0);
		heap_max(&(*pa)->right, nw, h, s, mi, cmp);
		return;
	}
}
/**
 * sizeHeightMiMxLv - function to calculate
 * the heigh, size, min, max, leaves
 *
 * @tree: pointer to the root
 * @sh: number of menu. 0: size, 1: height, 2: min, 3: max,
 *  4: leaves, 5: perfect
 * @height: heigh
 *
 * Return: the value needed
 */
size_t sizeHeightMiMxLv(heap_t *tree, size_t sh, size_t height)
{
	size_t count1 = 0, count2 = 0;

	if (sh == 0)
	{
		if (tree == NULL)
			return (0);
		count1 += sizeHeightMiMxLv(tree->left, 0, 0) + 1;
		count1 += sizeHeightMiMxLv(tree->right, 0, 0);
		return (count1);
	} else if (sh == 1)
	{
		if (tree == NULL)
			return (0);
		if (tree->left)
			count1 = sizeHeightMiMxLv(tree->left, 1, 0) + 1;
		if (tree->right)
			count2 = sizeHeightMiMxLv(tree->right, 1, 0) + 1;
		return ((count1 < count2) ? count2 : count1);
	} else if (sh == 2)
		return (powR(2.0, height - 1));
	else if (sh == 3)
		return ((powR(2.0, height - 1)) + (powR(2.0, height - 1) - 1));
	else if (sh == 4)
	{
		if (tree == NULL)
			return (0);
		if (tree->left ==  NULL && tree->right == NULL)
			return (1);
		count1 = sizeHeightMiMxLv(tree->left, 4, 0);
		count2 = sizeHeightMiMxLv(tree->right, 4, 0);
		return (count1 + count2);
	}
	else
	{
		if (tree == NULL)
			return (0);
		count1 = sizeHeightMiMxLv(tree, 4, 0);
		count2 = sizeHeightMiMxLv(tree, 1, 0);
		return ((count1 == powR(2, count2)) ? 1 : 0);
	}
}
/**
 * powR - function to pow function
 *
 * @x: base
 * @y: exp
 *
 * Return: x^y
 */
size_t powR(size_t x, size_t y)
{
	if (y != 0)
		return (x * powR(x, (y - 1)));
	else
		return (1);
}
/**
 * changeParent - change parent if parent->n < new->n
 *
 * @new: new node created
 *
 * Return: nothing
 */
void changeParent(heap_t **new)
{
	heap_t *current = (*new)->parent;
	int tmp = 0;

	while (current != NULL && current->n < (*new)->n)
	{
		tmp = current->n;
		current->n = (*new)->n;
		(*new)->n = tmp;
		*new = current;
		current = (*new)->parent;
	}
}
