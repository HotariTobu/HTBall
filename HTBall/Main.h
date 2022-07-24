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
	Main(std::string cmdLine);//������
	~Main();//�j��

	void Input();//����
	void Update();//�v�Z
	void Draw();//�`��

	static int GetMapAt(int index);//�}�b�v����擾����
	static void SetMapAt(int index, int value);//�}�b�v�ɒu��

	template <typename... Args>
	static void Log(const TCHAR* format, Args const & ...args);//���O���X�V����
	static void ResetInterval();//�{�[�������˂����Ԋu�����Z�b�g����

private:
	/*
	�}�b�v�̔z��̐錾
	-2	�A�C�e��
	-1	�����O
	0	��
	1~	�u���b�N
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