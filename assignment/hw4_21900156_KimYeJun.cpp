//21900156 김에준 hw4 2022.09.25

# include <iostream>
# define SIZE 100

using namespace std;

class my_stack {
	char stack[SIZE];
	int top;
public:
	my_stack();
	void push(char s);
	char pop();
	bool isEmpty();
	char topElement();//top에 있는 것을 알려줌
};
my_stack::my_stack() {
	top = 0;
}
void my_stack::push(char s) {
	stack[top] = s;
	top++;
}
char my_stack::pop() {
	top--;
	return stack[top];
}

bool my_stack::isEmpty() {
	if (top == 0) return true;
	else return false;
}
char my_stack::topElement() {
	return (stack[top - 1]);
}
//여는 괄호인지, 닫는 괄호인지를 확인하는 함수
int  openType(char s) {
	if (s == '(' ||   s == '{' ||  s == '[' )
		return 1;
	else if (s == ')' || s == '}' || s == ']')
		return 2;
	else return 0;
}
//알맞는 괄호를 반환주는 함수
char kindType(char s) {
	if (s == '(')
		return ')';
	else if (s == '{')
		return '}';
	else return ']';
}


int main() {
	string input,output;
	my_stack stack1;
	bool error = false;
	cout << "수식표현을 입력하시오 : ";
	cin >> input;

	for (int i = 0;i < input.size() ;i++) {
		if (openType(input[i])==1) {
			stack1.push(input[i]);
		}
		else if (openType(input[i]) == 2) {
			if (stack1.isEmpty()) {
				output += "Error: An extra parenthesis '" ;
				output += input[i];
				output += "' is found.\n";
				error = true;
			}
			else if (input[i] != kindType(stack1.topElement())) {
				output = "Error: mis matched parenthesis,'";
				output += kindType(stack1.topElement());
				output += "' is expected.\n";
				error = true;
			}
			else 
				stack1.pop();
		}
	}
	if (!error) output = "It's a noraml expression";
	cout << output;
}