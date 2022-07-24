#include "Draw.h"

void Main::Draw() {
	if (info) {
		DrawInfo();//������̕`��
	}
	DrawBall();//�{�[���̕`��
	DrawRing();//�����O�̕`��
	DrawBlock();//�u���b�N�̕`��
	if (canShot) {
		DrawShotLine();//�Ə����̕`��
	}
	DrawStageLine();//�X�e�[�W�̕`��
	if (isGameover) {
		DrawGameover();//�Q�[���I�[�o�[�̕`��
	}
	else if (help) {//�w���v�̕`��
		DrawHelp();
	}
	if (debug) {
		DrawDebug();//�f�o�b�O���̕`��
	}
}