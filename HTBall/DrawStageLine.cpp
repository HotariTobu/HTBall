#include "Draw.h"

void DrawStageLine() {
	//�f�b�h���C���̕\��
	DrawLine(deadline, fontSize, deadline, bottomWall, GetColor(240, 0, 0));

	//��[�̐��̕\��
	DrawLine(0, fontSize, clientSize.x, fontSize, white);

	//���[�̐��̕\��
	DrawLine(0, bottomWall, clientSize.x, bottomWall, white);
}