#include "Update.h"

void UpdateInfo() {
	frame++;//フレーム数のインクリメント

	newTime = GetNowCount();//今の時間の代入
	//前の時間から1秒間が経過したら
	if (newTime - previousTime >= 1000) {
		fps = frame;//fpsの代入
		previousTime = newTime;//前の時間の代入
		frame = 0;//フレーム数を元に戻す
	}
}