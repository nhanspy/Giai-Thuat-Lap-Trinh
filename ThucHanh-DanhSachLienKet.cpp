#include <iostream>
using namespace std;


struct Node {
	int data;
	Node * link;
};
Node *L;

void TAO(Node *&L){
	L = NULL;
	int code;
	do {
		cin >> code;
		if (code){
			Node *p = new(Node);
			p->data = code;
			p->link = L;
			L = p;
		}
	} while (code);
}

void TAO2(Node *&L){
	L = NULL;
	int code;
	Node *q;
	do {
		cin >> code;
		if (code){
			Node *p = new(Node);
			p->data = code;
			p->link = NULL;
			if (L == NULL){
				L = p;
				q = p;
			} else {
				q->link = p;
				q = p;
			}
		}
	} while (code);
}

void DUYET(Node *L){
	Node *p = L;
	while (p != NULL){
		cout << p->data << " ";
		p = p->link;
	}
}

void Dao(Node *&L){
	Node *p = L;
	Node *q = p->link;
	p->link = NULL;
	Node *c ;
	while (q != NULL){
		L = q;
		c = q->link;
		q->link = p;
		p = q;
		q = c;
	}
}

void XOA(Node *&L, Node *&pos) {
	Node *p;
	if (pos != NULL){
		if (pos == L){
			L = L->link;
		} else {
			p = L;
			if (p->link != pos) p = p->link;
			else p->link = pos->link;
		}
	}
}

int main(){
	TAO2(L),Dao(L) ,DUYET(L), XOA(L,L->link);
	return 0;
}
