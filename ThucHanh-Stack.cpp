#include <iostream>
using namespace std;

struct node {
	int data;
	node * link;
};

struct stack{
	node *top;
};

stack S;

void create(stack &S){
	S.top = NULL;
}

void push(stack &S, int data){
	node *p = new node();
	p->data = data;
	p->link = S.top;
	S.top = p;
}

bool isEmpty(stack &S){
	return S.top == NULL;
}

int pop(stack &S){
	if (isEmpty(S)) return NULL;
	node *p = S.top;
	int x = p->data;
	S.top = p->link;
	delete(p);
	return x;
}

void view(stack &S){
	stack T;
	create(T);
	int x;
	while (!isEmpty(S)){
		x = pop(S);
		cout << x << " ";
		push(T,x);
	}
	while (!isEmpty(T)){
		push(S,pop(T));
	}
}

stack sortStack(stack S){
	stack tmpStack;
	create(tmpStack);
	while (!isEmpty(S)){
		node * p = S.top ;
		pop(S);
		while (!isEmpty(tmpStack) and tmpStack.top->data > p->data ){
			push(S,pop(tmpStack));
		}
		push(tmpStack,p->data);
	}
	return tmpStack;
	//
	//3 2 5
	//data = 5
}

int main(){
	int code;
	do {
		cin >> code;
		if (code){
			push(S,code);
		}
	} while (code);
	stack tmp = sortStack(S);
	view(tmp);
}
