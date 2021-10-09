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

	float matRed[9] = { 1.0f, 2.0f, 3.0f,
					    0.0f, 0.0f, 6.0f,
					    0.0f, 1.0f, 5.f };

	lito::Matrix<float> matrix(3, 3, mat);
	lito::Matrix<float> vector(3, 1, vec);
	lito::Matrix<float> vectort(1, 3, vec);
	lito::Matrix<float> matReduction(3, 3, matRed);
	lito::Matrix<float> matOperation;
	std::pair<lito::Matrix<float>, lito::uint*> result = lito::gaussReduction(matReduction, matOperation);

	//std::get<0>(result)(2, 2) = 10.0f;
	//matReduction(2, 2) = 10.0f;

	try {
		std::cout
			<< std::get<0>(result) << std::endl
			<< matOperation << std::endl
			<< matReduction << std::endl
			<< lito::matMul(matOperation, matReduction) << std::endl;
	}
	catch (lito::MatrixException me)
	{
		me.showExeception();
	}
	return 0;
}
