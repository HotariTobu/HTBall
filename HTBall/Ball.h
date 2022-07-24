#pragma once

#ifndef __BALL_H_INCLUDED__
#define __BALL_H_INCLUDED__

#include "pch.h"

class Ball
{
public:
	float x, y;//ボールの座標を収納する変数の宣言
	float addX, addY;//ボールの座標に加減算する変数の宣言
	bool moving;//動けるかどうかの宣言
	bool stoped;//止まったかどうかの宣言

	/*
	0：右方向に対する当たり判定を計算する必要があるかどうか
	1：上方向に対する当たり判定を計算する必要があるかどうか
	2：左方向に対する当たり判定を計算する必要があるかどうか
	3：下方向に対する当たり判定を計算する必要があるかどうか
	*/
	bool walls[4];

	void GetPos(int* column, int* row);//ボールのポジションを求める関数の宣言
	double GetTheta() const;//ラジアンのボールが進む角度の取得
	void SetTheta(double value);//ラジアンのボールが進む角度の設定

private:
	double theta;//ラジアンのボールが進む角度の宣言
};

#endif // !__BALL_H_INCLUDED__