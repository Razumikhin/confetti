/* Implement a function that accepts a pair of binary trees, and returns true if
 * the second is a subtree of the first. Otherwise, the function should return
 * false. */

#include <stdbool.h>
#include <stdio.h>

/* Type defintion for trees */

typedef struct __tree {
	int key;
	struct __tree *left, *right;
} Tree;

/* Function prototypes */

bool areIdentical(Tree *, Tree *);
bool isSubtree(Tree *, Tree *);

/* Function definitions */

bool areIdentical(Tree *foo, Tree *bar) {
	if(!foo && !bar)
		return true;
	else if(!foo || !bar)
		return false;
	else
		return foo -> key == bar -> key && \
		areIdentical(foo -> left, bar -> left) && \
		areIdentical(foo -> right, bar -> right);
}

bool isSubtree(Tree *foo, Tree *bar) {
	if(!bar)
		return true;
	else if(!foo)
		return false;
	else if(areIdentical(foo, bar))
		return true;
	else
		return isSubtree(foo -> left, bar) || \
		isSubtree(foo -> right, bar);
}
