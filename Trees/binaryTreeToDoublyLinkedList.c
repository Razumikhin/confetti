/* Implement a function that accepts a binary tree, and transforms it to a
 * doubly-linked list in place. */

#include <stdio.h>

/* Type defintion for trees */

typedef struct __tree {
	int key;
	struct __tree *left, *right;
} Tree;

/* Function prototypes */

Tree *binaryTreeToDoublyLinkedList(Tree *);
Tree *binaryTreeToDoublyLinkedListHelper(Tree *);

/* Function definitions */

Tree *binaryTreeToDoublyLinkedList(Tree *tr) {
	if(!tr)
		return tr;
	tr = binaryTreeToDoublyLinkedListHelper(tr);
	while(tr -> left)
		tr = tr -> left;
	return tr;
}

Tree *binaryTreeToDoublyLinkedListHelper(Tree *tr) {
	if(!tr)
		return tr;
	if(tr -> left) {
		Tree *left = binaryTreeToDoublyLinkedListHelper(root -> left);
		for(; left -> right; left = left -> right)
			;
		left -> right = tr;
		tr -> left = left;
	}
	if(tr -> right) {
		Tree *right = binaryTreeToDoublyLinkedListHelper(root -> right);
		for(; right -> left; right = right -> left)
			;
		right -> left = tr;
		tr -> right = right;
	}
	return tr;
}
