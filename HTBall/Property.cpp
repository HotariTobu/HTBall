#include "Property.h"

bool isGameover = false;//ゲームオーバーかどうか
bool canShot = true;//ボールを発射できるかどうか
bool isTryingScreenShot = false;//スクリーンショットを撮ろうとしているか
bool info = true;//文字列を表示するかどうか
bool debug = false;//デバッグ情報を表示するかどうか
bool help = false;//ヘルプを表示するかどうか
bool ballsCo = false;//ボール同士を衝突させるかどうか
bool instantaneous = false;//瞬間的かどうか
bool floating = true;//着地点が決定していないかどうか。
bool onePos = false;//1つのポジションに複数のボールがあるかどうか
bool lastOnePos = false;//前の1つのポジションに複数のボールがあるかどうか

/*
マップの配列の宣言
-2	アイテム
-1	リング
0	無
1~	ブロック
*/
int map[MAPSIZE] = {};
unsigned int level = 1;//ステージレベルの初期化
unsigned int frame = 0;//フレーム数の宣言
unsigned int fps = 0;//1秒間に更新されるフレームの数の宣言
unsigned int baseFps = 0;//基準のfpsの宣言
unsigned int ballStock = 1;//動かせるボールの個数の初期化
unsigned int white = 0;//白を表すの宣言
unsigned int gray = 0;//灰色を表すの宣言
unsigned int ballColors[7] = {};//ボールの色の配列の宣言

float deltaTime = 0;//デルタの宣言
float speed = 0;//ボールの移動速度の宣言
int ballMode = 0;//ボールのモードの宣言
int movement = 32;//ボールが1フレームに動く回数の初期化
int difficulty = 0;//難易度の宣言
double addition = 0;//黄のボールの広がり具合の角度の宣言

unsigned long long score = 0;//スコアの宣言

std::string maxScoresStr = std::string();//スコアの表示で最高点のスコアを出した回数を示す文字列の宣言

Vec2<int> clientSize = Vec2<int>();//描画範囲の宣言
Vec2<int> toExitPos = Vec2<int>();//終了の案内の座標の宣言
Vec2<float> launcherPos = Vec2<float>();//発射する前のボールの座標の宣言
Vec2<float> pointer1 = Vec2<float>();//ボールの進む先１の座標の宣言
Vec2<float> pointer2 = Vec2<float>();//ボールの進む先２の座標の宣言
Vec2<float> pointer3 = Vec2<float>();//ボールの進む先３の座標の宣言

std::vector<Ball> balls = std::vector<Ball>();//ボールの配列の宣言
std::vector<Vec2<float>> fallingRings = std::vector<Vec2<float>>();//リングの配列の宣言
std::vector<std::vector<Vec2<float>>> locus = std::vector<std::vector<Vec2<float>>>();//軌跡の配列の初期化