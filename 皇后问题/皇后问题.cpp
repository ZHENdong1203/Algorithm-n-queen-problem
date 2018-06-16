#include<cstdio>  
#include<iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;
const int maxn = 105;
int tot, n;
int c[maxn];

void search_queen(int cur) {
	if (cur == n) tot++; //d递归边界。只要走到这所有皇后必然不冲突  
	else {
		for (int i = 0; i<n; i++) {
			int ok = 1;
			c[cur] = i; //尝试把第cur行的杭后放到第i列  
			for (int j = 0; j<cur; j++) { //检查是否与之前放好的皇后冲突，横向上肯定不会冲突，因此只需要检查纵向，斜向  
				if (c[cur] == c[j] || cur - c[cur] == j - c[j] || cur + c[cur] == j + c[j]) {
					ok = 0;
					break;
				}
			}
			if (ok) search_queen(cur + 1); //如果此位置合法，继续递归寻找下一个皇后的位置  
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);  
	cout << "输入皇后的个数:"<<endl;
	cin >> n;
	search_queen(0);
	cout << "方案有:"<<tot <<"种"<< endl;
	return 0;
}