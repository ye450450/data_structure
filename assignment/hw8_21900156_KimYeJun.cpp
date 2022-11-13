#include <iostream>
#include<string>
#define SIZE 100
using namespace std;

class element {
public:
	string name;
	double score;
	void set_data(string n, double s);
};
void element::set_data(string n, double s) {
	name = n;
	score = s;
}
class my_heap {
	int csize;
public:
	element h[SIZE];
	my_heap();
	int h_size();
	void insert_heap(element t);
	element delete_heap();
	bool heap_full();
	bool heap_empty();
	double score_sum();
	double score_average();
	int node_delete_by_name(string tname);
	void adjust(int t_root);
};
my_heap::my_heap() {
	csize = 0;
}
int my_heap::h_size() {
	return csize;
}
bool my_heap::heap_full() {
	if (csize >= SIZE-1) return true;
	else return false;
}
bool my_heap::heap_empty() {
	if (csize == 0) return true;
	else return false;
}
void my_heap::insert_heap(element t) {
	if (heap_full()) return;
	csize++;
	int k = csize;
	while (k!=1 && h[k/2].score< t.score) {
		h[k] = h[k / 2];
		k = k / 2;
	}
	h[k] = t;
}
element my_heap::delete_heap() {
	element t; //root를 저장
	element  tmp; //마지막 element를 저장
	int parent, child; // 위에서부터 실행할 때 필요한 변수들
	
	t = h[1];
	tmp = h[csize];
	csize--;
	parent = 1;
	child = 2;
	while (child <= csize) {
		if ((child < csize) && (h[child].score < h[child].score)) child++;
		if (tmp.score > h[child].score) break;
		h[parent] = h[child];
		parent = child;
		child = child * 2;
	}
	h[parent] = tmp;
	return t;
}
double summation(element a[], int troot, int n) {
	if (troot > n) return 0;
	return (summation(a, troot * 2, n) + summation(a, troot * 2 + 1, n) + a[troot].score);
}
double my_heap::score_sum() {
	return summation(h, 1, csize);
}
double my_heap::score_average() {
	if (csize == 0) return 0;
	return score_sum() / csize;
}
void adjust(element a[],int root, int size) {
	double tmpkey; // 일시적으로 key값을 저장한다.
	int child; // root의 child값을 저장한다.
	element tmp; // t_root의 element를 저장한다.

	tmp = a[root];
	tmpkey = a[root].score;
	child = 2 * root;

	while (child <= size) {
		if ((child < size) && (a[child].score < a[child + 1].score))
			child++;
		if (tmpkey > a[child].score) break;
		else {
			a[child / 2] = a[child];
			child = child * 2;
		}
	}
	a[child / 2] = tmp;
}
int delete_node(element a[], int troot, string tname, int n) {
	if (troot > n) return 0;
	else {
		if (a[troot].name == tname) {
			a[troot] = a[n]; //마지막 원소와 바꿔준다.
			n--;
			adjust(a, troot, n);
			return 1;
		}
		else {
			int result = delete_node(a, troot * 2, tname, n);
			if (result == 1) return result;
			else return (delete_node(a, troot * 2 + 1, tname, n));
		}
	}
}
int my_heap::node_delete_by_name(string tname) {
	if (csize == 0) return 0;
	if (delete_node(h, 1, tname, csize) == 1) {
		csize--;
		return 1;
	}
	else return 0;
}


int main() {
	int menu;
	string input_name;
	double input_score;
	my_heap heap;
	while (1) {
		cout << "----------------------" << endl;
		cout << "메뉴 \n1.새로운 원소 추가 \n2.원소 삭제(삭제내용보기) \n3.전체 인원, score 합, 평균 점수 보기 \n4.종료 \n번호 입력 : ";
		cin >> menu;
		cout << "----------------------" << endl;
		if (menu == 1) {
			cout << "이름을 입력하시오.";
			cin.ignore();
			getline(cin,input_name);
			cout << "성적을 입력하시오. ";
			cin >> input_score;
			element tmp;
			tmp.set_data(input_name, input_score);
			heap.insert_heap(tmp);
		}
		else if (menu == 2) {
			int check = 0;//삭제시 확인
			int deletenum = 0;//삭제번호
			for (int i = 1;i <= heap.h_size();i++) {
				cout << i  << " 이름 : " << heap.h[i].name << "\n  성적 : " << heap.h[i].score << endl;
			}
			while (1) {
				cout << "삭제할 번호를 고르시오. ";
				cin >> deletenum;
				if (deletenum <= 0 || deletenum>heap.h_size())
					cout << "번호를 잘못입력했습니다.\n";
				else break;
			}
			cout << "정말로 " << deletenum << "번을 삭제하시겠습니까?(확인시 1을 입력해주세요.)";
			cin >> check;
			if (check != 1) cout << "삭제가 취소되었습니다." << endl;
			else {
				if (heap.node_delete_by_name(heap.h[deletenum].name) == 1)
					cout << "삭제가 완료되었습니다.";
			}
		}
		else if (menu == 3) {
			cout << "전체인원 : " << heap.h_size() << "명" << endl;
			cout << "score 합 : " << heap.score_sum() << "점" << endl;
			cout<< "평균 점수 : " << heap.score_average() << "점"<<endl;
		}
		else {
			cout << "종료되었습니다.";
			break;
		}
	}
}