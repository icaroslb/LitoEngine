#ifndef VEC_4_H
#define VEC_4_H

#include <iostream>
#include <cstring>

namespace lito
{
	template <class T>
	class Vec_3;

	template <class T>
	class Vec_4 {
	private:
		union
		{
			T coord[4];
			struct { T _x, _y, _z, _w; };
		};
		
	public:
		Vec_4<T> ( T x = 0, T y = 0, T z = 0, T w = 0 ) : _x( x ) , _y( y ) , _z( z ) , _w( w ) {}
		Vec_4<T> ( const Vec_4<T> &v ) { *this = v; }
		
		inline T&       x ()       { return _x; }
		inline const T& x () const { return _x; }
		inline T&       y ()       { return _y; }
		inline const T& y () const { return _y; }
		inline T&       z ()       { return _z; }
		inline const T& z () const { return _z; }
		inline T&       w ()       { return _w; }
		inline const T& w () const { return _w; }
		
		inline       T& operator [] ( int i )       { return coord[i]; }
		inline const T& operator [] ( int i ) const { return coord[i]; }
		
		Vec_4<T>  operator + ( const Vec_4<T> &v ) const { return Vec_4<T>( _x + v._x, _y + v._y, _z + v._z, _w + v._w ); }
		Vec_4<T>  operator - ( const Vec_4<T> &v ) const { return Vec_4<T>( _x - v._x, _y - v._y, _z - v._z, _w - v._w ); }
		Vec_4<T>  operator * ( const Vec_4<T> &v ) const { return Vec_4<T>( _x * v._x, _y * v._y, _z * v._z, _w * v._w ); }
		Vec_4<T>  operator + ( const Vec_3<T> &v ) const { return Vec_4<T>( _x + v._x, _y + v._y, _z + v._z, _w ); }
		Vec_4<T>  operator - ( const Vec_3<T> &v ) const { return Vec_4<T>( _x - v._x, _y - v._y, _z - v._z, _w ); }
		Vec_4<T>  operator * ( const Vec_3<T> &v ) const { return Vec_4<T>( _x * v._x, _y * v._y, _z * v._z, _w ); }
		Vec_4<T>  operator + ( T c ) const { return Vec_4<T>( _x + c, _y + c, _z + c, _w + c ); }
		Vec_4<T>  operator - ( T c ) const { return Vec_4<T>( _x - c, _y - c, _z - c, _w - c ); }
		Vec_4<T>  operator * ( T c ) const { return Vec_4<T>( _x * c, _y * c, _z * c, _w * c ); }
		Vec_4<T>  operator / ( T c ) const { c = T(1) / c; return Vec_4<T>( _x * c, _y * c, _z * c, _w * c ); }
		
		Vec_4<T>& operator  = ( const Vec_4<T> &v ) { memcpy( coord, v.coord, sizeof(T) * 4 ); return *this; }
		Vec_4<T>& operator += ( const Vec_4<T> &v ) { _x += v._x; _y += v._y; _z += v._z; _w += v._w; return *this; }
		Vec_4<T>& operator -= ( const Vec_4<T> &v ) { _x -= v._x; _y -= v._y; _z -= v._z; _w -= v._w; return *this; }
		Vec_4<T>& operator *= ( const Vec_4<T> &v ) { _x *= v._x; _y *= v._y; _z *= v._z; _w *= v._w; return *this; }

		Vec_4<T>& operator += ( T c ) { _x += c; _y += c; _z += c; _w += c; return *this; }
		Vec_4<T>& operator -= ( T c ) { _x -= c; _y -= c; _z -= c; _w -= c; return *this; }
		Vec_4<T>& operator *= ( T c ) { _x *= c; _y *= c; _z *= c; _w *= c; return *this; }
		Vec_4<T>& operator /= ( T c ) { c = T(1) / c; _x *= c; _y *= c; _z *= c; _w *= c; return *this; }
	
		operator Vec_3<T> ()       { return Vec_3<T>( _x, _y, _z ); }
		operator Vec_3<T> () const { return Vec_3<T>( _x, _y, _z ); }

		template <class U> friend Vec_4<U> log ( const Vec_4<U> &v );
		template <class U> friend Vec_4<U> pow ( const Vec_4<U> &v, T c );

		template <class U> friend Vec_4<U> operator + ( const Vec_4<U> &v );
		template <class U> friend Vec_4<U> operator - ( const Vec_4<U> &v );
		template <class U> friend Vec_4<U> operator + ( T c, const Vec_4<U> &v );
		template <class U> friend Vec_4<U> operator - ( T c, const Vec_4<U> &v );
		template <class U> friend Vec_4<U> operator * ( T c, const Vec_4<U> &v );
		template <class U> friend Vec_4<U>& operator << ( Vec_4<U> &v, T data );
		template <class U> friend Vec_4<U>& operator ,  ( Vec_4<U> &v, T data );
		template <class U> friend std::ostream& operator << ( std::ostream &os, const Vec_4<U> &v );
	};
	
	typedef Vec_4<float>  Vec_4f;
	typedef Vec_4<double> Vec_4d;
	
	template <class T> Vec_4<T> log ( const Vec_4<T> &v )             { return Vec_4<T>( std::log( v._x ), std::log( v._y ), std::log( v._z ), std::log( v._w ) ); }
	template <class T> Vec_4<T> pow ( const Vec_4<T> &v, T c )        { return Vec_4<T>( std::pow( v._x, c ), std::pow( v._y, c ), std::pow( v._z, c ), std::pow( v._w, c ) ); }

	template <class T> Vec_4<T> operator + ( const Vec_4<T> &v )      { return Vec_4<T>( +v._x, +v._y, +v._z, +v._w ); }
	template <class T> Vec_4<T> operator - ( const Vec_4<T> &v )      { return Vec_4<T>( -v._x, -v._y, -v._z, -v._w ); }
	template <class T> Vec_4<T> operator + ( T c, const Vec_4<T> &v ) { return Vec_4<T>( c + v._x, c + v._y, c + v._z, c + v._w ); }
	template <class T> Vec_4<T> operator - ( T c, const Vec_4<T> &v ) { return Vec_4<T>( c - v._x, c - v._y, c - v._z, c - v._w ); }
	template <class T> Vec_4<T> operator * ( T c, const Vec_4<T> &v ) { return Vec_4<T>( c * v._x, c * v._y, c * v._z, c * v._w ); }
	template <class T> Vec_4<T>& operator << ( Vec_4<T> &v, T dado ) { v._x = dado; return v; }
	template <class T> Vec_4<T>& operator ,  ( Vec_4<T> &v, T dado )
	{
		static size_t indice   = 1;
		static auto   id_vetor = &v;
		
		if ( id_vetor != &v ) {
			indice = 1;
			id_vetor = &v;
		}
		
		switch ( indice ) {
			case 1: v._y = dado; indice++  ; break;
			case 2: v._z = dado; indice++  ; break;
			case 3: v._w = dado; indice = 1; break;
			default: break;
		}
		
		return v;
	}

	template <class T> std::ostream& operator << ( std::ostream &os, const Vec_4<T> &v ) { return os << "[ " << v._x << ", " << v._y << ", " << v._z << ", " << v._w << " ]"; }
	
	template <class T> Vec_4<T>  operator + ( const Vec_3<T> &v3, const Vec_4<T> &v4 ) { return Vec_4<T>( v3._x + v4._x, v3._y + v4._y, v3._z + v4._z, v4._w ); }
	template <class T> Vec_4<T>  operator - ( const Vec_3<T> &v3, const Vec_4<T> &v4 ) { return Vec_4<T>( v3._x - v4._x, v3._y - v4._y, v3._z - v4._z, v4._w ); }
	template <class T> Vec_4<T>  operator * ( const Vec_3<T> &v3, const Vec_4<T> &v4 ) { return Vec_4<T>( v3._x * v4._x, v3._y * v4._y, v3._z * v4._z, v4._w ); }
}

#endif
