/* Implement a function that accepts a binary search tree, and a pair of
 * integers, hi and lo, and deletes every node in the tree whose key lies
 * outside the interval, [lo, hi]. The resultant tree should be a BST. */

#include <stdbool.h>
#include <stdio.h>

/* Type defintion for trees */

typedef struct __tree {
	int key;
	struct __tree *left, *right;
} Tree;

/* Function prototypes */

Tree *rmBSTKeysOutsideRange(Tree *, int, int);

/* Function definitions */

Tree *rmBSTKeysOutsideRange(Tree *tr, int lo, int hi) {
	if(!tr)
		return NULL;
	tr -> left = rmBSTKeysOutsideRange(tr -> left, lo, hi);
	tr -> right = rmBSTKeysOutsideRange(tr -> right, lo, hi);
	if(tr -> key < lo) {
		Tree *rt = tr -> right;
		tr -> right = NULL;
		nuke(tr);
		return rt;
	}
	if(tr -> key > hi) {
		Tree *rt = tr -> left;
		tr -> left = NULL;
		nuke(tr);
		return rt;
	}
	return tr;
}
