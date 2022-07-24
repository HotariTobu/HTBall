#include "Draw.h"

void DrawDebug() {
	//軌跡を描画する
	for (auto ite = locus.begin(); ite != locus.end(); ite++) {
		if ((*ite).size() >= 2) {
			auto end = (*ite).end() - 1;
			for (auto ite2 = (*ite).begin(); ite2 != end; ite2++) {
				DrawLineAA((*ite2).x, (*ite2).y, (*(ite2 + 1)).x, (*(ite2 + 1)).y, gray);
			}
		}
	}

	//ポスガイドを描画する
	for (int row = 0; row < MAXROW; row++) {
		TCHAR label[4];//数字の文字列
		sprintfDx(label, "%d", row);
		int width = GetDrawStringWidth(label, (int)strlen(label));//文字列の幅
		DrawStringToHandle((int)((clientSize.x - blockSize) + (blockSize - width) / 2), (int)((fontSize + row * blockSize) + BlockY), label, gray, bfH);
	}
	for (int column = 0; column < MAXCOLUMN; column++) {
		TCHAR label[4];//数字の文字列
		sprintfDx(label, "%d", column);
		int width = GetDrawStringWidth(label, (int)strlen(label));//文字列の幅
		DrawStringToHandle((int)((clientSize.x - (column + 1) * blockSize) + (blockSize - width) / 2), (int)((fontSize + MAXROW * blockSize) + BlockY), label, gray, bfH);
	}

	unsigned int index = 0;//インデックスを収納する変数の宣言
	int i = 1;//表示数
	//ボールの配列の全要素のアクセス
	for (auto ite = balls.begin(); ite != balls.end(); ite++, index++) {
		//ボールが止まっていないなら
		if (!(*ite).stoped) {
			int column, row;
			(*ite).GetPos(&column, &row);
			DrawFormatString(0, fontSize * i, white, "%5d|(%0.2f, %0.2f), (%d, %d), %0.2f度, %s%s%s%s", index, (*ite).x, (*ite).y, column, row, rtod((*ite).GetTheta()), ((*ite).walls[0] ? "→" : ""), ((*ite).walls[1] ? "↑" : ""), ((*ite).walls[2] ? "←" : ""), ((*ite).walls[3] ? "↓" : ""));//ボールのインデックス、座標、角度の描画
			i++;
		}
	}

	i = 1;
	for (index = 0; index < MAPSIZE; index++) {
		if (int value = Main::GetMapAt(index) != 0) {
			DrawFormatString(450, fontSize * i++, white, "%3d|%d(%s)", index, value, value == -2 ? "アイテム" : value == -1 ? "リング" : "ブロック");//マップの値の描画
		}
	}

	i = 1;
	DrawFormatString(600, fontSize * i++, white, "スクリーン|width = %d , height = %d", clientSize.x, clientSize.y);//描画範囲の描画
	DrawFormatString(600, fontSize * i++, white, "最大行数|%d", MAXROW);//最大行数の描画
	DrawFormatString(600, fontSize * i++, white, "最大列数|%d", MAXCOLUMN);//最大列数の描画
	DrawFormatString(600, fontSize * i++, white, "ボール：ブロック = 1：%f", BALLRATIO);//ボールを１としたときに対するブロックの大きさの描画
	DrawFormatString(600, fontSize * i++, white, "ログの文字列|%s", logStr);//ログの文字列の描画
	DrawFormatString(600, fontSize * i++, white, "フレーム数|%u", frame);//フレーム数の描画
	DrawFormatString(600, fontSize * i++, white, "今の時間|%d", newTime);//今の時間の描画
	DrawFormatString(600, fontSize * i++, white, "前の時間|%d", previousTime);//前の時間の描画
	DrawFormatString(600, fontSize * i++, white, "デルタ|%f", deltaTime);//デルタの描画
	DrawFormatString(600, fontSize * i++, white, "ボールの移動速度|%f", speed);//ボールの移動速度の描画
	DrawFormatString(600, fontSize * i++, white, "フォントサイズ|%d", fontSize);//文字列の高さの描画
	DrawFormatString(600, fontSize * i++, white, "ブロックサイズ|%d", blockSize);//ブロックの1辺の長さの描画
	DrawFormatString(600, fontSize * i++, white, "ボールの半径|%f", ballSize);//ボールの半径の描画
	DrawFormatString(600, fontSize * i++, white, "デッドライン|%d", deadline);//デッドラインの描画
	DrawFormatString(600, fontSize * i++, white, "右端|%f", rightEnd);//右端の描画
	DrawFormatString(600, fontSize * i++, white, "上端|%f", topEnd);//上端の描画
	DrawFormatString(600, fontSize * i++, white, "下端|%f", bottomEnd);//下端の描画
	DrawFormatString(600, fontSize * i++, white, "発射する位置|%f", lastLauncherY);//前回の発射する前のボールのy座標の描画
	DrawFormatString(600, fontSize * i++, white, "着地点|%f", launcherPos.y);//発射する前のボールのy座標の描画
	DrawFormatString(600, fontSize * i++, white, "ボールモード|%d", ballMode);//ボールのモードの描画
	DrawFormatString(600, fontSize * i++, white, "ボールの色|%u(%s)", ballColors[ballMode], ballMode == 0 ? "白" : ballMode == 1 ? "赤" : ballMode == 2 ? "黄" : ballMode == 3 ? "緑" : ballMode == 4 ? "シアン" : ballMode == 5 ? "青" : "紫");//ボールのモードの描画
	DrawFormatString(600, fontSize * i++, white, "発射の間隔|%f", interval);//ボールが発射される間隔の描画
	DrawFormatString(600, fontSize * i++, white, "ログカウント|%f", logCount);//ログが消えるまでのカウントの描画
	DrawFormatString(600, fontSize * i++, white, "リングプラス|%f", ringPlus);//リングの大きさに加算する値の描画
	DrawFormatString(600, fontSize * i++, white, "カラーウェーブ|%f", colorWave);//色の変化の値の描画
	DrawFormatString(600, fontSize * i++, white, "ボールストック数|%u", ballStock);//動かせるボールの個数の描画
	DrawFormatString(600, fontSize * i++, white, "難易度|%d", (MAXROW - difficulty));//難易度の描画
	DrawFormatString(600, fontSize * i++, white, "ポインター１|x = %f , y = %f", pointer1.x, pointer1.y);//ボールの進む先１の座標の描画
	DrawFormatString(600, fontSize * i++, white, "ポインター２|x = %f , y = %f", pointer2.x, pointer2.y);//ボールの進む先２の座標の描画
	DrawFormatString(600, fontSize * i++, white, "ポインター３|x = %f , y = %f", pointer3.x, pointer3.y);//ボールの進む先３の座標の描画
	DrawFormatString(600, fontSize * i++, white, "拡散具合|%f度", rtod(addition));//黄のボールの広がり具合の角度の描画
	DrawFormatString(600, fontSize * i++, white, "ボール同士が近い|%s", (onePos ? "はい" : "いいえ"));//ボール同士の近さの描画
}