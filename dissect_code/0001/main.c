#include <stdlib.h>
#include <stdio.h>
#include "kann.h"
#include "kautodiff.h"

int main(int argc, char *argv[]) {

	kad_node_t *t;
	kann_t *nn;
	float input[5] = {0.1, 0.2, 0.3, 0.4, 0.5};

	printf("sizeof(kad_node_t): %d \n", sizeof(kad_node_t));
	t = kann_layer_input(5);
	printf("Show the dimension:");
	printf("Dimension: %d \n", t->n_d);
	
	printf("Size of dim 0 (t->d[0]): %d \n", t->d[0]);
	printf("Size of dim 1 (t->d[1]): %d \n", t->d[1]);
	printf("Size of dim 2 (t->d[2]): %d \n", t->d[2]);
	printf("Size of dim 3 (t->d[3]): %d \n", t->d[3]);
	printf("N children: %d \n", t->n_child);

	printf("t->x: %f \n", t->x);
	printf("Adding a dense layer:\n");

	// In dense layer, it add 2 nodes: weight (w) and (bias)
	// the weight and input are cmul together, the 
	t = kann_layer_dense(t, 10);
	printf("Dimension: %d \n", t->n_d);
	printf("N children: %d \n", t->n_child);
	printf("t->child[0]->x: %f \n", t->child[0]->x);
	printf("t->child[1]->x: %f \n", t->child[1]->x);

	// Input has no value
	printf("t->child[0]->child[0]->x: %f \n", t->child[0]->child[0]->x);

	// List weight value. There are 50 values.
	printf("t->child[0]->child[1]->x[0]: %f \n", t->child[0]->child[1]->x[0]);
	printf("t->child[0]->child[1]->x[9]: %f \n", t->child[0]->child[1]->x[9]);
	printf("t->child[0]->child[1]->x[10]: %f \n", t->child[0]->child[1]->x[10]);
	printf("t->child[0]->child[1]->x[49]: %f \n", t->child[0]->child[1]->x[49]);
	printf("t->child[0]->child[1]->x[50]: %f \n", t->child[0]->child[1]->x[50]);

	// List bias 
	printf("t->child[1]->x[0]: %f \n", t->child[1]->x[0]);
	printf("t->child[1]->x[1]: %f \n", t->child[1]->x[1]);
	printf("t->child[1]->x[2]: %f \n", t->child[1]->x[2]);
	printf("t->child[1]->x[3]: %f \n", t->child[1]->x[3]);
	printf("t->child[1]->x[4]: %f \n", t->child[1]->x[4]);
	printf("t->child[1]->x[5]: %f \n", t->child[1]->x[5]);
	printf("t->child[1]->x[6]: %f \n", t->child[1]->x[6]);
	printf("t->child[1]->x[7]: %f \n", t->child[1]->x[7]);
	printf("t->child[1]->x[8]: %f \n", t->child[1]->x[8]);
	printf("t->child[1]->x[9]: %f \n", t->child[1]->x[9]);
	printf("t->child[1]->x[10]: %f \n", t->child[1]->x[10]);

	return 0;
}