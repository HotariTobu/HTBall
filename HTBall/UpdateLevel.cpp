#include "Update.h"

void UpdateLevel() {
	level++;//���x�����グ��

	unsigned int ballNum = (unsigned int)balls.size();//�{�[���̌��̏�����

	//�u���b�N�̒ǉ�
	for (int i = 0; i < MAXROW - difficulty; i++) {
		Main::SetMapAt(GetRand(MAXROW - 1) * MAXCOLUMN, GetRand(ballNum - 1) + GetRand(level - 1) + 1);//�����_���ȃu���b�N�̔z�u
	}

	Main::SetMapAt(GetRand(MAXROW - 1) * MAXCOLUMN, -1);//�K��1�̃����O�̔z�u

	bool item = true;//�A�C�e�����Ȃ����ǂ����̏�����

	//�}�b�v��̂��̂����ɃV�t�g����
	for (int row = 0; row < MAXROW; row++) {
		int mapIndex = row * MAXCOLUMN;//�}�b�v�̗v�f�ԍ��̏�����
		for (int column = MAXCOLUMN - 2; column >= 0; column--) {
			int value = Main::GetMapAt(mapIndex + column);
			Main::SetMapAt(mapIndex + column + 1, value);//�V�t�g

			//���[�̃|�W�V������������
			if (column == MAXCOLUMN - 2) {
				//�����O���A�C�e����������
				if (value <= 0) {
					Main::SetMapAt(mapIndex + column + 1, 0);//���[�͖�
				}
				//�u���b�N��������
				else {
					isGameover = true;//�Q�[���I�[�o�[
				}
			}
			//�E�[�̃|�W�V������������
			else if (column == 0) {
				Main::SetMapAt(mapIndex + column, 0);//�E�[�͖�
			}

			//�A�C�e������������
			if (Main::GetMapAt(mapIndex + column + 1) == -2) {
				item = false;//�A�C�e���͂���
			}
		}
	}

	//�A�C�e�����Ȃ��A����1/4�̊m����
	if (item && GetRand(3) == 0) {
		Main::SetMapAt(GetRand(MAXROW - 1) * MAXCOLUMN + 1, -2);//�����_���ȃA�C�e���̔z�u
	}

	//�������̃����O�̌��������[�v
	for (size_t i = 0; i < fallingRings.size(); i++) {
		balls.push_back(Ball());//�{�[���̔z��Ƀ{�[����ǉ�
	}
	fallingRings.clear();//�������̃����O�͂Ȃ�

	lastLauncherY = launcherPos.y;//�O��̔��˂���O�̃{�[����y���W�̑��

	if (isGameover) {
		PlaySoundMem(gsH, DX_PLAYTYPE_BACK);//�Q�[���I�[�o�[���̃o�b�N�Đ�
	}
}