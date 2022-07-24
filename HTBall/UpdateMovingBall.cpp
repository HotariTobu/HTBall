#include "Update.h"

void UpdateMovingBall() {
	canShot = true;//ボールを発射できるように

	unsigned int index = 0;//発射したボールの要素番号の宣言
	auto beginIte = balls.begin();
	//ボールの配列の全要素または動かせるボールの個数だけのアクセス
	for (auto ite = beginIte; ite != balls.end() && index < ballStock; ite++, index++) {
		//ボールが止まっていたら
		if ((*ite).stoped) {
			continue;//次のボールに移る
		}
		//ボールが止まっていなかったら
		else {
			canShot = false;//ボールは発射できない
		}

		//ボールが落ちてなかったら
		if ((*ite).moving) {
			//ボールが1フレームに動く回数だけループ
			for (int i = 0; i < movement; i++) {
				(*ite).x += (*ite).addX;//ボールのx座標の加算
				(*ite).y -= (*ite).addY;//ボールのy座標の減算

				//ボールが右端に到達したら
				if ((*ite).x > rightEnd) {
					(*ite).x = rightEnd * 2 - (*ite).x;//差の2倍をボールのx座標に減算
					(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算
				}
				//ボールが上端に到達したら
				else if ((*ite).y < topEnd) {
					(*ite).y = topEnd * 2 - (*ite).y;//差の2倍をボールのy座標に加算
					(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算
				}
				//ボールが下端に到達したら
				else if ((*ite).y > bottomEnd) {
					(*ite).y = bottomEnd * 2 - (*ite).y;//差の2倍をボールのy座標に減算
					(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算
				}
				//ボールが端に到達していなかったら
				else if ((*ite).x > fontSize2) {
					int row = 0;//ボールのポジションの行の初期化
					int column = 0;//ボールのポジションの列の初期化
					(*ite).GetPos(&row, &column);//ボールのポジションの取得

					float ex = fmodf((*ite).x - fontSize2, (float)blockSize);//ブロックの中でのx座標の初期化
					float ey = fmodf((*ite).y - fontSize, (float)blockSize);//ブロックの中でのy座標の初期化

					//右方向に対する当たり判定を計算する必要があったら
					if ((*ite).walls[0]) {
						int mapIndex = row * MAXCOLUMN + (column - 1);//マップの配列の要素番号の初期化
						int value = Main::GetMapAt(mapIndex);//マップの要素の取得

						//ボールがブロックの右端にあり、右方向にブロックがあったら
						if (ex >= endInPos && value > 0) {
							(*ite).x -= (ex - endInPos) * 2;//差の2倍をボールのx座標に減算

							int j = 1;//すり抜けるブロックの数の初期化

							int toRow = 0;//行き先のポジションの行の初期化
							int toColumn = 0;//行き先のポジションの列の初期化

							 //ボールのモードで分岐
							switch (ballMode) {
								//ボールの色が赤だったら
							case 1:
								value -= 2;//ブロックの耐久度を減らす
								score += 2;//スコアを増やす

								break;//分岐を抜ける

								 //ボールの色が青だったら
							case 5:
								//すり抜けた先がブロックでなくなるまでループ
								while (column - j > 0 && Main::GetMapAt(mapIndex - j) > 0) {
									j++;//すり抜けるブロックの数を増やす
								}

								//すり抜けた先で端を越えていなかったら
								if (column - j > 0) {
									(*ite).x += (ex - endInPos) * 2 + ballSize2 + blockSize * j;//ボールのすり抜け

									(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

									//すり抜けるブロックの数だけループ
									for (int l = 0; l < j; l++) {
										Main::SetMapAt(mapIndex - l, Main::GetMapAt(mapIndex - l) - 1);//ブロックの耐久度を減らす
										score++;//スコアを増やす
									}
								}

								//ボールの色が緑だったら
							case 3:
								//1/2の確率で
								if (GetRand(1)) {
									value--;//ブロックの耐久度を減らす
									score++;//スコアを増やす
								}

								break;//分岐を抜ける

								//ボールの色がシアンだったら
							case 4:
								(*ite).x -= halfBlockSize;//ボールのx座標の減算

								(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

								value--;//ブロックの耐久度を減らす
								score++;//スコアを増やす

								break;//分岐を抜ける

								//ボールの色が紫だったら
							case 6:
								//行き先がブロックがないポジションになるまでループ
								do {
									toRow = GetRand(MAXROW - 1);//行き先のポジションの行の代入
									toColumn = GetRand(MAXCOLUMN - 1);//行き先のポジションの列の代入
								} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

								(*ite).x -= (toColumn - column) * blockSize;//ボールのx座標の減算
								(*ite).y += (toRow - row) * blockSize;//ボールのy座標の加算

								//ボールの色が上記以外だったら
							default:
								value--;//ブロックの耐久度を減らす
								score++;//スコアを増やす

								break;//分岐を抜ける
							}

							//ブロックの耐久度が負の数になったら
							if (value < 0) {
								value = 0;//無にする
							}

							Main::SetMapAt(mapIndex, value);//ブロックの耐久度を適用する

							(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

							PlaySoundMem(b1H, DX_PLAYTYPE_BACK);//ボールの効果音１のバック再生
						}
					}

					//上方向に対する当たり判定を計算する必要があったら
					if ((*ite).walls[1]) {
						int mapIndex = (row - 1) * MAXCOLUMN + column;//マップの配列の要素番号の初期化
						int value = Main::GetMapAt(mapIndex);//マップの要素の取得

						//ボールがブロックの上端にあり、上方向にブロックがあったら
						if (ey <= ballSize && value > 0) {
							(*ite).y += (ballSize - ey) * 2;//差の2倍をボールのy座標に加算

							int j = 1;//すり抜けるブロックの数の初期化

							int toRow = 0;//行き先のポジションの行の初期化
							int toColumn = 0;//行き先のポジションの列の初期化

							 //ボールのモードで分岐
							switch (ballMode) {
								//ボールの色が赤だったら
							case 1:
								value -= 2;//ブロックの耐久度を減らす
								score += 2;//スコアを増やす

								break;//分岐を抜ける

								//ボールの色が青だったら
							case 5:
								//すり抜けた先がブロックでなくなるまでループ
								while (row - j > 0 && Main::GetMapAt(mapIndex - j * MAXCOLUMN) > 0) {
									j++;//すり抜けるブロックの数を増やす
								}

								//すり抜けた先で端を越えていなかったら
								if (row - j > 0) {
									(*ite).y -= (ballSize - ey) * 2 + ballSize2 + blockSize * j;//ボールのすり抜け

									(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

									//すり抜けるブロックの数だけループ
									for (int l = 0; l < j; l++) {
										Main::SetMapAt(mapIndex - l * MAXCOLUMN, Main::GetMapAt(mapIndex - l * MAXCOLUMN) - 1);//ブロックの耐久度を減らす
										score++;//スコアを増やす
									}
								}

								//ボールの色が緑だったら
							case 3:
								//1/2の確率で
								if (GetRand(1)) {
									value--;//ブロックの耐久度を減らす
									score++;//スコアを増やす
								}

								break;//分岐を抜ける

								//ボールの色がシアンだったら
							case 4:
								(*ite).y += halfBlockSize;//ボールのy座標の加算

								(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

								value--;//ブロックの耐久度を減らす
								score++;//スコアを増やす

								break;//分岐を抜ける

								//ボールの色が紫だったら
							case 6:
								//行き先がブロックがないポジションになるまでループ
								do {
									toRow = GetRand(MAXROW - 1);//行き先のポジションの行の代入
									toColumn = GetRand(MAXCOLUMN - 1);//行き先のポジションの列の代入
								} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

								(*ite).x -= (toColumn - column) * blockSize;//ボールのx座標の減算
								(*ite).y += (toRow - row) * blockSize;//ボールのy座標の加算

								 //ボールの色が上記以外だったら
							default:
								value--;//ブロックの耐久度を減らす
								score++;//スコアを増やす

								break;//分岐を抜ける
							}

							//ブロックの耐久度が負の数になったら
							if (value < 0) {
								value = 0;//無にする
							}

							Main::SetMapAt(mapIndex, value);//ブロックの耐久度を適用する

							(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

							PlaySoundMem(b1H, DX_PLAYTYPE_BACK);//ボールの効果音１のバック再生
						}
					}

					//左方向に対する当たり判定を計算する必要があったら
					if ((*ite).walls[2] && column + 1 < MAXCOLUMN) {
						int mapIndex = row * MAXCOLUMN + (column + 1);//マップの配列の要素番号の初期化
						int value = Main::GetMapAt(mapIndex);//マップの要素の取得

						//ボールがブロックの左端にあり、左方向にブロックがあったら
						if (ex <= ballSize && value > 0) {
							(*ite).x += (ballSize - ex) * 2;//差の2倍をボールのx座標に加算

							int j = 1;//すり抜けるブロックの数の初期化

							int toRow = 0;//行き先のポジションの行の初期化
							int toColumn = 0;//行き先のポジションの列の初期化

							//ボールのモードで分岐
							switch (ballMode) {
								//ボールの色が赤だったら
							case 1:
								value -= 2;//ブロックの耐久度を減らす
								score += 2;//スコアを増やす

								break;//分岐を抜ける

								//ボールの色が青だったら
							case 5:
								//すり抜けた先がブロックでなくなるまでループ
								while (column + 1 + j < MAXCOLUMN && Main::GetMapAt(mapIndex + j) > 0) {
									j++;//すり抜けるブロックの数を増やす
								}

								(*ite).x -= (ballSize - ex) * 2 + ballSize2 + blockSize * j;//ボールのすり抜け

								(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

								//すり抜けるブロックの数だけループ
								for (int l = 0; l < j; l++) {
									Main::SetMapAt(mapIndex + l, Main::GetMapAt(mapIndex + l) - 1);//ブロックの耐久度を減らす
									score++;//スコアを増やす
								}

								//ボールの色が緑だったら
							case 3:
								//1/2の確率で
								if (GetRand(1)) {
									value--;//ブロックの耐久度を減らす
									score++;//スコアを増やす
								}

								break;//分岐を抜ける

								//ボールの色がシアンだったら
							case 4:
								(*ite).x += halfBlockSize;//ボールのx座標の加算

								(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

								value--;//ブロックの耐久度を減らす
								score++;//スコアを増やす

								break;//分岐を抜ける

								//ボールの色が紫だったら
							case 6:
								//行き先がブロックがないポジションになるまでループ
								do {
									toRow = GetRand(MAXROW - 1);//行き先のポジションの行の代入
									toColumn = GetRand(MAXCOLUMN - 1);//行き先のポジションの列の代入
								} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

								(*ite).x -= (toColumn - column) * blockSize;//ボールのx座標の減算
								(*ite).y += (toRow - row) * blockSize;//ボールのy座標の加算

								//ボールの色が上記以外だったら
							default:
								value--;//ブロックの耐久度を減らす
								score++;//スコアを増やす

								break;//分岐を抜ける
							}

							//ブロックの耐久度が負の数になったら
							if (value < 0) {
								value = 0;//無にする
							}

							Main::SetMapAt(mapIndex, value);//ブロックの耐久度を適用する

							(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

							PlaySoundMem(b1H, DX_PLAYTYPE_BACK);//ボールの効果音１のバック再生
						}
					}

					//下方向に対する当たり判定を計算する必要があったら
					if ((*ite).walls[3]) {
						int mapIndex = (row + 1) * MAXCOLUMN + column;//マップの配列の要素番号の初期化
						int value = Main::GetMapAt(mapIndex);//マップの要素の取得

						//ボールがブロックの下端にあり、下方向にブロックがあったら
						if (ey >= endInPos && value > 0) {
							(*ite).y -= (ey - endInPos) * 2;//差の2倍をボールのy座標に減算

							int j = 1;//すり抜けるブロックの数の初期化

							int toRow = 0;//行き先のポジションの行の初期化
							int toColumn = 0;//行き先のポジションの列の初期化

							//ボールのモードで分岐
							switch (ballMode) {
								//ボールの色が赤だったら
							case 1:
								value -= 2;//ブロックの耐久度を減らす
								score += 2;//スコアを増やす

								break;//分岐を抜ける

								//ボールの色が青だったら
							case 5:
								//すり抜けた先がブロックでなくなるまでループ
								while (row + j < MAXROW - 1 && Main::GetMapAt(mapIndex + j * MAXCOLUMN) > 0) {
									j++;//すり抜けるブロックの数を増やす
								}

								//すり抜けた先で端を越えていなかったら
								if (row + j < MAXROW - 1) {
									(*ite).y += (ey - endInPos) * 2 + ballSize2 + blockSize * j;//ボールのすり抜け

									(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

									//すり抜けるブロックの数だけループ
									for (int l = 0; l < j; l++) {
										Main::SetMapAt(mapIndex + l * MAXCOLUMN, Main::GetMapAt(mapIndex + l * MAXCOLUMN) - 1);//ブロックの耐久度を減らす
										score++;//スコアを増やす
									}
								}

								//ボールの色が緑だったら
							case 3:
								//1/2の確率で
								if (GetRand(1)) {
									value--;//ブロックの耐久度を減らす
									score++;//スコアを増やす
								}

								break;//分岐を抜ける

								//ボールの色がシアンだったら
							case 4:
								(*ite).y -= halfBlockSize;//ボールのy座標の減算

								(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

								value--;//ブロックの耐久度を減らす
								score++;//スコアを増やす

								break;//分岐を抜ける

								//ボールの色が紫だったら
							case 6:
								//行き先がブロックがないポジションになるまでループ
								do {
									toRow = GetRand(MAXROW - 1);//行き先のポジションの行の代入
									toColumn = GetRand(MAXCOLUMN - 1);//行き先のポジションの列の代入
								} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

								(*ite).x -= (toColumn - column) * blockSize;//ボールのx座標の減算
								(*ite).y += (toRow - row) * blockSize;//ボールのy座標の加算

								//ボールの色が上記以外だったら
							default:
								value--;//ブロックの耐久度を減らす
								score++;//スコアを増やす

								break;//分岐を抜ける
							}

							//ブロックの耐久度が負の数になったら
							if (value < 0) {
								value = 0;//無にする
							}

							Main::SetMapAt(mapIndex, value);//ブロックの耐久度を適用する

							(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

							PlaySoundMem(b1H, DX_PLAYTYPE_BACK);//ボールの効果音１のバック再生
						}
					}

					//リングの当たり判定
					{
						int mapIndex = row * MAXCOLUMN + column;//ボールのポジションのマップのインデックス
						int value = Main::GetMapAt(mapIndex);
						//マップの配列のボールのポジションにアイテムかリングがあったら
						if (value < 0) {
							float disX = ex - halfBlockSize;//ボールとアイテムかリングの水平方向における中心間距離の初期化
							float disY = ey - halfBlockSize;//ボールとアイテムかリングの垂直方向における中心間距離の初期化
							float dis2 = disX * disX + disY * disY;//ボールとアイテムかリングの中心間距離の二乗

							//ボールがアイテムかリングに触れていたら
							if (dis2 < ballRingDis2) {
								int tempBallMode = ballMode;//一時的なボールのモードの保持

								//アイテムかリングかで分岐
								switch (value) {
									//アイテムなら
								case -2:
									//かぶっている間はループ
									while (ballMode == tempBallMode) {
										ballMode = GetRand(6);//ボールのモードのランダムな選択
									}

									Main::Log("アイテムを獲得");

									PlaySoundMem(b3H, DX_PLAYTYPE_BACK);//ボールの効果音３のバック再生

									break;//分岐を抜ける

								//リングなら
								case -1:
									Vec2<float> fallingRing = Vec2<float>();//落下中のリングの宣言
									fallingRing.x = (*ite).x - disX;//落下中のリングのx座標の代入
									fallingRing.y = (*ite).y - disY;//落下中のリングのy座標の代入
									fallingRings.push_back(fallingRing);//リングの配列に落下中のリングの追加

									Main::Log("ボールを獲得");

									PlaySoundMem(b2H, DX_PLAYTYPE_BACK);//ボールの効果音２のバック再生

									break;//分岐を抜ける
								}

								Main::SetMapAt(mapIndex, 0);//アイテムかリングをマップから削除

								score++;//スコアを増やす
							}
						}
						//当たり漏れがあったら
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
									int j = 1;//すり抜けるブロックの数の初期化

									int toRow = 0;//行き先のポジションの行の初期化
									int toColumn = 0;//行き先のポジションの列の初期化

									 //ボールのモードで分岐
									switch (ballMode) {
										//ボールの色が赤だったら
									case 1:
										value -= 2;//ブロックの耐久度を減らす
										score += 2;//スコアを増やす

										break;//分岐を抜ける

										 //ボールの色が青だったら
									case 5:
										//すり抜けた先がブロックでなくなるまでループ
										while (column - j > 0 && Main::GetMapAt(mapIndex - j) > 0) {
											j++;//すり抜けるブロックの数を増やす
										}

										//すり抜けた先で端を越えていなかったら
										if (column - j > 0) {
											(*ite).x += (dif.x + ballSize * (signbit(dif.x) ? -1 : 1)) * 2 + blockSize * j;//ボールのすり抜け

											(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

											//すり抜けるブロックの数だけループ
											for (int l = 0; l < j; l++) {
												Main::SetMapAt(mapIndex - l, Main::GetMapAt(mapIndex - l) - 1);//ブロックの耐久度を減らす
												score++;//スコアを増やす
											}
										}

										//ボールの色が緑だったら
									case 3:
										//1/2の確率で
										if (GetRand(1)) {
											value--;//ブロックの耐久度を減らす
											score++;//スコアを増やす
										}

										break;//分岐を抜ける

										//ボールの色がシアンだったら
									case 4:
										(*ite).x -= halfBlockSize;//ボールのx座標の減算

										(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

										value--;//ブロックの耐久度を減らす
										score++;//スコアを増やす

										break;//分岐を抜ける

										//ボールの色が紫だったら
									case 6:
										//行き先がブロックがないポジションになるまでループ
										do {
											toRow = GetRand(MAXROW - 1);//行き先のポジションの行の代入
											toColumn = GetRand(MAXCOLUMN - 1);//行き先のポジションの列の代入
										} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

										(*ite).x -= (toColumn - column) * blockSize;//ボールのx座標の減算
										(*ite).y += (toRow - row) * blockSize;//ボールのy座標の加算

										//ボールの色が上記以外だったら
									default:
										value--;//ブロックの耐久度を減らす
										score++;//スコアを増やす

										break;//分岐を抜ける
									}

									//ブロックの耐久度が負の数になったら
									if (value < 0) {
										value = 0;//無にする
									}
								}
								else {
									int j = 1;//すり抜けるブロックの数の初期化

									int toRow = 0;//行き先のポジションの行の初期化
									int toColumn = 0;//行き先のポジションの列の初期化

									//ボールのモードで分岐
									switch (ballMode) {
										//ボールの色が赤だったら
									case 1:
										value -= 2;//ブロックの耐久度を減らす
										score += 2;//スコアを増やす

										break;//分岐を抜ける

										//ボールの色が青だったら
									case 5:
										//すり抜けた先がブロックでなくなるまでループ
										while (column + 1 + j < MAXCOLUMN && Main::GetMapAt(mapIndex + j) > 0) {
											j++;//すり抜けるブロックの数を増やす
										}

										(*ite).x -= (dif.x + ballSize * (signbit(dif.x) ? -1 : 1)) * 2 + blockSize * j;//ボールのすり抜け

										(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

										//すり抜けるブロックの数だけループ
										for (int l = 0; l < j; l++) {
											Main::SetMapAt(mapIndex + l, Main::GetMapAt(mapIndex + l) - 1);//ブロックの耐久度を減らす
											score++;//スコアを増やす
										}

										//ボールの色が緑だったら
									case 3:
										//1/2の確率で
										if (GetRand(1)) {
											value--;//ブロックの耐久度を減らす
											score++;//スコアを増やす
										}

										break;//分岐を抜ける

										//ボールの色がシアンだったら
									case 4:
										(*ite).x += halfBlockSize;//ボールのx座標の加算

										(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

										value--;//ブロックの耐久度を減らす
										score++;//スコアを増やす

										break;//分岐を抜ける

										//ボールの色が紫だったら
									case 6:
										//行き先がブロックがないポジションになるまでループ
										do {
											toRow = GetRand(MAXROW - 1);//行き先のポジションの行の代入
											toColumn = GetRand(MAXCOLUMN - 1);//行き先のポジションの列の代入
										} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

										(*ite).x -= (toColumn - column) * blockSize;//ボールのx座標の減算
										(*ite).y += (toRow - row) * blockSize;//ボールのy座標の加算

										//ボールの色が上記以外だったら
									default:
										value--;//ブロックの耐久度を減らす
										score++;//スコアを増やす

										break;//分岐を抜ける
									}

									//ブロックの耐久度が負の数になったら
									if (value < 0) {
										value = 0;//無にする
									}
								}

								(*ite).SetTheta(halfRadian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算
							}
							else {
								(*ite).y += (dif.y + ballSize * (signbit(dif.y) ? -1 : 1)) * 2;

								if ((*ite).walls[1]) {
									int j = 1;//すり抜けるブロックの数の初期化

									int toRow = 0;//行き先のポジションの行の初期化
									int toColumn = 0;//行き先のポジションの列の初期化

									 //ボールのモードで分岐
									switch (ballMode) {
										//ボールの色が赤だったら
									case 1:
										value -= 2;//ブロックの耐久度を減らす
										score += 2;//スコアを増やす

										break;//分岐を抜ける

										//ボールの色が青だったら
									case 5:
										//すり抜けた先がブロックでなくなるまでループ
										while (row - j > 0 && Main::GetMapAt(mapIndex - j * MAXCOLUMN) > 0) {
											j++;//すり抜けるブロックの数を増やす
										}

										//すり抜けた先で端を越えていなかったら
										if (row - j > 0) {
											(*ite).y -= (dif.y + ballSize * (signbit(dif.y) ? -1 : 1)) * 2 + blockSize * j;//ボールのすり抜け

											(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

											//すり抜けるブロックの数だけループ
											for (int l = 0; l < j; l++) {
												Main::SetMapAt(mapIndex - l * MAXCOLUMN, Main::GetMapAt(mapIndex - l * MAXCOLUMN) - 1);//ブロックの耐久度を減らす
												score++;//スコアを増やす
											}
										}

										//ボールの色が緑だったら
									case 3:
										//1/2の確率で
										if (GetRand(1)) {
											value--;//ブロックの耐久度を減らす
											score++;//スコアを増やす
										}

										break;//分岐を抜ける

										//ボールの色がシアンだったら
									case 4:
										(*ite).y += halfBlockSize;//ボールのy座標の加算

										(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

										value--;//ブロックの耐久度を減らす
										score++;//スコアを増やす

										break;//分岐を抜ける

										//ボールの色が紫だったら
									case 6:
										//行き先がブロックがないポジションになるまでループ
										do {
											toRow = GetRand(MAXROW - 1);//行き先のポジションの行の代入
											toColumn = GetRand(MAXCOLUMN - 1);//行き先のポジションの列の代入
										} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

										(*ite).x -= (toColumn - column) * blockSize;//ボールのx座標の減算
										(*ite).y += (toRow - row) * blockSize;//ボールのy座標の加算

										 //ボールの色が上記以外だったら
									default:
										value--;//ブロックの耐久度を減らす
										score++;//スコアを増やす

										break;//分岐を抜ける
									}

									//ブロックの耐久度が負の数になったら
									if (value < 0) {
										value = 0;//無にする
									}
								}
								else {
									int j = 1;//すり抜けるブロックの数の初期化

									int toRow = 0;//行き先のポジションの行の初期化
									int toColumn = 0;//行き先のポジションの列の初期化

									//ボールのモードで分岐
									switch (ballMode) {
										//ボールの色が赤だったら
									case 1:
										value -= 2;//ブロックの耐久度を減らす
										score += 2;//スコアを増やす

										break;//分岐を抜ける

										//ボールの色が青だったら
									case 5:
										//すり抜けた先がブロックでなくなるまでループ
										while (row + j < MAXROW - 1 && Main::GetMapAt(mapIndex + j * MAXCOLUMN) > 0) {
											j++;//すり抜けるブロックの数を増やす
										}

										//すり抜けた先で端を越えていなかったら
										if (row + j < MAXROW - 1) {
											(*ite).y += (dif.y + ballSize * (signbit(dif.y) ? -1 : 1)) * 2 + blockSize * j;//ボールのすり抜け

											(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

											//すり抜けるブロックの数だけループ
											for (int l = 0; l < j; l++) {
												Main::SetMapAt(mapIndex + l * MAXCOLUMN, Main::GetMapAt(mapIndex + l * MAXCOLUMN) - 1);//ブロックの耐久度を減らす
												score++;//スコアを増やす
											}
										}

										//ボールの色が緑だったら
									case 3:
										//1/2の確率で
										if (GetRand(1)) {
											value--;//ブロックの耐久度を減らす
											score++;//スコアを増やす
										}

										break;//分岐を抜ける

										//ボールの色がシアンだったら
									case 4:
										(*ite).y -= halfBlockSize;//ボールのy座標の減算

										(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算

										value--;//ブロックの耐久度を減らす
										score++;//スコアを増やす

										break;//分岐を抜ける

										//ボールの色が紫だったら
									case 6:
										//行き先がブロックがないポジションになるまでループ
										do {
											toRow = GetRand(MAXROW - 1);//行き先のポジションの行の代入
											toColumn = GetRand(MAXCOLUMN - 1);//行き先のポジションの列の代入
										} while (Main::GetMapAt(toRow * MAXCOLUMN + toColumn) > 0);

										(*ite).x -= (toColumn - column) * blockSize;//ボールのx座標の減算
										(*ite).y += (toRow - row) * blockSize;//ボールのy座標の加算

										//ボールの色が上記以外だったら
									default:
										value--;//ブロックの耐久度を減らす
										score++;//スコアを増やす

										break;//分岐を抜ける
									}

									//ブロックの耐久度が負の数になったら
									if (value < 0) {
										value = 0;//無にする
									}
								}

								(*ite).SetTheta(radian - (*ite).GetTheta());//ラジアンのボールが進む角度の再計算
							}

							Main::SetMapAt(mapIndex, value);//ブロックの耐久度を適用する
							PlaySoundMem(b1H, DX_PLAYTYPE_BACK);//ボールの効果音１のバック再生
						}
					}

					//スコアが最高点に達したら
					if (score == ULLONG_MAX) {
						Main::Log("スコアが最高点に到達！");

						score = 0;//スコアの代入
						maxScoresStr += "★";//最高点のスコアを出した回数を増やす

						PlaySoundMem(mxH, DX_PLAYTYPE_BACK);//最高点の効果音のバック再生
					}
				}

				//他のボールに対する当たり判定
				if (ballsCo && (ballMode != 2 || (*ite).x > deadline)) {
					int px = (int)(((*ite).x - fontSize2) / ballSize4);//ボールのボール専用のxポジションの初期化
					int py = (int)(((*ite).y - fontSize) / ballSize4);//ボールのボール専用のyポジションの初期化

					//動かせるボールの個数だけループ
					for (unsigned int j = 0; j < ballStock; j++) {
						auto otherIte = beginIte + j;//他のボールのイテレータの初期化

						//他のボールではなかった、または動いていなかった、または止まっていたら
						if (ite == otherIte || !(*otherIte).moving || (*otherIte).stoped) {
							continue;//処理を省く
						}

						float disX = (*otherIte).x - (*ite).x;//ボールと他のボールとの水平方向における距離の初期化
						float disY = (*ite).y - (*otherIte).y;//ボールと他のボールとの垂直方向における距離の初期化
						float dis2 = disX * disX + disY * disY;//ボールと他のボールの中心間距離の二乗の初期化

						onePos |= dis2 < ballsNearDis2;

						//ボールと他のボールが重なっていたら
						if (dis2 < ballsDis2) {
							float sub = ballsDis - sqrtf(dis2);//ボール同士の中心間距離とボールと他のボールの中心間距離の差の初期化
							(*ite).x -= (float)(sub * cos((*ite).GetTheta()));//水平方向においてボールと他のボールが重ならないようにする
							(*ite).y += (float)(sub * sin((*ite).GetTheta()));//垂直方向においてボールと他のボールが重ならないようにする

							double perpendicularRadian = atan2((double)disY, (double)disX) * 2;//水平方向からの角度のずれの計算

							(*ite).SetTheta(halfRadian - (*ite).GetTheta() + perpendicularRadian);//ボールのラジアンのボールが進む角度の再計算
							(*otherIte).SetTheta(halfRadian - (*otherIte).GetTheta() + perpendicularRadian);//他のボールのラジアンのボールが進む角度の再計算

							PlaySoundMem(b4H, DX_PLAYTYPE_BACK);//ボールの効果音４のバック再生
						}
					}
				}

				//ボールが左端に到達したら
				if ((*ite).x < launcherPos.x) {
					//着地点が設定されていなかったら
					if (floating) {
						launcherPos.y = (*ite).y;//発射する前のボールのy座標の代入

						Main::Log("着地点を設定");

						floating = false;//着地点が設定されている

						(*ite).SetTheta(0);//角度のリセット
						(*ite).stoped = true;//ボールは止まった
					}
					//着地点が設定されていたら
					else {
						(*ite).SetTheta(atan2f((*ite).y - launcherPos.y, launcherPos.x - (*ite).x));//着地点の方向を向く
						(*ite).moving = false;//ボールは落ちた
					}

					break;//ボールを動かすループを抜ける
				}
			}
		}
		//ボールが落ちていたら
		else {
			float disX = launcherPos.x - (*ite).x;//ボールと着地点との水平方向における距離の初期化
			float disY = launcherPos.y - (*ite).y;//ボールと着地点との垂直方向における距離の初期化
			float dis2 = disX * disX + disY * disY;//ボールと着地点との距離の二乗の初期化
			float dis = sqrtf(dis2);//ボールと着地点との距離の初期化
			float disr = dis / BALLRATIO * speed;//ボールと着地点との距離に移動するための数を乗算したものの初期化
			Vec2<float> addSub = Vec2<float>();//ボールの座標に加減算する値の宣言
			addSub.x = (float)(disr * cos((*ite).GetTheta()));//ボールのx座標に加算する値の計算
			addSub.y = (float)(disr * sin((*ite).GetTheta()));//ボールのy座標に減算する値の計算

			//ボールが1フレームに動く回数だけループ
			for (int i = 0; i < movement; i++) {
				(*ite).x += addSub.x;//ボールのx座標の加算
				(*ite).y -= addSub.y;//ボールのy座標の減算

				disX = launcherPos.x - (*ite).x;//ボールと着地点との水平方向における距離の代入
				disY = launcherPos.y - (*ite).y;//ボールと着地点との垂直方向における距離の代入
				dis2 = disX * disX + disY * disY;//ボールと着地点との距離の二乗の代入
				dis = sqrtf(dis2);//ボールと着地点との距離の代入
				float adis = sqrtf(dis2);//ボールと着地点との距離の代入

				//着地点に遠ざかっていたら
				if (dis < adis) {
					(*ite).SetTheta(atan2f((*ite).y - launcherPos.y, launcherPos.x - (*ite).x));//着地点の方向を向く
					float disr = adis / BALLRATIO * speed;//ボールと着地点との距離に移動するための数を乗算したものの初期化
					Vec2<float> addSub = Vec2<float>();//ボールの座標に加減算する値の宣言
					addSub.x = (float)(disr * cos((*ite).GetTheta()));//ボールのx座標に加算する値の計算
					addSub.y = (float)(disr * sin((*ite).GetTheta()));//ボールのy座標に減算する値の計算
				}

				//ボールが着地点に近くなったら
				if (adis < ballSize) {
					(*ite).x = launcherPos.x;//ボールのx座標の代入
					(*ite).y = launcherPos.y;//ボールのy座標の代入
					(*ite).stoped = true;//ボールは止まった

					break;//ボールを動かすループを抜ける
				}
			}
		}
	}
}