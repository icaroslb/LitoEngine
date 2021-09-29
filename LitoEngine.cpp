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
	float valores[6] = { 1.0f, 2.0f, 4.0f, 5.0f };

	lito::Matrix<float> teste1(2, 3, valores);
	lito::Matrix<float> teste2(2, 2, valores);
	lito::Matrix<float> teste3;
	lito::Matrix<float> teste4;

	try {
		teste3 = lito::matMul(teste1, teste2);
	}
	catch (lito::MatrixException me)
	{
		me.showExeception();
	}
	
	try {
		std::cout << "Hello CMake."
			<< teste1 << std::endl
			<< teste2 << std::endl
			<< teste3 << std::endl
			<< (teste4 = teste1 - teste3) << std::endl;
	}
	catch (lito::MatrixException me)
	{
		me.showExeception();
		std::cout << 1.0f + teste1 << 1.0f - teste1;
	}
	return 0;
}
