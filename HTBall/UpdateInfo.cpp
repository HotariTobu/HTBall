#include "Update.h"

void UpdateInfo() {
	frame++;//�t���[�����̃C���N�������g

	newTime = GetNowCount();//���̎��Ԃ̑��
	//�O�̎��Ԃ���1�b�Ԃ��o�߂�����
	if (newTime - previousTime >= 1000) {
		fps = frame;//fps�̑��
		previousTime = newTime;//�O�̎��Ԃ̑��
		frame = 0;//�t���[���������ɖ߂�
	}
}