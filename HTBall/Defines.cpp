#include "Defines.h"

const TCHAR strings[][32] = {
	" fps�F%d ",//0
	" �{�[���F%d ",//1
	" ���x���F%d ",//2
	" �X�R�A�F%d%s ",//3
	" �X�s�[�h�F%d ",//4
	"Press ESC to exit",//5
	"�Q�[���I�[�o�[",//6
	"�P�F�����ăj���[�Q�[��",//7
	"�Q�F�Ղ����ăj���[�Q�[��",//8
	"�R�F�����ĈՂ����ăj���[�Q�[��",//9
	"�����L�[�����",//10
	"ESC�F�I��",//11
	"F2�F�X�N���[���V���b�g",//12
	"F3�F�e�L�X�g�̕\��/��\��",//13
	"Z/X�F�{�[���̃X�s�[�h�A�b�v",//14
	"C/V�F�{�[���̃X�s�[�h�_�E��",//15
	"D�F�f�o�b�O���̕\��/��\��",//16
	"H�F�w���v�̕\��/��\��",//17
	"K�F�{�[�����m�̏Փ˂���/�Ȃ�",//18
	"O�FInstantaneous mode on/off",//19
	"���N���b�N/Enter�F�{�[���̔���",//20
	"�z�C�[���F���{�[���̍L����",//21
};
TCHAR info1[16] = {};//fps�̕�����
TCHAR info2[128] = {};//�{�[���̌��̕�����
TCHAR info3[128] = {};//���x���̕�����
TCHAR info4[128] = {};//�X�R�A�̕�����
TCHAR info5[128] = {};//�X�s�[�h�̕�����
TCHAR logStr[512] = {};//���O�̕�����̐錾

int newTime = 0;//���̎��Ԃ̐錾
int previousTime = 0;//�O�̎��Ԃ̐錾
int fontSize = 0;//������̍����̐錾
int fontSize2 = 0;//fontSize��2�{�̐錾
int blockSize = 0;//�u���b�N��1�ӂ̒����̐錾
int deadline = 0;//�f�b�h���C���̐錾
int bottomWall = 0;//���[�̐���y���W�̐錾
int ghH = 0;//�Q�[���I�[�o�[�ƃw���v�̔w�i�̃O���t�B�b�N�n���h���̐錾
int bfH = 0;//�u���b�N�̑ϋv�x�̃t�H���g�f�[�^�n���h���̐錾
int goH = 0;//�u�Q�[���I�[�o�[�v�̃t�H���g�f�[�^�n���h���̐錾
int btH = 0;//�w�i�̏�̕�����̃t�H���g�f�[�^�n���h���̐錾
int b1H = 0;//�{�[���̌��ʉ��P�̃T�E���h�n���h���̐錾
int b2H = 0;//�{�[���̌��ʉ��Q�̃T�E���h�n���h���̐錾
int b3H = 0;//�{�[���̌��ʉ��R�̃T�E���h�n���h���̐錾
int b4H = 0;//�{�[���̌��ʉ��S�̃T�E���h�n���h���̐錾
int bmH = 0;//�w�i���̃T�E���h�n���h���̐錾
int mxH = 0;//�ō��_�̌��ʉ��̃T�E���h�n���h���̐錾
int gsH = 0;//�Q�[���I�[�o�[���̃T�E���h�n���h���̐錾

float ballSize = 0;//�{�[���̔��a�̐錾
float ballSize2 = 0;//�{�[���̔��a��2�{�̐錾
float ballSize4 = 0;//�{�[���̔��a��4�{�̐錾
float halfBlockSize = 0;//�u���b�N��1�ӂ̒����̔����̐錾
float BlockY = 0;//���������ɂ�����u���b�N�̒[���烉�x���܂ł̋����̐錾
float rightEnd = 0;//�E�[�̐錾
float topEnd = 0;//��[�̐錾
float bottomEnd = 0;//���[�̐錾
float endInPos = 0;//�u���b�N�̒��ő΋ɂ̕ǂ���{�[���̒��S�܂ł̒����̐錾
float ringBar = 0;//�����������O���~�܂�y���W�̐錾
float ballsDis = 0;//�{�[�����m�̒��S�ԋ����̐錾
float ballsDis2 = 0;//�{�[�����m�̒��S�ԋ����̓��̐錾
float ballsNearDis2 = 0;//�{�[�����m�̋߂����S�ԋ����̓��̐錾
float ballRingDis = 0;//�{�[���ƃ����O�̒��S�ԋ����̐錾
float ballRingDis2 = 0;//�{�[���ƃ����O�̒��S�ԋ����̓��̐錾
float lastLauncherY = 0;//�O��̔��˂���O�̃{�[����y���W�̐錾
float interval = 0;//�{�[�������˂����Ԋu�̐錾
float logCount = 0;//���O��������܂ł̃J�E���g�̐錾
float ringPlus = 0;//�����O�̑傫���ɉ��Z����l�̐錾
float colorWave = 0;//�F�̕ω��̒l�̐錾

double radian = 0;//���W�A���\�L��360�x�̐錾
double halfRadian = 0;//���W�A���\�L��180�x�̐錾
double quarterRadian = 0;//���W�A���\�L��90�x�̐錾