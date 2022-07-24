#include "Draw.h"

void Main::Draw() {
	if (info) {
		DrawInfo();//文字列の描画
	}
	DrawBall();//ボールの描画
	DrawRing();//リングの描画
	DrawBlock();//ブロックの描画
	if (canShot) {
		DrawShotLine();//照準線の描画
	}
	DrawStageLine();//ステージの描画
	if (isGameover) {
		DrawGameover();//ゲームオーバーの描画
	}
	else if (help) {//ヘルプの描画
		DrawHelp();
	}
	if (debug) {
		DrawDebug();//デバッグ情報の描画
	}
}