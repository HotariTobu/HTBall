#include "Input.h"

void Shot() {
	floating = true;//���n�_���ݒ肳��Ă��Ȃ�

	ballStock = 1;//��������{�[���̌���1�ɂ���B

	//�{�[���̐F������������
	if (ballMode == 2) {
		ballStock += 2;//����ɓ�������{�[���̌��𑝂₷

		//��������{�[���̌��𑝂₵��������
		if (ballStock > balls.size()) {
			ballStock = (unsigned int)balls.size();//��������{�[���̌����{�[���̌��Ɠ����ɂ���
		}
	}

	Main::Log("%d�̃{�[���𔭎�", ballStock);

	double theta = atan2((double)launcherPos.y - (double)pointer1.y, (double)pointer1.x - (double)launcherPos.x);//���˂���O�̃{�[���̍��W�ƃ}�E�X�̍��W����{�[���̃��W�A���̃{�[�����i�ފp�x�̌v�Z

	for (auto ite = locus.begin(); ite != locus.end(); ite++) {
		(*ite).clear();
	}

	int i = 0;
	//�{�[���̔z��̑S�v�f�̃A�N�Z�X
	for (auto ite = balls.begin(); ite != balls.end(); ite++, i++) {
		(*ite).x = launcherPos.x;//�{�[����x���W�̑��
		(*ite).y = launcherPos.y;//�{�[����y���W�̑��
		(*ite).SetTheta(ballMode == 2 ? i % 3 == 0 ? theta : i % 3 == 1 ? theta + addition : theta - addition : theta);//���W�A���̃{�[�����i�ފp�x�̑��
		(*ite).moving = true;//�{�[����������悤��
		(*ite).stoped = false;//�{�[���͎~�܂��Ă��Ȃ�
	}
}