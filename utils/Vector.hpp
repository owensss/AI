#ifndef AI_UTILS_VECTOR_HPP
#define AI_UTILS_VECTOR_HPP

namespace AI
{
namespace utils
{

template <typename T>
class Vector {
	public:
		// ctor
		explicit Vector(T x, T y, T z) :x(x), y(y), z(z) {}
		// dtor
		~Vector()  {}
		// do not disable copy-ctor & copy-assign

		Vector<T>  operator+(const Vector<T>& rhs) const ;
		Vector<T>  operator-(const Vector<T>& rhs) const ;
		Vector<T>  operator*(T rhs) const ;
		Vector<T>  operator/(T rhs) const ;
		Vector<T>& operator+=(const Vector<T>& rhs) ;
		Vector<T>& operator-=(const Vector<T>& rhs) ;
		Vector<T>& operator*=(T rhs) ;
		Vector<T>& operator/=(T rhs) ;
		// 
		T          magnitude() const ;
		void       normalize();
		void       reverse();
		bool       operator==(const Vector<T>& rhs) const;
		// setter
		void       setX(T v) { x = v;}
		void       setY(T v) { y = v;}
		void       setZ(T v) { z = v;}
		// getter
		const T&   getX() const { return x; }
		const T&   getY() const { return y; }
		const T&   getZ() const { return z; }
		//
		Vector<T>& add(const Vector<T>& rhs);
		Vector<T>& sub(const Vector<T>& rhs);
		Vector<T>& mlt(const Vector<T>& rhs);
		Vector<T>& div(const Vector<T>& rhs);
	private:
		T x;
		T y;
		T z;
};

} // utils
} // AI

#include "detail\Vector_inl.h"

#endif
