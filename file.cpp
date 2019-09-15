#include "header.h"
using namespace std;

void writefile1(int map[13][13]) {
	ofstream outfile("data1.txt",ios::trunc);
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			outfile << map[i][j] << " ";
		}
		outfile << endl;
	}
	outfile.close();
}
void writefile2(int map[13][13]) {
	ofstream outfile("data2.txt", ios::trunc);
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			outfile << map[i][j] << " ";
		}
		outfile << endl;
	}
	outfile.close();
}
int **readfile1() {
	ifstream myfile("data1.txt", ios::in | ios::binary);
	int **map = NULL;
	//if (!myfile.is_open()) {
	//	cout << 1;
	//}
	map = (int **)malloc(sizeof(int) * 13);
	for (int i = 0; i < 13; i++) {
		map[i] = (int *)malloc(sizeof(int) * 13);
		for (int j = 0; j < 13; j++) {
			myfile >> map[i][j];
		}
	}
	myfile.close();
	return map;
}
int **readfile2() {
	ifstream myfile("data2.txt", ios::in | ios::binary);
	int **map = NULL;
	map = (int **)malloc(sizeof(int) * 13);
	for (int i = 0; i < 13; i++) {
		map[i] = (int *)malloc(sizeof(int) * 13);
		for (int j = 0; j < 13; j++) {
			myfile >> map[i][j];
		}
	}
	myfile.close();
	return map;
}