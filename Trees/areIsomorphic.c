/* Implement a function that accepts a pair of binary trees, and returns true if
 * they are isomorphic. The function should return false if they are not. */

#include <stdbool.h>
#include <stdio.h>

/* Type defintion for trees */

typedef struct __tree {
	int key;
	struct __tree *left, *right;
} Tree;

/* Function prototypes */

bool areIsomorphic(Tree *, Tree *);

/* Function definitions */

bool areIsomorphic(Tree *foo, Tree *bar) {
	if(!foo && !bar)
		return true;
	else if(!foo || !bar)
		return false;
	else if(foo -> key != bar -> key)
		return false;
	else 
		return (areIsomorphic(foo -> left, bar -> left) && \
		        areIsomorphic(foo -> right, bar -> right)) || \
		       (areIsomorphic(foo -> left, bar -> right) && \
		        areIsomorphic(foo -> right, bar -> left));
}
