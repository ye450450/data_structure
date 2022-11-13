//hw09  KimYeJun

#include <iostream>
#include<string>
using namespace std;

class bst_node {
public:
	string name; //이름
	string s_id; //학번
	int birthdate; //생일
	string mobile; //전화번호
	bst_node* left, * right;
	bst_node();
	bst_node(string s1, string s2, int n1,string s3);
	void set_data(string s1, string s2, int n1, string s3);
};
bst_node::bst_node() {
	name = "";
	s_id = "";
	birthdate = 0;
	mobile = "";
	left = NULL;
	right = NULL;
}
bst_node::bst_node(string s1, string s2, int n1, string s3) {
	name = s1;
	s_id = s2;
	birthdate = n1;
	mobile = s3;
}
void bst_node::set_data(string s1, string s2, int n1, string s3) {
	name = s1;
	s_id = s2;
	birthdate = n1;
	mobile = s3;
}
class bst_tree {
	bst_node* root;
	int csize;
public:
	bst_tree();
	void insert_node(bst_node t);
	void show_inorder();
	bst_node search(string tid);
};
bst_tree::bst_tree() {
	root = NULL;
	csize = 0;
}
void bst_tree:: insert_node(bst_node t){
	bst_node* p;
	bst_node* tmp;
	
	tmp = new bst_node;
	*tmp = t;
	tmp->left = NULL;
	tmp->right = NULL;

	if (root == NULL) {
		root = tmp;
		return;
	}
	p = root;
	while (1) {
		if (p->s_id == t.s_id) {
			cout << "Insertion Failed : the Key " << t.s_id << " already exists. " << endl;
			return;
		}
		if (p->s_id < t.s_id) {
			if (p->right == NULL) {
				p->right = tmp;
				return;
			}
			else
				p = p->right;
		}
		else {
			if (p->left == NULL) {
				p->left = tmp;
				return;
			}
			else
				p = p->left;
		}
	}
}
bst_node bst_tree::search(string tid) {
	bst_node* p;
	p = root;
	if (root == NULL) {
		bst_node tmp;
		tmp.set_data("00000000", "None", -1,"00000000000");
		cout << "The key" << tid << "does not exist\n";
		return tmp;
	}
	while (1) {
		if (p->s_id == tid)
			return (*p);
		if (p->s_id < tid) {
			if (p->right == NULL) {
				bst_node tmp;
				tmp.set_data("00000000", "None", -1, "00000000000");
				cout << "The key" << tid << "does not exist\n";
				return tmp;
			}
			else
				p = p->right;
		}
		else {
			if (p->left == NULL) {
				bst_node tmp;
				tmp.set_data("00000000", "None", -1, "00000000000");
				cout << "The key" << tid << "does not exist\n";
				return tmp;
			}
			else
				p = p->left;
		}

	}
}
void inorder_show(bst_node* p) {
	if (p == NULL) return;

	inorder_show(p->left);
	cout << "학번 :" << p->s_id << " 이름 :" << p->name << " 생일 :" << p->birthdate << " 전화번호 :" << p->mobile << endl;
	inorder_show(p->right);
}
void bst_tree::show_inorder() {
	inorder_show(root);
}
int main() {
	int menu;
	string input_name; //이름
	string input_id; //학번
	int input_birth; //생일
	string input_mobile; //전화번호
	bst_tree bst;
	while (1) {
		cout << "----------------------" << endl;
		cout << "메뉴 \n1.새로운 원소 추가 \n2.원소 조회 \n3.전체 목록 보기(inorder 순서) \n4.종료 \n번호 입력 : ";
		cin >> menu;
		cout << "----------------------" << endl;
		if (menu == 1) {
			cout << "이름을 입력하시오 : ";
			cin.ignore();
			getline(cin, input_name);
			cout << "학번을 입력하시오 : ";
			cin >> input_id;
			cout << "생일을 입력하시오 ex)19990818 : ";
			cin >> input_birth;
			cout << "전화번호를 입력하시오 ex)01012341234 : ";
			cin >> input_mobile;
			bst_node tmp;
			tmp.set_data(input_name, input_id, input_birth, input_mobile);
			bst.insert_node(tmp);
		}
		else if (menu == 2) {
			string search_id;
			bst_node temp;
			cout << "검색할 학번을 입력하시오 : ";
			cin >> search_id;
			temp= bst.search(search_id);
			cout << "==========" << search_id << "'s data ============"<< endl;
			cout << "학번 : " << temp.s_id << endl<< "이름 : " << temp.name << endl << "생일 : " << temp.birthdate << endl << "전화번호 :" << temp.mobile << endl;
		}
		else if (menu == 3) {
			bst.show_inorder();
		}
		else {
			cout << "종료되었습니다.";
			break;
		}
	}
}
