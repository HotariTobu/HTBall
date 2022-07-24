#include "Draw.h"

void DrawShotLine() {
	DrawLineAA(launcherPos.x, launcherPos.y, (float)pointer1.x, (float)pointer1.y, ballColors[ballMode]);//アンチエイリアス付きの線の表示

		//ボールの色が黄だったら
	if (ballMode == 2) {
		DrawLineAA(launcherPos.x, launcherPos.y, pointer2.x, pointer2.y, ballColors[ballMode]);//アンチエイリアス付きの線の表示
		DrawLineAA(launcherPos.x, launcherPos.y, pointer3.x, pointer3.y, ballColors[ballMode]);//アンチエイリアス付きの線の表示
	}
}