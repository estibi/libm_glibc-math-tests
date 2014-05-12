#include <stdio.h>
#include <math.h>

/*
 * gcc -lmvec -o libmvec_vcosf_loop_test libmvec_vcosf_loop_test.c
 */

int stridex = 1, stridey = 1;

void
show_values(float * x, int size)
{
	int i = 0;
	while (i < size) {
		printf("index %d, value: %f\n", i, x[i]);
		i++;
	}
	printf("\n");
}

int
main()
{
	int i, n = 100000, repeat = 20000;
	float x[n], y[n];

	printf("creating table with %d values..\n", n);
	float tmp = 0.0;
	for (i = 0; i < n; i++) {
		x[i] = tmp += 0.123;
	}

	printf("calling vcosf_ %d times in a loop..\n", repeat);
	for (i = 0; i < repeat; i++) {
		vcosf_(&n, x, &stridex, y, &stridey);
	}
	// show_values(x, n);
	// show_values(y, n);
}
