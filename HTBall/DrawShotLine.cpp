#include "Draw.h"

void DrawShotLine() {
	DrawLineAA(launcherPos.x, launcherPos.y, (float)pointer1.x, (float)pointer1.y, ballColors[ballMode]);//�A���`�G�C���A�X�t���̐��̕\��

		//�{�[���̐F������������
	if (ballMode == 2) {
		DrawLineAA(launcherPos.x, launcherPos.y, pointer2.x, pointer2.y, ballColors[ballMode]);//�A���`�G�C���A�X�t���̐��̕\��
		DrawLineAA(launcherPos.x, launcherPos.y, pointer3.x, pointer3.y, ballColors[ballMode]);//�A���`�G�C���A�X�t���̐��̕\��
	}
}