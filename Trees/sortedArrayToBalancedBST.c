/* Implement a function that accepts a sorted array of integers and uses its
 * elements to construct a balanced binary search tree. */

#include <stdio.h>

/* Type defintion for trees */

typedef struct __tree {
	int key;
	struct __tree *left, *right;
} Tree;

/* Function prototypes */

Tree *sortedArrayToBalancedBST(int[], unsigned, unsigned);

/* Function definitions */

Tree *sortedArrayToBalancedBST(int src[], unsigned lo, unsigned hi) {
	if(lo > hi)
		return NULL;
	int middle = lo + (hi - lo) / 2;
	Tree *rt = malloc(sizeof(Tree));
	rt -> key = src[mid];
	rt -> left = sortedArrayToBalancedBST(src, lo, mid - 1);
	rt -> right = sortedArrayToBalancedBST(src, mid + 1, hi);
	return rt;
}
