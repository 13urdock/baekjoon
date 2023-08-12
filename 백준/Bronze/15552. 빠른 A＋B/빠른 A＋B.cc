#include <iostream>
using namespace std;

	//코드의 실행속도를 높여주기 위한 코드. 그리고 endl 대신 \n을 사용하는 게 훨씬 빠름
	//이 코드 입력하고 scanf/printf/putchar/getchar 은 사용하면 안됨
	//https://velog.io/@gogori6565/BOJ-cin.tieNULL%EA%B3%BC-iosbasesyncwithstdiofalse
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int test_case, a, b;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		int a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return 0;
}