#pragma once

#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED

#include "pch.h"

//�ő�s���̒�`�i2�̔{���j
#define MAXROW 12

//�ő�񐔂̒�`
#define MAXCOLUMN (MAXROW * 2)

//�}�b�v�T�C�Y�̒�`
#define MAPSIZE (MAXROW * MAXCOLUMN)

//�{�[�����P�Ƃ����Ƃ��ɑ΂���u���b�N�̑傫���̒�`
#define BALLRATIO 16.0f

//�{�[�������˂����Ԋu�̒�`
#define INTERVAL 4

//������̏�����
extern const TCHAR strings[][32];
extern TCHAR info1[16];//fps�̕�����
extern TCHAR info2[128];//�{�[���̌��̕�����
extern TCHAR info3[128];//���x���̕�����
extern TCHAR info4[128];//�X�R�A�̕�����
extern TCHAR info5[128];//�X�s�[�h�̕�����
extern TCHAR logStr[512];//���O�̕�����̐錾

extern int newTime;//���̎��Ԃ̐錾
extern int previousTime;//�O�̎��Ԃ̐錾
extern int fontSize;//������̍����̐錾
extern int fontSize2;//fontSize��2�{�̐錾
extern int blockSize;//�u���b�N��1�ӂ̒����̐錾
extern int deadline;//�f�b�h���C���̐錾
extern int bottomWall;//���[�̐���y���W�̐錾
extern int ghH;//�Q�[���I�[�o�[�ƃw���v�̔w�i�̃O���t�B�b�N�n���h���̐錾
extern int bfH;//�u���b�N�̑ϋv�x�̃t�H���g�f�[�^�n���h���̐錾
extern int goH;//�u�Q�[���I�[�o�[�v�̃t�H���g�f�[�^�n���h���̐錾
extern int btH;//�w�i�̏�̕�����̃t�H���g�f�[�^�n���h���̐錾
extern int b1H;//�{�[���̌��ʉ��P�̃T�E���h�n���h���̐錾
extern int b2H;//�{�[���̌��ʉ��Q�̃T�E���h�n���h���̐錾
extern int b3H;//�{�[���̌��ʉ��R�̃T�E���h�n���h���̐錾
extern int b4H;//�{�[���̌��ʉ��S�̃T�E���h�n���h���̐錾
extern int bmH;//�w�i���̃T�E���h�n���h���̐錾
extern int mxH;//�ō��_�̌��ʉ��̃T�E���h�n���h���̐錾
extern int gsH;//�Q�[���I�[�o�[���̃T�E���h�n���h���̐錾

extern float ballSize;//�{�[���̔��a�̐錾
extern float ballSize2;//�{�[���̔��a��2�{�̐錾
extern float ballSize4;//�{�[���̔��a��4�{�̐錾
extern float halfBlockSize;//�u���b�N��1�ӂ̒����̔����̐錾
extern float BlockY;//���������ɂ�����u���b�N�̒[���烉�x���܂ł̋����̐錾
extern float rightEnd;//�E�[�̐錾
extern float topEnd;//��[�̐錾
extern float bottomEnd;//���[�̐錾
extern float endInPos;//�u���b�N�̒��ő΋ɂ̕ǂ���{�[���̒��S�܂ł̒����̐錾
extern float ringBar;//�����������O���~�܂�y���W�̐錾
extern float ballsDis;//�{�[�����m�̒��S�ԋ����̐錾
extern float ballsDis2;//�{�[�����m�̒��S�ԋ����̓��̐錾
extern float ballsNearDis2;//�{�[�����m�̋߂����S�ԋ����̓��̐錾
extern float ballRingDis;//�{�[���ƃ����O�̒��S�ԋ����̐錾
extern float ballRingDis2;//�{�[���ƃ����O�̒��S�ԋ����̓��̐錾
extern float lastLauncherY;//�O��̔��˂���O�̃{�[����y���W�̐錾
extern float interval;//�{�[�������˂����Ԋu�̐錾
extern float logCount;//���O��������܂ł̃J�E���g�̐錾
extern float ringPlus;//�����O�̑傫���ɉ��Z����l�̐錾
extern float colorWave;//�F�̕ω��̒l�̐錾

extern double radian;//���W�A���\�L��360�x�̐錾
extern double halfRadian;//���W�A���\�L��180�x�̐錾
extern double quarterRadian;//���W�A���\�L��90�x�̐錾

#endif // !DEFINES_H_INCLUDED