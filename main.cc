#include "iostream"
#include "fstream"
#include "math.h"
#include "bit"
using namespace std;


#define DURATION 2
#define SAMPLE_RATE 44100
#define FREQUENCY 440


void generate_song() {

	auto nsamps = DURATION * SAMPLE_RATE;
	auto sign = acos(0.0) * 2;
	auto angle = sign / float(nsamps);
	float sample;

	ofstream output_file("out.bin", std::ios::binary);

	for (auto i = 0; i < nsamps; i++) {

		sample = sin(angle * FREQUENCY * float(i));
		uint8_t buffer[8];
		static_cast<uint32_t>(sample);
		std::cout << sample << std::endl;
	}
}

int main() {

	generate_song();


	return 0;
}
