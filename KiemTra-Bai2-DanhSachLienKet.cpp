#include <iostream>
#include <math.h>
using namespace std;
struct Node {
	int data;
	Node * link;
};
Node * L;

void Tao(Node *&L){
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

void Xem(Node *L){
	Node *p = L;
	while (p != NULL){
		cout << p->data << " ";
		p = p->link;
	}
}

bool isSNT(int n){
	if (n < 2) return false;
	for (int i = 2 ; i <= sqrt(n) ; i ++)
		if (n % i == 0) return false;
	return true;
}

int DemPhanTuLaSoNguyenTo(Node * p){
	if (p != NULL){
		if (isSNT(p->data)) return 1 + DemPhanTuLaSoNguyenTo(p->link);
		return DemPhanTuLaSoNguyenTo(p->link);
	}
	return 0;
}

Node * Le, *Chan;
void ChuyenPTChanLenTruocLeRaSau(Node * L){
	Node * c, * ct, * l, *lt;
	Node * p = L;
	while (p != NULL){
		if (abs(p->data)%2 == 0){//Neu so chan
//			p->data = code;
			ct = p;
			ct->link = NULL;
			if (Chan == NULL){
				Chan = ct;
				c = ct;
			} else {
				c->link = ct;
				c = ct;
			}
		} else {//Neu so le
			lt = p;
			lt->link = NULL;
			if (Le == NULL){
				Le = lt;
				l = lt;
			} else {
				l->link = lt;
				l = lt;
			}
		}
		p = p->link;
	}
}
int main(){
	Tao(L),Xem(L);
}
