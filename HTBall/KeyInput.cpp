#include "Input.h"

void KeyDown(int key) {
	switch (key) {
	case KEY_INPUT_Z:
	case KEY_INPUT_X:
	case KEY_INPUT_C:
	case KEY_INPUT_V:
		if (!canShot) {
			Main::Log("Warning : Behavior may shift !");//�x��
		}
		break;
	}
}

void KeyUp(int key) {
	switch (key) {
	case KEY_INPUT_F2://�X�N�V��
		isTryingScreenShot = true;
		break;

	case KEY_INPUT_F3://������̕\���̐؂�ւ�
		info = !info;
		frame = baseFps;
		break;

	case KEY_INPUT_Z://�X�s�[�h�A�b�v
		movement++;
		break;

	case KEY_INPUT_C://�X�s�[�h�_�E��
		movement--;
		break;

	case KEY_INPUT_D://�f�o�b�O���̐؂�ւ�
		debug = !debug;
		Main::Log("�f�o�b�O���\����%s", (debug ? "����" : "�Ȃ�"));
		break;

	case KEY_INPUT_H://�w���v�̐؂�ւ�
		help = !help;
		break;

	case KEY_INPUT_K://�{�[�����m�̏Փ˂̐؂�ւ�
		ballsCo = !ballsCo;
		Main::Log("�{�[�����m�̏Փ�%s", (ballsCo ? "����" : "�Ȃ�"));
		Main::ResetInterval();
		break;

	case KEY_INPUT_O://�u�ԓI�̐؂�ւ�
		instantaneous = !instantaneous;
		Main::Log("Instantaneous mode %s", (instantaneous ? "on" : "off"));
		break;

	case KEY_INPUT_1://�Q�[���I�[�o�[�̓���
	case KEY_INPUT_2:
	case KEY_INPUT_3:
		if (isGameover) {
			Reset(key - KEY_INPUT_1 + 1);
			isGameover = false;
		}
		break;

	case KEY_INPUT_RETURN:
		if (canShot) {
			Shot();
			canShot = false;
		}
		break;
	}
}

void Key(int key) {
	switch (key) {
	case KEY_INPUT_X://�X�s�[�h�A�b�v
		movement += (int)deltaTime;
		break;
	case KEY_INPUT_V://�X�s�[�h�_�E��
		movement -= (int)deltaTime;
		break;
	}
}