#include "Draw.h"

void DrawRing() {
	for (auto ite = fallingRings.begin(); ite != fallingRings.end(); ite++) {
		DrawCircleAA((*ite).x, (*ite).y, ballSize4 + abs(ringPlus / 128.0f * ballSize), 16, white, false, ballSize);//�����O�̕`��
		DrawCircleAA((*ite).x, (*ite).y, ballSize, 8, ballColors[ballMode], true);//�����O�̒��̃{�[���̕`��
	}
}