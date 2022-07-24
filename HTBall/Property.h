#pragma once

#ifndef __Property_H_INCLUDED__
#define __Property_H_INCLUDED__

#include "pch.h"

#include "Vec2.h"
#include "Defines.h"
#include "Ball.h"

extern bool isGameover;//�Q�[���I�[�o�[���ǂ���
extern bool canShot;//�{�[���𔭎˂ł��邩�ǂ���
extern bool isTryingScreenShot;//�X�N���[���V���b�g���B�낤�Ƃ��Ă��邩
extern bool info;//�������\�����邩�ǂ���
extern bool debug;//�f�o�b�O����\�����邩�ǂ���
extern bool help;//�w���v��\�����邩�ǂ���
extern bool ballsCo;//�{�[�����m���Փ˂����邩�ǂ���
extern bool instantaneous;//�u�ԓI���ǂ���
extern bool floating;//���n�_�����肵�Ă��Ȃ����ǂ����B
extern bool onePos;//1�̃|�W�V�����ɕ����̃{�[�������邩�ǂ���
extern bool lastOnePos;//�O��1�̃|�W�V�����ɕ����̃{�[�������邩�ǂ���

extern unsigned int level;//�X�e�[�W���x���̏�����
extern unsigned int frame;//�t���[�����̐錾
extern unsigned int fps;//1�b�ԂɍX�V�����t���[���̐��̐錾
extern unsigned int baseFps;//���fps�̐錾
extern unsigned int ballStock;//��������{�[���̌��̏�����
extern unsigned int white;//����\���̐錾
extern unsigned int gray;//�D�F��\���̐錾
extern unsigned int ballColors[7];//�{�[���̐F�̔z��̐錾

extern float deltaTime;//�f���^�̐錾
extern float speed;//�{�[���̈ړ����x�̐錾
extern int ballMode;//�{�[���̃��[�h�̐錾
extern int movement;//�{�[����1�t���[���ɓ����񐔂̏�����
extern int difficulty;//��Փx�̐錾
extern double addition;//���̃{�[���̍L�����̊p�x�̐錾

extern unsigned long long score;//�X�R�A�̐錾
extern std::string maxScoresStr;//�X�R�A�̕\���ōō��_�̃X�R�A���o�����񐔂�����������̐錾

extern Vec2<int> clientSize;//�`��͈͂̐錾
extern Vec2<int> toExitPos;//�I���̈ē��̍��W�̐錾
extern Vec2<float> launcherPos;//���˂���O�̃{�[���̍��W�̐錾
extern Vec2<float> pointer1;//�{�[���̐i�ސ�P�̍��W�̐錾
extern Vec2<float> pointer2;//�{�[���̐i�ސ�Q�̍��W�̐錾
extern Vec2<float> pointer3;//�{�[���̐i�ސ�R�̍��W�̐錾

extern std::vector<Ball> balls;//�{�[���̔z��̐錾
extern std::vector<Vec2<float>> fallingRings;//�����O�̔z��̐錾
extern std::vector<std::vector<Vec2<float>>> locus;//�O�Ղ̔z��̐錾

#endif // !__PCH_H_INCLUDED__