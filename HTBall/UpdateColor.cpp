#include "Update.h"

void UpdateColor() {
	colorWave += deltaTime;//�F�̕ω��̒l�̌v�Z
	//�F�̕ω��̒l��4096�ȏゾ������
	if (colorWave >= 4096) {
		colorWave = -colorWave;//�F�̕ω��̒l�̕����𔽓]����
	}
}