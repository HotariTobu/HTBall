#include "Update.h"

void UpdateMouse() {
	//�}�E�X��x���W�����[�𒴂�����
	if (pointer1.x < fontSize2) {
		pointer1.x = (float)fontSize2;//����
	}

	double theta = atan2((double)launcherPos.y - (double)pointer1.y, (double)pointer1.x - (double)launcherPos.x);//���˂���O�̃{�[���̍��W�ƃ}�E�X�̍��W����{�[���̃��W�A���̃{�[�����i�ފp�x�̌v�Z

	//�}�E�X��y���W����[�𒴂�����
	if (pointer1.y < fontSize) {
		pointer1.x -= (fontSize - pointer1.y) / tanf((float)theta);//����
		pointer1.y = (float)fontSize;//����
	}
	//�}�E�X��y���W�����[�𒴂�����
	else if (pointer1.y > bottomWall) {
		pointer1.x -= (bottomWall - pointer1.y) / tanf((float)theta);//����
		pointer1.y = (float)bottomWall;//����
	}

	//�{�[���̐F������������
	if (ballMode == 2) {
		Vec2<float> dis1 = Vec2<float>();//���˂���O�̃{�[���̍��W�ƃ}�E�X�̍��W�̋����̐錾
		dis1.x = (float)pointer1.x - launcherPos.x;//���˂���O�̃{�[���̍��W�ƃ}�E�X�̍��W�̐��������ɂ����鋗���̌v�Z
		dis1.y = launcherPos.y - (float)pointer1.y;//���˂���O�̃{�[���̍��W�ƃ}�E�X�̍��W�̐��������ɂ����鋗���̌v�Z

		pointer2.x = launcherPos.x + (float)(dis1.x * cos(addition) - dis1.y * sin(addition));//�}�E�X�Q��x���W�̌v�Z
		pointer2.y = launcherPos.y - (float)(dis1.x * sin(addition) + dis1.y * cos(addition));//�}�E�X�Q��y���W�̌v�Z

		//�}�E�X�Q��y���W����[�𒴂�����
		if (pointer2.y < fontSize) {
			pointer2.x -= (fontSize - pointer2.y) / tanf((float)(theta + addition));//����
			pointer2.y = (float)fontSize;//����
		}

		pointer3.x = launcherPos.x + (float)(dis1.x * cos(-addition) - dis1.y * sin(-addition));//�}�E�X�R��x���W�̌v�Z
		pointer3.y = launcherPos.y - (float)(dis1.x * sin(-addition) + dis1.y * cos(-addition));//�}�E�X�R��y���W�̌v�Z

		//�}�E�X�R��y���W�����[�𒴂�����
		if (pointer3.y > bottomWall) {
			pointer3.x -= (bottomWall - pointer3.y) / tanf((float)(theta - addition));//����
			pointer3.y = (float)bottomWall;//����
		}
	}
}