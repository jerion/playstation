#include<music.h>
#define song 8

int music()
{
	int h;
	int r = 0, l = 0;

	srand((int)time(NULL));
	h = (rand() % song) + 1;


	do
	{
		r = 0;
		switch (h)
		{
		case 1:
			if (l != 1)
			{
				PlaySound(TEXT("Wishing.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				l = 1;
			}
			else
			{
				r = 1;
			}
			break;
		case 2:
			if (l != 2)
			{
				PlaySound(TEXT("dori.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				l = 2;
			}
			else{
				r = 1;
			}
			break;
		case 3:
			if (l != 3)
			{
				PlaySound(TEXT("Forever_TV_Size.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				l = 3;
			}
			else{
				r = 1;
			}
			break;
		case 4:
			if (l != 4)
			{
				PlaySound(TEXT("tea_leave.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				l = 4;
			}
			else{
				r = 1;
			}
			break;
		case 5:
			if (l != 5)
			{
				PlaySound(TEXT("aaaopop.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				l = 5;
			}
			else{
				r = 1;
			}
			break;
		case 6:
			if (l != 6)
			{
				PlaySound(TEXT("Hero.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				l = 6;
			}
			else{
				r = 1;
			}
			break;
		case 7:
			if (l != 7)
			{
				PlaySound(TEXT("for_the_world.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				l = 7;
			}
			else{
				r = 1;
			}
			break;
		case 8:
			if (l != 8)
			{
				PlaySound(TEXT("Gears_of_Love.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				l = 8;
			}
			else{
				r = 1;
			}
			break;
		}
	} while (r == 1);
	return 0;
}