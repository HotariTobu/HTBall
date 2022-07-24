#pragma once

#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED

#include "pch.h"

//最大行数の定義（2の倍数）
#define MAXROW 12

//最大列数の定義
#define MAXCOLUMN (MAXROW * 2)

//マップサイズの定義
#define MAPSIZE (MAXROW * MAXCOLUMN)

//ボールを１としたときに対するブロックの大きさの定義
#define BALLRATIO 16.0f

//ボールが発射される間隔の定義
#define INTERVAL 4

//文字列の初期化
extern const TCHAR strings[][32];
extern TCHAR info1[16];//fpsの文字列
extern TCHAR info2[128];//ボールの個数の文字列
extern TCHAR info3[128];//レベルの文字列
extern TCHAR info4[128];//スコアの文字列
extern TCHAR info5[128];//スピードの文字列
extern TCHAR logStr[512];//ログの文字列の宣言

extern int newTime;//今の時間の宣言
extern int previousTime;//前の時間の宣言
extern int fontSize;//文字列の高さの宣言
extern int fontSize2;//fontSizeの2倍の宣言
extern int blockSize;//ブロックの1辺の長さの宣言
extern int deadline;//デッドラインの宣言
extern int bottomWall;//下端の線のy座標の宣言
extern int ghH;//ゲームオーバーとヘルプの背景のグラフィックハンドルの宣言
extern int bfH;//ブロックの耐久度のフォントデータハンドルの宣言
extern int goH;//「ゲームオーバー」のフォントデータハンドルの宣言
extern int btH;//背景の上の文字列のフォントデータハンドルの宣言
extern int b1H;//ボールの効果音１のサウンドハンドルの宣言
extern int b2H;//ボールの効果音２のサウンドハンドルの宣言
extern int b3H;//ボールの効果音３のサウンドハンドルの宣言
extern int b4H;//ボールの効果音４のサウンドハンドルの宣言
extern int bmH;//背景音のサウンドハンドルの宣言
extern int mxH;//最高点の効果音のサウンドハンドルの宣言
extern int gsH;//ゲームオーバー音のサウンドハンドルの宣言

extern float ballSize;//ボールの半径の宣言
extern float ballSize2;//ボールの半径の2倍の宣言
extern float ballSize4;//ボールの半径の4倍の宣言
extern float halfBlockSize;//ブロックの1辺の長さの半分の宣言
extern float BlockY;//垂直方向におけるブロックの端からラベルまでの距離の宣言
extern float rightEnd;//右端の宣言
extern float topEnd;//上端の宣言
extern float bottomEnd;//下端の宣言
extern float endInPos;//ブロックの中で対極の壁からボールの中心までの長さの宣言
extern float ringBar;//落ちたリングが止まるy座標の宣言
extern float ballsDis;//ボール同士の中心間距離の宣言
extern float ballsDis2;//ボール同士の中心間距離の二乗の宣言
extern float ballsNearDis2;//ボール同士の近い中心間距離の二乗の宣言
extern float ballRingDis;//ボールとリングの中心間距離の宣言
extern float ballRingDis2;//ボールとリングの中心間距離の二乗の宣言
extern float lastLauncherY;//前回の発射する前のボールのy座標の宣言
extern float interval;//ボールが発射される間隔の宣言
extern float logCount;//ログが消えるまでのカウントの宣言
extern float ringPlus;//リングの大きさに加算する値の宣言
extern float colorWave;//色の変化の値の宣言

extern double radian;//ラジアン表記の360度の宣言
extern double halfRadian;//ラジアン表記の180度の宣言
extern double quarterRadian;//ラジアン表記の90度の宣言

#endif // !DEFINES_H_INCLUDED