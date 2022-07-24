#include "Main.h"

Main::~Main() {
	DeleteGraph(ghH);
	DeleteFontToHandle(bfH);
	DeleteFontToHandle(goH);
	DeleteFontToHandle(btH);
	DeleteSoundMem(b1H);
	DeleteSoundMem(b2H);
	DeleteSoundMem(b3H);
	DeleteSoundMem(b4H);
	DeleteSoundMem(bmH);
	DeleteSoundMem(mxH);
	DeleteSoundMem(gsH);

	DxLib_End();//DxLib‚ÌŒãˆ—
}