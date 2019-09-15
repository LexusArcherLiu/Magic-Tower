#include "header.h"
#pragma comment(lib,"winmm.lib")
extern HWND hwnd;
int win; // 点开数字的个数
#define ROW 13 //行
#define COL 13 //列
#define NUM 10 //雷的个数
#define SIZE 60//一张图片的宽度

IMAGE img[12];  //定义一个数组，用来存放12张图片；
int mine = 0; //所有排出的地雷的数量
int map[ROW + 2][COL + 2]; //游戏区以及辅助区,1-10行为游戏区，0和11是辅助区
//初始化
void GameInit()
{
	win = 0;
	srand((unsigned int)time(NULL));
	//二维数组初始化 全部初始化
	for (int i = 0; i < ROW + 2; i++) {
		for (int j = 0; j < COL + 2; j++)
		{
			map[i][j] = 0;
		}
	}
	//什么叫雷  -1当作雷 多少个雷 10 雷全部埋在辅助区
	for (int i = 0; i < NUM;)
	{
		int r = rand() % ROW + 1; //随机的行1~10
		int c = rand() % COL + 1;//随机的列1~10

		if (map[r][c] == 0) //全新的不重复的元素
		{
			map[r][c] = -1;//产生一个雷 循环一次
			i++;
		}
	}

	//遍历游戏区数组中不是雷的元素（此处是扫雷的基本思想）
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = 1; j < COL + 1; j++)
		{
			if (map[i][j] != -1)//不是雷
			{
				//遍历九宫格
				for (int m = i - 1; m <= i + 1; m++)
				{
					for (int n = j - 1; n <= j + 1; n++)
					{
						if (map[m][n] == -1)//出现一个雷
						{
							map[i][j]++;
						}
					}
				}
			}
		}
	}
	//要把游戏区每一个元素都+20
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = 1; j < COL + 1; j++)
		{
			map[i][j] += 20;
		}
	}
}
//显示它
void GamePaint()
{
	//二维数组打印
	for (int i = 1; i < ROW + 1; i++) {
		for (int j = 1; j < COL + 1; j++)
		{
			if (map[i][j] == -1)//雷
			{
				putimage((i - 1)*SIZE, (j - 1)*SIZE, &img[9]);
			}
			else if (map[i][j] >= 0 && map[i][j] <= 8)//数字
			{
				putimage((i - 1)*SIZE, (j - 1)*SIZE, &img[map[i][j]]);
			}
			else if (map[i][j] >= 19 && map[i][j] <= 28)//方块
			{
				putimage((i - 1)*SIZE, (j - 1)*SIZE, &img[10]);
			}
			//19-28 点一下 +10000  再点一下 -10000
			else if (map[i][j] > 30)//小旗子
			{
				putimage((i - 1)*SIZE, (j - 1)*SIZE, &img[11]);
			}
		}
		printf("\n");
	}
}
// 一扫一大片的功能
void ClickBlank(int x, int y)
{
	if (map[x][y] - 20 == 0)
	{
		map[x][y] -= 20;
		win++;
		if ((x - 1) > 0 && (y - 1) > 0 && (map[x - 1][y - 1] >= 19))
			ClickBlank(x - 1, y - 1);
		if ((x - 1) > 0 && (y) > 0 && (map[x - 1][y] >= 19))
			ClickBlank(x - 1, y);
		if ((x - 1) > 0 && (y + 1) > 0 && (map[x - 1][y + 1] >= 19))
			ClickBlank(x - 1, y + 1);
		if ((x) > 0 && (y - 1) > 0 && (map[x][y - 1] >= 19))
			ClickBlank(x, y - 1);
		if ((x) > 0 && (y + 1) > 0 && (map[x][y + 1] >= 19))
			ClickBlank(x, y + 1);
		if ((x + 1) > 0 && (y - 1) > 0 && (map[x + 1][y - 1] >= 19))
			ClickBlank(x + 1, y - 1);
		if ((x + 1) > 0 && (y) > 0 && (map[x + 1][y] >= 19))
			ClickBlank(x + 1, y);
		if ((x + 1) > 0 && (y + 1) > 0 && (map[x + 1][y + 1] >= 19))
			ClickBlank(x + 1, y + 1);
	}
	else {
		map[x][y] -= 20;
		win++;
	}
}
//玩
int GamePlay()
{
	MOUSEMSG msg = { 0 };
	int n;
	while (1) {
		msg = GetMouseMsg();//不断地获取鼠标消息

		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			PlaySound("./res/Click.wav", NULL, SND_ASYNC | SND_FILENAME);
			n = map[msg.x / SIZE + 1][msg.y / SIZE + 1];
			if (n == 20)
			{
				int a = msg.x / SIZE + 1;
				int b = msg.y / SIZE + 1;
				ClickBlank(a, b);
			}
			else if (n >= 19 && n <= 28)//点的是加密的
			{
				map[msg.x / SIZE + 1][msg.y / SIZE + 1] -= 20;
				win++;
			}

			return map[msg.x / SIZE + 1][msg.y / SIZE + 1];
			break;
		case WM_RBUTTONDOWN:
			//1 19-28
			PlaySound("./res/rightClick.wav", NULL, SND_ASYNC | SND_FILENAME);
			n = map[msg.x / SIZE + 1][msg.y / SIZE + 1];
			if (n >= 19 && n <= 28)
			{
				map[msg.x / SIZE + 1][msg.y / SIZE + 1] += 10000;
				if (n == 19) {
					mine++;
				}
			}
			else if (n > 30)
			{
				map[msg.x / SIZE + 1][msg.y / SIZE + 1] -= 10000;
				if (n - 10000 == 19) {
					mine--;
				}
			}
			return map[msg.x / SIZE + 1][msg.y / SIZE + 1];
			break;
		}
	}
}

void LoadimageScan() {
	loadimage(&img[0], "./res/0.jpg", SIZE, SIZE);
	loadimage(&img[1], "./res/1.jpg", SIZE, SIZE);
	loadimage(&img[2], "./res/2.jpg", SIZE, SIZE);
	loadimage(&img[3], "./res/3.jpg", SIZE, SIZE);
	loadimage(&img[4], "./res/4.jpg", SIZE, SIZE);
	loadimage(&img[5], "./res/5.jpg", SIZE, SIZE);
	loadimage(&img[6], "./res/6.jpg", SIZE, SIZE);
	loadimage(&img[7], "./res/7.jpg", SIZE, SIZE);
	loadimage(&img[8], "./res/8.jpg", SIZE, SIZE);
	loadimage(&img[9], "./res/9.jpg", SIZE, SIZE);
	loadimage(&img[10], "./res/10.jpg", SIZE, SIZE);
	loadimage(&img[11], "./res/11.jpg", SIZE, SIZE);
}

int StartScan()
{
	LoadimageScan();

	mciSendString("open ./res/start.mp3 alias start", 0, 0, 0);

	while (1)
	{
		mciSendString("open ./res/start.mp3 alias start", 0, 0, 0);
		GameInit();
		while (1)
		{

			GamePaint();
			if (GamePlay() == -1)
			{
				GamePaint();
				MessageBox(hwnd, "很遗憾，你并没有排除世界上所有的特异点", "", MB_OK);
				return mine;
				break;
			}
			if (ROW*COL - NUM == win)
			{
				MessageBox(hwnd, "愿你身上的荣光能照亮这个灰暗的现实，未来与你同在", "", MB_OK);
				return 10;
				break;
			}
		}
		if (MessageBox(hwnd, "你要再次挑战一次么？", "", MB_RETRYCANCEL) == IDCANCEL)
			break;
		mciSendString("close start", 0, 0, 0);
	}
	getchar();
}
