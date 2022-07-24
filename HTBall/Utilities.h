#pragma once

#ifndef __UTILITIES_H_INCLUDED__
#define __UTILITIES_H_INCLUDED__

#include "pch.h"

//HSV色空間からDxLib標準の色を表す整数を求める関数の定義
extern int GetColorFromHSV(float h, float s, float v);

//ラジアンから度を求める関数の定義
extern double rtod(double radian);

//度からラジアンを求める関数の定義
extern double dtor(double degree);

#endif // !__UTILITIES_H_INCLUDED__
