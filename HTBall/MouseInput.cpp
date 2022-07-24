#include "Input.h"

void MouseDown(int button) {

}

void MouseUp(int button) {
	switch (button) {
	case MOUSE_INPUT_LEFT:
		if (canShot) {
			Shot();
			canShot = false;
		}
		break;
	}
}

void Mouse(int button) {

}

void MouseHover(Vec2<int> point) {

}

void MouseMove(Vec2<int> point, Vec2<int> dif) {
	if (canShot) {
		pointer1 = Vec2<float>((float)point.x, (float)point.y);//ボールの進む先１の座標の代入
	}
}

void Wheel(int volume) {
	addition += (double)volume * 0.05f;//黄のボールの広がり具合の角度に加算

	//黄のボールの広がり具合の角度が負の数になったら
	if (addition < 0.1f) {
		addition = 0.1f;//黄のボールの広がり具合の角度の代入
	}
	//黄のボールの広がり具合の角度が90度を超えたら
	else if (addition > quarterRadian) {
		addition = quarterRadian;//黄のボールの広がり具合の角度の代入
	}
}