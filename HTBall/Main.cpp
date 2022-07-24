#include "Main.h"

#include <time.h>

int Main::map[MAPSIZE];

//Windowsアプリケーションのエントリポイント
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	Main *scene = new Main(std::string(lpCmdLine));//初期化

	//終了のメッセージが来るか、描画面のクリアに失敗するか、Escが押されるまでループ
	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//入力関係
		scene->Input();

		//計算関係
		scene->Update();

		//出力関係
		scene->Draw();

		ScreenFlip();//表画面と裏画面を切り替える

		//スクショを撮ろうとしていたら
		if (isTryingScreenShot) {
			time_t seconds;
			struct tm t;
			TCHAR name[128];

			time(&seconds);
			localtime_s(&t, &seconds);
			sprintfDx(name, "ScreenShot_%04d%02d%02d-%02d%02d%02d.png", (t.tm_year + 1900), (t.tm_mon + 1), t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);

			int result = SaveDrawScreen(0, 0, clientSize.x, clientSize.y, name);//スクショの保存

			//スクショに成功したら
			if (result == 0) {
				scene->Log("Screenshot was saved to %s", name);
			}
			else {
				scene->Log("Screenshot was failed to be saved");
			}

			isTryingScreenShot = false;//スクショを撮ろうとしていない
		}
	}

	delete scene;

	return 0;//正常終了
}