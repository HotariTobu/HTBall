#include "Utilities.h"

//HSV�F��Ԃ���DxLib�W���̐F��\�����������߂�֐��̒�`
int GetColorFromHSV(float h, float s, float v) {
	float r = v;//�ԗv�f�̏�����(0.0f�`1.0f)
	float g = v;//�Ηv�f�̏�����(0.0f�`1.0f)
	float b = v;//�v�f�̏�����(0.0f�`1.0f)
	//�ʓx��0.0f�ȏ�Ȃ�
	if (s > 0.0f) {
		h *= 6.0f;//�F����6.0f����Z
		const int i = (int)h;//�F���̐��������̏�����
		const float f = h - (float)i;//�F���̏��������̌v�Z
		//�F���̐��������̕���
		switch (i) {
			//�F���̐������������̐��܂���6�ȏゾ������
		default://�F���̐���������0�������Ƃ��Ɠ�������

			//�F���̐���������0��������
		case 0:
			g *= 1.0f - s * (1.0f - f);//�Ηv�f�̏�Z
			b *= 1.0f - s;//�v�f�̏�Z
			break;//����𔲂���

			//�F���̐���������1��������
		case 1:
			r *= 1.0f - s * f;//�ԗv�f�̏�Z
			b *= 1.0f - s;//�v�f�̏�Z
			break;//����𔲂���

			//�F���̐���������2��������
		case 2:
			r *= 1.0f - s;//�ԗv�f�̏�Z
			b *= 1.0f - s * (1.0f - f);//�v�f�̏�Z
			break;//����𔲂���

			//�F���̐���������3��������
		case 3:
			r *= 1.0f - s;//�ԗv�f�̏�Z
			g *= 1.0f - s * f;//�Ηv�f�̏�Z
			break;//����𔲂���

			//�F���̐���������4��������
		case 4:
			r *= 1.0f - s * (1.0f - f);//�ԗv�f�̏�Z
			g *= 1.0f - s;//�Ηv�f�̏�Z
			break;//����𔲂���

			//�F���̐���������5��������
		case 5:
			g *= 1.0f - s;//�Ηv�f�̏�Z
			b *= 1.0f - s * f;//�v�f�̏�Z
			break;//����𔲂���
		}
	}

	int red = (int)(r * 255);//�ԗv�f�̏�����(0�`255)
	int green = (int)(g * 255);//�Ηv�f�̏�����(0�`255)
	int blue = (int)(b * 255);//�v�f�̏�����(0�`255)

	return GetColor(red, green, blue);//DxLib�̐F�̌v�Z
}

//���W�A������x�����߂�֐��̒�`
double rtod(double radian) {
	return 180 / DX_PI * radian;//���W�A������x�����߂�v�Z
}

//�x���烉�W�A�������߂�֐��̒�`
double dtor(double degree) {
	return DX_PI / 180 * degree;//�x���烉�W�A�������߂�v�Z
}