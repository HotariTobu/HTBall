#include "Draw.h"

void DrawInfo() {
	//情報バーの表示
	{
		sprintfDx(info1, strings[0], fps);//fpsの文字列にfpsの値の挿入
		sprintfDx(info2, strings[1], balls.size());//ボールの個数の文字列にボールの配列の要素数の挿入
		sprintfDx(info3, strings[2], level);//レベルの文字列にレベルの値の挿入
		sprintfDx(info4, strings[3], score, maxScoresStr.c_str());//スコアの文字列にスコアの値の挿入
		sprintfDx(info5, strings[4], movement);//スピードの文字列にボールが1フレームに動く回数の挿入
		int width1 = GetDrawStringWidth(info1, (int)strlen(info1));//fpsの文字列の幅
		int width2 = GetDrawStringWidth(info2, (int)strlen(info2));//ボールの個数の文字列の幅
		int width3 = GetDrawStringWidth(info3, (int)strlen(info3));//レベルの文字列の幅
		int width4 = GetDrawStringWidth(info4, (int)strlen(info4));//スコアの文字列の幅
		int width5 = GetDrawStringWidth(info5, (int)strlen(info5));//スピードの文字列の幅
		int left1 = (clientSize.x - width1 - width2 - width3 - width4 - width5) / 2;//fpsの文字列の左端
		int left2 = left1 + width1;//ボールの個数の文字列の左端
		int left3 = left2 + width2;//レベルの文字列の左端
		int left4 = left3 + width3;//スコアの文字列の左端
		int left5 = left4 + width4;//スピードの文字列の左端
		int right = left1 + width1 + width2 + width3 + width4 + width5;//情報バーの右端
		DrawString(left1, 0, info1, white);//fpsの文字列の描画
		DrawString(left2, 0, info2, white);//ボールの個数の文字列の描画
		DrawString(left3, 0, info3, white);//レベルの文字列の描画
		DrawString(left4, 0, info4, white);//スコアの文字列の描画
		DrawString(left5, 0, info5, white);//スピードの文字列の描画

		DrawLine(left1 - 1, 0, left1 - 1, fontSize, white);//fpsの文字列の左端の線の描画
		DrawLine(left2 - 1, 0, left2 - 1, fontSize, white);//ボールの個数の文字列の左端の線の描画
		DrawLine(left3 - 1, 0, left3 - 1, fontSize, white);//レベルの文字列の左端の線の描画
		DrawLine(left4 - 1, 0, left4 - 1, fontSize, white);//スコアの文字列の左端の線の描画
		DrawLine(left5 - 1, 0, left5 - 1, fontSize, white);//スピードの文字列の左端の線の描画
		DrawLine(right + 1, 0, right + 1, fontSize, white);//情報バーの右端の線の描画
	}

	//ログの表示
	{
		//ログが消えるまでのカウントが０よりも大きかったら
		if (logCount > 0) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)logCount);//透過して描画する設定
			DrawString(0, toExitPos.y, logStr, white);//ログの文字列の描画
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//通常の描画の設定

			logCount -= deltaTime;//ログが消えるまでのカウントの減少
		}
	}

	//終了の案内の表示
	DrawString(toExitPos.x, toExitPos.y, strings[5], white);
}