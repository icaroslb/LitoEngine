#ifndef MATRIZ_ENUM_H
#define MATRIZ_ENUM_H

namespace lito {

	typedef unsigned int uint;

	enum class MatrixType { IDENTITY, ZEROS, ONES };
	enum class Ori_transf { xy, yz, zx };
	enum class MatrixExceptionType { INVALID_ACCESS, INCOMPATIBLE_SIZES };

}

#endif
