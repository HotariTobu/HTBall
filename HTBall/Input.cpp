#include "Input.h"

char keyBuf[256] = {};//������Ă���L�[�̔z��̐錾
char lastKeyBuf[256] = {};//�O�ɉ�����Ă���L�[�̔z��̐錾

int lastMouseButton = 0;//�Ō�ɉ����ꂽ�}�E�X�̃{�^���̐錾
Vec2<int> lastMousePos = Vec2<int>();//�Ō�̃}�E�X�̈ʒu�̐錾

void Main::Input() {
	GetHitKeyStateAll(keyBuf);//�S�ẴL�[�̏�Ԃ̎擾
	for (int i = 0; i < 256; i++) {
		char press = keyBuf[i];
		if (press != lastKeyBuf[i]) {
			if (press) {
				KeyDown(i);
			}
			else {
				KeyUp(i);
			}
		}
		if (press) {
			Key(i);
		}
		lastKeyBuf[i] = keyBuf[i];
	}

	int bit = 1;//�_���������邽�߂̃V�t�^�[
	int mouseButton = GetMouseInput();//�}�E�X�̃{�^���̎擾
	int mouseButtonX = mouseButton ^ lastMouseButton;//�}�E�X�̃{�^���̍���
	for (int i = 0; i < 8; i++) {
		bool press = (mouseButton & bit) != 0;
		if ((mouseButtonX & bit) != 0) {
			if (press) {
				MouseDown(bit);
			}
			else {
				MouseUp(bit);
			}
		}
		if (press) {
			Mouse(bit);
		}
	}
	lastMouseButton = mouseButton;

	Vec2<int> mousePos = Vec2<int>();//�}�E�X�̍��W�̐錾
	GetMousePoint(&mousePos.x, &mousePos.y);//�}�E�X�̍��W�̎擾
	if (mousePos == lastMousePos) {
		MouseHover(mousePos);
	}
	else {
		MouseMove(mousePos, mousePos - lastMousePos);
	}

	int wheelVolume = GetMouseWheelRotVol();
	if (wheelVolume != 0) {
		Wheel(wheelVolume);
	}

	//�X�s�[�h����
	if (movement < 0) {
		movement = 0;
	}
}