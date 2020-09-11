#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* get_numbers(int size);
double find_discrim(double* koef);
double* find_roots(int count_of_koef);

int main() {
	int count_of_koef = 3;
	double* answer = find_roots(count_of_koef);
	double count_of_solutions = answer[0];
	if (count_of_solutions == 0) {
		printf("No roots!!\n");
	}
	else if (count_of_solutions == 1) {
		printf("There is one root: %lf \n", answer[1]);
	}
	else {
		printf("Roots: %lf %lf \n", answer[1], answer[2]);
	}
}


double* get_numbers(int size) {
	double* koef = (double*)calloc(size, sizeof(double));
	for (int i = 0; i < size; i++) {
		printf("koef[%d] = ", i);
		scanf("%lf", &koef[i]);
	}
	return koef;
}


double find_discrim(double* koef) {
	return koef[1] * koef[1] - 4 * koef[0] * koef[2];
}


double* find_roots(int count_of_koef) {
	double* answer = (double*)calloc(count_of_koef, sizeof(double));
	double* koef = get_numbers(count_of_koef);
	if (koef[0] != 0){
		double discrim = find_discrim(koef);
		if (discrim < 0){
			answer[0] = 0;
		}
		else {
			double x1 = answer[1] = (-koef[1] + sqrt(discrim)) / (2 * koef[0]);
			double x2 = answer[1] = (-koef[1] - sqrt(discrim)) / (2 * koef[0]);
			if (discrim == 0){
				answer[0] = 1;
				answer[1] = x1;
			}
			else {
				answer[0] = 2;
				answer[1] = x1;
				answer[2] = x2;
			}
		}
	}
	else {
		answer[0] = 1;
		answer[1] = -koef[2]/koef[1];
	}
	return answer;
}
