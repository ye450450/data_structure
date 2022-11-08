//21900156 김예준 과제02
#include <iostream>
#define SIZE 100
using namespace std;

class mystack {
	int stack[SIZE];//stack을 선언
	int top;//끝위치
public:
	void init();//stack을 초기화
	void push(int a);//들어오는 숫자를 stack에 쌓음
	int pop();//stack으로부터 숫자를 내보냄
	bool stack_empty();//비어있는지를 확인
};
void mystack::init() {
	top = 0;
}
void mystack::push(int a) {
	stack[top] = a;
	top++;
}
int mystack::pop() {
	top--;
	return stack[top];
}
bool mystack::stack_empty() {
	if (top == 0)
		return true;
	else
		return false;
}

int main() {
	mystack s1;
	int list[5] = { 32,123,27,131,242 }, i, x;
	s1.init();
	for (i = 0;i < 5;i++)
		if (list[i] > 100)
			s1.push(list[i]);
	while (!s1.stack_empty())
	{
		x = s1.pop();
		cout << x << endl;
	}
	return 0;
}