#include "Input.h"

void KeyDown(int key) {
	switch (key) {
	case KEY_INPUT_Z:
	case KEY_INPUT_X:
	case KEY_INPUT_C:
	case KEY_INPUT_V:
		if (!canShot) {
			Main::Log("Warning : Behavior may shift !");//警告
		}
		break;
	}
}

void KeyUp(int key) {
	switch (key) {
	case KEY_INPUT_F2://スクショ
		isTryingScreenShot = true;
		break;

	case KEY_INPUT_F3://文字列の表示の切り替え
		info = !info;
		frame = baseFps;
		break;

	case KEY_INPUT_Z://スピードアップ
		movement++;
		break;

	case KEY_INPUT_C://スピードダウン
		movement--;
		break;

	case KEY_INPUT_D://デバッグ情報の切り替え
		debug = !debug;
		Main::Log("デバッグ情報表示の%s", (debug ? "あり" : "なし"));
		break;

	case KEY_INPUT_H://ヘルプの切り替え
		help = !help;
		break;

	case KEY_INPUT_K://ボール同士の衝突の切り替え
		ballsCo = !ballsCo;
		Main::Log("ボール同士の衝突%s", (ballsCo ? "あり" : "なし"));
		Main::ResetInterval();
		break;

	case KEY_INPUT_O://瞬間的の切り替え
		instantaneous = !instantaneous;
		Main::Log("Instantaneous mode %s", (instantaneous ? "on" : "off"));
		break;

	case KEY_INPUT_1://ゲームオーバーの入力
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
	case KEY_INPUT_X://スピードアップ
		movement += (int)deltaTime;
		break;
	case KEY_INPUT_V://スピードダウン
		movement -= (int)deltaTime;
		break;
	}
}