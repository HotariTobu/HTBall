#include "Update.h"

void UpdateFallingRing() {
	float ringSpeed = speed * movement * 2;//�����O�̗������x�̏�����
					//�������̃����O�̌��������[�v
	for (auto ite = fallingRings.begin(); ite != fallingRings.end(); ite++) {
		float y = (*ite).y;//�������̃����O��y���W�̎擾
		y += ringSpeed;//�������̃����O��y���W�Ƀ����O�̗������x�̉��Z

		//�������̃����O��y���W�������������O���~�܂�y���W�𒴂�����
		if (y > ringBar) {
			y = ringBar;//�������̃����O��y���W�̂̑��
		}

		(*ite).y = y;//�������̃����O��y���W�̑��
	}
}