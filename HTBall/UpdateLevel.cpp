#include "Update.h"

void UpdateLevel() {
	level++;//レベルを上げる

	unsigned int ballNum = (unsigned int)balls.size();//ボールの個数の初期化

	//ブロックの追加
	for (int i = 0; i < MAXROW - difficulty; i++) {
		Main::SetMapAt(GetRand(MAXROW - 1) * MAXCOLUMN, GetRand(ballNum - 1) + GetRand(level - 1) + 1);//ランダムなブロックの配置
	}

	Main::SetMapAt(GetRand(MAXROW - 1) * MAXCOLUMN, -1);//必ず1つのリングの配置

	bool item = true;//アイテムがないかどうかの初期化

	//マップ上のものを左にシフトする
	for (int row = 0; row < MAXROW; row++) {
		int mapIndex = row * MAXCOLUMN;//マップの要素番号の初期化
		for (int column = MAXCOLUMN - 2; column >= 0; column--) {
			int value = Main::GetMapAt(mapIndex + column);
			Main::SetMapAt(mapIndex + column + 1, value);//シフト

			//左端のポジションだったら
			if (column == MAXCOLUMN - 2) {
				//リングかアイテムだったら
				if (value <= 0) {
					Main::SetMapAt(mapIndex + column + 1, 0);//左端は無
				}
				//ブロックだったら
				else {
					isGameover = true;//ゲームオーバー
				}
			}
			//右端のポジションだったら
			else if (column == 0) {
				Main::SetMapAt(mapIndex + column, 0);//右端は無
			}

			//アイテムがあったら
			if (Main::GetMapAt(mapIndex + column + 1) == -2) {
				item = false;//アイテムはある
			}
		}
	}

	//アイテムがない、かつ1/4の確率で
	if (item && GetRand(3) == 0) {
		Main::SetMapAt(GetRand(MAXROW - 1) * MAXCOLUMN + 1, -2);//ランダムなアイテムの配置
	}

	//落下中のリングの個数だけループ
	for (size_t i = 0; i < fallingRings.size(); i++) {
		balls.push_back(Ball());//ボールの配列にボールを追加
	}
	fallingRings.clear();//落下中のリングはない

	lastLauncherY = launcherPos.y;//前回の発射する前のボールのy座標の代入

	if (isGameover) {
		PlaySoundMem(gsH, DX_PLAYTYPE_BACK);//ゲームオーバー音のバック再生
	}
}