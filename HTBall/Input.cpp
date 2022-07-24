#include "Input.h"

char keyBuf[256] = {};//押されているキーの配列の宣言
char lastKeyBuf[256] = {};//前に押されているキーの配列の宣言

int lastMouseButton = 0;//最後に押されたマウスのボタンの宣言
Vec2<int> lastMousePos = Vec2<int>();//最後のマウスの位置の宣言

void Main::Input() {
	GetHitKeyStateAll(keyBuf);//全てのキーの状態の取得
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

	int bit = 1;//論理走査するためのシフター
	int mouseButton = GetMouseInput();//マウスのボタンの取得
	int mouseButtonX = mouseButton ^ lastMouseButton;//マウスのボタンの差分
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

	Vec2<int> mousePos = Vec2<int>();//マウスの座標の宣言
	GetMousePoint(&mousePos.x, &mousePos.y);//マウスの座標の取得
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

	//スピード調節
	if (movement < 0) {
		movement = 0;
	}
}