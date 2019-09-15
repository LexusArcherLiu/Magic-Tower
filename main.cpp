//图形库的基本框架
#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#define MAXSTAR1 1000  //点的数量


extern void menu_select();
extern void loadResourse();
extern void LogIn();
extern void excessive0();
extern void excessive1();

//extern void init_map_floorOneGameUI();
extern void init_mapGameUI(int map[13][13]);
extern bool playGame(int map[13][13]);
extern bool playGame_search(int map[13][13]);
extern bool playGame_final();
extern HWND hwnd;
extern int map_init[13][13];
extern int map_floorOne[13][13];
extern int map_floorFin[13][13];
extern int map_floorSword[13][13];
extern int map_floorShield[13][13];
extern void initStar1(int i);
extern void initStar(int i);
extern void moveStar1(int i);
extern void initData(int weight);
extern void moveStar();
extern void drawStar();
extern void opening();
extern int Dialogue0(IMAGE bg);
extern int Dialogue2(IMAGE bg);
extern int Dialogue4(IMAGE bg);
extern char dialog_init[15][100];
extern char dialog_search[13][100];
extern char Dialogue_Boss[13][100];
extern void writefile1(int map[13][13]);
extern int **readfile1();
extern void writefile2(int map[13][13]);
extern int **readfile2();

int length0 = sizeof(dialog_init) / sizeof(dialog_init[0]);
int length2 = sizeof(dialog_search) / sizeof(dialog_search[0]);
int length4 = sizeof(Dialogue_Boss) / sizeof(Dialogue_Boss[0]);

int main()
{
	//writefile1(map_floorSword);
	//writefile2(map_floorShield);
	//int **map_Sword = NULL;
	//int **map_Shield = NULL;
	//int map_Sw[13][13] = { 0 };
	//int map_Sh[13][13] = { 0 };
	menu_select();
	hwnd = initgraph(60 * 14, 60 * 13);
	opening();
	loadResourse();
	excessive0();
	Sleep(3000);
	int temp1 = 0;
	IMAGE dialogue1,dialogue2, dialogue4;
	loadimage(&dialogue1, "素材/dialogue1.jpg", 60 * 13, 60 * 5);
	loadimage(&dialogue2, "素材/dialogue2.jpg", 60 * 13, 60 * 5);
	loadimage(&dialogue4, "素材/dialogue4.jpg", 60 * 13, 60 * 5);
	while (1) {
		init_mapGameUI(map_init);
		if (temp1 == 0) {
			while (1) {
				if (Dialogue0(dialogue1) == length0) {
					Sleep(1000);
					break;
				}
				else if (Dialogue0(dialogue1) == -1) {
					break;
				}
			}
			temp1++;
		}
		if (playGame(map_init) == true) {
			break;
		}
	}
	LogIn();
	Sleep(3000);
	while (1) {
		init_mapGameUI(map_floorOne);
		if (playGame(map_floorOne) == true) {
			break;
		}
	}
	LogIn();
	Sleep(3000);
	int temp = 1;
	for (int i = 0; i < 2; i++) {
		while (temp == 1) {
			/*map_Sword = readfile1();
				for (int m = 0; m < 13; m++) {
					for (int n = 0; n < 13; n++) {
						map_Sw[m][n] = map_Sword[m][n];
					}
				}
			delete(map_Sword);*/
			init_mapGameUI(map_floorSword);
			if (temp1 == 1) {
				while (1) {
					if (Dialogue2(dialogue2) == length2) {
						Sleep(1000);
						break;
					}
					else if (Dialogue2(dialogue2) == -1) {
						break;
					}
				}
				temp1++;
			}
			if (playGame_search(map_floorSword) == true) {
				break;
			}
		}
		while(temp == 2) {
			/*map_Shield = readfile2();
				for (int m = 0; m < 13; m++) {
					for (int n = 0; n < 13; n++) {
						map_Sh[m][n] = map_Shield[m][n];
					}
				}
				delete(map_Shield);*/
			init_mapGameUI(map_floorShield);
			if (playGame_search(map_floorShield) == true) {
				break;
			}
		}
		temp++;
	}
		//writefile1(map_Sh);
		//writefile1(map_Sw);
	excessive1();
	Sleep(3000);
	while (1) {
		init_mapGameUI(map_floorFin);
		if (temp1 == 2) {
			while (1) {
				if (Dialogue4(dialogue4) == length4) {
					Sleep(1000);
					break;
				}
				else if (Dialogue4(dialogue4) == -1) {
					break;
				}
			}
			temp1++;
		}
		if (playGame_final() == true) {
			break;
		}
	}
	initData(60 * 14);
	while (1) {
		BeginBatchDraw();
		cleardevice();
		for (int i = 0; i < MAXSTAR1; i++)
		{
			moveStar1(i);
		}
		moveStar();
		drawStar();
		Sleep(60);
		EndBatchDraw();
	}
	getchar();
	closegraph();

	return 0;
}
