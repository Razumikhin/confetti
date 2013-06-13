/* Implement a function that accepts a binary tree, and finds its depth in an
 * iterative fashion. */

#include <stdbool.h>
#include <stdio.h>

/* Type defintion for trees */

typedef struct __tree {
	int key;
	struct __tree *left, *right;
} Tree;

/* Function prototypes */

unsigned depth_i(Tree *);
void deQueue(Queue *);
void enQueue(Queue *, int);
Queue *front(Queue *);
unsigned size(Queue *);

/* Function definitions */

unsigned depth_i(Tree *tr) {
	if(!root)
		return 0;
	int depth = 0, nodeCount;
	Queue *q;
	Tree *n;
	enQueue(q, tr);
	while(true) {
		nodeCount = size(q);
		if(!nodeCount)
			return depth;
		++depth;
		while(nodeCount > 0) {
			n = front(q);
			deQueue(q);
			if(n -> left)
				enQueue(q, n -> left);
			if(n -> right)
				enQueue(q, n -> right);
			--nodeCount;
		}
	}
}
