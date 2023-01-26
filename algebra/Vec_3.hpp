#ifndef VEC_3_H
#define VEC_3_H

#include <iostream>
#include <cmath>

namespace lito
{
	template <class T>
	class Vec_2;

	template <class T>
	class Vec_3 {
	private:
		union
		{
			T coord[3];
			struct { T _x, _y, _z; };
		};

	public:	
		Vec_3<T> ( T x = 0, T y = 0, T z = 0 ): _x( x ) , _y( y ) , _z( z ) {}
		Vec_3<T> ( const Vec_3<T> &v ) { *this = v; }
		
		inline T&       x ()       { return _x; }
		inline const T& x () const { return _x; }
		inline T&       y ()       { return _y; }
		inline const T& y () const { return _y; }
		inline T&       z ()       { return _z; }
		inline const T& z () const { return _z; }
		
		inline       T& operator [] ( int i )       { return coord[i]; }
		inline const T& operator [] ( int i ) const { return coord[i]; }
		
		Vec_3<T>  operator + ( const Vec_3<T> &v ) const { return Vec_3<T>( _x + v._x, _y + v._y, _z + v._z ); }
		Vec_3<T>  operator - ( const Vec_3<T> &v ) const { return Vec_3<T>( _x - v._x, _y - v._y, _z - v._z ); }
		Vec_3<T>  operator * ( const Vec_3<T> &v ) const { return Vec_3<T>( _x * v._x, _y * v._y, _z * v._z ); }
		Vec_3<T>  operator + ( T c ) const { return Vec_3<T>( _x + c, _y + c, _z + c ); }
		Vec_3<T>  operator - ( T c ) const { return Vec_3<T>( _x - c, _y - c, _z - c ); }
		Vec_3<T>  operator * ( T c ) const { return Vec_3<T>( _x * c, _y * c, _z * c ); }
		Vec_3<T>  operator / ( T c ) const { c = T(1) / c; return Vec_3<T>( _x * c, _y * c, _z * c ); }
		
		Vec_3<T>& operator  = ( const Vec_3<T> &v ) { memcpy( coord, v.coord, sizeof(T) * 3 ); return *this; }
		Vec_3<T>& operator += ( const Vec_3<T> &v ) { _x += v._x; _y += v._y; _z += v._z; return *this; }
		Vec_3<T>& operator -= ( const Vec_3<T> &v ) { _x -= v._x; _y -= v._y; _z -= v._z; return *this; }
		Vec_3<T>& operator *= ( const Vec_3<T> &v ) { _x *= v._x; _y *= v._y; _z *= v._z; return *this; }
		
		Vec_3<T>& operator += ( T c ) { _x += c; _y += c; _z += c; return *this; }
		Vec_3<T>& operator -= ( T c ) { _x -= c; _y -= c; _z -= c; return *this; }
		Vec_3<T>& operator *= ( T c ) { _x *= c; _y *= c; _z *= c; return *this; }
		Vec_3<T>& operator /= ( T c ) { c = T(1) / c; _x *= c; _y *= c; _z *= c; return *this; }

		operator Vec_2<T> ()       { return Vec_2<T>( _x, _y ); }
		operator Vec_2<T> () const { return Vec_2<T>( _x, _y ); }

		template <class U> friend Vec_3<U> log ( const Vec_3<U> &v );
		template <class U> friend Vec_3<U> pow ( const Vec_3<U> &v, T c );

		template <class U> friend Vec_3<U> operator + ( const Vec_3<U> &v );
		template <class U> friend Vec_3<U> operator - ( const Vec_3<U> &v );
		template <class U> friend Vec_3<U> operator + ( U c, const Vec_3<U> &v );
		template <class U> friend Vec_3<U> operator - ( U c, const Vec_3<U> &v );
		template <class U> friend Vec_3<U> operator * ( U c, const Vec_3<U> &v );

		template <class U> friend Vec_2<U>& operator << ( Vec_2<U> &v, U data );
		template <class U> friend Vec_2<U>& operator ,  ( Vec_2<U> &v, U data );
		template <class U> friend std::ostream& operator << ( std::ostream &os, const Vec_3<U> &v );
	};
	
	typedef Vec_3<float>  Vec_3f;
	typedef Vec_3<double> Vec_3d;
	
	template <class T> Vec_3<T> log ( const Vec_3<T> &v )             { return Vec_3<T>( std::log( v._x ), std::log( v._y ), std::log( v._z ) ); }
	template <class T> Vec_3<T> pow ( const Vec_3<T> &v, T c )        { return Vec_3<T>( std::pow( v._x, c ), std::pow( v._y, c ), std::pow( v._z, c ) ); }

	template <class T> Vec_3<T> operator + ( const Vec_3<T> &v )      { return Vec_3<T>( +v._x, +v._y, +v._z ); }
	template <class T> Vec_3<T> operator - ( const Vec_3<T> &v )      { return Vec_3<T>( -v._x, -v._y, -v._z ); }
	template <class T> Vec_3<T> operator + ( T c, const Vec_3<T> &v ) { return Vec_3<T>( c + v._x, c + v._y, c + v._z ); }
	template <class T> Vec_3<T> operator - ( T c, const Vec_3<T> &v ) { return Vec_3<T>( c - v._x, c - v._y, c - v._z ); }
	template <class T> Vec_3<T> operator * ( T c, const Vec_3<T> &v ) { return Vec_3<T>( c * v._x, c * v._y, c * v._z ); }
	
	template <class T> Vec_3<T>& operator << ( Vec_2<T> &v, T data ) { v._x = data; return v; }
	template <class T> Vec_3<T>& operator ,  ( Vec_2<T> &v, T data )
	{
		static size_t indice   = 1;
		static auto   id_vetor = &v;
		
		if ( id_vetor != &v ) {
			indice = 1;
			id_vetor = &v;
		}
		
		switch ( indice ) {
			case 1: v._y = data; indice++  ; break;
			case 2: v._z = data; indice = 1; break;
			default: break;
		}
		
		return v;
	}

	template <class T> std::ostream& operator << ( std::ostream &os, const Vec_3<T> &v ) { return os << "[ " << v._x << ", " << v._y << ", " << v._z << " ]"; }

}

#endif
