#include "Defines.h"

const TCHAR strings[][32] = {
	" fps：%d ",//0
	" ボール：%d ",//1
	" レベル：%d ",//2
	" スコア：%d%s ",//3
	" スピード：%d ",//4
	"Press ESC to exit",//5
	"ゲームオーバー",//6
	"１：強くてニューゲーム",//7
	"２：易しくてニューゲーム",//8
	"３：強くて易しくてニューゲーム",//9
	"数字キーを入力",//10
	"ESC：終了",//11
	"F2：スクリーンショット",//12
	"F3：テキストの表示/非表示",//13
	"Z/X：ボールのスピードアップ",//14
	"C/V：ボールのスピードダウン",//15
	"D：デバッグ情報の表示/非表示",//16
	"H：ヘルプの表示/非表示",//17
	"K：ボール同士の衝突あり/なし",//18
	"O：Instantaneous mode on/off",//19
	"左クリック/Enter：ボールの発射",//20
	"ホイール：黄ボールの広がり具合",//21
};
TCHAR info1[16] = {};//fpsの文字列
TCHAR info2[128] = {};//ボールの個数の文字列
TCHAR info3[128] = {};//レベルの文字列
TCHAR info4[128] = {};//スコアの文字列
TCHAR info5[128] = {};//スピードの文字列
TCHAR logStr[512] = {};//ログの文字列の宣言

int newTime = 0;//今の時間の宣言
int previousTime = 0;//前の時間の宣言
int fontSize = 0;//文字列の高さの宣言
int fontSize2 = 0;//fontSizeの2倍の宣言
int blockSize = 0;//ブロックの1辺の長さの宣言
int deadline = 0;//デッドラインの宣言
int bottomWall = 0;//下端の線のy座標の宣言
int ghH = 0;//ゲームオーバーとヘルプの背景のグラフィックハンドルの宣言
int bfH = 0;//ブロックの耐久度のフォントデータハンドルの宣言
int goH = 0;//「ゲームオーバー」のフォントデータハンドルの宣言
int btH = 0;//背景の上の文字列のフォントデータハンドルの宣言
int b1H = 0;//ボールの効果音１のサウンドハンドルの宣言
int b2H = 0;//ボールの効果音２のサウンドハンドルの宣言
int b3H = 0;//ボールの効果音３のサウンドハンドルの宣言
int b4H = 0;//ボールの効果音４のサウンドハンドルの宣言
int bmH = 0;//背景音のサウンドハンドルの宣言
int mxH = 0;//最高点の効果音のサウンドハンドルの宣言
int gsH = 0;//ゲームオーバー音のサウンドハンドルの宣言

float ballSize = 0;//ボールの半径の宣言
float ballSize2 = 0;//ボールの半径の2倍の宣言
float ballSize4 = 0;//ボールの半径の4倍の宣言
float halfBlockSize = 0;//ブロックの1辺の長さの半分の宣言
float BlockY = 0;//垂直方向におけるブロックの端からラベルまでの距離の宣言
float rightEnd = 0;//右端の宣言
float topEnd = 0;//上端の宣言
float bottomEnd = 0;//下端の宣言
float endInPos = 0;//ブロックの中で対極の壁からボールの中心までの長さの宣言
float ringBar = 0;//落ちたリングが止まるy座標の宣言
float ballsDis = 0;//ボール同士の中心間距離の宣言
float ballsDis2 = 0;//ボール同士の中心間距離の二乗の宣言
float ballsNearDis2 = 0;//ボール同士の近い中心間距離の二乗の宣言
float ballRingDis = 0;//ボールとリングの中心間距離の宣言
float ballRingDis2 = 0;//ボールとリングの中心間距離の二乗の宣言
float lastLauncherY = 0;//前回の発射する前のボールのy座標の宣言
float interval = 0;//ボールが発射される間隔の宣言
float logCount = 0;//ログが消えるまでのカウントの宣言
float ringPlus = 0;//リングの大きさに加算する値の宣言
float colorWave = 0;//色の変化の値の宣言

double radian = 0;//ラジアン表記の360度の宣言
double halfRadian = 0;//ラジアン表記の180度の宣言
double quarterRadian = 0;//ラジアン表記の90度の宣言