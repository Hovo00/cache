#include <iostream>
#include <iomanip>
#include <chrono>

void printMatrix(int** p, const int n);

void createMatrix(int** (&), const int n);

void deleteMatrix(int** p, const int n);

void fillMatrix(int** p, const int n);
void fillMatrixres(int** p, const int n);


// function rotate matrix with 2 phases , first rotate rows , and second rotate semmetrical to additional diagonal

void rotateMatrix(int** p, const int n);


int main()

{
	int** p1;
	int** p2;
	int** p3;
	int n = 1500;
	int N, M, C;
	N = M = C = 1500;

	createMatrix(p1, n);
	fillMatrix(p1, n);
	createMatrix(p2, n);
	fillMatrix(p2, n);
	createMatrix(p3, n);
	fillMatrixres(p3, n);


std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());

for (int i = 0; i < N; ++i) {
	for (int j = 0; j < C; ++j) {
		for (int k = 0; k < M; ++k) {
			p3[i][k] += p1[i][j] * p2[j][k];
		}
	}
}


//for (int i = 0; i < N; ++i) {
//	for (int j = 0; j < M; ++j) {
//		for (int k = 0; k < C; ++k) {
//			p3[i][j] += p1[i][k] * p2[k][j];
//		}
//	}
//}

std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());

std::cout << std::chrono::duration_cast<std::chrono::duration<double>>(
	_end - _start).count(); // in seconds, read more about std::chrono

std::cout << "///////////////////////////////////////////////////////////";





	deleteMatrix(p1, n);
	deleteMatrix(p2, n);

}

void rotateMatrix(int** p, const int n)
{
	//first phase
	int temp;
	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < n / 2; ++j) {
			temp = p[i][j];
			p[i][j] = p[i][n - j - 1];
			p[i][n - j - 1] = temp;

		}
	}
	//second phase
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			temp = p[i][j];
			p[i][j] = p[n - j - 1][n - i - 1];
			p[n - j - 1][n - i - 1] = temp;
		}
	}
}

void createMatrix(int** (&p), const int n)
{
	p = new int* [n];

	for (int i = 0; i < n; ++i) {
		p[i] = new int[n];
	}
}

void fillMatrix(int** p, const int n)

{
	int t = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			p[i][j] = t++;

		}
	}

}

void fillMatrixres(int** p, const int n)
{
	int t = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			p[i][j] = t;

		}
	}
}

void printMatrix(int** p, const int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << std::setw(4) << p[i][j];
		}
		std::cout << std::endl;
	}
}

void deleteMatrix(int** p, const int n)
{
	for (int i = 0; i < n; ++i) {
		delete[] p[i];
	}
	delete[] p;

}





//std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
//
//for (int i = 0; i < N; ++i) {
//	for (int j = 0; j < C; ++j) {
//		for (int k = 0; k < M; ++k) {
//			res[i][k] += matrix1[i][j] * matrix2[j][k];
//		}
//	}
//}
//
//
//for (int i = 0; i < N; ++i) {
//	for (int j = 0; j < M; ++j) {
//		for (int k = 0; k < C; ++k) {
//			res[i][j] += matrix1[i][k] * matrix2[k][j];
//		}
//	}
//}
//
//std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());
//
//std::cout << std::chrono::duration_cast<std::chrono::duration<double>>(
//	_end - _start).count(); // in seconds, read more about std::chrono
//
//std::cout << "///////////////////////////////////////////////////////////";
//
//
//
