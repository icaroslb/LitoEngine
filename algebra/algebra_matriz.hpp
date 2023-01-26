#ifndef ALGEBRA_MATRIZ_H
#define ALGEBRA_MATRIZ_H

#include <cmath>
#include <string>

#include "Matriz_2.hpp"
#include "Matriz_3.hpp"
#include "Matriz_4.hpp"

namespace lito {

	class MatrixException : public std::exception
	{
	public:
		MatrixException ( std::string e ) : error( e ) {}
		void showExeception ()       { std::cerr << error << std::endl; }
		void showExeception () const { std::cerr << error << std::endl; }

	private:
		std::string error;
	};

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
		return ( m[0] * m[3] ) - ( m[1] * m[2] );
	}
	
	/*! determinant
	* Calculate the determinant of matrix 3x3
	* Matriz_3<T> m: Matrix 3x3
	* return: Determinant of m
	*/
	template <class T>
	T determinant ( const Matriz_3<T> &m )
	{
		return ( m( 0, 0 ) * ( ( m( 1, 1 ) * m( 2, 2 ) ) - ( m( 1, 2 ) * m( 2, 1 ) ) ) )
		     - ( m( 0, 1 ) * ( ( m( 1, 0 ) * m( 2, 2 ) ) - ( m( 1, 2 ) * m( 2, 0 ) ) ) )
		     + ( m( 0, 2 ) * ( ( m( 1, 0 ) * m( 2, 1 ) ) - ( m( 1, 1 ) * m( 2, 0 ) ) ) );
	}
	
	/*! determinant
	* Calculate the determinant of matrix 4x4
	* Matriz_4<T> m: Matrix 4x4
	* return: Determinant of m
	*/
	template <class T>
	T determinant ( const Matriz_4<T> &m )
	{
		// [ 0  1  2  3  ]
		// [ 4  5  6  7  ]
		// [ 8  9  10 11 ]
		// [ 12 13 14 15 ]
		
		T A = ( m[10] * m[15] ) - ( m[11] * m[14] );
		T B = ( m[9 ] * m[15] ) - ( m[11] * m[13] );
		T C = ( m[9 ] * m[14] ) - ( m[10] * m[13] );
		T D = ( m[8 ] * m[15] ) - ( m[11] * m[12] );
		T E = ( m[8 ] * m[14] ) - ( m[10] * m[12] );
		T F = ( m[8 ] * m[13] ) - ( m[9 ] * m[12] );
		
		return ( m[0] * ( ( m[5] * A ) - ( m[6] * B ) + ( m[7] * C ) ) )
			 - ( m[1] * ( ( m[4] * A ) - ( m[6] * D ) + ( m[7] * E ) ) )
			 + ( m[2] * ( ( m[4] * B ) - ( m[5] * D ) + ( m[7] * F ) ) )
			 - ( m[3] * ( ( m[4] * C ) - ( m[5] * E ) + ( m[6] * F ) ) );
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
				trasnpo[( i * 2 ) + j] = m[i + ( j * 2 )];
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
				trasnpo[( i * 3 ) + j] = m[i + ( j * 3 )];
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
				trasnpo[( i * 4 ) + j] = m[i + ( j * 4 )];
			}
		}
		
		return trasnpo;
	}
	
	/*! cofactor
	* Calculate the cofactor matrix
	* Matriz_2<T> m: Matrix 2x2
	* return: Cofactor matrix
	*/
	template <class T>
	Matriz_2<T> cofactor ( const Matriz_2<T> &m, size_t i, size_t j ) {
		//( ( i % 2 ) == 0 ) ? i++ : i-- ;
		//( ( j % 2 ) == 0 ) ? j++ : j-- ;
		//
		//return ( ( ( i + j ) % 2 ) == 0 ) ? +m( ( i + 1 ) % 2, ( j + 1 ) % 2 )
		//                                  : -m( ( i + 1 ) % 2, ( j + 1 ) % 2 );

		return cofactor( m , ( ( i * 2 ) + j ) );
	}
	
	/*! cofactor
	* Calculate the cofactor matrix
	* Matriz_3<T> m: Matrix 3x3
	* return: Cofactor matrix
	*/
	template <class T>
	T cofactor ( const Matriz_3<T> &m, size_t i, size_t j )
	{
		return cofactor( m , ( ( i * 3 ) + j ) );
	}
	
	/*! cofactor
	* Calculate the cofactor matrix
	* Matriz_4<T> m: Matrix 4x4
	* return: Cofactor matrix
	*/
	template <class T>
	T cofactor ( const Matriz_4<T> &m, size_t i, size_t j )
	{
		return cofactor( m , ( ( i * 4 ) + j ) );
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
				return +m[3];
			break;
			case 1:
				return -m[2];
			break;
			case 2:
				return -m[1];
			break;
			case 3:
				return +m[0];
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
				return +determinant( Matriz_2<T>( m[4], m[5],
				                                  m[7], m[8] ) );
			break;
			case 1:
				return -determinant( Matriz_2<T>( m[3], m[5],
				                                  m[6], m[8] ) );
			break;
			case 2:
				return +determinant( Matriz_2<T>( m[3], m[4],
				                                  m[6], m[7] ) );
			break;
			case 3:
				return -determinant( Matriz_2<T>( m[1], m[2],
				                                  m[7], m[8] ) );
			break;
			case 4:
				return +determinant( Matriz_2<T>( m[0], m[2],
				                                  m[6], m[8] ) );
			break;
			case 5:
				return -determinant( Matriz_2<T>( m[0], m[1],
				                                  m[6], m[7] ) );
			break;
			case 6:
				return +determinant( Matriz_2<T>( m[1], m[2],
				                                  m[4], m[5] ) );
			break;
			case 7:
				return -determinant( Matriz_2<T>( m[0], m[2],
				                                  m[3], m[5] ) );
			break;
			case 8:
				return +determinant( Matriz_2<T>( m[0], m[1],
				                                  m[3], m[4] ) );
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
				return +determinant( Matriz_3<T>( m[5 ], m[6 ], m[7 ],
				                                  m[9 ], m[10], m[11],
				                                  m[13], m[14], m[15] ) );
			break;
			case 1:
				return -determinant( Matriz_3<T>( m[4 ], m[6 ], m[7 ],
				                                  m[8 ], m[10], m[11],
				                                  m[12], m[14], m[15] ) );
			break;
			case 2:
				return +determinant( Matriz_3<T>( m[4 ], m[5 ], m[7 ],
				                                  m[8 ], m[9 ], m[11],
				                                  m[12], m[13], m[15] ) );
			break;
			case 3:
				return -determinant( Matriz_3<T>( m[4 ], m[5 ], m[6 ],
				                                  m[8 ], m[9 ], m[10],
				                                  m[12], m[13], m[14] ) );
			break;
			case 4:
				return -determinant( Matriz_3<T>( m[1 ], m[2 ], m[3 ],
				                                  m[9 ], m[10], m[11],
				                                  m[13], m[14], m[15] ) );
			break;
			case 5:
				return +determinant( Matriz_3<T>( m[0 ], m[2 ], m[3 ],
				                                  m[8 ], m[10], m[11],
				                                  m[12], m[14], m[15] ) );
			break;
			case 6:
				return -determinant( Matriz_3<T>( m[0 ], m[1 ], m[3],
				                                  m[8 ], m[9 ], m[11],
				                                  m[12], m[13], m[15] ) );
			break;
			case 7:
				return +determinant( Matriz_3<T>( m[0 ], m[1 ], m[2 ],
				                                  m[8 ], m[9 ], m[10],
				                                  m[12], m[13], m[14] ) );
			break;
			case 8:
				return +determinant( Matriz_3<T>( m[1 ], m[2 ], m[3],
				                                  m[5 ], m[6 ], m[7],
				                                  m[13], m[14], m[15] ) );
			break;
			case 9:
				return -determinant( Matriz_3<T>( m[0 ], m[2 ], m[3],
				                                  m[4 ], m[6 ], m[7],
				                                  m[12], m[14], m[15] ) );
			break;
			case 10:
				return +determinant( Matriz_3<T>( m[0 ], m[1 ], m[3 ],
				                                  m[4 ], m[5 ], m[7 ],
				                                  m[12], m[13], m[15] ) );
			break;
			case 11:
				return -determinant( Matriz_3<T>( m[0 ], m[1 ], m[2 ],
				                                  m[4 ], m[5 ], m[6 ],
				                                  m[12], m[13], m[14] ) );
			break;
			case 12:
				return -determinant( Matriz_3<T>( m[1 ], m[2 ], m[3 ],
				                                  m[5 ], m[6 ], m[7 ],
				                                  m[9 ], m[10], m[11] ) );
			break;
			case 13:
				return +determinant( Matriz_3<T>( m[0 ], m[2 ], m[3 ],
				                                  m[4 ], m[6 ], m[7 ],
				                                  m[8 ], m[10], m[11] ) );
			break;
			case 14:
				return -determinant( Matriz_3<T>( m[0 ], m[1 ], m[3 ],
				                                  m[4 ], m[5 ], m[7 ],
				                                  m[8 ], m[9 ], m[11] ) );
			break;
			case 15:
				return +determinant( Matriz_3<T>( m[0 ], m[1 ], m[2 ],
				                                  m[4 ], m[5 ], m[6 ],
				                                  m[8 ], m[9 ], m[10] ) );
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
			
			inver[0] = constante *  m[3];
			inver[1] = constante * -m[1];
			inver[2] = constante * -m[2];
			inver[3] = constante *  m[0];
		}
		
		return inver;
	}
	
	/*! invert
	* Calculate the inverted matrix by adjugate matrix
	* Matriz_3<T> m: Matrix to be inverted
	* return: The inverted matrix
	*/
	template <class T>
	Matriz_3<T> invert ( const Matriz_3<T> &m )
	{
		// [ 0 1 2 ]
		// [ 3 4 5 ]
		// [ 6 7 8 ]
		
		// Finding the determination
		T deter = determinant( m );
		
		if ( deter == T(0) )
			throw MatrixException{ "There is no inverse for the matrix." };
		
		T deterIverse = T(1) / deter;
		
		// Finding the cofactors times inverse of the determinant
		T c0 = deterIverse * ( + ( ( m[4] * m[8] ) - ( m[5] * m[7] ) ) );
		T c1 = deterIverse * ( - ( ( m[3] * m[8] ) - ( m[5] * m[6] ) ) );
		T c2 = deterIverse * ( + ( ( m[3] * m[7] ) - ( m[4] * m[6] ) ) );

		T c3 = deterIverse * ( - ( ( m[1] * m[8] ) - ( m[2] * m[7] ) ) );
		T c4 = deterIverse * ( + ( ( m[0] * m[8] ) - ( m[2] * m[6] ) ) );
		T c5 = deterIverse * ( - ( ( m[0] * m[7] ) - ( m[1] * m[6] ) ) );

		T c6 = deterIverse * ( + ( ( m[1] * m[5] ) - ( m[2] * m[4] ) ) );
		T c7 = deterIverse * ( - ( ( m[0] * m[5] ) - ( m[2] * m[3] ) ) );
		T c8 = deterIverse * ( + ( ( m[0] * m[4] ) - ( m[1] * m[3] ) ) );

		// Transposed adjunct matrix
		return Matriz_3<T> { c0, c3, c2
		                   , c1, c4, c7
						   , c2, c5, c8 };
	}
	
	/*! invert
	* Calculate the inverted matrix adjugate matrix
	* Matriz_4<T> m: Matrix to be inverted
	* return: The inverted matrix
	*/
	template <class T>
	Matriz_4<T> invert ( const Matriz_4<T> &m )
	{
		// Finding the determination
		T A = ( m[10] * m[15] ) - ( m[11] * m[14] );
		T B = ( m[9 ] * m[15] ) - ( m[11] * m[13] );
		T C = ( m[9 ] * m[14] ) - ( m[10] * m[13] );
		T D = ( m[8 ] * m[15] ) - ( m[11] * m[12] );
		T E = ( m[8 ] * m[14] ) - ( m[10] * m[12] );
		T F = ( m[8 ] * m[13] ) - ( m[9 ] * m[12] );

		T deter = ( m[0] * ( ( m[5] * A ) - ( m[6] * B ) + ( m[7] * C ) ) )
			    - ( m[1] * ( ( m[4] * A ) - ( m[6] * D ) + ( m[7] * E ) ) )
			    + ( m[2] * ( ( m[4] * B ) - ( m[5] * D ) + ( m[7] * F ) ) )
			    - ( m[3] * ( ( m[4] * C ) - ( m[5] * E ) + ( m[6] * F ) ) );
		
		if ( deter == T(0) )
			throw MatrixException{ "There is no inverse for the matrix." };
		
		T deterIverse = T(1) / deter;

		T G = ( m[2 ] * m[7 ] ) - ( m[3 ] * m[6 ] );
		T H = ( m[1 ] * m[7 ] ) - ( m[3 ] * m[5 ] );
		T I = ( m[1 ] * m[6 ] ) - ( m[2 ] * m[5 ] );
		T J = ( m[0 ] * m[7 ] ) - ( m[3 ] * m[4 ] );
		T K = ( m[0 ] * m[6 ] ) - ( m[2 ] * m[4 ] );
		T L = ( m[0 ] * m[5 ] ) - ( m[1 ] * m[4 ] );

		// [ 0  1  2  3  ]
		// [ 4  5  6  7  ]
		// [ 8  9  10 11 ]
		// [ 12 13 14 15 ]

		// Finding the cofactors times inverse of the determinant
		T c0  = deterIverse * ( + ( m[5 ] * A )
		                        - ( m[6 ] * B )
			                    + ( m[7 ] * C ) );
		T c1  = deterIverse * ( - ( m[4 ] * A )
		                        + ( m[6 ] * D )
			                    - ( m[7 ] * E ) );
		T c2  = deterIverse * ( + ( m[4 ] * B )
		                        - ( m[5 ] * D )
			                    + ( m[7 ] * F ) );
		T c3  = deterIverse * ( - ( m[4 ] * C )
		                        + ( m[5 ] * E )
			                    - ( m[6 ] * F ) );

		T c4  = deterIverse * ( - ( m[1 ] * A )
		                        + ( m[2 ] * B )
			                    - ( m[3 ] * C ) );
		T c5  = deterIverse * ( + ( m[0 ] * A )
		                        - ( m[2 ] * D )
			                    + ( m[3 ] * E ) );
		T c6  = deterIverse * ( - ( m[0 ] * B )
		                        + ( m[1 ] * D )
			                    - ( m[3 ] * F ) );
		T c7  = deterIverse * ( + ( m[0 ] * C )
		                        - ( m[1 ] * E )
			                    + ( m[2 ] * F ) );

		T c8  = deterIverse * ( + ( m[13] * G )
		                        - ( m[14] * H )
			                    + ( m[15] * I ) );
		T c9  = deterIverse * ( - ( m[12] * G )
		                        + ( m[14] * J )
			                    - ( m[15] * K ) );
		T c10 = deterIverse * ( + ( m[12] * H )
		                        - ( m[13] * J )
			                    + ( m[15] * L ) );
		T c11 = deterIverse * ( - ( m[12] * I )
		                        + ( m[13] * K )
			                    - ( m[14] * L ) );

		T c12 = deterIverse * ( - ( m[9 ] * G )
		                        + ( m[10] * H )
			                    - ( m[11] * I ) );
		T c13 = deterIverse * ( + ( m[8 ] * G )
		                        - ( m[10] * J )
			                    + ( m[11] * K ) );
		T c14 = deterIverse * ( - ( m[8 ] * H )
		                        + ( m[9 ] * J )
			                    - ( m[11] * L ) );
		T c15 = deterIverse * ( + ( m[8 ] * I )
		                        - ( m[9 ] * K )
			                    + ( m[10] * L ) );

		// Transposed adjunct matrix
		return Matriz_4<T> { c0 , c4 , c8 , c12
		                   , c1 , c5 , c9 , c13
						   , c2 , c6 , c10, c14
						   , c3 , c7 , c11, c15 };
	}
}

#endif
