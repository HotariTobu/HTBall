#include "Update.h"

void UpdateStandingBall() {
	unsigned int ballNum = (unsigned int)balls.size();//ボールの個数の初期化
	//発射していないボールがあったら
	if (ballStock < ballNum) {
		interval -= speed * movement;//ボールが発射される間隔の減算
		//ボールが発射される間隔が0以下になったら
		if (interval <= 0) {
			ballStock++;//動かせるボールの個数を増やす

			//ボールの色が黄だったら
			if (ballMode == 2) {
				ballStock += 2;//さらに動かせるボールの個数を増やす

				//動かせるボールの個数を増やしすぎたら
				if (ballStock > ballNum) {
					ballStock = ballNum;//動かせるボールの個数をボールの個数と同じにする
				}
			}

			Main::Log("%d個のボールを発射", ballStock);
			Main::ResetInterval();
		}
	}
}