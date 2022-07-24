#include "Update.h"

void UpdateMouse() {
	//マウスのx座標が左端を超えたら
	if (pointer1.x < fontSize2) {
		pointer1.x = (float)fontSize2;//制限
	}

	double theta = atan2((double)launcherPos.y - (double)pointer1.y, (double)pointer1.x - (double)launcherPos.x);//発射する前のボールの座標とマウスの座標からボールのラジアンのボールが進む角度の計算

	//マウスのy座標が上端を超えたら
	if (pointer1.y < fontSize) {
		pointer1.x -= (fontSize - pointer1.y) / tanf((float)theta);//制限
		pointer1.y = (float)fontSize;//制限
	}
	//マウスのy座標が下端を超えたら
	else if (pointer1.y > bottomWall) {
		pointer1.x -= (bottomWall - pointer1.y) / tanf((float)theta);//制限
		pointer1.y = (float)bottomWall;//制限
	}

	//ボールの色が黄だったら
	if (ballMode == 2) {
		Vec2<float> dis1 = Vec2<float>();//発射する前のボールの座標とマウスの座標の距離の宣言
		dis1.x = (float)pointer1.x - launcherPos.x;//発射する前のボールの座標とマウスの座標の水平方向における距離の計算
		dis1.y = launcherPos.y - (float)pointer1.y;//発射する前のボールの座標とマウスの座標の水平方向における距離の計算

		pointer2.x = launcherPos.x + (float)(dis1.x * cos(addition) - dis1.y * sin(addition));//マウス２のx座標の計算
		pointer2.y = launcherPos.y - (float)(dis1.x * sin(addition) + dis1.y * cos(addition));//マウス２のy座標の計算

		//マウス２のy座標が上端を超えたら
		if (pointer2.y < fontSize) {
			pointer2.x -= (fontSize - pointer2.y) / tanf((float)(theta + addition));//制限
			pointer2.y = (float)fontSize;//制限
		}

		pointer3.x = launcherPos.x + (float)(dis1.x * cos(-addition) - dis1.y * sin(-addition));//マウス３のx座標の計算
		pointer3.y = launcherPos.y - (float)(dis1.x * sin(-addition) + dis1.y * cos(-addition));//マウス３のy座標の計算

		//マウス３のy座標が下端を超えたら
		if (pointer3.y > bottomWall) {
			pointer3.x -= (bottomWall - pointer3.y) / tanf((float)(theta - addition));//制限
			pointer3.y = (float)bottomWall;//制限
		}
	}
}