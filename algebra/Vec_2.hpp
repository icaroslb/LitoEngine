#ifndef VEC_2_H
#define VEC_2_H

#include <iostream>
#include <cstring>

namespace lito {

	template <class T>
	class Vec_2 {
	private:
		union
		{
			T coord[2];
			struct { T _x, _y; };
		};

	public:
		Vec_2<T> ( T x = T(0), T y = T(0) ): _x( x ) , _y( y ) {}
		Vec_2<T> ( const Vec_2<T> &v ) { *this = v; }
		
		inline T&       x  ()       { return _x; }
		inline const T& x  () const { return _x; }
		inline T&       y  ()       { return _y; }
		inline const T& y  () const { return _y; }
		
		inline       T& operator [] ( int i )       { return coord[i]; }
		inline const T& operator [] ( int i ) const { return coord[i]; }
		
		Vec_2<T>  operator + ( const Vec_2<T> &v ) const { return Vec_2<T>( _x + v._x, _y + v._y ); }
		Vec_2<T>  operator - ( const Vec_2<T> &v ) const { return Vec_2<T>( _x - v._x, _y - v._y ); }
		Vec_2<T>  operator * ( const Vec_2<T> &v ) const { return Vec_2<T>( _x * v._x, _y * v._y ); }
		Vec_2<T>  operator + ( T c ) const { return Vec_2<T>( _x + c, _y + c ); }
		Vec_2<T>  operator - ( T c ) const { return Vec_2<T>( _x - c, _y - c ); }
		Vec_2<T>  operator * ( T c ) const { return Vec_2<T>( _x * c, _y * c ); }
		Vec_2<T>  operator / ( T c ) const { c = T(1) / c; return Vec_2<T>( _x * c, _y * c ); }
		
		Vec_2<T>& operator  = ( const Vec_2<T> &v ) { memcpy( coord, v.coord, sizeof(T) * 2 ); return *this; }
		Vec_2<T>& operator += ( const Vec_2<T> &v ) { _x += v._x; _y += v._y; return *this; }
		Vec_2<T>& operator -= ( const Vec_2<T> &v ) { _x -= v._x; _y -= v._y; return *this; }
		Vec_2<T>& operator *= ( const Vec_2<T> &v ) { _x *= v._x; _y *= v._y; return *this; }

		Vec_2<T>& operator += ( T c ) { _x += c; _y += c; return *this; }
		Vec_2<T>& operator -= ( T c ) { _x -= c; _y -= c; return *this; }
		Vec_2<T>& operator *= ( T c ) { _x *= c; _y *= c; return *this; }
		Vec_2<T>& operator /= ( T c ) { c = T(1) / c; _x *= c; _y *= c; return *this; }

		template <class U> friend Vec_2<U> log ( const Vec_2<U> &v );
		template <class U> friend Vec_2<U> pow ( const Vec_2<U> &v, T c );

		template <class U> friend Vec_2<U> operator + ( const Vec_2<U> &v );
		template <class U> friend Vec_2<U> operator - ( const Vec_2<U> &v );
		template <class U> friend Vec_2<U> operator + ( U c, const Vec_2<U> &v );
		template <class U> friend Vec_2<U> operator - ( U c, const Vec_2<U> &v );
		template <class U> friend Vec_2<U> operator * ( U c, const Vec_2<U> &v );

		template <class U> friend Vec_2<U>& operator << ( Vec_2<U> &v, U data );
		template <class U> friend Vec_2<U>& operator ,  ( Vec_2<U> &v, U data );
		template <class U> friend std::ostream& operator << ( std::ostream &os, const Vec_2<U> &v );
	};
	
	typedef Vec_2<float>  Vec_2f;
	typedef Vec_2<double> Vec_2d;

	template <class T> Vec_2<T> log ( const Vec_2<T> &v )             { return Vec_2<T>( std::log( v._x ), std::log( v._y ) ); }
	template <class T> Vec_2<T> pow ( const Vec_2<T> &v, T c )        { return Vec_2<T>( std::pow( v._x, c ), std::pow( v._y, c ) ); }
	
	template <class T> Vec_2<T> operator + ( const Vec_2<T> &v )      { return Vec_2<T>( +v._x, +v._y ); }
	template <class T> Vec_2<T> operator - ( const Vec_2<T> &v )      { return Vec_2<T>( -v._x, -v._y ); }
	template <class T> Vec_2<T> operator + ( T c, const Vec_2<T> &v ) { return Vec_2<T>( c + v._x, c + v._y ); }
	template <class T> Vec_2<T> operator - ( T c, const Vec_2<T> &v ) { return Vec_2<T>( c - v._x, c - v._y ); }
	template <class T> Vec_2<T> operator * ( T c, const Vec_2<T> &v ) { return Vec_2<T>( c * v._x, c * v._y ); }
	
	template <class T> Vec_2<T>& operator << ( Vec_2<T> &v, T data )                     { v._x = data; return v; }
	template <class T> Vec_2<T>& operator ,  ( Vec_2<T> &v, T data )                     { v._y = data; return v; }
	template <class T> std::ostream& operator << ( std::ostream &os, const Vec_2<T> &v ) { return os << "[ " << v._x << ", " << v._y << " ]"; }
}

#endif
