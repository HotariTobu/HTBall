#include "Ball.h"

#include "Defines.h"
#include "Property.h"
#include "Utilities.h"

//�{�[���̃|�W�V���������߂�֐��̒�`
void Ball::GetPos(int* row, int* column) {
	*row = ((int)y - fontSize) / blockSize;//�{�[���̃|�W�V�����̍s�̌v�Z
	*column = MAXCOLUMN - 1 - ((int)x - fontSize2) / blockSize;//�{�[���̃|�W�V�����̗�̌v�Z
}

double Ball::GetTheta() const {
	return theta;
}

void Ball::SetTheta(double value) {
	theta = value;

	//dtor(0) <= theta <= dtor(360)�ɂȂ�悤�ɂ���
	while (theta < 0) {
		theta += radian;
	}
	while (theta >= radian) {
		theta -= radian;
	}

	addX = (float)(speed * cos(theta));//�{�[����x���W�ɉ��Z����l�̌v�Z
	addY = (float)(speed * sin(theta));//�{�[����y���W�Ɍ��Z����l�̌v�Z

	for (int i = 0; i < 4; i++) {
		walls[i] = false;
	}
	int quadant = (int)(rtod(theta) / 90);//�ǂ̏ی��ɐi�ނ��̌v�Z
	walls[quadant] = walls[quadant == 3 ? 0 : quadant + 1] = true;//�v�Z����K�v����������̌���

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