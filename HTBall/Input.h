#pragma once

#ifndef __INPUT_H_INCLUDED__
#define __INPUT_H_INCLUDED__

#include "Main.h"

extern char keyBuf[256];//押されているキーの配列の宣言
extern char lastKeyBuf[256];//前に押されているキーの配列の宣言

extern int lastMouseButton;//最後に押されたマウスのボタンの宣言
extern Vec2<int> lastMousePos;//最後のマウスの位置の宣言

//キー入力
extern void KeyDown(int key);//キーが押された瞬間
extern void KeyUp(int key);//キーが離された瞬間
extern void Key(int key);//キーが押されているとき

//マウス入力
extern void MouseDown(int button);//ボタンが押された瞬間
extern void MouseUp(int button);//ボタンが離された瞬間
extern void Mouse(int button);//ボタンが押されているとき
extern void MouseHover(Vec2<int> point);//マウスが動いたとき
extern void MouseMove(Vec2<int> point, Vec2<int> dif);//マウスが止まっているとき
extern void Wheel(int volume);//ホイールが動いているとき

extern void Shot();//ボールを発射する
extern void Reset(int mode);//ニューゲームを始めるとき

#endif // !__INPUT_H_INCLUDED__
