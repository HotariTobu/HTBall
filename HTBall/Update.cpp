#include "Update.h"

void Main::Update() {
	if (info) {
		UpdateInfo();//deltaTimeとfpsの計算
	}

	UpdateColor();
	UpdateRingSize();

	if (!isGameover && !help) {
		if (canShot) {
			UpdateMouse();
		}
		else {
			UpdateInstantaneous();
			UpdateMovingBall();
			UpdateStandingBall();

			//全てのボールが止まっていたら
			if (canShot) {
				UpdateLevel();
			}

			UpdateFallingRing();
		}
	}
}