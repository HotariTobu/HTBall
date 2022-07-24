#pragma once

#ifndef __INPUT_H_INCLUDED__
#define __INPUT_H_INCLUDED__

#include "Main.h"

extern char keyBuf[256];//������Ă���L�[�̔z��̐錾
extern char lastKeyBuf[256];//�O�ɉ�����Ă���L�[�̔z��̐錾

extern int lastMouseButton;//�Ō�ɉ����ꂽ�}�E�X�̃{�^���̐錾
extern Vec2<int> lastMousePos;//�Ō�̃}�E�X�̈ʒu�̐錾

//�L�[����
extern void KeyDown(int key);//�L�[�������ꂽ�u��
extern void KeyUp(int key);//�L�[�������ꂽ�u��
extern void Key(int key);//�L�[��������Ă���Ƃ�

//�}�E�X����
extern void MouseDown(int button);//�{�^���������ꂽ�u��
extern void MouseUp(int button);//�{�^���������ꂽ�u��
extern void Mouse(int button);//�{�^����������Ă���Ƃ�
extern void MouseHover(Vec2<int> point);//�}�E�X���������Ƃ�
extern void MouseMove(Vec2<int> point, Vec2<int> dif);//�}�E�X���~�܂��Ă���Ƃ�
extern void Wheel(int volume);//�z�C�[���������Ă���Ƃ�

extern void Shot();//�{�[���𔭎˂���
extern void Reset(int mode);//�j���[�Q�[�����n�߂�Ƃ�

#endif // !__INPUT_H_INCLUDED__
