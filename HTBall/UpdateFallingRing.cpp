#include "Update.h"

void UpdateFallingRing() {
	float ringSpeed = speed * movement * 2;//リングの落下速度の初期化
					//落下中のリングの個数だけループ
	for (auto ite = fallingRings.begin(); ite != fallingRings.end(); ite++) {
		float y = (*ite).y;//落下中のリングのy座標の取得
		y += ringSpeed;//落下中のリングのy座標にリングの落下速度の加算

		//落下中のリングのy座標が落ちたリングが止まるy座標を超えたら
		if (y > ringBar) {
			y = ringBar;//落下中のリングのy座標のの代入
		}

		(*ite).y = y;//落下中のリングのy座標の代入
	}
}