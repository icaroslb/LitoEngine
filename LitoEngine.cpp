// LitoEngine.cpp: define o ponto de entrada para o aplicativo.
//

#include "LitoEngine.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
int wmain()
#else
int main()
#endif
{
	unsigned int rows = 3;
	unsigned int columns = 3;
	float mat[9] = { 1.0f, 2.0f, 3.0f,
		             4.0f, 5.0f, 6.0f,
	                 7.0f, 8.0f, 9.f};
	float vec[3] = { 1.0f, 2.0f, 3.0f };

	lito::Matrix<float> matrix(3, 3, mat);
	lito::Matrix<float> vector(3, 1, vec);
	lito::Matrix<float> vectort(1, 3, vec);

	try {
		std::cout
			<< matrix << std::endl
			<< vector << std::endl
			<< vectort << std::endl
			<< lito::matMul(matrix, vector) << std::endl
			<< lito::matMul(matrix, vectort.transpose()) << std::endl;
	}
	catch (lito::MatrixException me)
	{
		me.showExeception();
	}
	return 0;
}
