#include "Main.h"

Main::Main(std::string cmdLine) {
	//�R�}���h���C��������"-log"���܂܂�Ă�����
	if (cmdLine.find("-log", 0) == std::string::npos) {
		SetOutApplicationLogValidFlag(false);//���O���c���Ȃ��悤��
	}

	//�R�}���h���C��������"-window"���܂܂�Ă�����
	if (cmdLine.find("-window", 0) != std::string::npos) {
		ChangeWindowMode(true);//�E�B���h�E���[�h�ŋN������悤��
		SetWindowIconID(IDI_ICON1);//�E�B���h�E�̃A�C�R���̐ݒ�
	}

	//���O�I�ȏ�����
	{
		SetMainWindowText("HTBall");//�E�B���h�E�̃^�C�g���̐ݒ�

		radian = dtor(360);//���W�A���\�L��360�x�̌v�Z
		halfRadian = dtor(180);//���W�A���\�L��180�x�̌v�Z
		quarterRadian = dtor(90);//���W�A���\�L��90�x�̌v�Z
		addition = dtor(20);//���̃{�[���̍L�����̊p�x�̏����l�̌v�Z
	}



	//DxLib�̏�����
	if (DxLib_Init() == -1) {
		std::exit(-1);//�N���Ɏ��s
	}

	//����I�ȏ�����
	{
		SetAlwaysRunFlag(true);//�펞�v�Z����悤��

		//���Ԋ֌W
		{
			ScreenFlip();//�f���^�̌v���̑O�̒���
			newTime = GetNowCount();//���̎��Ԃ̎擾
			while (true) {
				ScreenFlip();//���������܂ő҂�
				if (GetNowCount() - newTime >= 1000) {
					break;//1�b��
				}
				frame++;//�t���[�������C���N�������g
			}
			deltaTime = 1000.0f / frame;//�f���^�̌v�Z
			baseFps = frame;//���fps�̋L�^
		}

		//�F
		{
			white = GetColor(255, 255, 255);//���̎擾
			gray = GetColor(128, 128, 128);//�D�F�̎擾

			ballColors[0] = white;//���F�ʏ�̃{�[���̐F�i�ʏ́F���ՓI�ȁj
			ballColors[1] = GetColor(255, 0, 0);//�ԁF�ϋv�x��1��̏Փ˂�2���点��{�[���̐F�i�ʏ́F�~����j
			ballColors[2] = GetColor(255, 255, 0);//���F�g�U�ł���{�[���̐F�i�ʏ́F�����֔��j
			ballColors[3] = GetColor(0, 255, 0);//�΁F�ϋv�x��1/2�̊m���Ō��点�Ȃ��{�[���̐F�i�ʏ́F�l�݁j
			ballColors[4] = GetColor(0, 255, 255);//�V�A���F�u���b�N�����{�[���̐F�i�ʏ́F�h�����j
			ballColors[5] = GetColor(0, 0, 255);//�F�u���b�N�����蔲����{�[���̐F�i�ʏ́F�ŋ��j
			ballColors[6] = GetColor(255, 0, 255);//���F���[�v����{�[���̐F�i�ʏ́F���ҁj
		}

		//�������ߊ֌W
		{
			fontSize = GetFontSize();//������̍����̎擾
			fontSize2 = fontSize * 2;//fontSize��2�{�̌v�Z
			RECT rect;//�N���C�A���g�̗̈�����[����ϐ��̐錾
			GetClientRect(GetMainWindowHandle(), &rect);//�N���C�A���g�̈�̎擾
			clientSize.x = rect.right - rect.left;//�N���C�A���g�̈�̐��������̒����̌v�Z
			blockSize = (clientSize.x - fontSize2) / MAXCOLUMN;//�u���b�N��1�ӂ̒����̌v�Z
			halfBlockSize = blockSize / 2.0f;//�u���b�N��1�ӂ̒����̔����̌v�Z
			BlockY = (blockSize - fontSize) / 2.0f;//���������ɂ�����u���b�N�̒[���烉�x���܂ł̋����̌v�Z
			ballSize = blockSize / BALLRATIO;//�{�[���̔��a�̌v�Z
			ballSize2 = ballSize * 2;//�{�[���̔��a��2�{�̌v�Z
			ballSize4 = ballSize2 * 2;//�{�[���̔��a��4�{�̌v�Z

			clientSize.x = fontSize2 + blockSize * MAXCOLUMN;//�N���C�A���g�̈�̐��������̒����̍Ē�`
			clientSize.y = rect.bottom - rect.top;//�N���C�A���g�̈�̐��������̒����̌v�Z
			clientSize.y = blockSize * (MAXROW + 1) + fontSize2;//�N���C�A���g�̈�̐��������̒����̍Ē�`
			SetGraphMode(clientSize.x, clientSize.y, GetColorBitDepth());//��ʂ̕`�惂�[�h�̐ݒ�

			launcherPos.x = (float)fontSize;//���˂���O�̃{�[����x���W�̌v�Z
			launcherPos.y = (float)(fontSize + blockSize * MAXROW / 2);//���˂���O�̃{�[����y���W�̌v�Z
			lastLauncherY = launcherPos.y;//�O��̔��˂���O�̃{�[����y���W�̑��

			rightEnd = clientSize.x - ballSize;//�E�[�̌v�Z
			topEnd = fontSize + ballSize;//��[�̌v�Z
			bottomWall = clientSize.y - fontSize - blockSize;//���[�̐���y���W
			ringBar = bottomWall + halfBlockSize;//�����������O���~�܂�y���W
			bottomEnd = bottomWall - ballSize;//���[�̌v�Z
			endInPos = blockSize - ballSize;//�u���b�N�̒��ő΋ɂ̕ǂ���{�[���̒��S�܂ł̒����̌v�Z
			ballsDis = ballSize * 2;//�{�[�����m�̒��S�ԋ����̌v�Z
			ballsDis2 = ballsDis * ballsDis;//�{�[�����m�̒��S�ԋ����̓��̌v�Z
			ballsNearDis2 = ballsDis2 * 8;//�{�[�����m�̒��S�ԋ����̓��̌v�Z
			ballRingDis = ballSize + ballSize4;//�{�[���ƃ����O�̒��S�ԋ����̌v�Z
			ballRingDis2 = ballRingDis * ballRingDis;//�{�[���ƃ����O�̒��S�ԋ����̓��̌v�Z

			deadline = (int)blockSize + fontSize2;//�f�b�h���C���̌v�Z

			speed = deltaTime * ballSize * 0.003f;//�{�[���̈ړ����x�̌v�Z
			ResetInterval();//�{�[�������˂����Ԋu�̌v�Z
		}

		//�Q�[���I�[�o�[�ƃw���v�̔w�i
		{
			Vec2<int> ghSize = Vec2<int>();//�w�i�̑傫���̐錾
			ghSize.x = MAXROW * 3 / 2 * blockSize;//�w�i�̕��̌v�Z
			ghSize.y = clientSize.y - fontSize2 * 2;

			ghH = MakeScreen(ghSize.x, ghSize.y, true);//�O���t�B�b�N�n���h���̍쐬
			if (ghH != -1) {
				SetDrawScreen(ghH);//�쐬�����O���t�B�b�N�n���h���ɕ`���̐ݒ�

				DrawCircleAA((float)blockSize, (float)blockSize, (float)blockSize - 0.5f, 32, white, true);//�E��̉~�̕`��
				DrawCircleAA((float)blockSize, (float)(ghSize.y - blockSize), (float)blockSize - 0.5f, 32, white, true);//�E���̉~�̕`��
				DrawCircleAA((float)(ghSize.x - blockSize), (float)blockSize, (float)blockSize - 0.5f, 32, white, true);//����̉~�̕`��
				DrawCircleAA((float)(ghSize.x - blockSize), (float)(ghSize.y - blockSize), (float)blockSize - 0.5f, 32, white, true);//�����̉~�̕`��

				DrawBox(blockSize, 0, (ghSize.x - blockSize), blockSize, white, true);//�㑤�̔��̕`��
				DrawBox(0, blockSize, ghSize.x, (ghSize.y - blockSize), white, true);//�^�񒆂̔��̕`��
				DrawBox(blockSize, (ghSize.y - blockSize), (ghSize.x - blockSize), ghSize.y, white, true);//�����̔��̕`��
			}
		}

		//�t�H���g�f�[�^�n���h��
		{
			bfH = CreateFontToHandle(NULL, -1, -1, DX_FONTTYPE_EDGE);//�u���b�N�̑ϋv�x�̃t�H���g�f�[�^�n���h���̍쐬
			goH = CreateFontToHandle(NULL, blockSize * 2, -1, DX_FONTTYPE_ANTIALIASING_EDGE, -1, (int)ballSize);//�u�Q�[���I�[�o�[�v�̃t�H���g�f�[�^�n���h���̍쐬
			btH = CreateFontToHandle(NULL, blockSize, -1, DX_FONTTYPE_ANTIALIASING);//�w�i�̏�̕�����̃t�H���g�f�[�^�n���h���̍쐬
		}

		//�T�E���h�n���h��
		{
			b1H = LoadSoundMem("res\\Ball_1.wav");//�{�[���̌��ʉ��P�̓ǂݍ���
			b2H = LoadSoundMem("res\\Ball_2.wav");//�{�[���̌��ʉ��Q�̓ǂݍ���
			b3H = LoadSoundMem("res\\Ball_3.wav");//�{�[���̌��ʉ��R�̓ǂݍ���
			b4H = LoadSoundMem("res\\Ball_4.wav");//�{�[���̌��ʉ��S�̓ǂݍ���
			bmH = LoadSoundMem("res\\BGM.wav");//�w�i���̓ǂݍ���
			mxH = LoadSoundMem("res\\Max.wav");//�ō��_�̌��ʉ��̓ǂݍ���
			gsH = LoadSoundMem("res\\Go.wav");//�Q�[���I�[�o�[���̓ǂݍ���
		}

		//�I���̈ē�
		{
			toExitPos.x = clientSize.x - GetDrawStringWidth(strings[5], (int)strlen(strings[5]));//�I���̈ē���x���W�̌v�Z
			toExitPos.y = clientSize.y - fontSize;//�I���̈ē���y���W�̌v�Z
		}

		//�G�������g�̒ǉ��֌W
		{
			balls.push_back(Ball());//�{�[���̔z��ɍŏ��̃{�[����ǉ�

			//�ő�s���������[�v
			for (int i = 0; i < MAXROW; i++) {
				map[GetRand(MAXROW - 1) * MAXCOLUMN + 1] = GetRand(1) + 1;//�����_���ȃu���b�N�̔z�u
			}
		}

		PlaySoundMem(bmH, DX_PLAYTYPE_LOOP);//�w�i���̃��[�v�Đ�

		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�


	}
}