#ifndef ALGEBRA_VETOR_H
#define ALGEBRA_VETOR_H

#include <cmath>
#include <limits>

#include "Vec_2.hpp"
#include "Vec_3.hpp"
#include "Vec_4.hpp"

namespace lito {

	template <class T> T dot ( const Vec_2<T> &v1, const Vec_2<T> &v2 );
	template <class T> T dot ( const Vec_3<T> &v1, const Vec_3<T> &v2 );
	template <class T> T dot ( const Vec_4<T> &v1, const Vec_4<T> &v2 );
	
	template <class T> T        cross ( const Vec_2<T> &v1, const Vec_2<T> &v2 );
	template <class T> Vec_3<T> cross ( const Vec_3<T> &v1, const Vec_3<T> &v2 );
	template <class T> Vec_4<T> cross ( const Vec_4<T> &v1, const Vec_4<T> &v2 );
	
	template <class T> T norm2 ( const Vec_2<T> &v );
	template <class T> T norm2 ( const Vec_3<T> &v );
	template <class T> T norm2 ( const Vec_4<T> &v );
	
	template <class T> T norm ( const Vec_2<T> &v );
	template <class T> T norm ( const Vec_3<T> &v );
	template <class T> T norm ( const Vec_4<T> &v );
	
	template <class T> Vec_2<T> unitary ( const Vec_2<T> &v );
	template <class T> Vec_3<T> unitary ( const Vec_3<T> &v );
	template <class T> Vec_4<T> unitary ( const Vec_4<T> &v );
	
	template <class T> Vec_2<T> projection ( const Vec_2<T> &v, const Vec_2<T> &v_proje );
	template <class T> Vec_3<T> projection ( const Vec_3<T> &v, const Vec_3<T> &v_proje );
	template <class T> Vec_3<T> projection ( const Vec_3<T> &v, const Vec_3<T> &v_proje1, const Vec_3<T> &v_proje2 );
	template <class T> Vec_4<T> projection ( const Vec_4<T> &v, const Vec_4<T> &v_proje );
	
	template <class T> T projectionValue ( const Vec_2<T> &v, const Vec_2<T> &v_proje );
	template <class T> T projectionValue ( const Vec_3<T> &v, const Vec_3<T> &v_proje );
	template <class T> T projectionValue ( const Vec_4<T> &v, const Vec_4<T> &v_proje );
	
	template <class T> Vec_2<T> projectionUnitary ( const Vec_2<T> &v, const Vec_2<T> &v_proje_unitary );
	template <class T> Vec_3<T> projectionUnitary ( const Vec_3<T> &v, const Vec_3<T> &v_proje_unitary );
	template <class T> Vec_4<T> projectionUnitary ( const Vec_4<T> &v, const Vec_4<T> &v_proje_unitary );
	
	template <class T> T projectionUnitaryValue ( const Vec_2<T> &v, const Vec_2<T> &v_proje_unitary );
	template <class T> T projectionUnitaryValue ( const Vec_3<T> &v, const Vec_3<T> &v_proje_unitary );
	template <class T> T projectionUnitaryValue ( const Vec_4<T> &v, const Vec_4<T> &v_proje_unitary );
	
	template <class T> Vec_2<T> projectionInverse ( const Vec_2<T> &v, const Vec_2<T> &v_proje );
	template <class T> Vec_3<T> projectionInverse ( const Vec_3<T> &v, const Vec_3<T> &v_proje );
	template <class T> Vec_4<T> projectionInverse ( const Vec_4<T> &v, const Vec_4<T> &v_proje );
	
	template <class T> Vec_2<T> projectionInverseUnitary ( const Vec_2<T> &v, const Vec_2<T> &v_proje_unitary );
	template <class T> Vec_3<T> projectionInverseUnitary ( const Vec_3<T> &v, const Vec_3<T> &v_proje_unitary );
	template <class T> Vec_4<T> projectionInverseUnitary ( const Vec_4<T> &v, const Vec_4<T> &v_proje_unitary );
	
	template <class T> T angleCos ( const Vec_2<T> &v1, const Vec_2<T> &v2 );
	template <class T> T angleCos ( const Vec_3<T> &v1, const Vec_3<T> &v2 );
	template <class T> T angleCos ( const Vec_4<T> &v1, const Vec_4<T> &v2 );
	
	template <class T> T angleSin ( const Vec_2<T> &v1, const Vec_2<T> &v2 );
	template <class T> T angleSin ( const Vec_3<T> &v1, const Vec_3<T> &v2 );
	template <class T> T angleSin ( const Vec_4<T> &v1, const Vec_4<T> &v2 );
	
	template <template <class> class T, class U> U angleCosValue ( const T<U> &v1, const T<U> &v2 );
	template <template <class> class T, class U> U angleSinValue ( const T<U> &v1, const T<U> &v2 );
	
	template <class T> T pseudoAngle ( const Vec_2<T> &v );
	template <class T> T pseudoAngle ( const Vec_2<T> &v1, const Vec_2<T> &v2 );
	template <class T> T pseudoAngle ( const Vec_3<T> &v, const Vec_3<T> &axis1, const Vec_3<T> &axis2 );
	template <class T> T pseudoAngle ( const Vec_3<T> &v1, const Vec_3<T> &v2, const Vec_3<T> &axis1, const Vec_3<T> &axis2 );
	template <class T> T pseudoAngle ( const Vec_4<T> &v );
	
	template <class T> T pseudoAngleCosValue ( const Vec_2<T> &v1, const Vec_2<T> &v2 );
	
	template <class T> T orientedAngle ( const Vec_2<T> &v );
	template <class T> T orientedAngle ( const Vec_2<T> &u, const Vec_2<T> &v );
	
	
	template <class T> T truncation ( T value );
	template <class T> T truncation ( T value, T valueMax, T valueMin );
	
	template <class T> bool linesIntesection ( const Vec_2<T> &l1_v1, const Vec_2<T> &l1_v2
	                                          , const Vec_2<T> &l2_v1, const Vec_2<T> &l2_v2 );
	template <class T> bool linesIntesection ( const Vec_3<T> &l1_v1, const Vec_3<T> &l1_v2
	                                          , const Vec_3<T> &l2_v1, const Vec_3<T> &l2_v2 );
	template <class T> bool facesIntesection ( const Vec_3<T> &f1_v1, const Vec_3<T> &f1_v2, const Vec_3<T> &f1_v3
	                                         , const Vec_3<T> &f2_v1, const Vec_3<T> &f2_v2, const Vec_3<T> &f2_v3 );
	
	template <class T> T area_orientada (const Vec_2<T> *pontos, int tamanho);
	template <class T> bool algoritmo_tiro (const Vec_2<T> *pontos, const Vec_2<T> &ponto_veri, int tamanho);
	template <class T> T indice_rotacao (const Vec_2<T> *pontos, const Vec_2<T> &ponto_veri, int tamanho);
	
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	/*********************************************************************************************************************************/
	
	/*! dot
	* Do the dot product
	* Vec_2<T> v1: Vector 2D
	* Vec_2<T> v2: Vector 2D
	* return: The value of the dot product of v1 with v2
	*/
	template <class T>
	T dot ( const Vec_2<T> &v1, const Vec_2<T> &v2 )
	{
		return ( v1.x() * v2.x() ) + ( v1.y() * v2.y() );
	}
	
	/*! dot
	* Do the dot product
	* Vec_3<T> v1: Vector 3D
	* Vec_3<T> v2: Vector 3D
	* return: The value of the dot product of v1 with v2
	*/
	template <class T>
	T dot ( const Vec_3<T> &v1, const Vec_3<T> &v2 )
	{
		return ( v1.x() * v2.x() ) + ( v1.y() * v2.y() ) + ( v1.z() * v2.z() );
	}
	
	/*! dot
	* Do the dot product
	* Vec_4<T> v1: Vector 4D
	* Vec_4<T> v2: Vector 4D
	* return: The value of the dot product of v1 with v2
	*/
	template <class T>
	T dot ( const Vec_4<T> &v1, const Vec_4<T> &v2 )
	{
		return ( v1.x() * v2.x() ) + ( v1.y() * v2.y() ) + ( v1.z() * v2.z() ) + ( v1.w() * v2.w() );
	}
	
	/*! cross
	* Do the cross product
	* Vec_2<T> v1: Vector 2D
	* Vec_2<T> v2: Vector 2D
	* return: The value of the cross product of v1 with v2
	*/
	template <class T>
	T cross ( const Vec_2<T> &v1, const Vec_2<T> &v2 )
	{
		return ( v1.x() * v2.y() ) - ( v1.y() * v2.x() );
	}
	
	/*! cross
	* Do the cross product
	* Vec_3<T> v1: Vector 3D
	* Vec_3<T> v2: Vector 3D
	* return: The Vec_3<T> result of the cross product of v1 with v2
	*/
	template <class T>
	Vec_3<T> cross ( const Vec_3<T> &v1, const Vec_3<T> &v2 )
	{
		return Vec_3<T>( ( v1.y() * v2.z() ) - ( v1.z() * v2.y() ),
		                 ( v1.z() * v2.x() ) - ( v1.x() * v2.z() ),
		                 ( v1.x() * v2.y() ) - ( v1.y() * v2.x() ) );
	}
	
	/*! cross
	* Do the cross product
	* Vec_4<T> v1: Vector 4D
	* Vec_4<T> v2: Vector 4D
	* return: The Vec_3<T> result of the cross product of v1 with v2
	*/
	template <class T>
	Vec_4<T> cross ( const Vec_4<T> &v1, const Vec_4<T> &v2 )
	{
		return Vec_4<T>( ( v1.y() * v2.z() ) - ( v1.z() * v2.y() ),
		                 ( v1.z() * v2.x() ) - ( v1.x() * v2.z() ),
		                 ( v1.x() * v2.y() ) - ( v1.y() * v2.x() ),
		                 0 );
	}
	
	/*! norm2
	* Calculate the quadract length of the vector
	* Vec_2<T> v: Vector 2D
	* return: The quadract length of the vector
	*/
	template <class T>
	T norm2 ( const Vec_2<T> &v )
	{
		return ( v.x() * v.x() ) + ( v.y() * v.y() );
	}
	
	/*! norm2
	* Calculate the quadract length of the vector
	* Vec_3<T> v: Vector 3D
	* return: The quadract length of the vector
	*/
	template <class T>
	T norm2 ( const Vec_3<T> &v )
	{
		return ( v.x() * v.x() ) + ( v.y() * v.y() ) + ( v.z() * v.z() );
	}
	
	/*! norm2
	* Calculate the quadract length of the vector
	* Vec_4<T> v: Vector 4D
	* return: The quadract length of the vector
	*/
	template <class T>
	T norm2 ( const Vec_4<T> &v )
	{
		return ( v.x() * v.x() ) + ( v.y() * v.y() ) + ( v.z() * v.z() ) + ( v.w() * v.w() );
	}
	
	/*! norm
	* Calculate the length of the vector
	* Vec_2<T> v: Vector 2D
	* return: The length of the vector
	*/
	template <class T>
	T norm ( const Vec_2<T> &v )
	{
		return T( sqrt( norm2( v ) ) );
	}
	
	/*! norm
	* Calculate the length of the vector
	* Vec_3<T> v: Vector 3D
	* return: The length of the vector
	*/
	template <class T>
	T norm ( const Vec_3<T> &v )
	{
		return T( sqrt( norm2( v ) ) );
	}
	
	/*! norm
	* Calculate the length of the vector
	* Vec_4<T> v: Vector 4D
	* return: The length of the vector
	*/
	template <class T>
	T norm ( const Vec_4<T> &v )
	{
		return T( sqrt( norm2( v ) ) );
	}
	
	
	/*! unitary
	* Calculate the unitary vector with same direction
	* Vec_2<T> v: Vector 2D
	* return: The unitary vector with same direction
	*/
	template <class T>
	Vec_2<T> unitary ( const Vec_2<T> &v )
	{
		const T norm_v = norm( v );
		
		if ( norm_v != T(0) )
			return v / norm_v;
		else
			return v;
	}
	
	/*! unitary
	* Calculate the unitary vector with same direction
	* Vec_3<T> v: Vector 3D
	* return: The unitary vector with same direction
	*/
	template <class T>
	Vec_3<T> unitary ( const Vec_3<T> &v )
	{
		const T norm_v = norm( v );
		
		if ( norm_v != T(0) )
			return v / norm_v;
		else
			return v;
	}
	
	/*! unitary
	* Calculate the unitary vector with same direction
	* Vec_4<T> v: Vector 4D
	* return: The unitary vector with same direction
	*/
	template <class T>
	Vec_4<T> unitary ( const Vec_4<T> &v )
	{
		const T norm_v = norm( v );
		
		if ( norm_v != T(0) )
			return v / norm_v;
		else
			return v;
	}
	
	/*! projection
	* Calculate the projection of the vector v over the v_project
	* Vec_2<T> v: Vector 2D that will be projected
	* Vec_2<T> v_proje: Projection vector 2D
	* return: The vector projected
	*/
	template <class T>
	Vec_2<T> projection ( const Vec_2<T> &v, const Vec_2<T> &v_proje )
	{
		return ( dot( v, v_proje ) / norm2( v_proje ) ) * v_proje;
	}
	
	/*! projection
	* Calculate the projection of the vector v over the v_project
	* Vec_3<T> v: Vector 3D that will be projected
	* Vec_3<T> v_proje: Projection vector 3D
	* return: The vector projected
	*/
	template <class T>
	Vec_3<T> projection ( const Vec_3<T> &v, const Vec_3<T> &v_proje )
	{
		return ( dot( v, v_proje ) / norm2( v_proje ) ) * v_proje;
	}
	
	/*! projection
	* Calculate the projection of the vector v over the plane created by v_proje1 and v_proje2
	* Vec_3<T> v: Vector 3D that will be projected
	* Vec_3<T> v_proje1: Projection vector 3D
	* Vec_3<T> v_proje2: Projection vector 3D
	* return: The vector projected
	*/
	template <class T>
	Vec_3<T> projection ( const Vec_3<T> &v, const Vec_3<T> &v_proje1, const Vec_3<T> &v_proje2 )
	{
		return projection( v, v_proje1 ) + projection( v, v_proje2 );
	}
	
	/*! projection
	* Calculate the projection of the vector v over the v_project
	* Vec_4<T> v: Vector 4D that will be projected
	* Vec_4<T> v_proje: Projection vector 4D
	* return: The vector projected
	*/
	template <class T>
	Vec_4<T> projection ( const Vec_4<T> &v, const Vec_4<T> &v_proje )
	{
		return ( dot( v, v_proje ) / norm2( v_proje ) ) * v_proje;
	}
	
	/*! projectionValue
	* Calculate the lenght of the projection of the vector v over the v_project
	* Vec_2<T> v: Vector 2D that will be projected
	* Vec_2<T> v_proje: Projection vector 2D
	* return: The length of the vector projected
	*/
	template <class T>
	T projectionValue ( const Vec_2<T> &v, const Vec_2<T> &v_proje )
	{
		return dot( v, v_proje ) / norm2( v_proje );
	}
	
	/*! projectionValue
	* Calculate the lenght of the projection of the vector v over the v_project
	* Vec_3<T> v: Vector 3D that will be projected
	* Vec_3<T> v_proje: Projection vector 3D
	* return: The length of the vector projected
	*/
	template <class T>
	T projectionValue ( const Vec_3<T> &v, const Vec_3<T> &v_proje )
	{
		return dot( v, v_proje ) / norm2( v_proje );
	}
	
	/*! projectionValue
	* Calculate the lenght of the projection of the vector v over the v_project
	* Vec_4<T> v: Vector 4D that will be projected
	* Vec_4<T> v_proje: Projection vector 4D
	* return: The length of the vector projected
	*/
	template <class T>
	T projectionValue ( const Vec_4<T> &v, const Vec_4<T> &v_proje )
	{
		return dot( v, v_proje ) / norm2( v_proje );
	}
	
	/*! projectionUnitary
	* Calculate the projection of the vector v over the v_project being unitary
	* Vec_2<T> v: Vector 2D that will be projected
	* Vec_2<T> v_proje: Projection vector 2D
	* return: The vector projected
	*/
	template <class T>
	Vec_2<T> projectionUnitary ( const Vec_2<T> &v, const Vec_2<T> &v_proje_unitary )
	{
		return dot( v, v_proje_unitary ) * v_proje_unitary;
	}
	
	/*! projectionUnitary
	* Calculate the projection of the vector v over the v_project being unitary
	* Vec_3<T> v: Vector 3D that will be projected
	* Vec_3<T> v_proje: Projection vector 3D
	* return: The vector projected
	*/
	template <class T>
	Vec_3<T> projectionUnitary ( const Vec_3<T> &v, const Vec_3<T> &v_proje_unitary )
	{
		return dot( v, v_proje_unitary ) * v_proje_unitary;
	}
	
	/*! projectionUnitary
	* Calculate the projection of the vector v over the v_project being unitary
	* Vec_3<T> v: Vector 3D that will be projected
	* Vec_3<T> v_proje: Projection vector 3D
	* return: The vector projected
	*/
	template <class T>
	Vec_4<T> projectionUnitary ( const Vec_4<T> &v, const Vec_4<T> &v_proje_unitary )
	{
		return dot( v, v_proje_unitary ) * v_proje_unitary;
	}
	
	/*! projectionUnitaryValue
	* Calculate the lenght of the projection of the vector v over the v_project being unitary
	* Vec_2<T> v: Vector 2D that will be projected
	* Vec_2<T> v_proje: Projection vector 2D
	* return: The length of the vector projected
	*/
	template <class T>
	T projectionUnitaryValue ( const Vec_2<T> &v, const Vec_2<T> &v_proje_unitary )
	{
		return dot( v, v_proje_unitary );
	}
	
	/*! projectionUnitaryValue
	* Calculate the lenght of the projection of the vector v over the v_project being unitary
	* Vec_3<T> v: Vector 3D that will be projected
	* Vec_3<T> v_proje: Projection vector 3D
	* return: The length of the vector projected
	*/
	template <class T>
	T projectionUnitaryValue ( const Vec_3<T> &v, const Vec_3<T> &v_proje_unitary )
	{
		return dot( v, v_proje_unitary );
	}
	
	/*! projectionUnitaryValue
	* Calculate the lenght of the projection of the vector v over the v_project being unitary
	* Vec_4<T> v: Vector 4D that will be projected
	* Vec_4<T> v_proje: Projection vector 4D
	* return: The length of the vector projected
	*/
	template <class T>
	T projectionUnitaryValue ( const Vec_4<T> &v, const Vec_4<T> &v_proje_unitary )
	{
		return dot( v, v_proje_unitary );
	}
	
	/*! projectionInverse
	* ...
	* Vec_2<T> v: Vector 2D that will be projected
	* Vec_2<T> v_proje: Projection vector 2D
	* return: The length of the vector projected
	*/
	template <class T>
	Vec_2<T> projectionInverse ( const Vec_2<T> &v, const Vec_2<T> &v_proje )
	{
		return ( cross( v_proje, v ) / norm( v_proje ) );
	}
	
	/*! projectionInverse
	* ...
	* Vec_2<T> v: Vector 2D that will be projected
	* Vec_2<T> v_proje: Projection vector 2D
	* return: The length of the vector projected
	*/
	template <class T>
	Vec_3<T> projectionInverse ( const Vec_3<T> &v, const Vec_3<T> &v_proje )
	{
		return ( dot( v, v_proje ) / norm2( v_proje ) ) * v_proje;
	}
	
	/*! projectionInverse
	* ...
	* Vec_2<T> v: Vector 2D that will be projected
	* Vec_2<T> v_proje: Projection vector 2D
	* return: The length of the vector projected
	*/
	template <class T>
	Vec_4<T> projectionInverse ( const Vec_4<T> &v, const Vec_4<T> &v_proje )
	{
		return ( dot( v, v_proje ) / norm2( v_proje ) ) * v_proje;
	}
	
	/*! projectionInverseUnitary
	* ... :::
	* Vec_2<T> v: Vector 2D that will be projected
	* Vec_2<T> v_proje: Projection vector 2D
	* return: The length of the vector projected
	*/
	template <class T>
	Vec_2<T> projectionInverseUnitary ( const Vec_2<T> &v, const Vec_2<T> &v_proje_unitary )
	{
		return cross( v, v_proje_unitary ) * v_proje_unitary;
	}
	
	/*! projectionInverseUnitary
	* ... :::
	* Vec_2<T> v: Vector 2D that will be projected
	* Vec_2<T> v_proje: Projection vector 2D
	* return: The length of the vector projected
	*/
	template <class T>
	Vec_3<T> projectionInverseUnitary ( const Vec_3<T> &v, const Vec_3<T> &v_proje_unitary )
	{
		return dot( v, v_proje_unitary ) * v_proje_unitary;
	}
	
	/*! projectionInverseUnitary
	* ... :::
	* Vec_2<T> v: Vector 2D that will be projected
	* Vec_2<T> v_proje: Projection vector 2D
	* return: The length of the vector projected
	*/
	template <class T>
	Vec_4<T> projectionInverseUnitary ( const Vec_4<T> &v, const Vec_4<T> &v_proje_unitary )
	{
		return dot( v, v_proje_unitary ) * v_proje_unitary;
	}
	
	/*! angleCos
	* Calculates the cosine angle betewen v1 and v2
	* Vec_2<T> v1: Vector 2D
	* Vec_2<T> v2: Vector 2D
	* return: The cosine angle betewen v1 and v2
	*/
	template <class T>
	T angleCos ( const Vec_2<T> &v1, const Vec_2<T> &v2 )
	{
		return truncation( dot( v1, v2 ) / T( sqrt( norm2( v1 ) * norm2( v2 ) ) ) );
	}
	
	/*! angleCos
	* Calculates the cosine angle betewen v1 and v2
	* Vec_3<T> v1: Vector 3D
	* Vec_3<T> v2: Vector 3D
	* return: The cosine angle betewen v1 and v2
	*/
	template <class T>
	T angleCos ( const Vec_3<T> &v1, const Vec_3<T> &v2 )
	{
		return truncation( dot( v1, v2 ) / T( sqrt( norm2( v1 ) * norm2( v2 ) ) ) );
	}
	
	/*! angleCos
	* Calculates the cosine angle betewen v1 and v2
	* Vec_4<T> v1: Vector 4D
	* Vec_4<T> v2: Vector 4D
	* return: The cosine angle betewen v1 and v2
	*/
	template <class T>
	T angleCos ( const Vec_4<T> &v1, const Vec_4<T> &v2 )
	{
		return truncation( dot( v1, v2 ) / T( sqrt( norm2( v1 ) * norm2( v2 ) ) ) );
	}
	
	/*! angleSin
	* Calculates the sine angle betewen v1 and v2
	* Vec_2<T> v1: Vector 2D
	* Vec_2<T> v2: Vector 2D
	* return: The sine angle betewen v1 and v2
	*/
	template <class T>
	T angleSin ( const Vec_2<T> &v1, const Vec_2<T> &v2 )
	{
		return truncation( cross( v1, v2 ) / T( sqrt( norm2( v1 ) * norm2( v2 ) ) ) );
	}
	
	/*! angleSin
	* Calculates the sine angle betewen v1 and v2
	* Vec_3<T> v1: Vector 3D
	* Vec_3<T> v2: Vector 3D
	* return: The sine angle betewen v1 and v2
	*/
	template <class T>
	T angleSin ( const Vec_3<T> &v1, const Vec_3<T> &v2 )
	{
		return truncation( norm( cross( v1, v2 ) ) / T( sqrt( norm2( v1 ) * norm2( v2 ) ) ) );
	}
	
	/*! angleSin
	* Calculates the sine angle betewen v1 and v2
	* Vec_4<T> v1: Vector 4D
	* Vec_4<T> v2: Vector 4D
	* return: The sine angle betewen v1 and v2
	*/
	template <class T>
	T angleSin ( const Vec_4<T> &v1, const Vec_4<T> &v2 )
	{
		return truncation( norm( cross( v1, v2 ) ) / T( sqrt( norm2( v1 ) * norm2( v2 ) ) ) );
	}
	
	/*! angleCosValue
	* Calculates the angle betewen v1 and v2 using cosine
	* Vec_2<T> v1: Vector 2D
	* Vec_2<T> v2: Vector 2D
	* return: The angle betewen v1 and v2
	*/
	template <template <class> class T, class U>
	U angleCosValue ( const T<U> &v1, const T<U> &v2 )
	{
		return U( acos( angleCos( v1, v2 ) ) );
	}
	
	/*! angleSinValue
	* Calculates the angle betewen v1 and v2 using sine
	* Vec_2<T> v1: Vector 2D
	* Vec_2<T> v2: Vector 2D
	* return: The angle betewen v1 and v2
	*/
	template <template <class> class T, class U>
	U angleSinValue ( const T<U> &v1, const T<U> &v2 )
	{
		return U( asin( angleSin( v1, v2 ) ) );
	}
	
	/*! pseudoAngle
	* Calculates the pseudoangle from square of the vector v
	* Vec_2<T> v: Vector 2D
	* return: The pseudoangle of the vector v
	*/
	template <class T>
	T pseudoAngle ( const Vec_2<T> &v )
	{
		T v_x = v.x(),
		  v_y = v.y();
		
		if ( std::abs( v_x ) <= std::abs( v_y ) ) {
			
			if ( v_y > 0 )
				return T(1) + ( T(1) - ( v_x / v_y ) );
			
			if ( v_y < 0 )
				return T(5) + ( T(1) - ( v_x / v_y ) );
			
		}
		
		if ( std::abs( v_x ) >= std::abs( v_y ) ) {
			
			if ( v_x > 0 )
				return ( ( v_y >= 0 )
				       ? T(1) - ( T(1) - ( v_y / v_x ) )
				       : T(7) + ( T(1) + ( v_y / v_x ) )
				       );
			
			if ( v_x < 0 )
				return T(3) + ( T(1) + ( v_y / v_x ) );
			
		}
		
		return T( nan("") );
	}
	
	/*! pseudoAngle
	* Calculates the pseudoangle from square betewen vector v1 and vector v2
	* Vec_2<T> v1: Vector 2D
	* Vec_2<T> v2: Vector 2D
	* return: The pseudoangle betewen v1 and v2
	*/
	template <class T>
	T pseudoAngle ( const Vec_2<T> &v1, const Vec_2<T> &v2 )
	{
		T ang1 = pseudoAngle(v1);
		T ang2 = pseudoAngle(v2);
	
		if (ang1 <= ang2)
			return ang2 - ang1;
		else
			return (T(8) - ang1) + ang2;
	}
	
	/*! pseudoAngle
	* Calculates the pseudoangle from square of vector v projected in plane formed by axis1 and axis2
	* Vec_3<T> v: Vector 2D
	* return: The pseudoangle of v projected in plane
	*/
	template <class T>
	T pseudoAngle ( const Vec_3<T> &v, const Vec_3<T> &axis1, const Vec_3<T> &axis2 )
	{
		const Vec_2<T> v_2d ( projectionValue( v, axis1 )
		                    , projectionValue( v, axis2 ) );
		
		return pseudoAngle( v_2d );
	}
	
	/*! pseudoAngle
	* Calculates the pseudoangle from square betewen vector v1 and v2 projected in plane formed by axis1 and axis2
	* Vec_3<T> v1: Vector 2D
	* Vec_3<T> v2: Vector 2D
	* return: The pseudoangle betewen v1 and v2 projected in plane
	*/
	template <class T>
	T pseudoAngle ( const Vec_3<T> &v1, const Vec_3<T> &v2, const Vec_3<T> &axis1, const Vec_3<T> &axis2 )
	{
		const Vec_2<T> v_2d_1 ( projectionValue( v1, axis1 )
		                      , projectionValue( v1, axis2 ) );
		const Vec_2<T> v_2d_2 ( projectionValue( v2, axis1 )
		                      , projectionValue( v2, axis2 ) );
		
		return pseudoAngle( v_2d_1, v_2d_2 );
	}
	
	/*! pseudoAngle
	* -----
	* Vec_4<T> v: Vector 2D
	* return: 
	*/
	template <class T>
	T pseudoAngle ( const Vec_4<T> &v )
	{
	
	}
	
	/*! pseudoAngleCosValue
	* Calculate the pseudoangle from cos betewen [0, 2] betewen vectors v1 and v2
	* Vec_2<T> v1: Vector 2D
	* Vec_2<T> v2: Vector 2D
	* return: The pseudoangle betewen vectors v1 and v2
	*/
	template <class T>
	T pseudoAngleCosValue ( const Vec_2<T> &v1, const Vec_2<T> &v2 )
	{
		return T(1) - angleCos(v1, v2);
	}
	
	/*! orientedAngle
	* Calculate the oriented angle of vector v
	* Vec_2<T> v: Vector 2D
	* return: The oriented angle of vector
	*/
	template <class T>
	T orientedAngle ( const Vec_2<T> &v )
	{
		const Vec_2<T> u(T(1), T(0));
		T angulo = angleCosValue(u, v);
	
		if (angulo >= 0)
			return angulo;
		else
			return -angulo;
	}
	
	/*! orientedAngle
	* Calculate the oriented angle betewen vector u and v
	* Vec_2<T> v1: Vector 2D
	* Vec_2<T> v2: Vector 2D
	* return: The oriented angle of vector
	*/
	template <class T>
	T orientedAngle ( const Vec_2<T> &u, const Vec_2<T> &v )
	{
		T angulo = angleCosValue(u, v);
	
		if (angulo >= 0)
			return angulo;
		else
			return -angulo;
	}
	
	/*! truncation
	* Truncate the value in [-1, 1]
	* T value: numeric that will be trucated
	* return: The value truncated in [-1, 1]
	*/
	template <class T>
	T truncation ( T value )
	{
		value = ( value < T(-1) ) ? T(-1) :
		        ( value > T( 1) ) ? T( 1)  :
		        value;
		
		return value;
	}
	
	/*! truncation
	* Truncate the value in [valueMin, valueMax]
	* T value: numeric that will be trucated
	* T valueMax: max numeric value
	* T valueMin: min numeric value
	* return: The value truncated in [valueMin, valueMax]
	*/
	template <class T>
	T truncation ( T value, T valueMax, T valueMin )
	{
		value = ( value < valueMin ) ? valueMin :
		        ( value > valueMax ) ? valueMax :
		        value;
		
		return value;
	}
	
	/*! linesIntesection
	* Calculate if lines l1 and l2 intersects
	* Vec_2<T> l1_v1: first point of the l1
	* Vec_2<T> l1_v2: second point of the l1
	* Vec_2<T> l2_v1: first point of the l2
	* Vec_2<T> l2_v2: second point of the l2
	* return: True if intersects and false if not
	*/
	template <class T>
	bool linesIntesection ( const Vec_2<T> &l1_v1, const Vec_2<T> &l1_v2
	                       , const Vec_2<T> &l2_v1, const Vec_2<T> &l2_v2 )
	{
		const Vec_2<T> v_1 = l1_v2 - l1_v1;
		const Vec_2<T> v_2 = l2_v2 - l2_v1;
	
		const T value_1 = cross( v_1, l2_v1 - l1_v1 ) * cross( v_1, l2_v2 - l1_v1 );
		const T value_2 = cross( v_2, l1_v1 - l2_v1 ) * cross( v_2, l1_v2 - l2_v1 );
	
		if ( value_1 <= T(0) && value_2 <= T(0) )
			return true;
		else
			return false;
	}
	
	/*! linesIntesection
	* Calculate if lines l1 and l2 intersects
	* Vec_3<T> l1_v1: first point of the l1
	* Vec_3<T> l1_v2: second point of the l1
	* Vec_3<T> l2_v1: first point of the l2
	* Vec_3<T> l2_v2: second point of the l2
	* return: True if intersects and false if not
	*/
	template <class T>
	bool linesIntesection ( const Vec_3<T> &l1_v1, const Vec_3<T> &l1_v2
	                       , const Vec_3<T> &l2_v1, const Vec_3<T> &l2_v2 )
	{
		const Vec_3<T> v_1 = l1_v2 - l1_v1;
		const Vec_3<T> v_2 = l2_v2 - l2_v1;
	
		const T value_1 = lito::dot( cross( v_1, l2_v1 - l1_v1 ), cross( v_1, l2_v2 - l1_v1 ) );
		const T value_2 = lito::dot( cross( v_2, l1_v1 - l2_v1 ), cross( v_2, l1_v2 - l2_v1 ) );
	
		if ( value_1 <= T(0) && value_2 <= T(0) )
			return true;
		else
			return false;
	}
	
	/*! linesIntesection
	* Calculate if faces f1 and f2 intersects
	* Vec_3<T> f1_v1: first point of the f1
	* Vec_3<T> f1_v2: second point of the f1
	* Vec_3<T> f1_v3: third point of the f1
	* Vec_3<T> f2_v1: first point of the f2
	* Vec_3<T> f2_v2: second point of the f2
	* * Vec_3<T> f1_v3: third point of the f2
	* return: True if intersects and false if not
	*/
	template <class T>
	bool facesIntesection ( const Vec_3<T> &f1_v1, const Vec_3<T> &f1_v2, const Vec_3<T> &f1_v3
	                      , const Vec_3<T> &f2_v1, const Vec_3<T> &f2_v2, const Vec_3<T> &f2_v3 )
	{
		const Vec_3<T> v_1 = f1_v2 - f1_v1;
		const Vec_3<T> v_2 = f2_v2 - f2_v1;
	
		const T value_1 = lito::dot( cross( v_1, f2_v1 - f1_v1 ), cross( v_1, f2_v2 - f1_v1 ) );
		const T value_2 = lito::dot( cross( v_2, f1_v1 - f2_v1 ), cross( v_2, f1_v2 - f2_v1 ) );
	
		if ( value_1 <= T(0) && value_2 <= T(0) )
			return true;
		else
			return false;
	}
	/*===============================================================================================================================*/
	template <class T>
	T area_orientada (const Vec_2<T> *pontos, int tamanho)
	{
		T area = T(0);
		
		for (int i = 0; i < tamanho; i++)
			area += cross(pontos[i], pontos[(i+1) % tamanho]);
		
		return area / T(2);
	}
	/*===============================================================================================================================*/
	template <class T>
	bool algoritmo_tiro (const Vec_2<T> *pontos, const Vec_2<T> &ponto_veri, int tamanho)
	{
		const Vec_2<T> ponto_infinito_pos( std::numeric_limits<T>::infinity()
		                                 , ponto_veri._y );
		int qtd_passada = 0;
		
		for (int i = 0; i < tamanho; i++) {
			if (pontos[i]._y != ponto_veri._y) {
				qtd_passada += linesIntesection( ponto_veri, ponto_infinito_pos
				                                , pontos[i], pontos[(i + 1) % tamanho] );
			} else {
				if ( pontos[(i-1) % tamanho]._y < ponto_veri._y
				&&   pontos[(i+1) % tamanho]._y < ponto_veri._y )
					qtd_passada += 2;
				else if ( pontos[(i-1) % tamanho]._y > ponto_veri._y
				     &&   pontos[(i+1) % tamanho]._y < ponto_veri._y )
					qtd_passada += 1;
				else if ( pontos[(i-1) % tamanho]._y < ponto_veri._y
				     &&   pontos[(i+1) % tamanho]._y == ponto_veri._y
						 &&   pontos[(i+2) % tamanho]._y < ponto_veri._y )
					qtd_passada += 2;
				else if ( pontos[(i-1) % tamanho]._y > ponto_veri._y
				     &&   pontos[(i+1) % tamanho]._y == ponto_veri._y
						 &&   pontos[(i+2) % tamanho]._y < ponto_veri._y )
					qtd_passada += 1;
			}
		}
	
		return (qtd_passada % 2) != 0;
	}
	/*===============================================================================================================================*/
	template <class T> T indice_rotacao (const Vec_2<T> *pontos, const Vec_2<T> &ponto_veri, int tamanho)
	{
		T indice = T(0);
	
		for (int i = 0; i < tamanho; i++) {
			indice += orientedAngle(pontos[i] - ponto_veri, pontos[(i + 1) % tamanho] - ponto_veri);
		}
	
		indice /= ( T(2) * M_PI );
	
		return indice;
	}
	/*===============================================================================================================================*/


}

#endif
