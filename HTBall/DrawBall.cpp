#include "Draw.h"

void DrawBall() {
	//�{�[�������˂ł�����
	if (canShot) {
		DrawCircleAA(launcherPos.x, launcherPos.y, ballSize, 8, ballColors[ballMode]);//��Ԏ�O�ɂ���Ǝv����{�[���̂ݕ`��
	}
	//�{�[�������˂ł��Ȃ��Ȃ�
	else {
		//���ׂẴ{�[���𓮂����Ȃ�������
		if (ballStock < balls.size()) {
			DrawCircleAA(launcherPos.x, lastLauncherY, ballSize, 8, ballColors[ballMode]);//���˂���O�̃{�[���̕`��
		}

		unsigned int index = 0;//�`�悵���{�[���̌������[����ϐ��̐錾
		//�{�[���̔z��̑S�v�f�܂��͓�������{�[���̌������̃A�N�Z�X
		for (auto ite = balls.begin(); ite != balls.end() && index < ballStock; ite++, index++) {
			//�{�[�����~�܂��Ă��Ȃ�������
			if (!(*ite).stoped) {
				DrawCircleAA((*ite).x, (*ite).y, ballSize, 8, ballColors[ballMode]);//�{�[���̕`��
			}
		}

		//�{�[����1�ł������Ă�����
		if (!floating) {
			DrawCircleAA(launcherPos.x, launcherPos.y, ballSize, 8, ballColors[ballMode]);//���n�_�Ƀ{�[���̕`��
		}
	}
}