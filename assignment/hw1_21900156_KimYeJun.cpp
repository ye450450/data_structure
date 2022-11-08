//21900156 김예준 과제01 (2022.09.15)
#include <iostream>
using namespace std;

class weight {
	int kg;
	int gram;
public:
	void set_weight(int a, int b);//a는 kg, b는 gram이다.
	int get_weight();
};
void weight::set_weight(int a, int b) {
	kg = a;
	gram = b;
}
int weight:: get_weight() {
	return kg*1000+gram;
}
weight add_weight(weight s1, weight s2) {
	weight new1;
	int add = s1.get_weight() + s2.get_weight();
	new1.set_weight(add / 1000, add % 1000);
	return new1;
}
bool less_than(weight s1, weight s2) {
	if (s1.get_weight() > s2.get_weight())
		return false;
}


int main() {
	weight w1, w2, w3;
	w1.set_weight(3, 400);
	w2.set_weight(2, 700);
	w3 = add_weight(w1, w2);
	cout << w3.get_weight() << "grams\n";
		if (less_than(w1, w2))
			cout << "yes\n";
		else
			cout << "no.\n";
	return 0;
}
