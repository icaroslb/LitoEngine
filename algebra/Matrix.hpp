#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstdint>
#include <cstring>
#include <algorithm>
#include "MatrixEnum.hpp"

namespace lito{
	class MatrixException : public std::exception
	{
	public:
		MatrixException (MatrixExceptionType exceptionType, uint rowFirst = 0, uint columnFirst = 0, uint rowSecond = 0, uint columnSecond = 0, char operation = ' ')
			: _exceptionType(exceptionType)
			, _rowFirst(rowFirst)
			, _columnFirst(columnFirst)
			, _rowSecond(rowSecond)
			, _columnSecond(columnSecond)
			, _operation(operation)
		{}

		void showExeception ()
		{
			switch (_exceptionType)
			{
			case MatrixExceptionType::INVALID_ACCESS:
				std::cerr <<    "Invalid access for matrix( " << _rowFirst  << ", " << _columnFirst
					      << " ):  possition accessed was ( " << _rowSecond << ", " << _columnSecond << " )!" << std::endl;
				break;
			case MatrixExceptionType::INVALID_SIZE:
				std::cerr << "Invalid size: " << "( " << _rowFirst << ", " << _columnFirst << " )!" << std::endl;
				break;
			case MatrixExceptionType::INCOMPATIBLE_SIZES:
				std::cerr << "Invalid sizes for " << _operation
					      <<    " operation: M1( " << _rowFirst  << ", " << _columnFirst  << " ) "
					      << _operation << " M2( " << _rowSecond << ", " << _columnSecond << " )!" << std::endl;
				break;
			case MatrixExceptionType::MATRIX_NOT_INITIALIZED:
				std::cerr << "Matrix not initialized!" << std::endl;
				break;
			}
		}

	private:
		MatrixExceptionType _exceptionType;
		uint _rowFirst;
		uint _columnFirst;
		uint _rowSecond;
		uint _columnSecond;
		char _operation;
	};

	template <typename T>
	class Matrix {
	public:
		Matrix(uint rows = 0, uint columns = 0, const MatrixType& type = MatrixType::ZEROS);
		Matrix(uint rows, uint columns, const T* data);

		Matrix<T>& resize(uint rows, uint columns);
		
		T& operator () (const uint& line, const uint& column);
		const T& operator () (const uint& line, const uint& column) const;
	
		Matrix<T>& operator = (const Matrix<T>& rec);

		Matrix<T> operator + (const Matrix<T>& sum);
		Matrix<T> operator - (const Matrix<T>& sub);
		Matrix<T> operator * (const Matrix<T>& mul);
	
		Matrix<T> operator + (const T& sum);
		Matrix<T> operator - (const T& sub);
		Matrix<T> operator * (const T& mul);

		Matrix<T> transpose ();

		template <typename _T> friend Matrix<_T> operator + (const Matrix<_T>& sum);
		template <typename _T> friend Matrix<_T> operator - (const Matrix<_T>& sub);

		template <typename _T> friend Matrix<_T> operator + (const _T& sum, const Matrix<_T>& mat);
		template <typename _T> friend Matrix<_T> operator - (const _T& sub, const Matrix<_T>& mat);
		template <typename _T> friend Matrix<_T> operator * (const _T& mul, const Matrix<_T>& mat);

		template <typename _T>
		friend Matrix<_T> matMul(const Matrix<_T>& matrix1, const Matrix<_T>& matrix2);
		template <typename _T>
		friend std::ostream& operator << (std::ostream& out, const Matrix<_T>& mat);

	private:
		uint _rows;
		uint _columns;
		T* _data;
	};
	template <typename T> Matrix<T> matMul(const Matrix<T>& matrix1, const Matrix<T>& matrix2);
	template <typename T> std::ostream& operator << (std::ostream& out, const Matrix<T>& mat);
	


	/*! Matrix
	* Initialize the matrix for types specifiques
	* uint rows: Quantities of rows
	* uint columns: Quantities of columns
	* MatrixType: The type of matrix (ones, zeros or identity)
	*/
	template <typename T>
	Matrix<T>::Matrix(uint rows, uint columns, const MatrixType& type)
		: _rows(0)
		, _columns(0)
		, _data(nullptr)
	{
		try
		{
			resize(rows, columns);
		}
		catch (const MatrixException& me)
		{
			throw(me);
		}

		if (_data != nullptr) {
			switch (type)
			{
			case MatrixType::IDENTITY:
				for (uint i = 0; i < _rows; i++)
					for (uint j = 0; j < _columns; j++)
						_data[j + (_columns * i)] = (i == j) ? T(1) : T(0);
				break;
			case MatrixType::ZEROS:
				std::fill(_data, _data + (_rows * _columns), T(0));
				break;
			case MatrixType::ONES:
				std::fill(_data, _data + (_rows * _columns), T(1));
				break;
			}
		}
	}
	
	/*! Matrix
	* Initialize the matrix with a array
	* uint rows: Quantities of rows
	* uint columns: Quantities of columns
	* T*: The array to be copied
	*/
	template <typename T>
	Matrix<T>::Matrix(uint rows, uint columns, const T* data)
		: _rows(0)
		, _columns(0)
		, _data(nullptr)
	{
		try
		{
			resize(rows, columns);
		}
		catch (const MatrixException& me)
		{
			throw(me);
		}

		std::copy(data, data + (_rows * _columns), _data);
	}

	/*! resize
	* Resize the quantites of rows or columns of the matrix
	* uint rows: New quantities of rows
	* uint columns: New quantities of columns
	* return: The matrix resized
	*/
	template <typename T>
	Matrix<T>& Matrix<T>::resize(uint rows, uint columns)
	{
		if (_rows >= 0 && _columns >= 0)
		{
			_rows = rows;
			_columns = columns;

			if (_data != nullptr)
				delete[] _data;

			if (_rows > 0 && _columns > 0)
				_data = new T[_rows * _columns];
			else
				_data = nullptr;
		}
		else
		{
			throw(MatrixException(MatrixExceptionType::INVALID_SIZE, _rows, _columns));
		}

		return *this;
	}
	
	/*! operator ()
	* Get the value of specific line and column
	* uint line: Indice of the line
	* uint column: Indice of the column
	* return: The value of specific line and column
	*/
	template <typename T>
	T& Matrix<T>::operator () (const uint& line, const uint& column)
	{
		if (line < 0 || line >= _rows || column < 0 || column > _columns)
			throw(MatrixException(MatrixExceptionType::INVALID_ACCESS, _rows, _columns, line, column));

		return _data[column + (_columns * line)];
	}

	/*! operator ()
	* Get the value of specific line and column
	* uint line: Indice of the line
	* uint column: Indice of the column
	* return: The value of specific line and column
	*/
	template <typename T>
	const T& Matrix<T>::operator () (const uint& line, const uint& column) const
	{
		if (line < 0 || line >= _rows || column < 0 || column >= _columns)
			throw(MatrixException(MatrixExceptionType::INVALID_ACCESS, _rows, _columns, line, column));

		return _data[column + (_columns * line)];
	}
	
	/*! operator =
	* Copy the matrix
	* Matrix<T> rec: The matrix to be copied
	* return: The matrix modified
	*/
	template <typename T>
	Matrix<T>& Matrix<T>::operator = (const Matrix<T>& rec)
	{
		try
		{
			resize(rec._rows, rec._columns);
		}
		catch (const MatrixException& me)
		{
			throw(me);
		}

		std::copy(rec._data, rec._data + (_rows * _columns), _data);

		return *this;
	}

	/*! operator +
	* Sum the matrices
	* Matrix<T> sum: Matrix to be added
	* return: The sum of the matrices
	*/
	template <typename T>
	Matrix<T> Matrix<T>::operator + (const Matrix<T>& sum)
	{
		if (_rows != sum._rows || _columns != sum._columns)
			throw(MatrixException(MatrixExceptionType::INCOMPATIBLE_SIZES, _rows, _columns, sum._rows, sum._columns, '+'));
		else if (_data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(_rows, _columns);
	
		for (uint i = 0; i < _rows; i++)
			for (uint j = 0; j < _columns; j++)
				newMatrix(i, j) = (*this)(i, j) + sum(i, j);
		
		return newMatrix;
	}
	
	/*! operator -
	* Subtract the matrices
	* Matrix<T> sub: Matrix to be subtracted
	* return: The subtract of the matrices
	*/
	template <typename T>
	Matrix<T> Matrix<T>::operator - (const Matrix<T>& sub)
	{
		if (_rows != sub._rows || _columns != sub._columns)
			throw(MatrixException(MatrixExceptionType::INCOMPATIBLE_SIZES, _rows, _columns, sub._rows, sub._columns, '-'));
		else if (_data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(_rows, _columns);
	
		for (uint i = 0; i < _rows; i++)
			for (uint j = 0; j < _columns; j++)
				newMatrix(i, j) = (*this)(i, j) - sub(i, j);
	
		return newMatrix;
	}
	
	/*! operator *
	* Multiply the matrices value to value
	* Matrix<T> mul: Matrix to be multiplied
	* return: The multiplication of the matrices
	*/
	template <typename T>
	Matrix<T> Matrix<T>::operator * (const Matrix<T>& mul)
	{
		if (_rows != mul._rows || _columns != mul._columns)
			throw(MatrixException(MatrixExceptionType::INCOMPATIBLE_SIZES, _rows, _columns, mul._rows, mul._columns, '*'));
		else if (_data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(_rows, _columns);
	
		for (uint i = 0; i < _rows; i++)
			for (uint j = 0; j < _columns; j++)
				newMatrix(i, j) = (*this)(i, j) * mul(i, j);
	
		return newMatrix;
	}
	
	/*! operator +
	* Sum the matrix with matrix identity multiplied to sum value
	* T sum: Value to be multiplied to matrix identity
	* return: The sum of the matrix with matrix identity multiplied to sum value
	*/
	template <typename T>
	Matrix<T> Matrix<T>::operator + (const T& sum)
	{
		if (_data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(_rows, _columns, _data);
	
		for (uint i = 0; i < std::min(_rows, _columns); i++)
				newMatrix(i, i) += sum;
	
		return newMatrix;
	}
	
	/*! operator -
	* Subtract the matrix with matrix identity multiplied to sub value
	* T sub: Value to be multiplied to matrix identity
	* return: The subtraction of the matrix with matrix identity multiplied to sub value
	*/
	template <typename T>
	Matrix<T> Matrix<T>::operator - (const T& sub)
	{
		if (_data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(_rows, _columns, _data);
	
		for (uint i = 0; i < std::min(_rows, _columns); i++)
			newMatrix(i, i) -= sub;
	
		return newMatrix;
	}
	
	/*! operator *
	* Multiply the matrix with mul value
	* T mul: Value to be multiplied
	* return: The multiplication of the matrix with mul value
	*/
	template <typename T>
	Matrix<T> Matrix<T>::operator * (const T& mul)
	{
		if (_data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(_rows, _columns, _data);
	
		for (uint i = 0; i < _rows; i++)
			for (uint j = 0; j < _columns; j++)
				newMatrix(i, j) *= mul;
	
		return newMatrix;
	}

	/*! transpose
	* Transpose the matrix
	* return: The mtrix transposed
	*/
	template <typename T>
	Matrix<T> Matrix<T>::transpose()
	{
		Matrix<T> newMatrix(_columns, _rows);

		for (uint i = 0; i < _columns; i++)
		{
			for (uint j = 0; j < _rows; j++)
				newMatrix(i, j) = (*this)(j, i);
		}

		return newMatrix;
	}

	/*! operator +
	* The matrix multiplied to +1
	* Matrix<T> mat: Matrix to be multiplied
	* return: The matrix multiplied to +1
	*/
	template <typename T>
	Matrix<T> operator + (const Matrix<T>& mat)
	{
		if (_data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		return mat;
	}

	/*! operator -
	* The matrix multiplied to -1
	* Matrix<T> mat: Matrix to be multiplied
	* return: The matrix multiplied to -1
	*/
	template <typename T>
	Matrix<T> operator - (const Matrix<T>& mat)
	{
		if (_data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(mat._rows, mat._columns, mat._data);

		for (uint i = 0; i < mat._rows * mat._columns; i++)
			newMatrix._data[i] = -newMatrix._data[i];

		return newMatrix;
	}

	/*! operator +
	* Sum the matrix identity multiplied to sum value with matrix mat
	* T sum: Value to be multiplied to matrix identity
	* Matrix<T> mat: Matrix to add
	* return: The sum the matrix identity multiplied to sum value with matrix mat
	*/
	template <typename T>
	Matrix<T> operator + (const T& sum, const Matrix<T>& mat)
	{
		if (mat._data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(mat._rows, mat._columns, mat._data);

		for (uint i = 0; i < std::min(newMatrix._rows, newMatrix._columns); i++)
			newMatrix(i, i) = sum + newMatrix(i, i);

		return newMatrix;
	}

	/*! operator -
	* Subtract the matrix identity multiplied to sub value with matrix mat
	* T sub: Value to be multiplied to matrix identity
	* Matrix<T> mat: Matrix to subtract
	* return: The subtraction of the matrix identity multiplied to sub value with matrix mat
	*/
	template <typename T>
	Matrix<T> operator - (const T& sub, const Matrix<T>& mat)
	{
		if (mat._data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(mat._rows, mat._columns, mat._data);

		for (uint i = 0; i < std::min(newMatrix._rows, newMatrix._columns); i++)
			newMatrix(i, i) = sub - newMatrix(i, i);

		return newMatrix;
	}

	/*! operator *
	* Multiply the mul value to matrix mat
	* T mul: Value to be multiplied
	* Matrix<T> mat: Matrix to be multiplied
	* return: The multiplication of the mul value to matrix
	*/
	template <typename T>
	Matrix<T> operator * (const T& mul, const Matrix<T>& mat)
	{
		if (_data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(mat._rows, mat._columns, mat._data);

		for (uint i = 0; i < newMatrix._rows; i++)
			for (uint j = 0; j < newMatrix._columns; j++)
				newMatrix(i, j) = mul * newMatrix(i, j);

		return newMatrix;
	}
	
	/*! matMul
	* Matrices multiplication
	* Matrix<T> matrix1: Matrix to multiply
	* Matrix<T> matrix2: Matrix to multiply
	* return: The matrix of multiplication of matrices
	*/
	template <typename T>
	Matrix<T> matMul(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
	{
		if (matrix1._columns != matrix2._rows)
			throw(MatrixException(MatrixExceptionType::INCOMPATIBLE_SIZES, matrix1._rows, matrix1._columns, matrix2._rows, matrix2._columns, 'X'));
		else if (matrix1._data == nullptr || matrix2._data == nullptr)
			throw(MatrixException(MatrixExceptionType::MATRIX_NOT_INITIALIZED));

		Matrix<T> newMatrix(matrix1._rows, matrix2._columns);
	
		for (uint i = 0; i < matrix1._rows; i++)
		{
			for (uint j = 0; j < matrix2._columns; j++)
			{
				for (uint k = 0; k < matrix1._columns; k++)
				{
					newMatrix(i, j) += matrix1(i, k) * matrix2(k, j);
				}
			}
		}
	
		return newMatrix;
	}

	/*! operator <<
	* Shows the matrix in console
	* ostream out: Output stream
	* Matrix<T> mat: Matrix to show
	* return: Output stream
	*/
	template <typename T>
	std::ostream& operator << (std::ostream& out, const Matrix<T>& mat)
	{
		out << std::endl;
		
		if (mat._rows * mat._columns == 0)
		{
			out << "Matrix not initialized!";
		}
		else
		{
			for (uint i = 0; i < mat._rows; i++)
			{
				out << "[ " << mat(i, 0);
				for (uint j = 1; j < mat._columns; j++)
				{
					out << ", " << mat(i, j);
				}
				out << " ]" << std::endl;
			}
		}

		return out;
	}

}

#endif
