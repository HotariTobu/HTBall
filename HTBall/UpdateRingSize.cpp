#include "Update.h"

void UpdateRingSize() {
	ringPlus += deltaTime;//�����O�̑傫���ɉ��Z�����l�̌v�Z
			//�����O�̑傫���ɉ��Z�����l��128�ȏゾ������
	if (ringPlus >= 128) {
		ringPlus = -ringPlus;//�����O�̑傫���ɉ��Z�����l�̕����𔽓]����
	}
}