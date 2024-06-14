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

	auto nsamps = DURATION * SAMPLE_RATE;
	auto sign = acos(0.0) * 2;
	auto angle = sign / float(nsamps);
	double sample;

	std::ofstream output_file("out.bin", std::ios::binary);

	for (auto i = 0; i < nsamps; i++) {

		sample = std::sin(angle * FREQUENCY * static_cast<double>(i));
		float sample_float = static_cast<float>(sample);
		// uint8_t buffer[8];
		uint32_t sample_uint = *reinterpret_cast<uint32_t*>(&sample_float);
		output_file.write(reinterpret_cast<char*>(&sample_uint), sizeof(sample_uint));
		// std::cout << "\rWrote: " << (i + 1) * sizeof(sample_uint) << " bytes to " << output_file << std::flush;
	}
}

int main() {

	generate_song();


	return 0;
}



// func generate() {
// 	nsamps := Duration * SampleRate
// 	var angle float64 = tau / float64(nsamps)
// 	file := "out.bin"
// 	f, _ := os.Create(file)
// 	for i := 0; i < nsamps; i++ {
// 		sample := math.Sin(angle * Frequency * float64(i))
// 		var buf [8]byte
// 		binary.LittleEndian.PutUint32(buf[:], math.Float32bits(float32(sample)))
// 		math.Float32bits -> converte float em um inteiro unsigned
// 		PutUnit32 -> 
// 		bw,_ := f.Write(buf[:])
// 		fmt.Printf("\rWrote: %v bytes to %s", bw, file)
// 	}
// }