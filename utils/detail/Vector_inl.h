#ifndef AI_UTILS_DETAIL_VECTOR_INC__HPP
#define AI_UTILS_DETAIL_VECTOR_INC__HPP
#include <cassert>
#include <cmath>

namespace AI
{
namespace utils
{

template <typename T>
inline Vector<T>& Vector<T>::add(const Vector<T>& rhs) 
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::sub(const Vector<T>& rhs) 
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::mlt(T rhs) 
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::div(T rhs)
{
	assert(rhs != 0);
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::operator +=(const Vector<T>& rhs) {
	return add(rhs);
}

template <typename T>
inline Vector<T>& Vector<T>::operator -=(const Vector<T>& rhs) {
	return sub(rhs);
}

template <typename T>
inline Vector<T>& Vector<T>::operator *=(T rhs) {
	return mlt(rhs);
}

template <typename T>
inline Vector<T>& Vector<T>::operator /=(T rhs) {
	return div(rhs);
}

template <typename T>
inline Vector<T> Vector<T>::operator+(const Vector<T>& rhs) const {
	Vector<T> res(*this);
	return res.add(rhs);
}

template <typename T>
inline Vector<T> Vector<T>::operator-(const Vector<T>& rhs) const {
	Vector<T> res(*this);
	return res.sub(rhs);
}

template <typename T>
inline Vector<T> Vector<T>::operator*(T rhs) const {
	Vector<T> res(*this);
	return res.mlt(rhs);
}

template <typename T>
inline Vector<T> Vector<T>::operator/(T rhs) const {
	Vector<T> res(*this);
	return res.div(rhs);
}

template <typename T>
inline T Vector<T>::magnitude() const {
	return std::sqrt(x*x+y*y+z*z);
}

inline void Vector<T>::normalize() {
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
inline void Vector<T>::reverse() {
	x = -x;
	y = -y;
	z = -z;
}

template <typename T>
inline Vector<T>& Vector<T>::crossProduct(const Vector<T>& r) {
	Vector<T> t = *this;
	x = t.y*r.z-t.z*r.y;
	y = t.x*r.z+t.z*r.x;
	z = t.x*r.y-t.y*r.x;

	return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::operator ^ (const Vector<T>& r) const {
	return Vector(y*r.z-z*r.y, x*r.z+z*r.x, x*r.y-y*r.x);
}

template <typename T>
inline Vector<T>& Vector<T>::operator^=(const Vector<T>& r) {
	return crossProduct(r);
}

template <typename T>
inline T Vector<T>::dotProduct(const Vector<T>& rhs) const {
	return x*rhs.x+y*rhs.y+z*rhs.z;
}

template <typename T>
inline T Vector<T>::operator*(const Vector<T>& rhs) const {
	return dotProduct(rhs);
}

} // utils 
} // AI

#endif
