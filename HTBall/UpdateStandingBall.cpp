#include "Update.h"

void UpdateStandingBall() {
	unsigned int ballNum = (unsigned int)balls.size();//�{�[���̌��̏�����
	//���˂��Ă��Ȃ��{�[������������
	if (ballStock < ballNum) {
		interval -= speed * movement;//�{�[�������˂����Ԋu�̌��Z
		//�{�[�������˂����Ԋu��0�ȉ��ɂȂ�����
		if (interval <= 0) {
			ballStock++;//��������{�[���̌��𑝂₷

			//�{�[���̐F������������
			if (ballMode == 2) {
				ballStock += 2;//����ɓ�������{�[���̌��𑝂₷

				//��������{�[���̌��𑝂₵��������
				if (ballStock > ballNum) {
					ballStock = ballNum;//��������{�[���̌����{�[���̌��Ɠ����ɂ���
				}
			}

			Main::Log("%d�̃{�[���𔭎�", ballStock);
			Main::ResetInterval();
		}
	}
}