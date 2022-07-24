#include "Property.h"

bool isGameover = false;//�Q�[���I�[�o�[���ǂ���
bool canShot = true;//�{�[���𔭎˂ł��邩�ǂ���
bool isTryingScreenShot = false;//�X�N���[���V���b�g���B�낤�Ƃ��Ă��邩
bool info = true;//�������\�����邩�ǂ���
bool debug = false;//�f�o�b�O����\�����邩�ǂ���
bool help = false;//�w���v��\�����邩�ǂ���
bool ballsCo = false;//�{�[�����m���Փ˂����邩�ǂ���
bool instantaneous = false;//�u�ԓI���ǂ���
bool floating = true;//���n�_�����肵�Ă��Ȃ����ǂ����B
bool onePos = false;//1�̃|�W�V�����ɕ����̃{�[�������邩�ǂ���
bool lastOnePos = false;//�O��1�̃|�W�V�����ɕ����̃{�[�������邩�ǂ���

/*
�}�b�v�̔z��̐錾
-2	�A�C�e��
-1	�����O
0	��
1~	�u���b�N
*/
int map[MAPSIZE] = {};
unsigned int level = 1;//�X�e�[�W���x���̏�����
unsigned int frame = 0;//�t���[�����̐錾
unsigned int fps = 0;//1�b�ԂɍX�V�����t���[���̐��̐錾
unsigned int baseFps = 0;//���fps�̐錾
unsigned int ballStock = 1;//��������{�[���̌��̏�����
unsigned int white = 0;//����\���̐錾
unsigned int gray = 0;//�D�F��\���̐錾
unsigned int ballColors[7] = {};//�{�[���̐F�̔z��̐錾

float deltaTime = 0;//�f���^�̐錾
float speed = 0;//�{�[���̈ړ����x�̐錾
int ballMode = 0;//�{�[���̃��[�h�̐錾
int movement = 32;//�{�[����1�t���[���ɓ����񐔂̏�����
int difficulty = 0;//��Փx�̐錾
double addition = 0;//���̃{�[���̍L�����̊p�x�̐錾

unsigned long long score = 0;//�X�R�A�̐錾

std::string maxScoresStr = std::string();//�X�R�A�̕\���ōō��_�̃X�R�A���o�����񐔂�����������̐錾

Vec2<int> clientSize = Vec2<int>();//�`��͈͂̐錾
Vec2<int> toExitPos = Vec2<int>();//�I���̈ē��̍��W�̐錾
Vec2<float> launcherPos = Vec2<float>();//���˂���O�̃{�[���̍��W�̐錾
Vec2<float> pointer1 = Vec2<float>();//�{�[���̐i�ސ�P�̍��W�̐錾
Vec2<float> pointer2 = Vec2<float>();//�{�[���̐i�ސ�Q�̍��W�̐錾
Vec2<float> pointer3 = Vec2<float>();//�{�[���̐i�ސ�R�̍��W�̐錾

std::vector<Ball> balls = std::vector<Ball>();//�{�[���̔z��̐錾
std::vector<Vec2<float>> fallingRings = std::vector<Vec2<float>>();//�����O�̔z��̐錾
std::vector<std::vector<Vec2<float>>> locus = std::vector<std::vector<Vec2<float>>>();//�O�Ղ̔z��̏�����