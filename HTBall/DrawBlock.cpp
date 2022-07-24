#include "Draw.h"

void DrawBlock() {
	for (int row = 0; row < MAXROW; row++) {
		for (int column = 0; column < MAXCOLUMN; column++) {
			int value = Main::GetMapAt(row * MAXCOLUMN + column);//マップの値の初期化

			//リングかアイテムだったら
			if (value < 0) {
				Vec2<float> ring = Vec2<float>();//リングかアイテムの座標の宣言
				ring.x = clientSize.x - (column + 1) * blockSize + halfBlockSize;//リングかアイテムのx座標の計算
				ring.y = fontSize + row * blockSize + halfBlockSize;//リングかアイテムのy座標の計算

				//リングかアイテムかで分岐
				switch (value) {
					//アイテムだったら
				case -2:
					DrawCircleAA(ring.x, ring.y, ballSize4, 16, GetColorFromHSV(abs(colorWave / 4096.0f), 1.0f, 1.0f), true);//カラフルなアイテムの描画

					break;//分岐を抜ける

					//リングだったら
				case -1:
					DrawCircleAA(ring.x, ring.y, ballSize4 + abs(ringPlus / 128.0f * ballSize), 16, white, false, ballSize);//リングの描画
					DrawCircleAA(ring.x, ring.y, ballSize, 8, ballColors[ballMode], true);//リングの中のボールの描画

					break;//分岐を抜ける
				}
			}
			//ブロックだったら
			else if (value > 0) {
				Vec2<int> block = Vec2<int>();//ブロックの座標の宣言
				block.x = clientSize.x - (column + 1) * blockSize;//ブロックのx座標の計算
				block.y = fontSize + row * blockSize;//ブロックのy座標の計算

				DrawBoxAA(block.x + 0.5f, block.y + 0.5f, block.x + blockSize - 0.5f, block.y + blockSize - 0.5f, GetColorFromHSV(value % 360 / 360.0f, 1.0f, min(1.0f - value / 3600.0f, 1.0f)), true);//耐久度から色を決定しブロックの描画

				TCHAR label[16];//ブロックに貼る数字の文字列
				sprintfDx(label, "%d", value);//ブロックに貼る数字の文字列に耐久度の挿入
				int width = GetDrawStringWidth(label, (int)strlen(label));//ブロックに貼る数字の文字列の幅
				 //ブロックに貼る数字の文字列の幅がブロックの幅を超えなかったら
				if (width < blockSize) {
					DrawStringToHandle((int)(block.x + (blockSize - width) / 2), (int)(block.y + BlockY), label, white, bfH);//ブロックの耐久度の描画
				}
			}
		}
	}
}