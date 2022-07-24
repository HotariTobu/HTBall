#pragma once

#ifndef __BALL_H_INCLUDED__
#define __BALL_H_INCLUDED__

#include "pch.h"

class Ball
{
public:
	float x, y;//�{�[���̍��W�����[����ϐ��̐錾
	float addX, addY;//�{�[���̍��W�ɉ����Z����ϐ��̐錾
	bool moving;//�����邩�ǂ����̐錾
	bool stoped;//�~�܂������ǂ����̐錾

	/*
	0�F�E�����ɑ΂��铖���蔻����v�Z����K�v�����邩�ǂ���
	1�F������ɑ΂��铖���蔻����v�Z����K�v�����邩�ǂ���
	2�F�������ɑ΂��铖���蔻����v�Z����K�v�����邩�ǂ���
	3�F�������ɑ΂��铖���蔻����v�Z����K�v�����邩�ǂ���
	*/
	bool walls[4];

	void GetPos(int* column, int* row);//�{�[���̃|�W�V���������߂�֐��̐錾
	double GetTheta() const;//���W�A���̃{�[�����i�ފp�x�̎擾
	void SetTheta(double value);//���W�A���̃{�[�����i�ފp�x�̐ݒ�

private:
	double theta;//���W�A���̃{�[�����i�ފp�x�̐錾
};

#endif // !__BALL_H_INCLUDED__