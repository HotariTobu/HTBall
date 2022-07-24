#pragma once

#ifndef __MAIN_H_INCLUDED__
#define __MAIN_H_INCLUDED__

#include "pch.h"

#include "Vec2.h"
#include "Utilities.h"

#include "Ball.h"

#include "Defines.h"
#include "Property.h"

class Main {
public:
	Main(std::string cmdLine);//初期化
	~Main();//破棄

	void Input();//入力
	void Update();//計算
	void Draw();//描画

	static int GetMapAt(int index);//マップから取得する
	static void SetMapAt(int index, int value);//マップに置く

	template <typename... Args>
	static void Log(const TCHAR* format, Args const & ...args);//ログを更新する
	static void ResetInterval();//ボールが発射される間隔をリセットする

private:
	/*
	マップの配列の宣言
	-2	アイテム
	-1	リング
	0	無
	1~	ブロック
	*/
	static int map[MAPSIZE];
};

inline int Main::GetMapAt(int index) {
	if (index < MAPSIZE && index >= 0) {
		return map[index];
	}
	return 0;
}

inline void Main::SetMapAt(int index, int value) {
	if (index < MAPSIZE && index >= 0) {
		map[index] = value;
	}
}

template <typename... Args>
inline void Main::Log(const TCHAR* format, Args const & ...args) {
	sprintfDx(logStr, format, args...);
	logCount = 2000;
}

inline void Main::ResetInterval() {
	interval = INTERVAL * ballSize * (ballsCo ? 4 : 1);
}

#endif // !__MAIN_H_INCLUDED__