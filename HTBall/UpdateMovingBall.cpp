#include "Update.h"

void UpdateMovingBall() {
	canShot = true;//�{�[���𔭎˂ł���悤��

	unsigned int index = 0;//���˂����{�[���̗v�f�ԍ��̐錾
	auto beginIte = balls.begin();
	//�{�[���̔z��̑S�v�f�܂��͓�������{�[���̌������̃A�N�Z�X
	for (auto ite = beginIte; ite != balls.end() && index < ballStock; ite++, index++) {
		//�{�[�����~�܂��Ă�����
		if ((*ite).stoped) {
			continue;//���̃{�[���Ɉڂ�
		}
		//�{�[�����~�܂��Ă��Ȃ�������
		else {
			canShot = false;//�{�[���͔��˂ł��Ȃ�
		}

		//�{�[���������ĂȂ�������
		if ((*ite).moving) {
			//�{�[����1�t���[���ɓ����񐔂������[�v
			for (int i = 0; i < movement; i++) {
				(*ite).x += (*ite).addX;//�{�[����x���W�̉��Z
				(*ite).y -= (*ite).addY;//�{�[����y���W�̌��Z

				//�{�[�����E�[�ɓ��B������
				if ((*ite).x > rightEnd) {
					(*ite).x = rightEnd * 2 - (*ite).x;//����2�{���{�[����x���W�Ɍ��Z
					(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z
				}
				//�{�[������[�ɓ��B������
				else if ((*ite).y < topEnd) {
					(*ite).y = topEnd * 2 - (*ite).y;//����2�{���{�[����y���W�ɉ��Z
					(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z
				}
				//�{�[�������[�ɓ��B������
				else if ((*ite).y > bottomEnd) {
					(*ite).y = bottomEnd * 2 - (*ite).y;//����2�{���{�[����y���W�Ɍ��Z
					(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z
				}
				//�{�[�����[�ɓ��B���Ă��Ȃ�������
				else if ((*ite).x > fontSize2) {
					int row = 0;//�{�[���̃|�W�V�����̍s�̏�����
					int column = 0;//�{�[���̃|�W�V�����̗�̏�����
					(*ite).GetPos(&row, &column);//�{�[���̃|�W�V�����̎擾

					float ex = fmodf((*ite).x - fontSize2, (float)blockSize);//�u���b�N�̒��ł�x���W�̏�����
					float ey = fmodf((*ite).y - fontSize, (float)blockSize);//�u���b�N�̒��ł�y���W�̏�����

					//�E�����ɑ΂��铖���蔻����v�Z����K�v����������
					if ((*ite).walls[0]) {
						int mapIndex = row * MAXCOLUMN + (column - 1);//�}�b�v�̔z��̗v�f�ԍ��̏�����
						int value = Main::GetMapAt(mapIndex);//�}�b�v�̗v�f�̎擾

						//�{�[�����u���b�N�̉E�[�ɂ���A�E�����Ƀu���b�N����������
						if (ex >= endInPos && value > 0) {
							(*ite).x -= (ex - endInPos) * 2;//����2�{���{�[����x���W�Ɍ��Z

							int j = 1;//���蔲����u���b�N�̐��̏�����

							int toRow = 0;//�s����̃|�W�V�����̍s�̏�����
							int toColumn = 0;//�s����̃|�W�V�����̗�̏�����

							 //�{�[���̃��[�h�ŕ���
							switch (ballMode) {
								//�{�[���̐F���Ԃ�������
							case 1:
								value -= 2;//�u���b�N�̑ϋv�x�����炷
								score += 2;//�X�R�A�𑝂₷

								break;//����𔲂���

								 //�{�[���̐F����������
							case 5:
								//���蔲�����悪�u���b�N�łȂ��Ȃ�܂Ń��[�v
								while (column - j > 0 && Main::GetMapAt(mapIndex - j) > 0) {
									j++;//���蔲����u���b�N�̐��𑝂₷
								}

								//���蔲������Œ[���z���Ă��Ȃ�������
								if (column - j > 0) {
									(*ite).x += (ex - endInPos) * 2 + ballSize2 + blockSize * j;//�{�[���̂��蔲��

									(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

									//���蔲����u���b�N�̐��������[�v
									for (int l = 0; l < j; l++) {
										Main::SetMapAt(mapIndex - l, Main::GetMapAt(mapIndex - l) - 1);//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷
									}
								}

								//�{�[���̐F���΂�������
							case 3:
								//1/2�̊m����
								if (GetRand(1)) {
									value--;//�u���b�N�̑ϋv�x�����炷
									score++;//�X�R�A�𑝂₷
								}

								break;//����𔲂���

								//�{�[���̐F���V�A����������
							case 4:
								(*ite).x -= halfBlockSize;//�{�[����x���W�̌��Z

								(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

								value--;//�u���b�N�̑ϋv�x�����炷
								score++;//�X�R�A�𑝂₷

								break;//����𔲂���

								//�{�[���̐F������������
							case 6:
								//�s���悪�u���b�N���Ȃ��|�W�V�����ɂȂ�܂Ń��[�v
								do {
									toRow = GetRand(MAXROW - 1);//�s����̃|�W�V�����̍s�̑��
									toColumn = GetRand(MAXCOLUMN - 1);//�s����̃|�W�V�����̗�̑��
								} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

								(*ite).x -= (toColumn - column) * blockSize;//�{�[����x���W�̌��Z
								(*ite).y += (toRow - row) * blockSize;//�{�[����y���W�̉��Z

								//�{�[���̐F����L�ȊO��������
							default:
								value--;//�u���b�N�̑ϋv�x�����炷
								score++;//�X�R�A�𑝂₷

								break;//����𔲂���
							}

							//�u���b�N�̑ϋv�x�����̐��ɂȂ�����
							if (value < 0) {
								value = 0;//���ɂ���
							}

							Main::SetMapAt(mapIndex, value);//�u���b�N�̑ϋv�x��K�p����

							(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

							PlaySoundMem(b1H, DX_PLAYTYPE_BACK);//�{�[���̌��ʉ��P�̃o�b�N�Đ�
						}
					}

					//������ɑ΂��铖���蔻����v�Z����K�v����������
					if ((*ite).walls[1]) {
						int mapIndex = (row - 1) * MAXCOLUMN + column;//�}�b�v�̔z��̗v�f�ԍ��̏�����
						int value = Main::GetMapAt(mapIndex);//�}�b�v�̗v�f�̎擾

						//�{�[�����u���b�N�̏�[�ɂ���A������Ƀu���b�N����������
						if (ey <= ballSize && value > 0) {
							(*ite).y += (ballSize - ey) * 2;//����2�{���{�[����y���W�ɉ��Z

							int j = 1;//���蔲����u���b�N�̐��̏�����

							int toRow = 0;//�s����̃|�W�V�����̍s�̏�����
							int toColumn = 0;//�s����̃|�W�V�����̗�̏�����

							 //�{�[���̃��[�h�ŕ���
							switch (ballMode) {
								//�{�[���̐F���Ԃ�������
							case 1:
								value -= 2;//�u���b�N�̑ϋv�x�����炷
								score += 2;//�X�R�A�𑝂₷

								break;//����𔲂���

								//�{�[���̐F����������
							case 5:
								//���蔲�����悪�u���b�N�łȂ��Ȃ�܂Ń��[�v
								while (row - j > 0 && Main::GetMapAt(mapIndex - j * MAXCOLUMN) > 0) {
									j++;//���蔲����u���b�N�̐��𑝂₷
								}

								//���蔲������Œ[���z���Ă��Ȃ�������
								if (row - j > 0) {
									(*ite).y -= (ballSize - ey) * 2 + ballSize2 + blockSize * j;//�{�[���̂��蔲��

									(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

									//���蔲����u���b�N�̐��������[�v
									for (int l = 0; l < j; l++) {
										Main::SetMapAt(mapIndex - l * MAXCOLUMN, Main::GetMapAt(mapIndex - l * MAXCOLUMN) - 1);//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷
									}
								}

								//�{�[���̐F���΂�������
							case 3:
								//1/2�̊m����
								if (GetRand(1)) {
									value--;//�u���b�N�̑ϋv�x�����炷
									score++;//�X�R�A�𑝂₷
								}

								break;//����𔲂���

								//�{�[���̐F���V�A����������
							case 4:
								(*ite).y += halfBlockSize;//�{�[����y���W�̉��Z

								(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

								value--;//�u���b�N�̑ϋv�x�����炷
								score++;//�X�R�A�𑝂₷

								break;//����𔲂���

								//�{�[���̐F������������
							case 6:
								//�s���悪�u���b�N���Ȃ��|�W�V�����ɂȂ�܂Ń��[�v
								do {
									toRow = GetRand(MAXROW - 1);//�s����̃|�W�V�����̍s�̑��
									toColumn = GetRand(MAXCOLUMN - 1);//�s����̃|�W�V�����̗�̑��
								} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

								(*ite).x -= (toColumn - column) * blockSize;//�{�[����x���W�̌��Z
								(*ite).y += (toRow - row) * blockSize;//�{�[����y���W�̉��Z

								 //�{�[���̐F����L�ȊO��������
							default:
								value--;//�u���b�N�̑ϋv�x�����炷
								score++;//�X�R�A�𑝂₷

								break;//����𔲂���
							}

							//�u���b�N�̑ϋv�x�����̐��ɂȂ�����
							if (value < 0) {
								value = 0;//���ɂ���
							}

							Main::SetMapAt(mapIndex, value);//�u���b�N�̑ϋv�x��K�p����

							(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

							PlaySoundMem(b1H, DX_PLAYTYPE_BACK);//�{�[���̌��ʉ��P�̃o�b�N�Đ�
						}
					}

					//�������ɑ΂��铖���蔻����v�Z����K�v����������
					if ((*ite).walls[2] && column + 1 < MAXCOLUMN) {
						int mapIndex = row * MAXCOLUMN + (column + 1);//�}�b�v�̔z��̗v�f�ԍ��̏�����
						int value = Main::GetMapAt(mapIndex);//�}�b�v�̗v�f�̎擾

						//�{�[�����u���b�N�̍��[�ɂ���A�������Ƀu���b�N����������
						if (ex <= ballSize && value > 0) {
							(*ite).x += (ballSize - ex) * 2;//����2�{���{�[����x���W�ɉ��Z

							int j = 1;//���蔲����u���b�N�̐��̏�����

							int toRow = 0;//�s����̃|�W�V�����̍s�̏�����
							int toColumn = 0;//�s����̃|�W�V�����̗�̏�����

							//�{�[���̃��[�h�ŕ���
							switch (ballMode) {
								//�{�[���̐F���Ԃ�������
							case 1:
								value -= 2;//�u���b�N�̑ϋv�x�����炷
								score += 2;//�X�R�A�𑝂₷

								break;//����𔲂���

								//�{�[���̐F����������
							case 5:
								//���蔲�����悪�u���b�N�łȂ��Ȃ�܂Ń��[�v
								while (column + 1 + j < MAXCOLUMN && Main::GetMapAt(mapIndex + j) > 0) {
									j++;//���蔲����u���b�N�̐��𑝂₷
								}

								(*ite).x -= (ballSize - ex) * 2 + ballSize2 + blockSize * j;//�{�[���̂��蔲��

								(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

								//���蔲����u���b�N�̐��������[�v
								for (int l = 0; l < j; l++) {
									Main::SetMapAt(mapIndex + l, Main::GetMapAt(mapIndex + l) - 1);//�u���b�N�̑ϋv�x�����炷
									score++;//�X�R�A�𑝂₷
								}

								//�{�[���̐F���΂�������
							case 3:
								//1/2�̊m����
								if (GetRand(1)) {
									value--;//�u���b�N�̑ϋv�x�����炷
									score++;//�X�R�A�𑝂₷
								}

								break;//����𔲂���

								//�{�[���̐F���V�A����������
							case 4:
								(*ite).x += halfBlockSize;//�{�[����x���W�̉��Z

								(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

								value--;//�u���b�N�̑ϋv�x�����炷
								score++;//�X�R�A�𑝂₷

								break;//����𔲂���

								//�{�[���̐F������������
							case 6:
								//�s���悪�u���b�N���Ȃ��|�W�V�����ɂȂ�܂Ń��[�v
								do {
									toRow = GetRand(MAXROW - 1);//�s����̃|�W�V�����̍s�̑��
									toColumn = GetRand(MAXCOLUMN - 1);//�s����̃|�W�V�����̗�̑��
								} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

								(*ite).x -= (toColumn - column) * blockSize;//�{�[����x���W�̌��Z
								(*ite).y += (toRow - row) * blockSize;//�{�[����y���W�̉��Z

								//�{�[���̐F����L�ȊO��������
							default:
								value--;//�u���b�N�̑ϋv�x�����炷
								score++;//�X�R�A�𑝂₷

								break;//����𔲂���
							}

							//�u���b�N�̑ϋv�x�����̐��ɂȂ�����
							if (value < 0) {
								value = 0;//���ɂ���
							}

							Main::SetMapAt(mapIndex, value);//�u���b�N�̑ϋv�x��K�p����

							(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

							PlaySoundMem(b1H, DX_PLAYTYPE_BACK);//�{�[���̌��ʉ��P�̃o�b�N�Đ�
						}
					}

					//�������ɑ΂��铖���蔻����v�Z����K�v����������
					if ((*ite).walls[3]) {
						int mapIndex = (row + 1) * MAXCOLUMN + column;//�}�b�v�̔z��̗v�f�ԍ��̏�����
						int value = Main::GetMapAt(mapIndex);//�}�b�v�̗v�f�̎擾

						//�{�[�����u���b�N�̉��[�ɂ���A�������Ƀu���b�N����������
						if (ey >= endInPos && value > 0) {
							(*ite).y -= (ey - endInPos) * 2;//����2�{���{�[����y���W�Ɍ��Z

							int j = 1;//���蔲����u���b�N�̐��̏�����

							int toRow = 0;//�s����̃|�W�V�����̍s�̏�����
							int toColumn = 0;//�s����̃|�W�V�����̗�̏�����

							//�{�[���̃��[�h�ŕ���
							switch (ballMode) {
								//�{�[���̐F���Ԃ�������
							case 1:
								value -= 2;//�u���b�N�̑ϋv�x�����炷
								score += 2;//�X�R�A�𑝂₷

								break;//����𔲂���

								//�{�[���̐F����������
							case 5:
								//���蔲�����悪�u���b�N�łȂ��Ȃ�܂Ń��[�v
								while (row + j < MAXROW - 1 && Main::GetMapAt(mapIndex + j * MAXCOLUMN) > 0) {
									j++;//���蔲����u���b�N�̐��𑝂₷
								}

								//���蔲������Œ[���z���Ă��Ȃ�������
								if (row + j < MAXROW - 1) {
									(*ite).y += (ey - endInPos) * 2 + ballSize2 + blockSize * j;//�{�[���̂��蔲��

									(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

									//���蔲����u���b�N�̐��������[�v
									for (int l = 0; l < j; l++) {
										Main::SetMapAt(mapIndex + l * MAXCOLUMN, Main::GetMapAt(mapIndex + l * MAXCOLUMN) - 1);//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷
									}
								}

								//�{�[���̐F���΂�������
							case 3:
								//1/2�̊m����
								if (GetRand(1)) {
									value--;//�u���b�N�̑ϋv�x�����炷
									score++;//�X�R�A�𑝂₷
								}

								break;//����𔲂���

								//�{�[���̐F���V�A����������
							case 4:
								(*ite).y -= halfBlockSize;//�{�[����y���W�̌��Z

								(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

								value--;//�u���b�N�̑ϋv�x�����炷
								score++;//�X�R�A�𑝂₷

								break;//����𔲂���

								//�{�[���̐F������������
							case 6:
								//�s���悪�u���b�N���Ȃ��|�W�V�����ɂȂ�܂Ń��[�v
								do {
									toRow = GetRand(MAXROW - 1);//�s����̃|�W�V�����̍s�̑��
									toColumn = GetRand(MAXCOLUMN - 1);//�s����̃|�W�V�����̗�̑��
								} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

								(*ite).x -= (toColumn - column) * blockSize;//�{�[����x���W�̌��Z
								(*ite).y += (toRow - row) * blockSize;//�{�[����y���W�̉��Z

								//�{�[���̐F����L�ȊO��������
							default:
								value--;//�u���b�N�̑ϋv�x�����炷
								score++;//�X�R�A�𑝂₷

								break;//����𔲂���
							}

							//�u���b�N�̑ϋv�x�����̐��ɂȂ�����
							if (value < 0) {
								value = 0;//���ɂ���
							}

							Main::SetMapAt(mapIndex, value);//�u���b�N�̑ϋv�x��K�p����

							(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

							PlaySoundMem(b1H, DX_PLAYTYPE_BACK);//�{�[���̌��ʉ��P�̃o�b�N�Đ�
						}
					}

					//�����O�̓����蔻��
					{
						int mapIndex = row * MAXCOLUMN + column;//�{�[���̃|�W�V�����̃}�b�v�̃C���f�b�N�X
						int value = Main::GetMapAt(mapIndex);
						//�}�b�v�̔z��̃{�[���̃|�W�V�����ɃA�C�e���������O����������
						if (value < 0) {
							float disX = ex - halfBlockSize;//�{�[���ƃA�C�e���������O�̐��������ɂ����钆�S�ԋ����̏�����
							float disY = ey - halfBlockSize;//�{�[���ƃA�C�e���������O�̐��������ɂ����钆�S�ԋ����̏�����
							float dis2 = disX * disX + disY * disY;//�{�[���ƃA�C�e���������O�̒��S�ԋ����̓��

							//�{�[�����A�C�e���������O�ɐG��Ă�����
							if (dis2 < ballRingDis2) {
								int tempBallMode = ballMode;//�ꎞ�I�ȃ{�[���̃��[�h�̕ێ�

								//�A�C�e���������O���ŕ���
								switch (value) {
									//�A�C�e���Ȃ�
								case -2:
									//���Ԃ��Ă���Ԃ̓��[�v
									while (ballMode == tempBallMode) {
										ballMode = GetRand(6);//�{�[���̃��[�h�̃����_���ȑI��
									}

									Main::Log("�A�C�e�����l��");

									PlaySoundMem(b3H, DX_PLAYTYPE_BACK);//�{�[���̌��ʉ��R�̃o�b�N�Đ�

									break;//����𔲂���

								//�����O�Ȃ�
								case -1:
									Vec2<float> fallingRing = Vec2<float>();//�������̃����O�̐錾
									fallingRing.x = (*ite).x - disX;//�������̃����O��x���W�̑��
									fallingRing.y = (*ite).y - disY;//�������̃����O��y���W�̑��
									fallingRings.push_back(fallingRing);//�����O�̔z��ɗ������̃����O�̒ǉ�

									Main::Log("�{�[�����l��");

									PlaySoundMem(b2H, DX_PLAYTYPE_BACK);//�{�[���̌��ʉ��Q�̃o�b�N�Đ�

									break;//����𔲂���
								}

								Main::SetMapAt(mapIndex, 0);//�A�C�e���������O���}�b�v����폜

								score++;//�X�R�A�𑝂₷
							}
						}
						//������R�ꂪ��������
						else if (value > 0) {
							Vec2<float> dif;
							if ((*ite).walls[0]) {
								dif.x = ex;
							}
							if ((*ite).walls[1]) {
								dif.y = blockSize - ey;
							}
							if ((*ite).walls[2]) {
								dif.x = ex - blockSize;
							}
							if ((*ite).walls[3]) {
								dif.y = -ey;
							}

							if (abs(dif.x / cos((*ite).GetTheta())) < abs(dif.y / sin((*ite).GetTheta()))) {
								(*ite).x -= (dif.x + ballSize * (signbit(dif.x) ? -1 : 1)) * 2;

								if ((*ite).walls[0]) {
									int j = 1;//���蔲����u���b�N�̐��̏�����

									int toRow = 0;//�s����̃|�W�V�����̍s�̏�����
									int toColumn = 0;//�s����̃|�W�V�����̗�̏�����

									 //�{�[���̃��[�h�ŕ���
									switch (ballMode) {
										//�{�[���̐F���Ԃ�������
									case 1:
										value -= 2;//�u���b�N�̑ϋv�x�����炷
										score += 2;//�X�R�A�𑝂₷

										break;//����𔲂���

										 //�{�[���̐F����������
									case 5:
										//���蔲�����悪�u���b�N�łȂ��Ȃ�܂Ń��[�v
										while (column - j > 0 && Main::GetMapAt(mapIndex - j) > 0) {
											j++;//���蔲����u���b�N�̐��𑝂₷
										}

										//���蔲������Œ[���z���Ă��Ȃ�������
										if (column - j > 0) {
											(*ite).x += (dif.x + ballSize * (signbit(dif.x) ? -1 : 1)) * 2 + blockSize * j;//�{�[���̂��蔲��

											(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

											//���蔲����u���b�N�̐��������[�v
											for (int l = 0; l < j; l++) {
												Main::SetMapAt(mapIndex - l, Main::GetMapAt(mapIndex - l) - 1);//�u���b�N�̑ϋv�x�����炷
												score++;//�X�R�A�𑝂₷
											}
										}

										//�{�[���̐F���΂�������
									case 3:
										//1/2�̊m����
										if (GetRand(1)) {
											value--;//�u���b�N�̑ϋv�x�����炷
											score++;//�X�R�A�𑝂₷
										}

										break;//����𔲂���

										//�{�[���̐F���V�A����������
									case 4:
										(*ite).x -= halfBlockSize;//�{�[����x���W�̌��Z

										(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

										value--;//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷

										break;//����𔲂���

										//�{�[���̐F������������
									case 6:
										//�s���悪�u���b�N���Ȃ��|�W�V�����ɂȂ�܂Ń��[�v
										do {
											toRow = GetRand(MAXROW - 1);//�s����̃|�W�V�����̍s�̑��
											toColumn = GetRand(MAXCOLUMN - 1);//�s����̃|�W�V�����̗�̑��
										} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

										(*ite).x -= (toColumn - column) * blockSize;//�{�[����x���W�̌��Z
										(*ite).y += (toRow - row) * blockSize;//�{�[����y���W�̉��Z

										//�{�[���̐F����L�ȊO��������
									default:
										value--;//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷

										break;//����𔲂���
									}

									//�u���b�N�̑ϋv�x�����̐��ɂȂ�����
									if (value < 0) {
										value = 0;//���ɂ���
									}
								}
								else {
									int j = 1;//���蔲����u���b�N�̐��̏�����

									int toRow = 0;//�s����̃|�W�V�����̍s�̏�����
									int toColumn = 0;//�s����̃|�W�V�����̗�̏�����

									//�{�[���̃��[�h�ŕ���
									switch (ballMode) {
										//�{�[���̐F���Ԃ�������
									case 1:
										value -= 2;//�u���b�N�̑ϋv�x�����炷
										score += 2;//�X�R�A�𑝂₷

										break;//����𔲂���

										//�{�[���̐F����������
									case 5:
										//���蔲�����悪�u���b�N�łȂ��Ȃ�܂Ń��[�v
										while (column + 1 + j < MAXCOLUMN && Main::GetMapAt(mapIndex + j) > 0) {
											j++;//���蔲����u���b�N�̐��𑝂₷
										}

										(*ite).x -= (dif.x + ballSize * (signbit(dif.x) ? -1 : 1)) * 2 + blockSize * j;//�{�[���̂��蔲��

										(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

										//���蔲����u���b�N�̐��������[�v
										for (int l = 0; l < j; l++) {
											Main::SetMapAt(mapIndex + l, Main::GetMapAt(mapIndex + l) - 1);//�u���b�N�̑ϋv�x�����炷
											score++;//�X�R�A�𑝂₷
										}

										//�{�[���̐F���΂�������
									case 3:
										//1/2�̊m����
										if (GetRand(1)) {
											value--;//�u���b�N�̑ϋv�x�����炷
											score++;//�X�R�A�𑝂₷
										}

										break;//����𔲂���

										//�{�[���̐F���V�A����������
									case 4:
										(*ite).x += halfBlockSize;//�{�[����x���W�̉��Z

										(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

										value--;//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷

										break;//����𔲂���

										//�{�[���̐F������������
									case 6:
										//�s���悪�u���b�N���Ȃ��|�W�V�����ɂȂ�܂Ń��[�v
										do {
											toRow = GetRand(MAXROW - 1);//�s����̃|�W�V�����̍s�̑��
											toColumn = GetRand(MAXCOLUMN - 1);//�s����̃|�W�V�����̗�̑��
										} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

										(*ite).x -= (toColumn - column) * blockSize;//�{�[����x���W�̌��Z
										(*ite).y += (toRow - row) * blockSize;//�{�[����y���W�̉��Z

										//�{�[���̐F����L�ȊO��������
									default:
										value--;//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷

										break;//����𔲂���
									}

									//�u���b�N�̑ϋv�x�����̐��ɂȂ�����
									if (value < 0) {
										value = 0;//���ɂ���
									}
								}

								(*ite).SetTheta(halfRadian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z
							}
							else {
								(*ite).y += (dif.y + ballSize * (signbit(dif.y) ? -1 : 1)) * 2;

								if ((*ite).walls[1]) {
									int j = 1;//���蔲����u���b�N�̐��̏�����

									int toRow = 0;//�s����̃|�W�V�����̍s�̏�����
									int toColumn = 0;//�s����̃|�W�V�����̗�̏�����

									 //�{�[���̃��[�h�ŕ���
									switch (ballMode) {
										//�{�[���̐F���Ԃ�������
									case 1:
										value -= 2;//�u���b�N�̑ϋv�x�����炷
										score += 2;//�X�R�A�𑝂₷

										break;//����𔲂���

										//�{�[���̐F����������
									case 5:
										//���蔲�����悪�u���b�N�łȂ��Ȃ�܂Ń��[�v
										while (row - j > 0 && Main::GetMapAt(mapIndex - j * MAXCOLUMN) > 0) {
											j++;//���蔲����u���b�N�̐��𑝂₷
										}

										//���蔲������Œ[���z���Ă��Ȃ�������
										if (row - j > 0) {
											(*ite).y -= (dif.y + ballSize * (signbit(dif.y) ? -1 : 1)) * 2 + blockSize * j;//�{�[���̂��蔲��

											(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

											//���蔲����u���b�N�̐��������[�v
											for (int l = 0; l < j; l++) {
												Main::SetMapAt(mapIndex - l * MAXCOLUMN, Main::GetMapAt(mapIndex - l * MAXCOLUMN) - 1);//�u���b�N�̑ϋv�x�����炷
												score++;//�X�R�A�𑝂₷
											}
										}

										//�{�[���̐F���΂�������
									case 3:
										//1/2�̊m����
										if (GetRand(1)) {
											value--;//�u���b�N�̑ϋv�x�����炷
											score++;//�X�R�A�𑝂₷
										}

										break;//����𔲂���

										//�{�[���̐F���V�A����������
									case 4:
										(*ite).y += halfBlockSize;//�{�[����y���W�̉��Z

										(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

										value--;//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷

										break;//����𔲂���

										//�{�[���̐F������������
									case 6:
										//�s���悪�u���b�N���Ȃ��|�W�V�����ɂȂ�܂Ń��[�v
										do {
											toRow = GetRand(MAXROW - 1);//�s����̃|�W�V�����̍s�̑��
											toColumn = GetRand(MAXCOLUMN - 1);//�s����̃|�W�V�����̗�̑��
										} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

										(*ite).x -= (toColumn - column) * blockSize;//�{�[����x���W�̌��Z
										(*ite).y += (toRow - row) * blockSize;//�{�[����y���W�̉��Z

										 //�{�[���̐F����L�ȊO��������
									default:
										value--;//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷

										break;//����𔲂���
									}

									//�u���b�N�̑ϋv�x�����̐��ɂȂ�����
									if (value < 0) {
										value = 0;//���ɂ���
									}
								}
								else {
									int j = 1;//���蔲����u���b�N�̐��̏�����

									int toRow = 0;//�s����̃|�W�V�����̍s�̏�����
									int toColumn = 0;//�s����̃|�W�V�����̗�̏�����

									//�{�[���̃��[�h�ŕ���
									switch (ballMode) {
										//�{�[���̐F���Ԃ�������
									case 1:
										value -= 2;//�u���b�N�̑ϋv�x�����炷
										score += 2;//�X�R�A�𑝂₷

										break;//����𔲂���

										//�{�[���̐F����������
									case 5:
										//���蔲�����悪�u���b�N�łȂ��Ȃ�܂Ń��[�v
										while (row + j < MAXROW - 1 && Main::GetMapAt(mapIndex + j * MAXCOLUMN) > 0) {
											j++;//���蔲����u���b�N�̐��𑝂₷
										}

										//���蔲������Œ[���z���Ă��Ȃ�������
										if (row + j < MAXROW - 1) {
											(*ite).y += (dif.y + ballSize * (signbit(dif.y) ? -1 : 1)) * 2 + blockSize * j;//�{�[���̂��蔲��

											(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

											//���蔲����u���b�N�̐��������[�v
											for (int l = 0; l < j; l++) {
												Main::SetMapAt(mapIndex + l * MAXCOLUMN, Main::GetMapAt(mapIndex + l * MAXCOLUMN) - 1);//�u���b�N�̑ϋv�x�����炷
												score++;//�X�R�A�𑝂₷
											}
										}

										//�{�[���̐F���΂�������
									case 3:
										//1/2�̊m����
										if (GetRand(1)) {
											value--;//�u���b�N�̑ϋv�x�����炷
											score++;//�X�R�A�𑝂₷
										}

										break;//����𔲂���

										//�{�[���̐F���V�A����������
									case 4:
										(*ite).y -= halfBlockSize;//�{�[����y���W�̌��Z

										(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z

										value--;//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷

										break;//����𔲂���

										//�{�[���̐F������������
									case 6:
										//�s���悪�u���b�N���Ȃ��|�W�V�����ɂȂ�܂Ń��[�v
										do {
											toRow = GetRand(MAXROW - 1);//�s����̃|�W�V�����̍s�̑��
											toColumn = GetRand(MAXCOLUMN - 1);//�s����̃|�W�V�����̗�̑��
										} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

										(*ite).x -= (toColumn - column) * blockSize;//�{�[����x���W�̌��Z
										(*ite).y += (toRow - row) * blockSize;//�{�[����y���W�̉��Z

										//�{�[���̐F����L�ȊO��������
									default:
										value--;//�u���b�N�̑ϋv�x�����炷
										score++;//�X�R�A�𑝂₷

										break;//����𔲂���
									}

									//�u���b�N�̑ϋv�x�����̐��ɂȂ�����
									if (value < 0) {
										value = 0;//���ɂ���
									}
								}

								(*ite).SetTheta(radian - (*ite).GetTheta());//���W�A���̃{�[�����i�ފp�x�̍Čv�Z
							}

							Main::SetMapAt(mapIndex, value);//�u���b�N�̑ϋv�x��K�p����
							PlaySoundMem(b1H, DX_PLAYTYPE_BACK);//�{�[���̌��ʉ��P�̃o�b�N�Đ�
						}
					}

					//�X�R�A���ō��_�ɒB������
					if (score == ULLONG_MAX) {
						Main::Log("�X�R�A���ō��_�ɓ��B�I");

						score = 0;//�X�R�A�̑��
						maxScoresStr += "��";//�ō��_�̃X�R�A���o�����񐔂𑝂₷

						PlaySoundMem(mxH, DX_PLAYTYPE_BACK);//�ō��_�̌��ʉ��̃o�b�N�Đ�
					}
				}

				//���̃{�[���ɑ΂��铖���蔻��
				if (ballsCo && (ballMode != 2 || (*ite).x > deadline)) {
					int px = (int)(((*ite).x - fontSize2) / ballSize4);//�{�[���̃{�[����p��x�|�W�V�����̏�����
					int py = (int)(((*ite).y - fontSize) / ballSize4);//�{�[���̃{�[����p��y�|�W�V�����̏�����

					//��������{�[���̌��������[�v
					for (unsigned int j = 0; j < ballStock; j++) {
						auto otherIte = beginIte + j;//���̃{�[���̃C�e���[�^�̏�����

						//���̃{�[���ł͂Ȃ������A�܂��͓����Ă��Ȃ������A�܂��͎~�܂��Ă�����
						if (ite == otherIte || !(*otherIte).moving || (*otherIte).stoped) {
							continue;//�������Ȃ�
						}

						float disX = (*otherIte).x - (*ite).x;//�{�[���Ƒ��̃{�[���Ƃ̐��������ɂ����鋗���̏�����
						float disY = (*ite).y - (*otherIte).y;//�{�[���Ƒ��̃{�[���Ƃ̐��������ɂ����鋗���̏�����
						float dis2 = disX * disX + disY * disY;//�{�[���Ƒ��̃{�[���̒��S�ԋ����̓��̏�����

						onePos |= dis2 < ballsNearDis2;

						//�{�[���Ƒ��̃{�[�����d�Ȃ��Ă�����
						if (dis2 < ballsDis2) {
							float sub = ballsDis - sqrtf(dis2);//�{�[�����m�̒��S�ԋ����ƃ{�[���Ƒ��̃{�[���̒��S�ԋ����̍��̏�����
							(*ite).x -= (float)(sub * cos((*ite).GetTheta()));//���������ɂ����ă{�[���Ƒ��̃{�[�����d�Ȃ�Ȃ��悤�ɂ���
							(*ite).y += (float)(sub * sin((*ite).GetTheta()));//���������ɂ����ă{�[���Ƒ��̃{�[�����d�Ȃ�Ȃ��悤�ɂ���

							double perpendicularRadian = atan2((double)disY, (double)disX) * 2;//������������̊p�x�̂���̌v�Z

							(*ite).SetTheta(halfRadian - (*ite).GetTheta() + perpendicularRadian);//�{�[���̃��W�A���̃{�[�����i�ފp�x�̍Čv�Z
							(*otherIte).SetTheta(halfRadian - (*otherIte).GetTheta() + perpendicularRadian);//���̃{�[���̃��W�A���̃{�[�����i�ފp�x�̍Čv�Z

							PlaySoundMem(b4H, DX_PLAYTYPE_BACK);//�{�[���̌��ʉ��S�̃o�b�N�Đ�
						}
					}
				}

				//�{�[�������[�ɓ��B������
				if ((*ite).x < launcherPos.x) {
					//���n�_���ݒ肳��Ă��Ȃ�������
					if (floating) {
						launcherPos.y = (*ite).y;//���˂���O�̃{�[����y���W�̑��

						Main::Log("���n�_��ݒ�");

						floating = false;//���n�_���ݒ肳��Ă���

						(*ite).SetTheta(0);//�p�x�̃��Z�b�g
						(*ite).stoped = true;//�{�[���͎~�܂���
					}
					//���n�_���ݒ肳��Ă�����
					else {
						(*ite).SetTheta(atan2f((*ite).y - launcherPos.y, launcherPos.x - (*ite).x));//���n�_�̕���������
						(*ite).moving = false;//�{�[���͗�����
					}

					break;//�{�[���𓮂������[�v�𔲂���
				}
			}
		}
		//�{�[���������Ă�����
		else {
			float disX = launcherPos.x - (*ite).x;//�{�[���ƒ��n�_�Ƃ̐��������ɂ����鋗���̏�����
			float disY = launcherPos.y - (*ite).y;//�{�[���ƒ��n�_�Ƃ̐��������ɂ����鋗���̏�����
			float dis2 = disX * disX + disY * disY;//�{�[���ƒ��n�_�Ƃ̋����̓��̏�����
			float dis = sqrtf(dis2);//�{�[���ƒ��n�_�Ƃ̋����̏�����
			float disr = dis / BALLRATIO * speed;//�{�[���ƒ��n�_�Ƃ̋����Ɉړ����邽�߂̐�����Z�������̂̏�����
			Vec2<float> addSub = Vec2<float>();//�{�[���̍��W�ɉ����Z����l�̐錾
			addSub.x = (float)(disr * cos((*ite).GetTheta()));//�{�[����x���W�ɉ��Z����l�̌v�Z
			addSub.y = (float)(disr * sin((*ite).GetTheta()));//�{�[����y���W�Ɍ��Z����l�̌v�Z

			//�{�[����1�t���[���ɓ����񐔂������[�v
			for (int i = 0; i < movement; i++) {
				(*ite).x += addSub.x;//�{�[����x���W�̉��Z
				(*ite).y -= addSub.y;//�{�[����y���W�̌��Z

				disX = launcherPos.x - (*ite).x;//�{�[���ƒ��n�_�Ƃ̐��������ɂ����鋗���̑��
				disY = launcherPos.y - (*ite).y;//�{�[���ƒ��n�_�Ƃ̐��������ɂ����鋗���̑��
				dis2 = disX * disX + disY * disY;//�{�[���ƒ��n�_�Ƃ̋����̓��̑��
				dis = sqrtf(dis2);//�{�[���ƒ��n�_�Ƃ̋����̑��
				float adis = sqrtf(dis2);//�{�[���ƒ��n�_�Ƃ̋����̑��

				//���n�_�ɉ��������Ă�����
				if (dis < adis) {
					(*ite).SetTheta(atan2f((*ite).y - launcherPos.y, launcherPos.x - (*ite).x));//���n�_�̕���������
					float disr = adis / BALLRATIO * speed;//�{�[���ƒ��n�_�Ƃ̋����Ɉړ����邽�߂̐�����Z�������̂̏�����
					Vec2<float> addSub = Vec2<float>();//�{�[���̍��W�ɉ����Z����l�̐錾
					addSub.x = (float)(disr * cos((*ite).GetTheta()));//�{�[����x���W�ɉ��Z����l�̌v�Z
					addSub.y = (float)(disr * sin((*ite).GetTheta()));//�{�[����y���W�Ɍ��Z����l�̌v�Z
				}

				//�{�[�������n�_�ɋ߂��Ȃ�����
				if (adis < ballSize) {
					(*ite).x = launcherPos.x;//�{�[����x���W�̑��
					(*ite).y = launcherPos.y;//�{�[����y���W�̑��
					(*ite).stoped = true;//�{�[���͎~�܂���

					break;//�{�[���𓮂������[�v�𔲂���
				}
			}
		}
	}
}