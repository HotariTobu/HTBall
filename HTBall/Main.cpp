#include "Main.h"

#include <time.h>

int Main::map[MAPSIZE];

//Windows�A�v���P�[�V�����̃G���g���|�C���g
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	Main *scene = new Main(std::string(lpCmdLine));//������

	//�I���̃��b�Z�[�W�����邩�A�`��ʂ̃N���A�Ɏ��s���邩�AEsc���������܂Ń��[�v
	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//���͊֌W
		scene->Input();

		//�v�Z�֌W
		scene->Update();

		//�o�͊֌W
		scene->Draw();

		ScreenFlip();//�\��ʂƗ���ʂ�؂�ւ���

		//�X�N�V�����B�낤�Ƃ��Ă�����
		if (isTryingScreenShot) {
			time_t seconds;
			struct tm t;
			TCHAR name[128];

			time(&seconds);
			localtime_s(&t, &seconds);
			sprintfDx(name, "ScreenShot_%04d%02d%02d-%02d%02d%02d.png", (t.tm_year + 1900), (t.tm_mon + 1), t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);

			int result = SaveDrawScreen(0, 0, clientSize.x, clientSize.y, name);//�X�N�V���̕ۑ�

			//�X�N�V���ɐ���������
			if (result == 0) {
				scene->Log("Screenshot was saved to %s", name);
			}
			else {
				scene->Log("Screenshot was failed to be saved");
			}

			isTryingScreenShot = false;//�X�N�V�����B�낤�Ƃ��Ă��Ȃ�
		}
	}

	delete scene;

	return 0;//����I��
}