#pragma once

#ifndef __Vec2_H_INCLUDED__
#define __Vec2_H_INCLUDED__

//主に座標を表す構造体の宣言
template <typename T>
class Vec2 {
public:
	T x, y;//座標を収納する変数の宣言

	Vec2();
	Vec2(T x, T y);

	Vec2<T>& operator =(const Vec2<T>& value);

	Vec2<T> operator +(const Vec2<T>& value);
	Vec2<T>& operator +=(const Vec2<T>& value);
	Vec2<T> operator -(const Vec2<T>& value);
	Vec2<T>& operator -=(const Vec2<T>& value);
	Vec2<T> operator *(const Vec2<T>& value);
	Vec2<T>& operator *=(const Vec2<T>& value);
	Vec2<T> operator /(const Vec2<T>& value);
	Vec2<T>& operator /=(const Vec2<T>& value);

	bool operator ==(const Vec2<T>& value);
	bool operator !=(const Vec2<T>& value);

	Vec2<T> operator +() const;
	Vec2<T> operator -() const;
};

#endif // !__Vec2_H_INCLUDED__