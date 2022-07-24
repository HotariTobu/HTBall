#include "Input.h"

void Shot() {
	floating = true;//着地点が設定されていない

	ballStock = 1;//動かせるボールの個数を1個にする。

	//ボールの色が黄だったら
	if (ballMode == 2) {
		ballStock += 2;//さらに動かせるボールの個数を増やす

		//動かせるボールの個数を増やしすぎたら
		if (ballStock > balls.size()) {
			ballStock = (unsigned int)balls.size();//動かせるボールの個数をボールの個数と同じにする
		}
	}

	Main::Log("%d個のボールを発射", ballStock);

	double theta = atan2((double)launcherPos.y - (double)pointer1.y, (double)pointer1.x - (double)launcherPos.x);//発射する前のボールの座標とマウスの座標からボールのラジアンのボールが進む角度の計算

	for (auto ite = locus.begin(); ite != locus.end(); ite++) {
		(*ite).clear();
	}

	int i = 0;
	//ボールの配列の全要素のアクセス
	for (auto ite = balls.begin(); ite != balls.end(); ite++, i++) {
		(*ite).x = launcherPos.x;//ボールのx座標の代入
		(*ite).y = launcherPos.y;//ボールのy座標の代入
		(*ite).SetTheta(ballMode == 2 ? i % 3 == 0 ? theta : i % 3 == 1 ? theta + addition : theta - addition : theta);//ラジアンのボールが進む角度の代入
		(*ite).moving = true;//ボールが動けるように
		(*ite).stoped = false;//ボールは止まっていない
	}
}