#include "Update.h"

void Main::Update() {
	if (info) {
		UpdateInfo();//deltaTime��fps�̌v�Z
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

			//�S�Ẵ{�[�����~�܂��Ă�����
			if (canShot) {
				UpdateLevel();
			}

			UpdateFallingRing();
		}
	}
}