#ifndef AI_UTILS_DETAIL_VECTOR_INC__HPP
#define AI_UTILS_DETAIL_VECTOR_INC__HPP
#include <cassert>
#include <cmath>

namespace AI
{
namespace utils
{

template <typename T>
Vector<T>& Vector<T>::add(const Vector<T>& rhs) 
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::sub(const Vector<T>& rhs) 
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::mlt(T rhs) 
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::div(T rhs)
{
	assert(rhs != 0);
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator +=(const Vector<T>& rhs) {
	return add(rhs);
}

template <typename T>
Vector<T>& Vector<T>::operator -=(const Vector<T>& rhs) {
	return sub(rhs);
}

template <typename T>
Vector<T>& Vector<T>::operator *=(T rhs) {
	return mlt(rhs);
}

template <typename T>
Vector<T>& Vector<T>::operator /=(T rhs) {
	return div(rhs);
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& rhs) const {
	Vector<T> res(*this);
	return res.add(rhs);
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& rhs) const {
	Vector<T> res(*this);
	return res.sub(rhs);
}

template <typename T>
Vector<T> Vector<T>::operator*(T rhs) const {
	Vector<T> res(*this);
	return res.mlt(rhs);
}

template <typename T>
Vector<T> Vector<T>::operator/(T rhs) const {
	Vector<T> res(*this);
	return res.div(rhs);
}

template <typename T>
T Vector<T>::magnitude() const {
	return std::sqrt(x*x+y*y+z*z);
}

void Vector<T>::normalize() {
	static const T tolerant = 0.0001;
	T mag = magnitude();
	if (mag <= tolerant) mag = 1;

	x /= mag;
	y /= mag;
	z /= mag;

	if (fabs(x) < tolerant) x = 0.0;
	if (fabs(y) < tolerant) y = 0.0;
	if (fabs(z) < tolerant) z = 0.0;
}

template <typename T>
void Vector<T>::reverse() {
	x = -x;
	y = -y;
	z = -z;
}

} // utils 
} // AI

#endif
