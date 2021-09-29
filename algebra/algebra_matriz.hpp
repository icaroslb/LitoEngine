#ifndef ALGEBRA_MATRIZ_H
#define ALGEBRA_MATRIZ_H

#include <cmath>

#include "Matriz_2.hpp"
#include "Matriz_3.hpp"
#include "Matriz_4.hpp"

namespace lito {

	template <class T> T determinant ( const Matriz_2<T> &m );
	template <class T> T determinant ( const Matriz_3<T> &m );
	template <class T> T determinant ( const Matriz_4<T> &m );
	
	template <class T> Matriz_2<T> transpose ( const Matriz_2<T> &m );
	template <class T> Matriz_3<T> transpose ( const Matriz_3<T> &m );
	template <class T> Matriz_4<T> transpose ( const Matriz_4<T> &m );
	
	template <class T> T cofactor ( const Matriz_2<T> &m, size_t i, size_t j );
	template <class T> T cofactor ( const Matriz_3<T> &m, size_t i, size_t j );
	template <class T> T cofactor ( const Matriz_4<T> &m, size_t i, size_t j );
	
	template <class T> T cofactor ( const Matriz_2<T> &m, size_t id );
	template <class T> T cofactor ( const Matriz_3<T> &m, size_t id );
	template <class T> T cofactor ( const Matriz_4<T> &m, size_t id );
	
	template <class T> Matriz_2<T> invert ( const Matriz_2<T> &m );
	template <class T> Matriz_3<T> invert ( const Matriz_3<T> &m );
	template <class T> Matriz_4<T> invert ( const Matriz_4<T> &m );
	
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	
	
	/*! determinant
	* Calculate the determinant of matrix 2x2
	* Matriz_2<T> m: Matrix 2x2
	* return: Determinant of m
	*/
	template <class T>
	T determinant ( const Matriz_2<T> &m )
	{
		return ( m._val[0] * m._val[3] ) - ( m._val[1] * m._val[2] );
	}
	
	/*! determinant
	* Calculate the determinant of matrix 3x3
	* Matriz_3<T> m: Matrix 3x3
	* return: Determinant of m
	*/
	template <class T>
	T determinant ( const Matriz_3<T> &m )
	{
		return   ( m._val[0] * m._val[4] * m._val[8] )
		       + ( m._val[3] * m._val[7] * m._val[2] )
		       + ( m._val[6] * m._val[1] * m._val[5] )
		       - ( m._val[6] * m._val[4] * m._val[2] )
		       - ( m._val[0] * m._val[7] * m._val[5] )
		       - ( m._val[3] * m._val[1] * m._val[8] );
	}
	
	/*! determinant
	* Calculate the determinant of matrix 4x4
	* Matriz_4<T> m: Matrix 4x4
	* return: Determinant of m
	*/
	template <class T>
	T determinant ( const Matriz_4<T> &m )
	{
		return ;
	}
	
	/*! transpose
	* Calculate the transposed matrix of matrix 2x2
	* Matriz_2<T> m: Matrix 2x2
	* return: m transposed
	*/
	template <class T>
	Matriz_2<T> transpose ( const Matriz_2<T> &m ) {
		Matriz_2<T> trasnpo;
		
		for ( int i = 0; i < 2; i++ ) {
			for ( int j = 0; j < 2; j++ ) {
				trasnpo._val[( i * 2 ) + j] = m._val[i + ( j * 2 )];
			}
		}
		
		return trasnpo;
	}
	
	/*! transpose
	* Calculate the transposed matrix of matrix 3x3
	* Matriz_3<T> m: Matrix 3x3
	* return: m transposed
	*/
	template <class T>
	Matriz_3<T> transpose ( const Matriz_3<T> &m )
	{
		Matriz_3<T> trasnpo;
		
		for ( int i = 0; i < 3; i++ ) {
			for ( int j = 0; j < 3; j++ ) {
				trasnpo._val[( i * 3 ) + j] = m._val[i + ( j * 3 )];
			}
		}
		
		return trasnpo;
	}
	
	/*! transpose
	* Calculate the transposed matrix of matrix 4x4
	* Matriz_4<T> m: Matrix 4x4
	* return: m transposed
	*/
	template <class T>
	Matriz_4<T> transpose ( const Matriz_4<T> &m )
	{
		Matriz_4<T> trasnpo;
		
		for ( int i = 0; i < 4; i++ ) {
			for ( int j = 0; j < 4; j++ ) {
				trasnpo._val[( i * 4 ) + j] = m._val[i + ( j * 4 )];
			}
		}
		
		return trasnpo;
	}
	
	/*! cofactores
	* Calculate the cofactor matrix
	* Matriz_2<T> m: Matrix 2x2
	* return: Cofactor matrix
	*/
	template <class T>
	Matriz_2<T> cofactores ( const Matriz_2<T> &m, size_t i, size_t j ) {
		( ( i % 2 ) == 0 ) ? i++ : i-- ;
		( ( j % 2 ) == 0 ) ? j++ : j-- ;
		
		return ( ( ( i + j ) % 2 ) == 0 ) ? +m._val[i + ( j * 2 )] : -m._val[i + ( j * 2 )];
	}
	
	/*! cofactores
	* Calculate the cofactor matrix
	* Matriz_3<T> m: Matrix 3x3
	* return: Cofactor matrix
	*/
	template <class T>
	T cofactor ( const Matriz_3<T> &m, size_t i, size_t j )
	{
		
	}
	
	/*! cofactores
	* Calculate the cofactor matrix
	* Matriz_4<T> m: Matrix 4x4
	* return: Cofactor matrix
	*/
	template <class T>
	T cofactor ( const Matriz_4<T> &m, size_t i, size_t j )
	{
	
	}
	
	/*! cofactor
	* Calculate the cofactor of id in matrix
	* Matriz_2<T> m: Matrix 2x2
	* size_t id: Id of the cofactor
	* return: The value of cofactor
	*/
	template <class T>
	T cofactor ( const Matriz_2<T> &m, size_t id )
	{
		switch ( id ) {
			case 0:
				return +m._val[3];
			break;
			case 1:
				return -m._val[2];
			break;
			case 2:
				return -m._val[1];
			break;
			case 3:
				return +m._val[0];
			break;
			default: break;
		}
		
		return T(0);
	}
	
	/*! cofactor
	* Calculate the cofactor of id in matrix
	* Matriz_3<T> m: Matrix 3x3
	* size_t id: Id of the cofactor
	* return: The value of cofactor
	*/
	template <class T>
	T cofactor ( const Matriz_3<T> &m, size_t id )
	{
		switch ( id ) {
			case 0:
				return +determinant( Matriz_2<T>( m._val[4], m._val[5],
				                                   m._val[7], m._val[8] ) );
			break;
			case 1:
				return -determinant( Matriz_2<T>( m._val[3], m._val[5],
				                                   m._val[6], m._val[8] ) );
			break;
			case 2:
				return +determinant( Matriz_2<T>( m._val[3], m._val[4],
				                                   m._val[6], m._val[7] ) );
			break;
			case 3:
				return -determinant( Matriz_2<T>( m._val[1], m._val[2],
				                                   m._val[7], m._val[8] ) );
			break;
			case 4:
				return +determinant( Matriz_2<T>( m._val[0], m._val[2],
				                                   m._val[6], m._val[8] ) );
			break;
			case 5:
				return -determinant( Matriz_2<T>( m._val[0], m._val[1],
				                                   m._val[6], m._val[7] ) );
			break;
			case 6:
				return +determinant( Matriz_2<T>( m._val[1], m._val[2],
				                                   m._val[4], m._val[5] ) );
			break;
			case 7:
				return -determinant( Matriz_2<T>( m._val[0], m._val[2],
				                                   m._val[3], m._val[5] ) );
			break;
			case 8:
				return +determinant( Matriz_2<T>( m._val[0], m._val[1],
				                                   m._val[3], m._val[4] ) );
			break;
			default: break;
		}
		
		return T(0);
	}
	
	/*! cofactor
	* Calculate the cofactor of id in matrix
	* Matriz_4<T> m: Matrix 4x4
	* size_t id: Id of the cofactor
	* return: The value of cofactor
	*/
	template <class T>
	T cofactor ( const Matriz_4<T> &m, size_t id )
	{
		switch ( id ) {
			case 0:
				return +determinant( Matriz_3<T>( m._val[5],  m._val[6],  m._val[7],
				                                   m._val[9],  m._val[10], m._val[11],
				                                   m._val[13], m._val[14], m._val[15] ) );
			break;
			case 1:
				return -determinant( Matriz_3<T>( m._val[4],  m._val[6],  m._val[7],
				                                   m._val[8],  m._val[10], m._val[11],
				                                   m._val[12], m._val[14], m._val[15] ) );
			break;
			case 2:
				return +determinant( Matriz_3<T>( m._val[4],  m._val[5],  m._val[7],
				                                   m._val[8],  m._val[9],  m._val[11],
				                                   m._val[12], m._val[13], m._val[15] ) );
			break;
			case 3:
				return -determinant( Matriz_3<T>( m._val[4],  m._val[5],  m._val[6],
				                                   m._val[8],  m._val[9],  m._val[10],
				                                   m._val[12], m._val[13], m._val[14] ) );
			break;
			case 4:
				return -determinant( Matriz_3<T>( m._val[1],  m._val[2],  m._val[3],
				                                   m._val[9],  m._val[10], m._val[11],
				                                   m._val[13], m._val[14], m._val[15] ) );
			break;
			case 5:
				return +determinant( Matriz_3<T>( m._val[0],  m._val[2],  m._val[3],
				                                   m._val[8],  m._val[10], m._val[11],
				                                   m._val[12], m._val[14], m._val[15] ) );
			break;
			case 6:
				return -determinant( Matriz_3<T>( m._val[0],  m._val[1],  m._val[3],
				                                m._val[8],  m._val[9],  m._val[11],
				                                m._val[12], m._val[13], m._val[15] ) );
			break;
			case 7:
				return +determinant( Matriz_3<T>( m._val[0],  m._val[1],  m._val[2],
				                                   m._val[8],  m._val[9],  m._val[10],
				                                   m._val[12], m._val[13], m._val[14] ) );
			break;
			case 8:
				return +determinant( Matriz_3<T>( m._val[1],  m._val[2],  m._val[3],
				                                   m._val[5],  m._val[6],  m._val[7],
				                                   m._val[13], m._val[14], m._val[15] ) );
			break;
			case 9:
				return -determinant( Matriz_3<T>( m._val[0],  m._val[2],  m._val[3],
				                                   m._val[4],  m._val[6],  m._val[7],
				                                   m._val[12], m._val[14], m._val[15] ) );
			break;
			case 10:
				return +determinant( Matriz_3<T>( m._val[0],  m._val[1],  m._val[3],
				                                   m._val[4],  m._val[5],  m._val[7],
				                                   m._val[12], m._val[13], m._val[15] ) );
			break;
			case 11:
				return -determinant( Matriz_3<T>( m._val[0],  m._val[1],  m._val[2],
				                                m._val[4],  m._val[5],  m._val[6],
				                                m._val[12], m._val[13], m._val[14] ) );
			break;
			case 12:
				return -determinant( Matriz_3<T>( m._val[1], m._val[2],  m._val[3],
				                                m._val[5], m._val[6],  m._val[7],
				                                m._val[9], m._val[10], m._val[11] ) );
			break;
			case 13:
				return +determinant( Matriz_3<T>( m._val[0], m._val[2],  m._val[3],
				                                   m._val[4], m._val[6],  m._val[7],
				                                   m._val[8], m._val[10], m._val[11] ) );
			break;
			case 14:
				return -determinant( Matriz_3<T>( m._val[0], m._val[1], m._val[3],
				                                   m._val[4], m._val[5], m._val[7],
				                                   m._val[8], m._val[9], m._val[11] ) );
			break;
			case 15:
				return +determinant( Matriz_3<T>( m._val[0], m._val[1], m._val[2],
				                                   m._val[4], m._val[5], m._val[6],
				                                   m._val[8], m._val[9], m._val[10] ) );
			break;
			default: break;
		}
		
		return T(0);
	}
	
	/*! invert
	* Calculate the inverted matrix
	* Matriz_2<T> m: Matrix to be inverted
	* return: The inverted matrix
	*/
	template <class T>
	Matriz_2<T> invert ( const Matriz_2<T> &m )
	{
		Matriz_2<T> inver;
		T constante;
		
		if ( ( constante = determinant( m ) ) != T(0) ) {
			constante = T(1) / constante;
			
			inver._val[0] = constante *  m._val[3];
			inver._val[1] = constante * -m._val[1];
			inver._val[2] = constante * -m._val[2];
			inver._val[3] = constante *  m._val[0];
		}
		
		return inver;
	}
	
	/*! invert
	* Calculate the inverted matrix
	* Matriz_3<T> m: Matrix to be inverted
	* return: The inverted matrix
	*/
	template <class T>
	Matriz_3<T> invert ( const Matriz_3<T> &m )
	{
	}
	
	/*! invert
	* Calculate the inverted matrix
	* Matriz_4<T> m: Matrix to be inverted
	* return: The inverted matrix
	*/
	template <class T>
	Matriz_4<T> invert ( const Matriz_4<T> &m )
	{
	}


}

#endif
