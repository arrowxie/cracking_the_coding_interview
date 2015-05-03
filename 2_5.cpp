#include<iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node* LinkList(int a[],int n)
{
	node *head,*p;
	for(int i=0;i<n;i++)
	{
		node *nd = new node();
		nd->data = a[i];
		if(i==0)
			head = p =nd;
		else
		{
			p->next = nd;
			p = nd;
		}
		nd->next = NULL;
	}
	return head;
}

void print(node *head)
{	
	node *p = head;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
	return;
}


 //测试没有通过 当两数的长度不一致且有进位时出错
node* add(node *h1, node *h2)
{

	if(!h1 && !h2)
		return NULL;
	if(!h1)
		return h2;
	if(!h2)
		return h1;
	node *p = h1;
	node *q = h2;
	node *head;
	int len1 = 0;
	int len2 = 0;
	int carry = 0;
	while(p)
	{
		len1++;
		p = p->next;
	}
	while(q)
	{
		len2++;
		q = q->next;
	}
	if(len1>=len2)
		head = h1;
	else
		head = h2;
	node *t = head;
	p = h1;
	q = h2;
	while(p&&q)
	{
		int temp = p->data + q->data + carry;
		if(temp>=10)	
		{
			temp -=10;
			carry = 1;			
		}
		else
			carry = 0;
		t->data = temp;		
		p = p->next;
		q = q->next;
		if(p&&q)
			t = t->next;
	}
	if(len1!=len2)
	{
		t = t->next;
		if(!p)
		{
			while(p)
			{
				int temp = p->data + carry;
				if(temp>=10)	
				{
					temp -=10;
					carry = 1;			
				}
				else
					carry = 0;
				t->data = temp;				
				p = p->next;
				if(p)
					t = t->next;
			}			
		}
		if(!q)
		{
			while(q)
			{
				int temp = q->data + carry;
				if(temp>=10)	
				{
					temp -=10;
					carry = 1;			
				}
				else
					carry = 0;
				t->data = temp;
				q = q->next;
				if(q)
					t = t->next;				
			}
		}
	}
	if(carry)
	{
		node *nd = new node();
		nd->data = 1;
		nd->next = NULL;
		t->next = nd;
	}
	return head;
}

int main()
{
	int a[]={7,1,7,2};
	int b[]={5,9,2};
	node *h1 = LinkList(a,4);
	print(h1);
	node *h2 = LinkList(b,3);
	print(h2);
	node *h = add(h1,h2);
	print(h);
	return 0;
}
