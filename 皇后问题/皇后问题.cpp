#include<cstdio>  
#include<iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;
const int maxn = 105;
int tot, n;
int c[maxn];

void search_queen(int cur) {
	if (cur == n) tot++; //d�ݹ�߽硣ֻҪ�ߵ������лʺ��Ȼ����ͻ  
	else {
		for (int i = 0; i<n; i++) {
			int ok = 1;
			c[cur] = i; //���԰ѵ�cur�еĺ���ŵ���i��  
			for (int j = 0; j<cur; j++) { //����Ƿ���֮ǰ�źõĻʺ��ͻ�������Ͽ϶������ͻ�����ֻ��Ҫ�������б��  
				if (c[cur] == c[j] || cur - c[cur] == j - c[j] || cur + c[cur] == j + c[j]) {
					ok = 0;
					break;
				}
			}
			if (ok) search_queen(cur + 1); //�����λ�úϷ��������ݹ�Ѱ����һ���ʺ��λ��  
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);  
	cout << "����ʺ�ĸ���:"<<endl;
	cin >> n;
	search_queen(0);
	cout << "������:"<<tot <<"��"<< endl;
	return 0;
}