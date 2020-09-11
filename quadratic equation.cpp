#include <stdlib.h>
#include <math.h>
#include <iostream>


double* get_numbers(double* koef, int size);
double find_discrim(double* koef);
double* find_roots(double* koef, double discrim);

int main() {
	double* koef;
	double* answer;
	int count_of_koef = 3;
	std::cout << "Please, enter coefficients of quadratic equation:" << std::endl;
	koef = get_numbers(koef, count_of_koef);
	if (koef[0] != 0) {
		double discrim = find_discrim(koef);
		if (discrim < 0){
		    std::cout << "Equastion doesn't have any root" << std::endl;
		}
		else {
			answer = find_roots(koef, discrim);
			if (discrim == 0){
			    std::cout << "Resolve is one root: " << answer[0] << std::endl;
			}
			else {
			    std::cout << "Roots are: " << answer[0] << " and " << answer[1] << std::endl;
			}
			free(answer);
		}
	}
	else {
		double linear_root = -koef[2]/koef[1];
		std::cout << "Equastion is linear! Root: " << linear_root << std::endl;
	}
	free(koef);
}


double* get_numbers(double* koef, int size) {
	koef = (double*)malloc(size* sizeof(double));
	for (int i = 0; i < size; i++) {
	    std::cin >> koef[i];
	}
	return koef;
}


double find_discrim(double* koef) {
	return koef[1] * koef[1] - 4 * koef[0] * koef[2];
}

double* find_roots(double* koef, double discrim) {
	double* answer = (double*)malloc(2 * sizeof(double));
	answer[0] = (-koef[1] + sqrt(discrim)) / (2 * koef[0]);
	answer[1] = (-koef[1] - sqrt(discrim)) / (2 * koef[0]);
	return answer;
}
