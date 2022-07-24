#include "Vec2.h"

template <typename T>
Vec2<T>::Vec2() {
	this->x = 0;
	this->y = 0;
}

template <typename T>
Vec2<T>::Vec2(T x, T y) {
	this->x = x;
	this->y = y;
}

template <typename T>
Vec2<T>& Vec2<T>::operator =(const Vec2<T>& value) {
	x = value.x;
	y = value.y;
	return *this;
}

template <typename T>
Vec2<T> Vec2<T>::operator +(const Vec2<T>& value) {
	return Vec2<T>(*this) += value;
}

template <typename T>
Vec2<T>& Vec2<T>::operator +=(const Vec2<T>& value) {
	x += value.x;
	y += value.y;
	return *this;
}

template <typename T>
Vec2<T> Vec2<T>::operator -(const Vec2<T>& value) {
	return Vec2<T>(*this) -= value;
}

template <typename T>
Vec2<T>& Vec2<T>::operator -=(const Vec2<T>& value) {
	x -= value.x;
	y -= value.y;
	return *this;
}

template <typename T>
Vec2<T> Vec2<T>::operator *(const Vec2<T>& value) {
	return Vec2<T>(*this) *= value;
}

template <typename T>
Vec2<T>& Vec2<T>::operator *=(const Vec2<T>& value) {
	x *= value.x;
	y *= value.y;
	return *this;
}

template <typename T>
Vec2<T> Vec2<T>::operator /(const Vec2<T>& value) {
	return Vec2<T>(*this) /= value;
}

template <typename T>
Vec2<T>& Vec2<T>::operator /=(const Vec2<T>& value) {
	x /= value.x;
	y /= value.y;
	return *this;
}

template <typename T>
bool Vec2<T>::operator ==(const Vec2<T>& value) {
	return x == value.x && y == value.y;
}

template <typename T>
bool Vec2<T>::operator !=(const Vec2<T>& value) {
	return !(*this == value);
}

template <typename T>
Vec2<T> Vec2<T>::operator +() const {
	return *this;
}

template <typename T>
Vec2<T> Vec2<T>::operator -() const {
	return Vec2<T>(-x, -y);
}

template class Vec2<int>;
template class Vec2<float>;