//21900156 김예준 hw6 2022.10.05
#include <iostream>
using namespace std;

class node {
public:
	string name;
	double score;
	node *link;
	void set_data(string s, double n);
};
class my_list {
	node *head,*tail;
public:
	my_list();
	void add_to_head(node s);
	void add_to_tail(node s);
	node delete_from_head();
	int num_nodes();
	bool list_empty();
	double score_sum();
	double get_score(string t_name);
	int remove_a_node(string t_name);
};
void node::set_data(string s, double n) {
	name = s;
	score = n;
}
my_list::my_list() {
	head= NULL;
	tail = NULL;
}
void my_list::add_to_head(node s) {
	node* tmp;
	tmp = new node;
	(*tmp) = s;
	tmp->link= head;
	head = tmp;
	if (tail == NULL)
		tail = tmp;
}
void my_list::add_to_tail(node s) {
	node* tmp;
	tmp = new node;
	(*tmp) = s;
	tmp->link = NULL;
	if(tail!=NULL)
		tail->link=tmp;
	else
		head = tmp;
	tail = tmp;
}
node my_list::delete_from_head() {
	node tmp;//노드를 저장
	node* t;//주소값을 삭제하기 위해 만듬
	tmp = *head;
	t = head;
	head = head->link;
	delete t;
	if (head == NULL)
		tail = NULL;
	return tmp;
}
int my_list::num_nodes() {
	node* t;
	int count = 0;
	for (t = head;t!= NULL;t=t->link) {
		count++;
	}
	return count;
}
bool my_list::list_empty() {
	if (head == NULL)
		return true;
	else
		return false;
}
double my_list::score_sum() {
	node* tmp;
	double sum = 0;
	for (tmp = head;tmp!=NULL;tmp = tmp->link) {
		sum += tmp->score;
	}
	return sum;
}
double my_list::get_score(string t_name) {
	node* tmp;
	for (tmp = head; tmp!= NULL;tmp = tmp->link) {
		if (tmp->name == t_name) {
			return tmp->score;
		}
	}
	return 0;
}
int my_list::remove_a_node(string t_name) {
	node* tmp;//현재 것을 저장하는 pointer
	node* last;//이전 것을 저장하는 pointer
	int check = 0;//있는지 확인하는 변수
	tmp = head;
	//첫번째 node를 삭제하는 경우
	if (tmp->name == t_name) {
		node* t2;
		t2 = tmp;
		head = tmp->link;
		delete t2;
		if (head == NULL)
			tail = NULL;
		return 1;
	}
	while(tmp != NULL) {
		last = tmp;
		tmp = tmp->link;//다음 것으로 넘어감
		if (tmp->name == t_name) {
			last->link = tmp->link;
			//마지막 node를 delete하는 경우
			if (last ->link == NULL) {
				tail = last;
			}
			delete tmp;//삭제
			check = 1;
			break;
		}
		else
			check=0;
	}
	return check;//empty인 경우 0을 반환한다.
}
int main(){
	my_list    a;
	node   tmp;
	tmp.set_data("Kim", 83.5);
		a.add_to_head(tmp);
	tmp.set_data("Lee", 78.2);
		a.add_to_head(tmp);           // head 위치로 2개의 원소 추가
	cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1단계 점검
	tmp.set_data("Park", 91.3);
		a.add_to_tail(tmp);             // tail 위치로 1개의 원소 추가
	cout << a.num_nodes() << " : "<< a.score_sum() << "\n";  //2단계 점검
	tmp = a.delete_from_head();
	cout << tmp.name << " is deleted.\n";   // 3단계 점검
	tmp.set_data("Choi", 85.1);
		a.add_to_tail(tmp);
	tmp.set_data("Ryu", 94.3);
		a.add_to_head(tmp);             // 2개의 원소 추가
	cout << a.num_nodes() << " : " << a.score_sum() << "\n";
	cout << "Park’s score : " << a.get_score("Park") << "\n";  // 4단계 점검
	if (a.remove_a_node("Kim") == 1)
		cout << "Kim is deleted from the list. \n";     // 5단계 점검
	cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 최종 점검       
	return 0;
}