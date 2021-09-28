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
		MatrixException (MatrixExceptionType exceptionType, uint rowFirst, uint columnFirst, uint rowSecond, uint columnSecond, char operation = ' ')
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
				std::cerr << "Invalid access for matrix( " << _rowFirst << ", " << _columnFirst
					      << " ):  possition accessed was ( " << _rowSecond << ", " << _columnSecond << " )!" << std::endl;
				break;
			case MatrixExceptionType::INCOMPATIBLE_SIZES:
				std::cerr << "Invalid sizes for " << _operation
					      <<    " operation: M1( " << _rowFirst  << ", " << _columnFirst  << " ) "
					      << _operation << " M2( " << _rowSecond << ", " << _columnSecond << " )!" << std::endl;
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
	
	template <typename T>
	Matrix<T>::Matrix(uint rows, uint columns, const MatrixType& type)
	{
		_data = nullptr;

		resize(rows, columns);

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
	
	template <typename T>
	Matrix<T>::Matrix(uint rows, uint columns, const T* data)
	{
		_data = nullptr;

		resize(rows, columns);

		std::copy(data, data + (_rows * _columns), _data);
	}

	template <typename T>
	Matrix<T>& Matrix<T>::resize(uint rows, uint columns)
	{
		_rows = rows;
		_columns = columns;

		if (_data != nullptr)
			delete[] _data;

		if (_rows * _columns > 0)
			_data = new T[_rows * _columns];

		return *this;
	}
	
	template <typename T>
	T& Matrix<T>::operator () (const uint& line, const uint& column)
	{
		if (line < 0 || line >= _rows || column < 0 || column > _columns)
			throw(MatrixException(MatrixExceptionType::INVALID_ACCESS, _rows, _columns, line, column));

		return _data[column + (_columns * line)];
	}

	template <typename T>
	const T& Matrix<T>::operator () (const uint& line, const uint& column) const
	{
		if (line < 0 || line >= _rows || column < 0 || column >= _columns)
			throw(MatrixException(MatrixExceptionType::INVALID_ACCESS, _rows, _columns, line, column));

		return _data[column + (_columns * line)];
	}
	
	template <typename T>
	Matrix<T>& Matrix<T>::operator = (const Matrix<T>& rec)
	{
		resize(rec._rows, rec._columns);

		std::copy(rec._data, rec._data + (_rows * _columns), _data);

		return *this;
	}

	template <typename T>
	Matrix<T> Matrix<T>::operator + (const Matrix<T>& sum)
	{
		if (_rows != sum._rows || _columns != sum._columns)
			throw(MatrixException(MatrixExceptionType::INCOMPATIBLE_SIZES, _rows, _columns, sum._rows, sum._columns, '+'));

		Matrix<T> newMatrix(_rows, _columns);
	
		for (uint i = 0; i < _rows; i++)
			for (uint j = 0; j < _columns; j++)
				newMatrix(i, j) = (*this)(i, j) + sum(i, j);
		
		return newMatrix;
	}
	
	template <typename T>
	Matrix<T> Matrix<T>::operator - (const Matrix<T>& sub)
	{
		if (_rows != sub._rows || _columns != sub._columns)
			throw(MatrixException(MatrixExceptionType::INCOMPATIBLE_SIZES, _rows, _columns, sub._rows, sub._columns, '-'));

		Matrix<T> newMatrix(_rows, _columns);
	
		for (uint i = 0; i < _rows; i++)
			for (uint j = 0; j < _columns; j++)
				newMatrix(i, j) = (*this)(i, j) - sub(i, j);
	
		return newMatrix;
	}
	
	template <typename T>
	Matrix<T> Matrix<T>::operator * (const Matrix<T>& mul)
	{
		if (_rows != mul._rows || _columns != mul._columns)
			throw(MatrixException(MatrixExceptionType::INCOMPATIBLE_SIZES, _rows, _columns, mul._rows, mul._columns, '*'));

		Matrix<T> newMatrix(_rows, _columns);
	
		for (uint i = 0; i < _rows; i++)
			for (uint j = 0; j < _columns; j++)
				newMatrix(i, j) = (*this)(i, j) * mul(i, j);
	
		return newMatrix;
	}
	
	template <typename T>
	Matrix<T> Matrix<T>::operator + (const T& sum)
	{
		Matrix<T> newMatrix(_rows, _columns, _data);
	
		for (uint i = 0; i < std::min(_rows, _columns); i++)
				newMatrix(i, i) += sum;
	
		return newMatrix;
	}
	
	template <typename T>
	Matrix<T> Matrix<T>::operator - (const T& sub)
	{
		Matrix<T> newMatrix(_rows, _columns, _data);
	
		for (uint i = 0; i < std::min(_rows, _columns); i++)
			newMatrix(i, i) -= sub;
	
		return newMatrix;
	}
	
	template <typename T>
	Matrix<T> Matrix<T>::operator * (const T& mul)
	{
		Matrix<T> newMatrix(_rows, _columns, _data);
	
		for (uint i = 0; i < _rows; i++)
			for (uint j = 0; j < _columns; j++)
				newMatrix(i, j) *= mul;
	
		return newMatrix;
	}
	
	template <typename T>
	Matrix<T> matMul(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
	{
		if (matrix1._columns != matrix2._rows)
			throw(MatrixException(MatrixExceptionType::INCOMPATIBLE_SIZES, matrix1._rows, matrix1._columns, matrix2._rows, matrix2._columns, 'X'));

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
				out << " ]";
			}
		}

		return out << std::endl;
	}

}

#endif
