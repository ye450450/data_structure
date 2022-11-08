//hw7 kimyejun 21900156 과제3을 바꾸어서 작성
#include <iostream>
#define SIZE 100
#define EOS '$'
using namespace std;

class node {
public:
	char ch;
	node* link;
};
class mystack {
	node* top;
public:
	mystack();
	void push(char ch);
	char pop();
	bool isEmpty();
	char top_element();
};
mystack::mystack() {
	top = NULL;
}
void mystack::push(char x) {
	node* t;//새로 공간을 확보하고 연결하기 위해
	t = new node;
	t->ch = x;
	t->link = top;//새로운 공간으로 이어줌
	top = t;
}
char mystack::pop() {
	node temp;//반환하기위해 저장하는 공간
	node* t;//삭제하기 위해 만듬
	temp = *top;
	t = top;
	top = t->link;
	delete t;
	return (temp.ch);
}
bool mystack::isEmpty() {
	if (top == NULL)
		return true;
	else
		return false;
}
char mystack::top_element() {
	return top->ch;
}
bool is_operand(char h) {
	if (h == '*' || h == '+' || h == '-' || h == '/' || h == '(' || h == ')' || h == '$' || h == '%')
		return false;
	else
		return true;
}
int get_precedence(char op) {
	if (op == '(' || op == '$')
		return 0;
	else if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/' || op == '%')
		return 2;
	else
		return -1;
}

int main() {
	mystack postfix;
	string input, output;
	postfix.push(EOS);

	std::cout << "Input an infix expression to convert : ";
	cin >> input;

	for (int i = 0;i < input.size();i++) {
		if (is_operand(input[i])) {
			output += input[i];
		}	
		else {
			if (input[i] == ')') {
				while (postfix.top_element() != '(') {
					output += postfix.pop();
				}
				postfix.pop();//'('를 제거하기위해
				continue;
			}
			else if (input[i] == '(') {
				postfix.push(input[i]);
				continue;
			}
			else {
				while ((get_precedence(input[i])) <= get_precedence(postfix.top_element())) {
					output += postfix.pop();
				}
				postfix.push(input[i]);
			}
		}
	}
	while (postfix.top_element() != EOS)
		output += postfix.pop();
	
	std::cout << output;
}