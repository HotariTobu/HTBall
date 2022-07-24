#include "Update.h"

void UpdateColor() {
	colorWave += deltaTime;//色の変化の値の計算
	//色の変化の値が4096以上だったら
	if (colorWave >= 4096) {
		colorWave = -colorWave;//色の変化の値の符号を反転する
	}
}