#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int printtable(char *Block,char ppattern);//重印表格
int inputpro(char *Iblock, int Input, char *Ipattern, int *End, int *t);//輸入處理
int direction();//按鍵說明
int decidepattern(char *Pattern);//決定初始符號
int exchangepattern(char *Pattern);//交換符號
int check(char block[9], char *cpattern, int *END, int *Ti);//check
int music();//音樂

int circlecross()
{
	char block[9] = { '\0' },pattern;
	int input, end, T[9] = { 0 };

	direction();//說明
	decidepattern(&pattern);//決定誰先
	printtable(block,pattern);//印出初始table
	do
	{
		printf("請輸入位置:\n");//接收輸入
		scanf_s("%d", &input);//接收輸入
		inputpro(block, input, &pattern,&end,T);//處理輸入+check
	} while (end!=1);
	return 0;
}

int printtable(char *Block,char ppattern)
{
	system("cls");
	direction();
	printf("------------\n"
		"| %c | %c | %c |\n"
		"------------\n"
		"| %c | %c | %c |\n"
		"------------\n"
		"| %c | %c | %c |\n"
		"------------\n", Block[6], Block[7], Block[8], Block[3], Block[4], Block[5], Block[0], Block[1], Block[2]);
	printf("現在輪到\"%c\"嚕\n\n", ppattern);

	return 0;
}

int inputpro(char *Iblock,int Input,char *Ipattern,int *End,int *t)
{
	switch (Input)
	{
	case 0:
		printf("\n\n準備換歌嚕!!\n\n"); Sleep(2500);
		music(); printtable(Iblock,*Ipattern);
		break;
	default:
		if (Iblock[Input - 1] == '\0')
		{
			Iblock[Input - 1] = *Ipattern;
			t[Input - 1]++;
			check(Iblock, Ipattern, End, t);
		}
		else{ printf("\n\n重複或錯誤輸入!!\n\n"); Sleep(4000); printtable(Iblock, *Ipattern); }
		break;
	}
	return 0;
}

int direction()
{
	printf("玩法說明.......\n\n\n"
		"參照以下圖示.......\n\n\n"
		"------------\n"
		"| %c | %c | %c |\n"
		"------------\n"
		"| %c | %c | %c |\n"
		"------------\n"
		"| %c | %c | %c |\n"
		"------------\n"
		"位置表!!\n對應鍵盤右側1-9!!\n0可換歌喔~~\n\n", '7', '8', '9', '4', '5', '6', '1', '2', '3');

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
	return 0;
}

int decidepattern(char *Pattern)
{
	srand((int)time(NULL));
	int buffer = (rand()%2)+1;
	switch (buffer)
	{
	case 1:
		*Pattern='X';
		break;
	case 2:
		*Pattern='O';
		break;
	}
	return 0;
}

int exchangepattern(char *Pattern)
{
	if (*Pattern == 'X'){
		*Pattern = 'O';
	}
	else
	{
		*Pattern = 'X';
	}
	return 0;
}

int check(char *block ,char *cpattern,int *END,int *Ti)
{
	int i,go=0;
	go = 0;
	for ( i = 0; i <= 2; i++)
	{
		if ((block[i] == *cpattern) && (block[i + 3] == *cpattern) && (block[i+6]==*cpattern))
		{
			go = 1;
		}
		
	}
	for (i = 0; i <= 8; i=i+3)
	{
		if ((block[i] == *cpattern) && (block[i + 1] == *cpattern) && (block[i + 2] == *cpattern))
		{
			go = 1;
		}
	}
	if (((block[0] == *cpattern) && (block[4] == *cpattern) && (block[8] == *cpattern)) || ((block[2] == *cpattern) && (block[4] == *cpattern) && (block[6] == *cpattern)))
	{
		go = 1;
	}
	if ((((Ti[8] == Ti[7]) && (Ti[7] == Ti[6])) && ((Ti[6] == Ti[5]) && (Ti[5] == Ti[4])))
		&& (((Ti[4] == Ti[3]) && (Ti[3] == Ti[2])) && ((Ti[2] == Ti[1]) && (Ti[1] == Ti[0])))
		&& (Ti[0] == 1)){
		if (go != 1)
		{
			go = 3;
		}
	}
	if (go == 0)
	{
		exchangepattern(cpattern); //換符號*/
		printtable(block, *cpattern);
	}
	else if(go == 1){ printtable(block, *cpattern); printf("\n\n\"%c\"贏了!!\n\n", *cpattern); *END = 1;  }
	else { printtable(block, *cpattern); printf("\n\n平手了!!for god sake!\n\n", *cpattern); *END = 1;  }
	return 0;
}