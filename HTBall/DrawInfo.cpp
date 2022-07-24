#include "Draw.h"

void DrawInfo() {
	//���o�[�̕\��
	{
		sprintfDx(info1, strings[0], fps);//fps�̕������fps�̒l�̑}��
		sprintfDx(info2, strings[1], balls.size());//�{�[���̌��̕�����Ƀ{�[���̔z��̗v�f���̑}��
		sprintfDx(info3, strings[2], level);//���x���̕�����Ƀ��x���̒l�̑}��
		sprintfDx(info4, strings[3], score, maxScoresStr.c_str());//�X�R�A�̕�����ɃX�R�A�̒l�̑}��
		sprintfDx(info5, strings[4], movement);//�X�s�[�h�̕�����Ƀ{�[����1�t���[���ɓ����񐔂̑}��
		int width1 = GetDrawStringWidth(info1, (int)strlen(info1));//fps�̕�����̕�
		int width2 = GetDrawStringWidth(info2, (int)strlen(info2));//�{�[���̌��̕�����̕�
		int width3 = GetDrawStringWidth(info3, (int)strlen(info3));//���x���̕�����̕�
		int width4 = GetDrawStringWidth(info4, (int)strlen(info4));//�X�R�A�̕�����̕�
		int width5 = GetDrawStringWidth(info5, (int)strlen(info5));//�X�s�[�h�̕�����̕�
		int left1 = (clientSize.x - width1 - width2 - width3 - width4 - width5) / 2;//fps�̕�����̍��[
		int left2 = left1 + width1;//�{�[���̌��̕�����̍��[
		int left3 = left2 + width2;//���x���̕�����̍��[
		int left4 = left3 + width3;//�X�R�A�̕�����̍��[
		int left5 = left4 + width4;//�X�s�[�h�̕�����̍��[
		int right = left1 + width1 + width2 + width3 + width4 + width5;//���o�[�̉E�[
		DrawString(left1, 0, info1, white);//fps�̕�����̕`��
		DrawString(left2, 0, info2, white);//�{�[���̌��̕�����̕`��
		DrawString(left3, 0, info3, white);//���x���̕�����̕`��
		DrawString(left4, 0, info4, white);//�X�R�A�̕�����̕`��
		DrawString(left5, 0, info5, white);//�X�s�[�h�̕�����̕`��

		DrawLine(left1 - 1, 0, left1 - 1, fontSize, white);//fps�̕�����̍��[�̐��̕`��
		DrawLine(left2 - 1, 0, left2 - 1, fontSize, white);//�{�[���̌��̕�����̍��[�̐��̕`��
		DrawLine(left3 - 1, 0, left3 - 1, fontSize, white);//���x���̕�����̍��[�̐��̕`��
		DrawLine(left4 - 1, 0, left4 - 1, fontSize, white);//�X�R�A�̕�����̍��[�̐��̕`��
		DrawLine(left5 - 1, 0, left5 - 1, fontSize, white);//�X�s�[�h�̕�����̍��[�̐��̕`��
		DrawLine(right + 1, 0, right + 1, fontSize, white);//���o�[�̉E�[�̐��̕`��
	}

	//���O�̕\��
	{
		//���O��������܂ł̃J�E���g���O�����傫��������
		if (logCount > 0) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)logCount);//���߂��ĕ`�悷��ݒ�
			DrawString(0, toExitPos.y, logStr, white);//���O�̕�����̕`��
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�ʏ�̕`��̐ݒ�

			logCount -= deltaTime;//���O��������܂ł̃J�E���g�̌���
		}
	}

	//�I���̈ē��̕\��
	DrawString(toExitPos.x, toExitPos.y, strings[5], white);
}