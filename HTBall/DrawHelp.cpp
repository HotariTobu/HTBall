#include "Draw.h"

void DrawHelp() {
	DrawGraph((clientSize.x - MAXROW * 3 / 2 * blockSize) / 2, fontSize2, ghH, true);//�w�i�̕`��

		//11�񃋁[�v
	for (int i = 11; i < 22; i++) {
		int buttonWidth = GetDrawStringWidthToHandle(strings[i], (int)strlen(strings[i]), btH);//�{�^���̕��̎擾
		DrawStringToHandle((clientSize.x - MAXROW * 3 / 2 * blockSize) / 2 + blockSize, fontSize2 + blockSize * (i - 11) + (int)halfBlockSize, strings[i], 0, btH);//�{�^���̕`��
	}
}