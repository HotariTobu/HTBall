#include "Draw.h"

void DrawBall() {
	//ボールが発射できたら
	if (canShot) {
		DrawCircleAA(launcherPos.x, launcherPos.y, ballSize, 8, ballColors[ballMode]);//一番手前にあると思われるボールのみ描画
	}
	//ボールが発射できないなら
	else {
		//すべてのボールを動かせなかったら
		if (ballStock < balls.size()) {
			DrawCircleAA(launcherPos.x, lastLauncherY, ballSize, 8, ballColors[ballMode]);//発射する前のボールの描画
		}

		unsigned int index = 0;//描画したボールの個数を収納する変数の宣言
		//ボールの配列の全要素または動かせるボールの個数だけのアクセス
		for (auto ite = balls.begin(); ite != balls.end() && index < ballStock; ite++, index++) {
			//ボールが止まっていなかったら
			if (!(*ite).stoped) {
				DrawCircleAA((*ite).x, (*ite).y, ballSize, 8, ballColors[ballMode]);//ボールの描画
			}
		}

		//ボールが1つでも落ちていたら
		if (!floating) {
			DrawCircleAA(launcherPos.x, launcherPos.y, ballSize, 8, ballColors[ballMode]);//着地点にボールの描画
		}
	}
}