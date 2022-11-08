//김예준 21900156 과제03
#include <iostream>
#define SIZE 50
#define EOS '$'
using namespace std;

class stack {
	char s[SIZE];
	int top;
public:
	stack();
	void push(char a);
	char pop();
	bool isEmpty();
	char top_element();
};

stack::stack() {
	top = 0;
}

void stack::push(char a) {
	s[top] = a;
	top++;
}
char stack::pop() {
	top--;
	return s[top];
}
bool stack::isEmpty() {
	if (top == 0)
		return true;
	else
		return false;
}
char stack::top_element() {
	return (s[top - 1]);
}

bool is_operand(char h) {
	if (h == '(' || h == '+' || h == '-' || h == '*' || h == '/' || h == '%' || h == '$' || h == ')')
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
	stack postfix;
	string input, output;
	postfix.push(EOS);

	std::cout << "Input an infix expression to convert : ";
	cin >> input;

	for (int i = 0;i < input.size();i++) {
		if (is_operand(input[i]))
			output += input[i];
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
	//cout << postfix.top_element();
	std::cout << output;
}
