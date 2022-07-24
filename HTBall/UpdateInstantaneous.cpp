#include "Update.h"

void UpdateInstantaneous() {
	//瞬間的かつボール同士が衝突するなら
	if (instantaneous && ballsCo && (onePos ^ lastOnePos)) {
		movement = onePos ? 1 : 32;//早さの更新
	}
	lastOnePos = onePos;//1つのポジションに複数のボールがあるかどうかの更新
	onePos = false;//1つのポジションに複数のボールはない
}