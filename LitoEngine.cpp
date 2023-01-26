// LitoEngine.cpp: define o ponto de entrada para o aplicativo.
//

#include "LitoEngine.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
int wmain()
#else
int main()
#endif
{
	lito::Matriz_3f m{ 1.0f, 2.0f, 3.0f,
					   1.0f, 0.0f, 6.0f,
					   0.0f, 0.0f, 5.0f };
	lito::Matriz_4f m2{ 1.0f, 2.0f, 3.0f, 1.0f,
					    1.0f, 0.0f, 6.0f, 0.0f,
					    0.0f, 0.0f, 5.0f, 1.0f,
						0.0f, 2.0f, 3.0f, 1.0 };

	try {
		std::cout << lito::invert( m )  << std::endl
		          << lito::invert( m2 ) << std::endl;
	}
	catch ( const lito::MatrixException &me )
	{
		me.showExeception();
	}
	
	return 0;
}
