#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <string>
#include <algorithm> 
#include "Header.h"
#include <iomanip> 
#include <map>
using namespace std;
void makeTree(int,int);
void Switch(int, int);
void showSteps(int,int);
void showHow();
int zeroSite(string);
tree game[100][10000];
string in, out;
int treeSon[100];
bool test;
vector<string>A;
map<string, bool> noMul;
int total;
int main()
{
	int i,zero,row=1,cul=0;
	cin >> in>>out;
	for (i = 0; i < in.length(); i++)
		if (in[i] == '0')zero=i;
	game[0][0].setZero(zero);
	game[0][0].setString(in);
	noMul[game[0][0].num] = true;
	makeTree(0, 0);
	
	while (!test) {
		for (i = 0; i < treeSon[row]; i++)
			makeTree(row, i);
		row++;
	}
	reverse(A.begin(), A.end());
	showHow();
	
	return 0;
}
void showHow()
{
	int pre, next, no = 0,i;
	string step[5] = { "jump right, ","move right, "," ","move left,  ","jump left,  " };
	cout << " find depth=" << A.size()-1 << endl;
	cout << " total nodes=" << total << endl;
	cout << " initial board:" << A[0] << endl;
	for (i = 0; i < A.size()-1; i++)
	{
		pre = zeroSite(A[i]);
		next= zeroSite(A[i+1]);
		no = pre - next+2;
		cout << setw(2)<<i+1<<" "<<step[no] << A[i + 1] << endl;
	}

}
int zeroSite(string x)
{
	for (int i = 0; i <x.length(); i++)
		if (x[i] == '0')
			return i;
}
void makeTree(int x, int y)
{
	int zero = game[x][y].zeroSite();
	if (zero + 2 <= in.length() &&test==false)
	{
		game[x + 1][treeSon[x + 1]].num = game[x][y].num;
		game[x + 1][treeSon[x + 1]].num[zero+1] = game[x][y].num[zero];
		
		game[x + 1][treeSon[x + 1]].num[zero] = game[x][y].num[zero+1];
		if (game[x + 1][treeSon[x + 1] ].num == out)
			game[x + 1][treeSon[x + 1]].row = x, game[x + 1][treeSon[x + 1]].cul = y, showSteps(x + 1,treeSon[x + 1]);
		else if (!noMul[game[x + 1][treeSon[x + 1]].num]) {
			game[x + 1][treeSon[x + 1]].row = x, game[x + 1][treeSon[x + 1]].cul = y;
			noMul[game[x + 1][treeSon[x + 1]].num] = true, treeSon[x + 1]++, total++;
		}
	}
	if (zero + 3 <= in.length() && test == false)
	{
		game[x + 1][treeSon[x + 1]].num = game[x][y].num;
		game[x + 1][treeSon[x + 1]].num[zero + 2] = game[x][y].num[zero];
		
		game[x + 1][treeSon[x + 1]].num[zero] = game[x][y].num[zero + 2];
		if (game[x + 1][treeSon[x + 1] ].num == out)
			game[x + 1][treeSon[x + 1]].row = x, game[x + 1][treeSon[x + 1]].cul = y,showSteps(x + 1, treeSon[x + 1]);
		else if (!noMul[game[x + 1][treeSon[x + 1]].num]) {
			game[x + 1][treeSon[x + 1]].row = x, game[x + 1][treeSon[x + 1]].cul = y;
			noMul[game[x + 1][treeSon[x + 1]].num] = true, treeSon[x + 1]++, total++;
		}
		
	}
	if (zero - 1 >= 0 && test == false)
	{
		game[x + 1][treeSon[x + 1]].num = game[x][y].num;
		game[x + 1][treeSon[x + 1]].num[zero - 1] = game[x][y].num[zero];
		
		game[x + 1][treeSon[x + 1]].num[zero] = game[x][y].num[zero -1];
		if (game[x + 1][treeSon[x + 1] ].num == out)
			game[x + 1][treeSon[x + 1]].row = x, game[x + 1][treeSon[x + 1]].cul = y, showSteps(x + 1, treeSon[x + 1]);
		else if (!noMul[game[x + 1][treeSon[x + 1]].num]) {
			game[x + 1][treeSon[x + 1]].row = x, game[x + 1][treeSon[x + 1]].cul = y;
			noMul[game[x + 1][treeSon[x + 1]].num] = true, treeSon[x + 1]++, total++;
		}
	}
	if (zero - 2 >= 0 && test == false)
	{
		game[x + 1][treeSon[x + 1]].num = game[x][y].num;
		game[x + 1][treeSon[x + 1]].num[zero - 2] = game[x][y].num[zero];
		game[x + 1][treeSon[x + 1]].num[zero] = game[x][y].num[zero - 2];
		if (game[x + 1][treeSon[x + 1] ].num == out)
			game[x + 1][treeSon[x + 1]].row = x, game[x + 1][treeSon[x + 1]].cul = y, showSteps(x + 1, treeSon[x + 1]);
		else if (!noMul[game[x + 1][treeSon[x + 1]].num]) {
			game[x + 1][treeSon[x + 1]].row = x, game[x + 1][treeSon[x + 1]].cul = y;
			noMul[game[x + 1][treeSon[x + 1]].num] = true, treeSon[x + 1]++, total++;
		}
	}
	
}
void showSteps(int x,int y)
{
	test = true;
	int fx=1, fy;
	//cout << x<<" "<<y<<endl;
	A.push_back(game[x][y].num);
	while (fx) 
	{
		fx = game[x][y].row;
		fy = game[x][y].cul;
		A.push_back(game[fx][fy].num);
		//cout << game[fx][fy].num<< endl;
		x = fx;
		y = fy;
	}
}
