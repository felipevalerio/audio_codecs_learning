#include "iostream"
#include "math.h"

using namespace std;


void generate_sin_wave() {

	int nsamps = 50;
	double sign = acos(0.0) * 2;
	float angle = sign / nsamps;

	for (auto i = 0; i < nsamps; i++) {

		auto sample = sin(angle * float(i));
		std::cout << sample << std::endl;
	}
	 
}

int main() {

	generate_sin_wave();
	return 0;
}