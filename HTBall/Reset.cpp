#include "Input.h"

//�j���[�Q�[�����n�߂邽�߂̊֐��̒�`
void Reset(int mode) {
	//�����ŕ���
	switch (mode) {
	case 1://�����ăj���[�Q�[����������
		break;//����𔲂���
		
	case 2://�Ղ����ăj���[�Q�[����������
		ballMode = 0;//�{�[���̃��[�h�̑��

		balls.clear();//�{�[���̔z��̃N���A
		balls.push_back(Ball());//�{�[���̔z��ɍŏ��̃{�[���̒ǉ�

	case 3://�����ĈՂ����ăj���[�Q�[����������
		//��Փx���Ղ������Ȃ�������
		if (difficulty < MAXROW - 1) {
			difficulty++;//��Փx��������
		}

		break;//����𔲂���
	}

	level = 1;//�X�e�[�W���x���̑��

	launcherPos.x = (float)fontSize;//���˂���O�̃{�[����x���W�̌v�Z
	launcherPos.y = (float)(fontSize + blockSize * MAXROW / 2);//���˂���O�̃{�[����y���W�̌v�Z
	lastLauncherY = launcherPos.y;//�O��̔��˂���O�̃{�[����y���W�̑��

	score = 0;//�X�R�A�̑��
	maxScoresStr.clear();//�X�R�A�̕\���ōō��_�̃X�R�A���o�����񐔂�����������̃N���A

	//�}�b�v�̗v�f���������[�v
	for (int i = 0; i < MAPSIZE; i++) {
		Main::SetMapAt(i, 0);//�}�b�v�ɂ͂Ȃɂ��Ȃ�
	}

	//�u���b�N�̒ǉ�
	for (int i = 0; i < MAXROW - difficulty; i++) {
		Main::SetMapAt(GetRand(MAXROW - 1) * MAXCOLUMN + 1, GetRand(1) + 1);//�����_���ȃu���b�N�̔z�u
	}

	for (auto ite = locus.begin(); ite != locus.end(); ite++) {
		(*ite).clear();
	}
}