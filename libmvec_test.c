#include <stdio.h>
#include <math.h>

/*
 * gcc -lmvec -o libmvec_test libmvec_test.c && ./libmvec_test
 */

int stridex = 1, stridey = 1;
double double_x_tbl[] = {
	0.1,
	0.5,
	1,
	0,
	2,
	2.5,
	3000,
	0.0002,
	3.14,
	0.75,
	HUGE,
	M_PI,
	M_PI_2,
	M_PI_4
};
float float_x_tbl[] = {
	0.1,
	0.5,
	1,
	0,
	2,
	2.5,
	3000,
	0.0002,
	3.14,
	0.75,
	HUGE,
	M_PI,
	M_PI_2,
	M_PI_4
};

int double_elements = sizeof (double_x_tbl) / sizeof (double_x_tbl[0]);
int float_elements = sizeof (float_x_tbl) / sizeof (float_x_tbl[0]);

void
show_results_double(double *y)
{
	int i;
	for (i = 0; i < double_elements; i++) {
		printf("X value: %f, Y value: %f\n", double_x_tbl[i], y[i]);
	}
	printf("\n");
}

void
show_results_float(float *y)
{
	int i;
	for (i = 0; i < float_elements; i++) {
		printf("X value: %f, Y value: %f\n", float_x_tbl[i], y[i]);
	}
	printf("\n");
}

void
test_vcosf_()
{
	printf("Testing vcosf_ - float\n");
	float y[float_elements];

	/*
	 * void vcosf_(int *n, float * restrict x, int *stridex,
	 *		float * restrict y, int *stridey);
	 */
	vcosf_(&float_elements, float_x_tbl, &stridex, y, &stridey);
	show_results_float(y);
}

void
test_vcos_()
{
	printf("Testing vcos_ - double\n");
	double y[double_elements];

	/*
	 * void vcos_(int *n, double * restrict x, int *stridex,
	 *		double * restrict y, int *stridey);
	 */
	vcos_(&double_elements, double_x_tbl, &stridex, y, &stridey);
	show_results_double(y);
}

void
test_vatan_()
{
	printf("Testing vatan_ - double\n");
	double y[double_elements];

	/*
	 * void vatan_(int *n,double * restrict x, int *stridex,
	 * double * restrict y, int *stridey);
	 */
	vatan_(&double_elements, double_x_tbl, &stridex, y, &stridey);
	show_results_double(y);
}

void
test_vatanf_()
{
	printf("Testing vatanf_ - float\n");
	float y[float_elements];

	/*
	 * void vatanf_(int *n, float * restrict x, int *stridex,
	 *		float * restrict y, int *stridey);
	 */
	vatanf_(&float_elements, float_x_tbl, &stridex, y, &stridey);
	show_results_float(y);
}

void
test_vexp_()
{
	printf("Testing vexp_ - double\n");
	double y[double_elements];

	/*
	 * void vexp_(int *n,double * restrict x, int *stridex,
	 * double * restrict y, int *stridey);
	 */
	vexp_(&double_elements, double_x_tbl, &stridex, y, &stridey);
	show_results_double(y);
}

void
test_vlog_()
{
	printf("Testing vlog_ - double\n");
	double y[double_elements];

	/*
	 * void vlog_(int *n,double * restrict x, int *stridex,
	 * double * restrict y, int *stridey);
	 */
	vlog_(&double_elements, double_x_tbl, &stridex, y, &stridey);
	show_results_double(y);
}

void
test_vsin_()
{
	printf("Testing vsin_ - double\n");
	double y[double_elements];

	/*
	 * void vsin_(int *n,double * restrict x, int *stridex,
	 * double * restrict y, int *stridey);
	 */
	vsin_(&double_elements, double_x_tbl, &stridex, y, &stridey);
	show_results_double(y);
}

void
test_vsinpi_()
{
	printf("Testing vsinpi_ - double\n");
	double y[double_elements];

	/*
	 * void vsinpi_(int *n,double * restrict x, int *stridex,
	 * double * restrict y, int *stridey);
	 */
	vsinpi_(&double_elements, double_x_tbl, &stridex, y, &stridey);
	show_results_double(y);
}


void
test_vsqrt_()
{
	printf("Testing vsqrt_ - double\n");
	double y[double_elements];

	/*
	 * void vsqrt_(int *n, double * restrict x, int *stridex,
	 * double * restrict y, int *stridey);
	 */
	vsqrt_(&double_elements, double_x_tbl, &stridex, y, &stridey);
	show_results_double(y);
}

void
test_vsqrtf_()
{
	printf("Testing vsqrtf_ - float\n");
	float y[float_elements];

	/*
	 * void vsqrtf_(int *n, float * restrict x, int *stridex,
	 * float * restrict y, int *stridey);
	 */
	vsqrtf_(&float_elements, float_x_tbl, &stridex, y, &stridey);
	show_results_float(y);
}

void
show_x_values()
{
	int i;
	char *c = "X values (double):\n";
	printf(c);

	for (i = 0; i < double_elements; i++) {
		printf("index %d, value: %f\n", i, double_x_tbl[i]);
	}
	printf("\n");

	c = "X values (float):\n";
	printf(c);

	for (i = 0; i < float_elements; i++) {
		printf("index %d, value: %f\n", i, float_x_tbl[i]);
	}
	printf("\n");
}

int
main()
{
	show_x_values();
	test_vcosf_();
	test_vcos_();
	test_vsin_();
	test_vsinpi_();
	test_vatan_();
	test_vatanf_();
	test_vexp_();
	test_vlog_();
	test_vsqrt_();
	test_vsqrtf_();
}
