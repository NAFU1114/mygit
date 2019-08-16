#include <stdio.h>
#include <cblas.h>
#include <stdlib.h>


#define Type double

void print_s(float *x, float *y, const int n) {

	printf("X: \n");
	for (int i = 0; i < n; i++) {
		printf("%.1f,", x[i]);
		x[i] = i + 1.0;
	}
	printf("\nY: \n");
	for (int j = 0; j < n; j++) {
		printf("%.1f,", y[j]);
		y[j] = j + 21.0;
	}
	printf("\n");
}

void print_d(double *x, double *y, const int n) {

	printf("X: \n");
	for (int i = 0; i < n; i++) {
		printf("%.1f,", x[i]);
		x[i] = i + 1.0;
	}
	printf("\nY: \n");
	for (int j = 0; j < n; j++) {
		printf("%.1f,", y[j]);
		y[j] = j + 21.0;
	}
	printf("\n");
}

int main() {
	
	//Type x[100] = {1, 2, 3, 4};
	//float y[4] = { 5, 6, 7, 8 };
	//float a[2] = { 10, 20 };
	
	float a[16];
	for (int i = 0; i < 16; i++) {
		a[i] = i;
	}
	float x[4] = { 1, 2, 3, 4 };
	float y[4] = { -1, -1, -1, -1 };
	//cblas_cscal(2, y, y, 1);
	//cblas_sgbmv(CblasNoTrans,);
	int m = 3, n = 4, lda = 4;
	int incx = 1, incy = 1;
	float alpha = 1, beta = 1;
	cblas_sgemv(CblasColMajor, CblasNoTrans, m, n, alpha, a, lda, x, incx, beta, y, incy);

	for (int i = 0; i < 4; i++) {
		if (i % 4 == 0) printf("\n");
		printf("%.1f  ", y[i]);
	}
	
	system("pause");
	return 0;
}