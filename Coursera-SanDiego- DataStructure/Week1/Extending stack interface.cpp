#include <bits/stdc++.h>



#define ll long long int
#define ull unsigned long long int

using namespace std;

#define MAX 1000
#define NIL -1

#define STACK_ENTRY int
#define MAX_ENTRY 10


		/************ Structures ***********/
typedef struct StackNode{
	STACK_ENTRY Entry;
	StackNode *next;
};
typedef struct Stack{
	StackNode *top;
	int size;
};


void createStack(Stack * const ps){
	ps->top = NULL;
	ps->size = 0;
}

bool pushStack(STACK_ENTRY element,Stack * const ps){
	StackNode *pn = new StackNode;
	if(pn)
	{
		pn->Entry = element;
		pn->next = ps->top;
		ps->top = pn;
		ps->size++;
		return true;
	}
	else
	{
		return false;
	}
}

void popStack(STACK_ENTRY * const pe,Stack * const ps){
	StackNode *pTemp = ps->top;
	*pe = ps->top->Entry ;
	ps->top = ps->top->next;
	free(pTemp);
	ps->size--;
}


void stackTop(STACK_ENTRY * const pe,Stack * const ps){
	*pe = ps->top->Entry;
}



int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	Stack stk,tempStk;
	createStack(&stk);
	createStack(&tempStk);
	string s;
	int q, temp, currentMax;
	// Initialize the stack with low value element
	pushStack(NIL,&tempStk);


	cin >> q;

	for (int var = 0; var < q; ++var) {
		cin >> s;

		if(s == "push")
		{
			cin >> temp;
			stackTop(&currentMax,&tempStk);
			if(temp >= currentMax)
				pushStack(temp,&tempStk);

			pushStack(temp,&stk);
		}
		else if(s == "max")
		{
			stackTop(&currentMax,&tempStk);
			cout << currentMax << '\n';
		}
		else
		{
			stackTop(&currentMax,&tempStk);
			stackTop(&temp,&stk);

			if(currentMax == temp)
			{
				popStack(&temp,&stk);
				popStack(&temp,&tempStk);
			}
			else
				popStack(&temp,&stk);
		}
	}

}














