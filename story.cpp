#include "header.h"


char dialog_init[][100] = { "......,"
							,"........,"
							,"......,"
							,"头好疼"
							,"......,"
							,".........,"
							,"这是哪儿，"
							,"我不是电脑面前编程么？"
							,"好老套的剧情啊，我穿越到了异世界"
							,"不管了，我怎样才能逃出这个鬼地方啊"
							,"我刚刚才约了我的青梅竹马去看流星雨"
							,"去星空下讲述那些你所不知道的物语"
							,"......,"
							,".........,"
							,"前面好像有人，我先去看看吧"
};

char dialog_first[][100] = { "很高兴见到你，年轻人"
								,"现在这个世界正在面临威胁，我们需要你的帮助"
								,"但是你太弱小了，手无缚鸡之力，你现在自身都难保，"
								,"更谈何保护他人，守护世界"
								,"但是你我相遇一场，便送你一份机缘，"
								,"假如你能排除异世界的魔王特异点的话，"
								,"你将会获得相应的初始值能力,"
								,"不管怎么说，在这个世界，"
								,"只有拥有力量才能获得自己想要的"
								,"如果你不能在这里阻挡住魔王军，"
								,"魔王载入侵完这个世界后"
								,"下一个就是你的世界了，那时候谁都阻挡不了他"
};

char dialog_second[][100] = { "那老头真的神龙见头不见尾呢"
								,"不知道他刚刚对我干了什么"
								,"但是好像基础能力值上升了，"
								,"但是却没有一件趁手的武器"
								,"应该能在这个迷宫里面找到吧，"
								,"。。。。。。"
								,"。。。。。。。"
								,"我为什么会这么熟练啊？"
								,"不管了，走一步看一步吧"
								,"一定要将魔王阻拦在这"
								,"我一定要实现和她去看流星雨的愿望"
};

char dialog_search[][100] = { "这就是存放传说武器的地方么？"
								,"难怪有这么多不应该属于这层的魔王队在这里守护"
								,"一定要在躲避魔王队的前提下获得"
								,"而且据说夜空之剑和冰蔷薇之盾还是存放在密室中"
								,"传说中的武器库只有手持黄钥匙的选中之人才能获取"
								,"好在在第一层捡到了钥匙"
								,"没有缘分的话可能很难见到这传说中的至宝"
								,"更别说将两者同时获得了"
								,"只要获得，便能获得和魔王一样强大的力量"
								,"并且能获得抵御诅咒的加持"
								,"在没获得装备之前，还是远离噬身蛇的地板吧"
								,"什么都无法舍弃的人，什么都无法得到"
								,"尽人事，听天命"
};

char Dialogue_Boss[][100] = {"好强的诅咒的力量啊，还好获得了传说装备"
								,"不然光是诅咒都能让我喝上一壶。"
								,"......."
								,"............"
								,"魔王：你终于来了，勇者"
								,"魔王：你终于来了，勇者"
								,"魔王：也真亏你能坚持到这里来"
								,"魔王：让我看看你到底有几分实力"
								,"魔王：能在我面前蹦跶几回"
								,"勇者：少**废话，我等这一刻已经等了很久了"
								,"勇者：来吧"
								,"勇者：杀了你，就能回家了"
								,"魔王：呵呵，口舌之利"
};

char Ending_dialogue[][100] = { "终于结束了么"
								,"身上装备，武器的耐久值也不够了啊"
								,"我也到了极限了啊"
								,"我有好好保护了这个世界了么"
								,"这个残酷而又美丽的世界"
								,"......."
								,"对不起了，约定无法实现了"
								,"要看流星雨的话只能等以后了啊...."
								,"再见了......"
};
int k = 0;
int Dialogue0(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//不断地获取鼠标消息
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "华文琥珀");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, dialog_init[k++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "华文琥珀");
	setcolor(WHITE);
	return k;
}
int i = 0;
int Dialogue1(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//不断地获取鼠标消息
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "华文琥珀");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, dialog_first[i++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "华文琥珀");
	setcolor(WHITE);
	return i;
}
int j = 0;
int Dialogue2(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//不断地获取鼠标消息
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "华文琥珀");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, dialog_search[j++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "华文琥珀");
	setcolor(WHITE);
	return j;
}
int m = 0;
int Dialogue3(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//不断地获取鼠标消息
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "华文琥珀");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, dialog_second[m++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "华文琥珀");
	setcolor(WHITE);
	return m;
}
int n = 0;
int Dialogue4(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//不断地获取鼠标消息
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "华文琥珀");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, Dialogue_Boss[n++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "华文琥珀");
	setcolor(WHITE);
	return n;
}
int p = 0;
int Dialogue5(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//不断地获取鼠标消息
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "华文琥珀");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, Ending_dialogue[p++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "华文琥珀");
	setcolor(WHITE);
	return p;
}
	/*if (cUser == 13) {
		putimage(0, 0, &bg);
		setbkmode(TRANSPARENT);
		settextstyle(60, 0, "华文琥珀");
		outtextxy(60 * 5, 60 * 6, "上楼中。。。。");
		setcolor(RED);
	}*/


