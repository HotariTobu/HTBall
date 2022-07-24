#include "Draw.h"

void DrawStageLine() {
	//デッドラインの表示
	DrawLine(deadline, fontSize, deadline, bottomWall, GetColor(240, 0, 0));

	//上端の線の表示
	DrawLine(0, fontSize, clientSize.x, fontSize, white);

	//下端の線の表示
	DrawLine(0, bottomWall, clientSize.x, bottomWall, white);
}