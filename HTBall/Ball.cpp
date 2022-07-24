#include "Ball.h"

#include "Defines.h"
#include "Property.h"
#include "Utilities.h"

//ボールのポジションを求める関数の定義
void Ball::GetPos(int* row, int* column) {
	*row = ((int)y - fontSize) / blockSize;//ボールのポジションの行の計算
	*column = MAXCOLUMN - 1 - ((int)x - fontSize2) / blockSize;//ボールのポジションの列の計算
}

double Ball::GetTheta() const {
	return theta;
}

void Ball::SetTheta(double value) {
	theta = value;

	//dtor(0) <= theta <= dtor(360)になるようにする
	while (theta < 0) {
		theta += radian;
	}
	while (theta >= radian) {
		theta -= radian;
	}

	addX = (float)(speed * cos(theta));//ボールのx座標に加算する値の計算
	addY = (float)(speed * sin(theta));//ボールのy座標に減算する値の計算

	for (int i = 0; i < 4; i++) {
		walls[i] = false;
	}
	int quadant = (int)(rtod(theta) / 90);//どの象限に進むかの計算
	walls[quadant] = walls[quadant == 3 ? 0 : quadant + 1] = true;//計算する必要がある方向の決定

	if (debug) {
		unsigned int index = 0;
		for (auto ite = balls.begin(); ite != balls.end(); ite++, index++) {
			if (&(*ite) == this) {
				break;
			}
		}

		if (index != balls.size()) {
			while (index >= locus.size()) {
				locus.push_back(std::vector<Vec2<float>>());
			}

			locus[index].push_back(Vec2<float>(x, y));
		}
	}
}