#include "iostream"
#include "fstream"
#include "math.h"
#include "cstdint"
#include "vector"

using namespace std;


#define DURATION 2
#define SAMPLE_RATE 44100
#define FREQUENCY 440


void generate_song() {

	// modificando a amplitude do sinal
	// multiplicando pelo fator decay

	auto start = 1.0; 
	auto end = 1.0e-4;
	auto nsamps = DURATION * SAMPLE_RATE;
	auto sign = acos(0.0) * 2;
	auto angle = sign / float(nsamps);
	auto decay_factor = pow(end/start, 1.0/static_cast<float>(nsamps));
	double sample;

	std::string file_name = "out.bin";
	std::ofstream output_file(file_name, std::ios::binary);


	for (auto i = 0; i < nsamps; i++) {

		sample = std::sin(angle * FREQUENCY * static_cast<double>(i));
		sample *= start;
		start *= decay_factor;
		float sample_float = static_cast<float>(sample);
		uint32_t sample_uint = *reinterpret_cast<uint32_t*>(&sample_float);
		output_file.write(reinterpret_cast<char*>(&sample_uint), sizeof(sample_uint));
		// std::cout << "\rWrote: " << (i + 1) * sizeof(sample_uint) << " bytes to " << file_name << std::flush;
	}
}


int main() {

	generate_song();


	return 0;
}