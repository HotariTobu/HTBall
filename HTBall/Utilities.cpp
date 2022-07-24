#include "Utilities.h"

//HSV色空間からDxLib標準の色を表す整数を求める関数の定義
int GetColorFromHSV(float h, float s, float v) {
	float r = v;//赤要素の初期化(0.0f～1.0f)
	float g = v;//緑要素の初期化(0.0f～1.0f)
	float b = v;//青要素の初期化(0.0f～1.0f)
	//彩度が0.0f以上なら
	if (s > 0.0f) {
		h *= 6.0f;//色相に6.0fを乗算
		const int i = (int)h;//色相の整数部分の初期化
		const float f = h - (float)i;//色相の小数部分の計算
		//色相の整数部分の分岐
		switch (i) {
			//色相の整数部分が負の数または6以上だったら
		default://色相の整数部分が0だったときと同じ処理

			//色相の整数部分が0だったら
		case 0:
			g *= 1.0f - s * (1.0f - f);//緑要素の乗算
			b *= 1.0f - s;//青要素の乗算
			break;//分岐を抜ける

			//色相の整数部分が1だったら
		case 1:
			r *= 1.0f - s * f;//赤要素の乗算
			b *= 1.0f - s;//青要素の乗算
			break;//分岐を抜ける

			//色相の整数部分が2だったら
		case 2:
			r *= 1.0f - s;//赤要素の乗算
			b *= 1.0f - s * (1.0f - f);//青要素の乗算
			break;//分岐を抜ける

			//色相の整数部分が3だったら
		case 3:
			r *= 1.0f - s;//赤要素の乗算
			g *= 1.0f - s * f;//緑要素の乗算
			break;//分岐を抜ける

			//色相の整数部分が4だったら
		case 4:
			r *= 1.0f - s * (1.0f - f);//赤要素の乗算
			g *= 1.0f - s;//緑要素の乗算
			break;//分岐を抜ける

			//色相の整数部分が5だったら
		case 5:
			g *= 1.0f - s;//緑要素の乗算
			b *= 1.0f - s * f;//青要素の乗算
			break;//分岐を抜ける
		}
	}

	int red = (int)(r * 255);//赤要素の初期化(0～255)
	int green = (int)(g * 255);//緑要素の初期化(0～255)
	int blue = (int)(b * 255);//青要素の初期化(0～255)

	return GetColor(red, green, blue);//DxLibの色の計算
}

//ラジアンから度を求める関数の定義
double rtod(double radian) {
	return 180 / DX_PI * radian;//ラジアンから度を求める計算
}

//度からラジアンを求める関数の定義
double dtor(double degree) {
	return DX_PI / 180 * degree;//度からラジアンを求める計算
}