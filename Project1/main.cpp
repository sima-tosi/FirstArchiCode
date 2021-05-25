#include <DxLib.h>
#include <sstream>

struct Vec2 {
	float x;
	float y;
};

struct Rect
{
	Vec2 center;
	float w;
	float h;
	float Top  () { return center.y   ; };
	float Down () { return center.y + h; };
	float Left () { return center.x; };
	float Right() { return center.x + w; };
};

void move(const char key[256], Rect& rec)
{
	constexpr float speed = 4.0f;
	if (key[KEY_INPUT_UP] != 0)
	{
		rec.center.y -= speed;
	}
	if (key[KEY_INPUT_DOWN] != 0)
	{
		rec.center.y += speed;
	}
	if (key[KEY_INPUT_LEFT] != 0)
	{
		rec.center.x -= speed;
	}
	if (key[KEY_INPUT_RIGHT] != 0)
	{
		rec.center.x += speed;
	}
}

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	ChangeWindowMode(true);
	DxLib_Init();
	SetGraphMode(640, 480, 16);
	SetWindowText(L"1916016_ìáë∫èrãP");
	SetDrawScreen(DX_SCREEN_BACK);

	Rect rcA = { 100,100,50,50 };
	
	char key[256];

	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();
		GetHitKeyStateAll(key);

		move(key, rcA);
		DrawBox(rcA.Left(), rcA.Top(),
			rcA.Right(), rcA.Down(), 0xffffff, true);

		/*char out[64];
		sprintf_s(out, sizeof(out),
			"x=%3.2f,Å@y=%3.2f\n",
			rcA.center.x, rcA.center.y);
		OutputDebugStringA(out);*/

		std::ostringstream oss;
		oss << "x=" << rcA.center.x;
		oss << ", y=" << rcA.center.y << std::endl;
		OutputDebugStringA(oss.str().c_str());

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}