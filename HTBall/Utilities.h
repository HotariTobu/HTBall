#pragma once

#ifndef __UTILITIES_H_INCLUDED__
#define __UTILITIES_H_INCLUDED__

#include "pch.h"

//HSV�F��Ԃ���DxLib�W���̐F��\�����������߂�֐��̒�`
extern int GetColorFromHSV(float h, float s, float v);

//���W�A������x�����߂�֐��̒�`
extern double rtod(double radian);

//�x���烉�W�A�������߂�֐��̒�`
extern double dtor(double degree);

#endif // !__UTILITIES_H_INCLUDED__
