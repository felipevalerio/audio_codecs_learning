#include "iostream"
#include "fstream"
#include "math.h"
using namespace std;


#define DURATION 2
#define SAMPLE_RATE 44100
#define FREQUENCY 440


void generate_song() {

	int nsamps = DURATION * SAMPLE_RATE;
	float sample;
	double sign = acos(0.0) * 2;
	float angle = sign / float(nsamps);

	ofstream output_file("out.bin");

	for (auto i = 0; i < nsamps; i++) {

		sample = sin(angle * FREQUENCY * float(i));
		std::cout << sample << std::endl;
	}
}

int main() {

	generate_song();


	return 0;
}