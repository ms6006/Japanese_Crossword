#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int BHor[101][51];
int BVer[101][51];
bool M[101][101];
int SizeX, SizeY;
ifstream InF;
ofstream OutF;

bool MustOn, MustOff;
int Num, Cnt;
int i, j;

void Print() {

	for (i = 1; i <= SizeY; i++) {
		for (j = 1; j <= SizeX; j++) {
			if (M[j][i]) {
				OutF << "##";
				cout << "##";
			}
			else {
				cout << "  ";
				OutF << "  ";
			}
		}
		cout << "\n";
		OutF << "\n";
	}
	cout << "\n";
	OutF << "\n";
}

int Pass(int X, int Y) {

	if (Y == SizeY) {
		X++;
		Y = 1;
		if (X == SizeX + 1) {
			Print();
			return 0;
		}
	}
	else Y++;

	MustOn = false;
	MustOff = false;
	Num = 1;

	for (i = 1; i <= (Y - 2); i++) {
		if ((M[X][i]) && (!M[X][i + 1])) {
			Num++;
		}
	}

	Cnt = 0;
	i = Y - 1;

	while (i > 0 && M[X][i]) {
		i--;
		Cnt++;
	}
	if (Cnt > 0) {
		if (BVer[X][Num] == Cnt) {
			MustOff = true;
			Num++;
		}
		else MustOn = true;
	}

	Cnt = -Cnt;

	for (i = Num; i <= BVer[X][0]; i++) {
		Cnt += BVer[X][i] + 1;
	}

	if (Cnt - 1 >= SizeY - Y + 1) {
		MustOn = true;
	}
	if (Num > BVer[X][0]) {
		MustOff = true;
	}

	Num = 1;

	for (i = 1; i <= (X - 2); i++) {
		if ((M[i][Y]) && (!M[i + 1][Y])) {
			Num++;
		}
	}

	Cnt = 0;
	i = X - 1;

	while (i > 0 && M[i][Y]) {
		i--;
		Cnt++;
	}
	if (Cnt > 0) {
		if (BHor[Y][Num] == Cnt) {
			MustOff = true;
			Num++;
		}
		else MustOn = true;
	}

	Cnt = -Cnt;

	for (i = Num; i <= BHor[Y][0]; i++) {
		Cnt += BHor[Y][i] + 1;
	}
	if (Cnt - 1 >= SizeX - X + 1) {
		MustOn = true;
	}
	if (Num > BHor[Y][0]) {
		MustOff = true;
	}

	if (MustOn && MustOff) {
		return 0;
	}

	if (MustOn) {
		M[X][Y] = true;
		Pass(X, Y);
		return 0;
	}
	if (MustOff) {
		M[X][Y] = false;
		Pass(X, Y);
		return 0;
	}

	M[X][Y] = false;
	Pass(X, Y);
	M[X][Y] = true;
	Pass(X, Y);
}

int main() {
	InF.open("input.txt");
	string s;
	getline(InF, s);
	istringstream iss(s);
	iss >> SizeX; iss >> SizeY;

	for (i = 1; i <= SizeY; i++) {
		getline(InF, s);
		istringstream iss(s);
		j = 1;
		int t = 0;
		while (iss) {
			if (iss >> t) {
				BHor[i][j] = t;
				j++;
			}
		}
		BHor[i][0] = j - 1;
	}

	for (i = 1; i <= SizeX; i++) {
		getline(InF, s);
		istringstream iss(s);
		j = 1;
		int t = 0;
		while (iss) {
			if (iss >> t) {
				BVer[i][j] = t;
				j++;
			}
		}
		BVer[i][0] = j - 1;
	}

	InF.close();

	OutF.open("result.txt");
	for (i = 1; i <= 4; i++) {
		OutF << "\n";
	}
	Pass(1, 0);
	OutF.close();
	return 0;
}
