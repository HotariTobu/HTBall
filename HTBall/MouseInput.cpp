#include "Input.h"

void MouseDown(int button) {

}

void MouseUp(int button) {
	switch (button) {
	case MOUSE_INPUT_LEFT:
		if (canShot) {
			Shot();
			canShot = false;
		}
		break;
	}
}

void Mouse(int button) {

}

void MouseHover(Vec2<int> point) {

}

void MouseMove(Vec2<int> point, Vec2<int> dif) {
	if (canShot) {
		pointer1 = Vec2<float>((float)point.x, (float)point.y);//�{�[���̐i�ސ�P�̍��W�̑��
	}
}

void Wheel(int volume) {
	addition += (double)volume * 0.05f;//���̃{�[���̍L�����̊p�x�ɉ��Z

	//���̃{�[���̍L�����̊p�x�����̐��ɂȂ�����
	if (addition < 0.1f) {
		addition = 0.1f;//���̃{�[���̍L�����̊p�x�̑��
	}
	//���̃{�[���̍L�����̊p�x��90�x�𒴂�����
	else if (addition > quarterRadian) {
		addition = quarterRadian;//���̃{�[���̍L�����̊p�x�̑��
	}
}