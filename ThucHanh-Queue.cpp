#include <iostream>
using namespace std;

struct node {
	int data;
	node * link;
};

struct queue{
	node * top;
	node * bot;
};

queue Q;

void create(queue &Q){
	Q.top = NULL;
	Q.bot = NULL;
}

bool isEmpty(queue &Q){
	return Q.top == NULL and Q.bot == NULL;
}

void push(queue & Q, int data){
	node *p = new node();
	p->data = data;
	p->link = NULL;
	if (isEmpty(Q)){
		Q.bot = p; Q.top = p;
	} else {
		Q.bot->link = p;
		Q.bot = p;
	}
}



int pop(queue &Q){
	//Empty
	if (isEmpty(Q)) return NULL;
	node * p = Q.top;//top
	int x = p->data;
	//1PT
	if (Q.top == Q.bot) {
		delete(p);
		create(Q);
		return x;
	}
	//n PT
	Q.top = p->link;
	delete(p);
	return x;
}

void view(queue &Q){
	queue T;
	create(T);
	int x;
	while (!isEmpty(Q)){
		x = pop(Q);
		cout << x << " ";
		push(T,x);
	}
	while (!isEmpty(T)){
		push(Q,pop(T));
	}
	cout << endl;
}

void sortQueue(queue &Q){
	queue T;
	create(T);
	while (!isEmpty(Q)){
		node * p = Q.top ;
		pop(Q);
		while (!isEmpty(T) and T.top->data > p->data ){
			push(Q,pop(T));
		}
		push(T,p->data);
	}
	Q.top = T.top;
	Q.bot = T.bot;
	//
	//3 2 5
	//data = 5
}

void popBot(queue &Q){
	queue T;
	create(T);
	int x;
	while (!isEmpty(Q)){
		x = pop(Q);
		push(T,x);
		if (Q.top == Q.bot) pop(Q);
	}
	while (!isEmpty(T)){
		push(Q,pop(T));
	}
}

void removeIndex(queue &Q, int index){
	queue T;
	create(T);
	int x;
	int dem = 0;
	while (!isEmpty(Q)){
		x = pop(Q);
		push(T,x);
		dem ++ ;
		if (dem == index) pop(Q);
	}
	while (!isEmpty(T)){
		push(Q,pop(T));
	}
}

int main(){
	int code;
	do {
		cin >> code;
		if (code){
			push(Q,code);
		}
	} while (code);
	view(Q);
	removeIndex(Q,1);
	view(Q);
}
