#include "Update.h"

void UpdateRingSize() {
	ringPlus += deltaTime;//リングの大きさに加算される値の計算
			//リングの大きさに加算される値が128以上だったら
	if (ringPlus >= 128) {
		ringPlus = -ringPlus;//リングの大きさに加算される値の符号を反転する
	}
}