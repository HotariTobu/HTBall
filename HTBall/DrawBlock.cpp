#include "Draw.h"

void DrawBlock() {
	for (int row = 0; row < MAXROW; row++) {
		for (int column = 0; column < MAXCOLUMN; column++) {
			int value = Main::GetMapAt(row * MAXCOLUMN + column);//�}�b�v�̒l�̏�����

			//�����O���A�C�e����������
			if (value < 0) {
				Vec2<float> ring = Vec2<float>();//�����O���A�C�e���̍��W�̐錾
				ring.x = clientSize.x - (column + 1) * blockSize + halfBlockSize;//�����O���A�C�e����x���W�̌v�Z
				ring.y = fontSize + row * blockSize + halfBlockSize;//�����O���A�C�e����y���W�̌v�Z

				//�����O���A�C�e�����ŕ���
				switch (value) {
					//�A�C�e����������
				case -2:
					DrawCircleAA(ring.x, ring.y, ballSize4, 16, GetColorFromHSV(abs(colorWave / 4096.0f), 1.0f, 1.0f), true);//�J���t���ȃA�C�e���̕`��

					break;//����𔲂���

					//�����O��������
				case -1:
					DrawCircleAA(ring.x, ring.y, ballSize4 + abs(ringPlus / 128.0f * ballSize), 16, white, false, ballSize);//�����O�̕`��
					DrawCircleAA(ring.x, ring.y, ballSize, 8, ballColors[ballMode], true);//�����O�̒��̃{�[���̕`��

					break;//����𔲂���
				}
			}
			//�u���b�N��������
			else if (value > 0) {
				Vec2<int> block = Vec2<int>();//�u���b�N�̍��W�̐錾
				block.x = clientSize.x - (column + 1) * blockSize;//�u���b�N��x���W�̌v�Z
				block.y = fontSize + row * blockSize;//�u���b�N��y���W�̌v�Z

				DrawBoxAA(block.x + 0.5f, block.y + 0.5f, block.x + blockSize - 0.5f, block.y + blockSize - 0.5f, GetColorFromHSV(value % 360 / 360.0f, 1.0f, min(1.0f - value / 3600.0f, 1.0f)), true);//�ϋv�x����F�����肵�u���b�N�̕`��

				TCHAR label[16];//�u���b�N�ɓ\�鐔���̕�����
				sprintfDx(label, "%d", value);//�u���b�N�ɓ\�鐔���̕�����ɑϋv�x�̑}��
				int width = GetDrawStringWidth(label, (int)strlen(label));//�u���b�N�ɓ\�鐔���̕�����̕�
				 //�u���b�N�ɓ\�鐔���̕�����̕����u���b�N�̕��𒴂��Ȃ�������
				if (width < blockSize) {
					DrawStringToHandle((int)(block.x + (blockSize - width) / 2), (int)(block.y + BlockY), label, white, bfH);//�u���b�N�̑ϋv�x�̕`��
				}
			}
		}
	}
}