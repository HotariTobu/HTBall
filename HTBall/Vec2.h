#pragma once

#ifndef __Vec2_H_INCLUDED__
#define __Vec2_H_INCLUDED__

//��ɍ��W��\���\���̂̐錾
template <typename T>
class Vec2 {
public:
	T x, y;//���W�����[����ϐ��̐錾

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