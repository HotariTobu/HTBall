#pragma once

#ifndef __Property_H_INCLUDED__
#define __Property_H_INCLUDED__

#include "pch.h"

#include "Vec2.h"
#include "Defines.h"
#include "Ball.h"

extern bool isGameover;//ゲームオーバーかどうか
extern bool canShot;//ボールを発射できるかどうか
extern bool isTryingScreenShot;//スクリーンショットを撮ろうとしているか
extern bool info;//文字列を表示するかどうか
extern bool debug;//デバッグ情報を表示するかどうか
extern bool help;//ヘルプを表示するかどうか
extern bool ballsCo;//ボール同士を衝突させるかどうか
extern bool instantaneous;//瞬間的かどうか
extern bool floating;//着地点が決定していないかどうか。
extern bool onePos;//1つのポジションに複数のボールがあるかどうか
extern bool lastOnePos;//前の1つのポジションに複数のボールがあるかどうか

extern unsigned int level;//ステージレベルの初期化
extern unsigned int frame;//フレーム数の宣言
extern unsigned int fps;//1秒間に更新されるフレームの数の宣言
extern unsigned int baseFps;//基準のfpsの宣言
extern unsigned int ballStock;//動かせるボールの個数の初期化
extern unsigned int white;//白を表すの宣言
extern unsigned int gray;//灰色を表すの宣言
extern unsigned int ballColors[7];//ボールの色の配列の宣言

extern float deltaTime;//デルタの宣言
extern float speed;//ボールの移動速度の宣言
extern int ballMode;//ボールのモードの宣言
extern int movement;//ボールが1フレームに動く回数の初期化
extern int difficulty;//難易度の宣言
extern double addition;//黄のボールの広がり具合の角度の宣言

extern unsigned long long score;//スコアの宣言
extern std::string maxScoresStr;//スコアの表示で最高点のスコアを出した回数を示す文字列の宣言

extern Vec2<int> clientSize;//描画範囲の宣言
extern Vec2<int> toExitPos;//終了の案内の座標の宣言
extern Vec2<float> launcherPos;//発射する前のボールの座標の宣言
extern Vec2<float> pointer1;//ボールの進む先１の座標の宣言
extern Vec2<float> pointer2;//ボールの進む先２の座標の宣言
extern Vec2<float> pointer3;//ボールの進む先３の座標の宣言

extern std::vector<Ball> balls;//ボールの配列の宣言
extern std::vector<Vec2<float>> fallingRings;//リングの配列の宣言
extern std::vector<std::vector<Vec2<float>>> locus;//軌跡の配列の宣言

#endif // !__PCH_H_INCLUDED__