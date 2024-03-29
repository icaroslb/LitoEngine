#ifndef MATRIZ_3_H
#define MATRIZ_3_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include "MatrixEnum.hpp"
#include "Vec_3.hpp"

namespace lito {

	template <class T>
	class Matriz_3 {
	public:
		T _val[9];
	
		Matriz_3<T> ( T valor = 0 );
		Matriz_3<T> ( const MatrixType &tipo );
		Matriz_3<T> ( T v0, T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8 );
		Matriz_3<T> ( const T *valor );
		Matriz_3<T> ( const Matriz_3<T> &m );
		
		inline       T& operator () ( const size_t &line, const size_t &column );
		inline const T& operator () ( const size_t &line, const size_t &column ) const;
		inline       T& operator [] ( const size_t &pos );
		inline const T& operator [] ( const size_t &pos ) const;
		
		Matriz_3<T>  operator  + ( const Matriz_3<T> &m );
		Matriz_3<T>  operator  - ( const Matriz_3<T> &m );
		Matriz_3<T>  operator  * ( const Matriz_3<T> &m );
		Vec_3<T>     operator  * ( const Vec_3<T> &v );
		Matriz_3<T>  operator  + ( T c );
		Matriz_3<T>  operator  - ( T c );
		Matriz_3<T>  operator  * ( T c );
		Matriz_3<T>  operator  / ( T c );
		
		Matriz_3<T>& operator  = ( const Matriz_3<T> &m );
		Matriz_3<T>& operator += ( const Matriz_3<T> &m );
		Matriz_3<T>& operator -= ( const Matriz_3<T> &m );
		Matriz_3<T>& operator *= ( const Matriz_3<T> &m );
		Matriz_3<T>& operator += ( T c );
		Matriz_3<T>& operator -= ( T c );
		Matriz_3<T>& operator *= ( T c );
		Matriz_3<T>& operator /= ( T c );
		
		Matriz_3<T> transposta ();
	};
	
	typedef Matriz_3<float>  Matriz_3f;
	typedef Matriz_3<double> Matriz_3d;
	
	template <class T> Matriz_3<T>  operator + ( const Matriz_3<T> &mat );
	template <class T> Matriz_3<T>  operator - ( const Matriz_3<T> &mat );
	template <class T> Matriz_3<T>  operator + ( T c , const Matriz_3<T> &mat );
	template <class T> Matriz_3<T>  operator - ( T c , const Matriz_3<T> &mat );
	template <class T> Matriz_3<T>  operator * ( T c , const Matriz_3<T> &mat );
	
	template <class T> Matriz_3<T>& operator << ( Matriz_3<T> &mat, T dado );
	template <class T> Matriz_3<T>& operator ,  ( Matriz_3<T> &mat, T dado );
	template <class T> std::ostream& operator << ( std::ostream &out, const Matriz_3<T> &mat );
	template <class T> Matriz_3<T> translacao ( T x, T y, T z );
	
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	
	template <class T>
	Matriz_3<T>::Matriz_3 ( T valor )
	{
		std::fill( _val, ( _val + 9 ), valor );
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T>::Matriz_3 ( const MatrixType &tipo )
	{
		switch ( tipo ) {
			case MatrixType::IDENTITY :
				std::fill( _val, ( _val + 9 ), 0 );
				_val[0] = 1;
				_val[4] = 1;
				_val[8] = 1;
			break;
			case MatrixType::ZEROS :
				std::fill( _val, ( _val + 9 ), 0 );
			break;
			case MatrixType::ONES :
				std::fill( _val, ( _val + 9 ), 1 );
			break;
			default: break;
		}
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T>::Matriz_3 ( T v0, T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8 )
	{
		_val[0]  = v0;
		_val[1]  = v1;
		_val[2]  = v2;
		_val[3]  = v3;
		_val[4]  = v4;
		_val[5]  = v5;
		_val[6]  = v6;
		_val[7]  = v7;
		_val[8]  = v8;
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T>::Matriz_3( const T *valor )
	{
		memcpy( _val, valor, sizeof(T) * 9 );
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T>::Matriz_3 ( const Matriz_3<T> &m )
	{
		*this = m;
	}
	/*===============================================================================================================================*/
	template <class T>
	T& Matriz_3<T>::operator () ( const size_t &line,  const size_t &column )
	{
		return _val[ ( line * 3 ) + column ];
	}
	/*===============================================================================================================================*/
	template <class T>
	const T& Matriz_3<T>::operator () ( const size_t &line,  const size_t &column ) const
	{
		return _val[ ( line * 3 ) + column ];
	}
	/*===============================================================================================================================*/
	template <class T>
	T& Matriz_3<T>::operator [] ( const size_t &pos )
	{
		
		return _val[ pos ];
	}
	/*===============================================================================================================================*/
	template <class T>
	const T& Matriz_3<T>::operator [] ( const size_t &pos ) const
	{
		
		return _val[ pos ];
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T> Matriz_3<T>::operator + ( const Matriz_3<T> &m ) {
		Matriz_3<T> mat;
		
		for ( size_t i = 0; i < 9; i++ ) {
			mat._val[i] = _val[i] + m._val[i];
		}
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T> Matriz_3<T>::operator - ( const Matriz_3<T> &m ) {
		Matriz_3<T> mat;
		
		for ( size_t i = 0; i < 9; i++ ) {
			mat._val[i] = _val[i] - m._val[i];
		}
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T> Matriz_3<T>::operator * ( const Matriz_3<T> &m ) {
		Matriz_3<T> mat;
		
		for ( size_t i = 0; i < 3; i++ ) {
			for ( size_t j = 0; j < 3; j++ ) {
				for ( size_t k = 0; k < 3; k++ ) {
					mat._val[ ( i * 3 ) + j ] += _val [ ( i * 3 ) + k ] * m._val[ j + ( k * 3 ) ];
				}
			}
		}
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Vec_3<T> Matriz_3<T>::operator * ( const Vec_3<T> &v ) {
		Vec_3<T> vet;
		
		vet._x = ( _val[ 0 ] * v._x ) + ( _val[ 1 ] * v._y ) + ( _val[ 2 ] * v._z );
		vet._y = ( _val[ 3 ] * v._x ) + ( _val[ 4 ] * v._y ) + ( _val[ 5 ] * v._z );
		vet._z = ( _val[ 6 ] * v._x ) + ( _val[ 7 ] * v._y ) + ( _val[ 8 ] * v._z );
		
		return vet;
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T> Matriz_3<T>::operator + ( T c ) {
		Matriz_3<T> mat( _val );
		
		for ( size_t i = 0; i < 9; i += 4 ) {
			mat._val[i] = _val[i] + c;
		}
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T> Matriz_3<T>::operator - ( T c ) {
		Matriz_3<T> mat( _val );
		
		for ( size_t i = 0; i < 9; i += 4 ) {
			mat._val[i] = _val[i] - c;
		}
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T> Matriz_3<T>::operator * ( T c ) {
		Matriz_3<T> mat;
		
		for ( size_t i = 0; i < 9; i++ ) {
			mat._val[i] = _val[i] * c;
		}
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T> Matriz_3<T>::operator / ( T c ) {
		Matriz_3<T> mat;
		c = T(1) / c;
		
		for ( size_t i = 0; i < 9; i++ ) {
			mat._val[i] = _val[i] * c;
		}
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T>& Matriz_3<T>::operator = ( const Matriz_3<T> &m ) {
		memcpy( _val, m._val, sizeof(T) * 9);
		
		return *this;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T>& Matriz_3<T>::operator += ( const Matriz_3<T> &m ) {
		for ( size_t i = 0; i < 9; i += 4 ) {
			_val[i] += m._val[i];
		}
		
		return *this;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T>& Matriz_3<T>::operator -= ( const Matriz_3<T> &m ) {
		for ( size_t i = 0; i < 9; i += 4 ) {
			_val[i] -= m._val[i];
		}
		
		return *this;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T>& Matriz_3<T>::operator *= ( const Matriz_3<T> &m ) {
		Matriz_3<T> mat;
		
		for ( size_t i = 0; i < 3; i++ ) {
			for ( size_t j = 0; j < 3; j++ ) {
				for ( size_t k = 0; k < 3; k++ ) {
					mat._val[ ( i * 3 ) + j ] += _val [ ( i * 3 ) + k ] * m._val[ j + ( k * 3 ) ];
				}
			}
		}
		
		*this = mat;
		
		return *this;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T>& Matriz_3<T>::operator += ( T c ) {
		for ( size_t i = 0; i < 9; i += 4 ) {
			_val[i] += c;
		}
		
		return *this;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T>& Matriz_3<T>::operator -= ( T c ) {
		for ( size_t i = 0; i < 9; i += 4 ) {
			_val[i] -= c;
		}
		
		return *this;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T>& Matriz_3<T>::operator *= ( T c ) {
		for ( size_t i = 0; i < 9; i++ ) {
			_val[i] *= c;
		}
		
		return *this;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T>& Matriz_3<T>::operator /= ( T c ) {
		c =  T(1) / c;
		
		for ( size_t i = 0; i < 9; i++ ) {
			_val[i] *= c;
		}
		
		return *this;
	}
	/*===============================================================================================================================*/
	template <class T>
	Matriz_3<T> Matriz_3<T>::transposta () {
		Matriz_3<T> t;
		
		for ( size_t i = 0; i < 3; i++ ) {
			for ( size_t j = 0; j < 3; j++ ) {
				t._val[( i * 3 ) + j] = _val[i + ( j * 3 )];
			}
		}
		
		return transposta;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T> operator + ( const Matriz_3<T> &m ) {
		return m;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T> operator - ( const Matriz_3<T> &m ) {
		Matriz_3<T> mat;
	
		for ( size_t i = 0; i < 9; i++ )
			mat._val[i] = -m._val[i];
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T> operator + ( T c , const Matriz_3<T> &m ) {
		Matriz_3<T> mat( m._val );
	
		for ( size_t i = 0; i < 9; i += 4 )
			mat._val[i] = c + m._val[i];
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T> operator - ( T c , const Matriz_3<T> &m ) {
		Matriz_3<T> mat;
	
		for ( size_t i = 0; i < 9; i++ )
			mat._val[i] = c - m._val[i];
	
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T> operator * ( T c , const Matriz_3<T> &m ) {
		Matriz_3<T> mat;
		
		for ( size_t i = 0; i < 9; i++ )
			mat._val[i] = c * m._val[i];
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T>& operator << ( Matriz_3<T> &mat, T dado ) {
		
		mat._val[0] = dado;
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>	
	Matriz_3<T>& operator , ( Matriz_3<T> &mat, T dado ) {
		static size_t indice = 1;
		static auto   id_matriz  = &mat;
		
		if ( id_matriz != &mat ) {
			indice = 1;
			id_matriz = &mat;
		}
		
		mat._val[indice] = dado;
		
		indice++;
		indice = indice % 9;
		
		return mat;
	}
	/*===============================================================================================================================*/
	template <class T>	
	std::ostream& operator << ( std::ostream &out, const Matriz_3<T> &mat ) {
		out << std::endl;
		for ( size_t i = 0; i < 3; i++ ) {
			out << "[ " << mat._val[i * 3];
			for ( size_t j = 1; j < 3; j++ ) {
				out << ", " << mat._val[( i * 3 ) + j];
			}
			out << " ]" << std::endl;
		}
		
		return out;
	}
	/*===============================================================================================================================*/


}

#endif
