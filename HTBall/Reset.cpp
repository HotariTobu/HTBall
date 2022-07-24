#include "Input.h"

//ニューゲームを始めるための関数の定義
void Reset(int mode) {
	//引数で分岐
	switch (mode) {
	case 1://強くてニューゲームだったら
		break;//分岐を抜ける
		
	case 2://易しくてニューゲームだったら
		ballMode = 0;//ボールのモードの代入

		balls.clear();//ボールの配列のクリア
		balls.push_back(Ball());//ボールの配列に最初のボールの追加

	case 3://強くて易しくてニューゲームだったら
		//難易度が易しすぎなかったら
		if (difficulty < MAXROW - 1) {
			difficulty++;//難易度を下げる
		}

		break;//分岐を抜ける
	}

	level = 1;//ステージレベルの代入

	launcherPos.x = (float)fontSize;//発射する前のボールのx座標の計算
	launcherPos.y = (float)(fontSize + blockSize * MAXROW / 2);//発射する前のボールのy座標の計算
	lastLauncherY = launcherPos.y;//前回の発射する前のボールのy座標の代入

	score = 0;//スコアの代入
	maxScoresStr.clear();//スコアの表示で最高点のスコアを出した回数を示す文字列のクリア

	//マップの要素数だけループ
	for (int i = 0; i < MAPSIZE; i++) {
		Main::SetMapAt(i, 0);//マップにはなにもない
	}

	//ブロックの追加
	for (int i = 0; i < MAXROW - difficulty; i++) {
		Main::SetMapAt(GetRand(MAXROW - 1) * MAXCOLUMN + 1, GetRand(1) + 1);//ランダムなブロックの配置
	}

	for (auto ite = locus.begin(); ite != locus.end(); ite++) {
		(*ite).clear();
	}
}