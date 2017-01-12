#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>

int circlecross();
int music();
int sss();
int _SetConsoleTitle();


int main()
{
	char Title[12] = "playstation";
	_SetConsoleTitle(&Title);
	if (MessageBox(NULL, TEXT("你確定要玩??"), TEXT("圈圈叉叉時間到~~~"), MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		MessageBox(NULL, TEXT("不爽讓你玩~~"), TEXT("不爽讓你玩!!"), MB_OK);
		goto end;
	}
	else
	{
		MessageBox(NULL, TEXT("大哥別動怒，給你玩就是了"), TEXT("給你玩就是了"), MB_OK);
		MessageBox(NULL, TEXT("請好好享受雷姆教music"), TEXT("enjoy~~"), MB_OK);
	}
	system("color F4");
	sss(0);
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hOut, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	typedef enum{Circlecross = 1,changesong,out}choicegame;
	choicegame selectmodel;

	keybd_event(VK_LWIN, 0x5B, 0, 0);
	keybd_event(VK_UP, 0x26, 0, 0);
	keybd_event(VK_LWIN, 0x5B, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_UP, 0x26, KEYEVENTF_KEYUP, 0);
	
	music();
	
	do
	{
		printf("%s", "Please enter modol(1圈圈叉叉,2換歌,3結束):");
		scanf_s("%d", &selectmodel);
		printf("\n");


		system("cls");
		switch (selectmodel)
		{
		case Circlecross:
			SetConsoleTextAttribute(hOut,
				BACKGROUND_BLUE |
				FOREGROUND_RED |  // 前景色_红色
				FOREGROUND_BLUE | // 前景色_蓝色
				FOREGROUND_INTENSITY);// 加强
			circlecross();
			Sleep(5000);
			break;
		case out:
			goto end;
			break;
		case changesong:
			music();
			break;
		}
		SetConsoleTextAttribute(hOut, wOldColorAttrs);
		system("cls");
	} while (selectmodel != EOF);

	system("pause");
end:
	return 0;
}

int sss(int x)
{
	CONSOLE_CURSOR_INFO y;
	y.bVisible = x;
	y.dwSize = 12;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &y);
	return 0;
}

int _SetConsoleTitle(const char* title)
{
	SetConsoleTitle(title);
	return 0;

}