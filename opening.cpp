#include "header.h"

extern int Dialogue1(IMAGE bg);

void opening() {
	setbkcolor(BLACK);
	cleardevice();
	Sleep(4000);
	setbkcolor(WHITE);
	cleardevice();
	Sleep(1000);
	settextstyle(60, 0, "华文琥珀");
	setbkcolor(BLACK);
	cleardevice();
	Sleep(4000);
	outtextxy(280, 170, "我现在是在哪儿？");
	Sleep(2000);
	cleardevice();
	outtextxy(100, 450, "我的头好疼....");
	outtextxy(100, 560, "耳鸣声好严重");
	Sleep(2000);
	cleardevice();
	outtextxy(200, 250, "......");
	Sleep(2000);
	Sleep(1000);
	cleardevice();
	setbkcolor(WHITE);
	//putimage(0, 0, &bg);
	settextstyle(60, 0, "华文琥珀");
	setbkmode(TRANSPARENT);
	outtextxy(150, 250, "我好像忘了点什么...");
	Sleep(2000);
	setcolor(BLACK);
	cleardevice();
	outtextxy(200, 250, "...");
	Sleep(2000);
	cleardevice();
	outtextxy(200, 350, ".....");
	Sleep(3000);
	cleardevice();
	setbkcolor(BLACK);
	setcolor(WHITE);
	settextstyle(12, 0, "华文琥珀");
}