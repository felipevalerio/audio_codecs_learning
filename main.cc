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

	std::string file_name = "out.bin";
	std::ofstream output_file(file_name, std::ios::binary);


	for (auto i = 0; i < nsamps; i++) {

		sample = std::sin(angle * FREQUENCY * static_cast<double>(i));
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

// pensando em uma onda sonoro se deslocando pelo ar...
// amplitude: é o descolamento máximo de uma molécula a partir do seu ponto de equilíbrio
// período (T): é tempo gasto por uma molécula para completar um ciclo (ir e voltar, pensando em uma onda). Número de segundos por oscilação
// frequência: número de oscilações por segundo. Medido por Hertz (Hz)
// comprimento: a distância entre duas regiões de compressão de ar

// notas mais altas (agudas) tem frequências mais altas, notas mais baixas (graves) tem frequências mais baixas
// a nota A (Lá) tem a frequência de 440Hz por segundos, serão 440 oscilações que serão feitas pelas moléculas em 1 segundo
// o ser humano ouve frequências em uma faixa de 20Hz até 22.000Hz