#include "Draw.h"

void DrawGameover() {
	DrawGraph((clientSize.x - MAXROW * 3 / 2 * blockSize) / 2, fontSize2, ghH, true);//背景の描画

	int goHWidth = GetDrawStringWidthToHandle(strings[6], (int)strlen(strings[6]), goH);//「ゲームオーバー」の幅の取得
	DrawStringToHandle((clientSize.x - goHWidth) / 2, fontSize2 + blockSize, strings[6], GetColorFromHSV(fmodf(abs(colorWave / 4096.0f) * 360.0f, 60.0f) / 360.0f, 1.0f, 1.0f), goH);//「ゲームオーバー」の描画

	//3回ループ
	for (int i = 7; i < 10; i++) {
		int buttonWidth = GetDrawStringWidthToHandle(strings[i], (int)strlen(strings[i]), btH);//ボタンの幅の取得
		DrawStringToHandle((clientSize.x - MAXROW * 3 / 2 * blockSize) / 2 + blockSize, fontSize2 + blockSize * (i - 3), strings[i], 0, btH);//ボタンの描画
	}

	int buttonWidth = GetDrawStringWidthToHandle(strings[10], (int)strlen(strings[10]), btH);//ボタンの幅の取得
	DrawStringToHandle((clientSize.x - buttonWidth) / 2, fontSize2 + blockSize * 8, strings[10], GetColor(20, 20, 250), btH);//ボタンの描画
}