#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#define MAXSTAR 100    //图片的数量
#define MAXSTAR1 1000  //点的数量

//流星
struct STAR
{
	int x, y;//坐标
	int step;//移动的速度
	int style; //样式

}star[MAXSTAR];
//星空

//结构体可以连续存储不同类型的多种数据
//可以将不同类型的数据整合
struct STAR1
{
	int x, y;
	int step;
	int color;
}star1[MAXSTAR1];

IMAGE img;

void initStar1(int i);
void initStar(int i);
void moveStar1(int i);
void moveStar();
void drawStar();

void initData(int weight);

void initData(int weight)
{
	srand((unsigned int)time(NULL));
	loadimage(&img, "素材/2.jpg", 60, 60);
	//图片的批量输出
	int i = 0;
	for (i = 0; i < MAXSTAR1; i++)
	{
		initStar1(i);
		star1[i].x = rand() % (60*14);
	}
	//初始化流星
	for (i = 0; i < MAXSTAR; i++)
	{
		initStar(i);
	}
}
void initStar1(int i)
{
	star1[i].x = 0;
	star[i].y = rand() % (60*13);	//0-599
	star[i].step = rand() % 5;  //0-4  随机来表现出移动
	star1[i].color = RGB(star1[i].step * 51, star1[i].step * 51, star1[i].step * 51);//RGB的范围是0-255，颜色表示出渐变的过程；
}
void initStar(int i)
{
	star[i].x = rand() % (60*14) - 640;//-640--639
	star[i].y = -144;
	do {
		star[i].step = rand() % 30 + 1;  // 1-30
	} while (star[i].step < 5);
	star[i].style = rand() & 3 + 1;    //设置几张图片一起输出；

}
void moveStar1(int i)
{
	putpixel(star1[i].x, star1[i].y, 0);
	star1[i].x += star1[i].step;
	if (star1[i].x > 60*14)
	{
		initStar1(i);
	}
	putpixel(star1[i].x, star1[i].y, star1[i].color);
}
void moveStar()
{
	for (int i = 0; i < MAXSTAR; i++)
	{
		star[i].x += star[i].step;
		star[i].y += star[i].step * 0.7;
	}
}
void drawStar()
{
	for (int i = 0; i < MAXSTAR; i++)
	{
		putimage(star[i].x, star[i].y, &img, SRCPAINT);//处理图像，使图像透明，不会被星星遮挡，避免出现框体；
	}
}