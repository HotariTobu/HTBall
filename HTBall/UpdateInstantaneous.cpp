#include "Update.h"

void UpdateInstantaneous() {
	//�u�ԓI���{�[�����m���Փ˂���Ȃ�
	if (instantaneous && ballsCo && (onePos ^ lastOnePos)) {
		movement = onePos ? 1 : 32;//�����̍X�V
	}
	lastOnePos = onePos;//1�̃|�W�V�����ɕ����̃{�[�������邩�ǂ����̍X�V
	onePos = false;//1�̃|�W�V�����ɕ����̃{�[���͂Ȃ�
}