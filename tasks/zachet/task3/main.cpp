#include <iostream>
#include <vector>
#include <fstream>

class Matrix {
private:
	std::vector<std::vector<double>> data;
	size_t rows, cols;

public:
	Matrix(size_t r = 0, size_t c = 0) : rows(r), cols(c) {

	}

	void read(std::istream& in) {

	}

	Matrix operator*(const Matrix& other) const {

	}

	void write(std::ostream& out) const {

	}
};

int main() {
	std::ifstream file1("matrix1.txt");
	std::ifstream file2("matrix2.txt");
	std::ofstream outfile("result.txt");

	if (!file1 || !file2 || !outfile) {
		std::cerr << "Ошибка открытия файлов\n";
		return 1;
	}

	Matrix m1, m2;
	m1.read(file1);
	m2.read(file2);

	Matrix result = m1 * m2;
	result.write(outfile);
	// или записать временный результат (m1 * m2).write(outfile);

	file1.close();
	file2.close();
	outfile.close();

	return 0;
}