#include "Main.h"

Main::Main(std::string cmdLine) {
	//コマンドライン引数に"-log"が含まれていたら
	if (cmdLine.find("-log", 0) == std::string::npos) {
		SetOutApplicationLogValidFlag(false);//ログを残さないように
	}

	//コマンドライン引数に"-window"が含まれていたら
	if (cmdLine.find("-window", 0) != std::string::npos) {
		ChangeWindowMode(true);//ウィンドウモードで起動するように
		SetWindowIconID(IDI_ICON1);//ウィンドウのアイコンの設定
	}

	//事前的な初期化
	{
		SetMainWindowText("HTBall");//ウィンドウのタイトルの設定

		radian = dtor(360);//ラジアン表記の360度の計算
		halfRadian = dtor(180);//ラジアン表記の180度の計算
		quarterRadian = dtor(90);//ラジアン表記の90度の計算
		addition = dtor(20);//黄のボールの広がり具合の角度の初期値の計算
	}



	//DxLibの初期化
	if (DxLib_Init() == -1) {
		std::exit(-1);//起動に失敗
	}

	//事後的な初期化
	{
		SetAlwaysRunFlag(true);//常時計算するように

		//時間関係
		{
			ScreenFlip();//デルタの計測の前の調節
			newTime = GetNowCount();//今の時間の取得
			while (true) {
				ScreenFlip();//垂直同期まで待つ
				if (GetNowCount() - newTime >= 1000) {
					break;//1秒後
				}
				frame++;//フレーム数をインクリメント
			}
			deltaTime = 1000.0f / frame;//デルタの計算
			baseFps = frame;//基準のfpsの記録
		}

		//色
		{
			white = GetColor(255, 255, 255);//白の取得
			gray = GetColor(128, 128, 128);//灰色の取得

			ballColors[0] = white;//白：通常のボールの色（通称：普遍的な）
			ballColors[1] = GetColor(255, 0, 0);//赤：耐久度を1回の衝突で2つ減らせるボールの色（通称：救世主）
			ballColors[2] = GetColor(255, 255, 0);//黄：拡散できるボールの色（通称：竜頭蛇尾）
			ballColors[3] = GetColor(0, 255, 0);//緑：耐久度を1/2の確率で減らせないボールの色（通称：詰み）
			ballColors[4] = GetColor(0, 255, 255);//シアン：ブロックをつつくボールの色（通称：ドリル）
			ballColors[5] = GetColor(0, 0, 255);//青：ブロックをすり抜けるボールの色（通称：最強）
			ballColors[6] = GetColor(255, 0, 255);//紫：ワープするボールの色（通称：厄介者）
		}

		//長さ調節関係
		{
			fontSize = GetFontSize();//文字列の高さの取得
			fontSize2 = fontSize * 2;//fontSizeの2倍の計算
			RECT rect;//クライアントの領域を収納する変数の宣言
			GetClientRect(GetMainWindowHandle(), &rect);//クライアント領域の取得
			clientSize.x = rect.right - rect.left;//クライアント領域の水平方向の長さの計算
			blockSize = (clientSize.x - fontSize2) / MAXCOLUMN;//ブロックの1辺の長さの計算
			halfBlockSize = blockSize / 2.0f;//ブロックの1辺の長さの半分の計算
			BlockY = (blockSize - fontSize) / 2.0f;//垂直方向におけるブロックの端からラベルまでの距離の計算
			ballSize = blockSize / BALLRATIO;//ボールの半径の計算
			ballSize2 = ballSize * 2;//ボールの半径の2倍の計算
			ballSize4 = ballSize2 * 2;//ボールの半径の4倍の計算

			clientSize.x = fontSize2 + blockSize * MAXCOLUMN;//クライアント領域の水平方向の長さの再定義
			clientSize.y = rect.bottom - rect.top;//クライアント領域の垂直方向の長さの計算
			clientSize.y = blockSize * (MAXROW + 1) + fontSize2;//クライアント領域の垂直方向の長さの再定義
			SetGraphMode(clientSize.x, clientSize.y, GetColorBitDepth());//画面の描画モードの設定

			launcherPos.x = (float)fontSize;//発射する前のボールのx座標の計算
			launcherPos.y = (float)(fontSize + blockSize * MAXROW / 2);//発射する前のボールのy座標の計算
			lastLauncherY = launcherPos.y;//前回の発射する前のボールのy座標の代入

			rightEnd = clientSize.x - ballSize;//右端の計算
			topEnd = fontSize + ballSize;//上端の計算
			bottomWall = clientSize.y - fontSize - blockSize;//下端の線のy座標
			ringBar = bottomWall + halfBlockSize;//落ちたリングが止まるy座標
			bottomEnd = bottomWall - ballSize;//下端の計算
			endInPos = blockSize - ballSize;//ブロックの中で対極の壁からボールの中心までの長さの計算
			ballsDis = ballSize * 2;//ボール同士の中心間距離の計算
			ballsDis2 = ballsDis * ballsDis;//ボール同士の中心間距離の二乗の計算
			ballsNearDis2 = ballsDis2 * 8;//ボール同士の中心間距離の二乗の計算
			ballRingDis = ballSize + ballSize4;//ボールとリングの中心間距離の計算
			ballRingDis2 = ballRingDis * ballRingDis;//ボールとリングの中心間距離の二乗の計算

			deadline = (int)blockSize + fontSize2;//デッドラインの計算

			speed = deltaTime * ballSize * 0.003f;//ボールの移動速度の計算
			ResetInterval();//ボールが発射される間隔の計算
		}

		//ゲームオーバーとヘルプの背景
		{
			Vec2<int> ghSize = Vec2<int>();//背景の大きさの宣言
			ghSize.x = MAXROW * 3 / 2 * blockSize;//背景の幅の計算
			ghSize.y = clientSize.y - fontSize2 * 2;

			ghH = MakeScreen(ghSize.x, ghSize.y, true);//グラフィックハンドルの作成
			if (ghH != -1) {
				SetDrawScreen(ghH);//作成したグラフィックハンドルに描画先の設定

				DrawCircleAA((float)blockSize, (float)blockSize, (float)blockSize - 0.5f, 32, white, true);//右上の円の描画
				DrawCircleAA((float)blockSize, (float)(ghSize.y - blockSize), (float)blockSize - 0.5f, 32, white, true);//右下の円の描画
				DrawCircleAA((float)(ghSize.x - blockSize), (float)blockSize, (float)blockSize - 0.5f, 32, white, true);//左上の円の描画
				DrawCircleAA((float)(ghSize.x - blockSize), (float)(ghSize.y - blockSize), (float)blockSize - 0.5f, 32, white, true);//左下の円の描画

				DrawBox(blockSize, 0, (ghSize.x - blockSize), blockSize, white, true);//上側の箱の描画
				DrawBox(0, blockSize, ghSize.x, (ghSize.y - blockSize), white, true);//真ん中の箱の描画
				DrawBox(blockSize, (ghSize.y - blockSize), (ghSize.x - blockSize), ghSize.y, white, true);//下側の箱の描画
			}
		}

		//フォントデータハンドル
		{
			bfH = CreateFontToHandle(NULL, -1, -1, DX_FONTTYPE_EDGE);//ブロックの耐久度のフォントデータハンドルの作成
			goH = CreateFontToHandle(NULL, blockSize * 2, -1, DX_FONTTYPE_ANTIALIASING_EDGE, -1, (int)ballSize);//「ゲームオーバー」のフォントデータハンドルの作成
			btH = CreateFontToHandle(NULL, blockSize, -1, DX_FONTTYPE_ANTIALIASING);//背景の上の文字列のフォントデータハンドルの作成
		}

		//サウンドハンドル
		{
			b1H = LoadSoundMem("res\\Ball_1.wav");//ボールの効果音１の読み込み
			b2H = LoadSoundMem("res\\Ball_2.wav");//ボールの効果音２の読み込み
			b3H = LoadSoundMem("res\\Ball_3.wav");//ボールの効果音３の読み込み
			b4H = LoadSoundMem("res\\Ball_4.wav");//ボールの効果音４の読み込み
			bmH = LoadSoundMem("res\\BGM.wav");//背景音の読み込み
			mxH = LoadSoundMem("res\\Max.wav");//最高点の効果音の読み込み
			gsH = LoadSoundMem("res\\Go.wav");//ゲームオーバー音の読み込み
		}

		//終了の案内
		{
			toExitPos.x = clientSize.x - GetDrawStringWidth(strings[5], (int)strlen(strings[5]));//終了の案内のx座標の計算
			toExitPos.y = clientSize.y - fontSize;//終了の案内のy座標の計算
		}

		//エレメントの追加関係
		{
			balls.push_back(Ball());//ボールの配列に最初のボールを追加

			//最大行数だけループ
			for (int i = 0; i < MAXROW; i++) {
				map[GetRand(MAXROW - 1) * MAXCOLUMN + 1] = GetRand(1) + 1;//ランダムなブロックの配置
			}
		}

		PlaySoundMem(bmH, DX_PLAYTYPE_LOOP);//背景音のループ再生

		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に


	}
}