#include <iostream>
#include<string>
#include <stdlib.h>
using namespace std;


struct Biodata
{
	string name;
	int no;
	Biodata *next;
};

struct Rollnumber
{
	string rno;
	Rollnumber *next;
	Biodata *beginn;
};


Rollnumber *start = NULL;

void insert_Rollnumber(string Rn)
{
	Rollnumber *temp = new Rollnumber();
	temp->rno = Rn;
	temp->next = NULL;
	temp->beginn = NULL;

	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		Rollnumber *curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
}

Rollnumber* seachh(string rn)
{
    Rollnumber *temp= start;
    while(temp->rno!= rn)
    {
        temp= temp->next;
    }
    return temp;
}


void insert_biodata(string rn,string n, int num)
{
	Biodata *temp = new Biodata();
	temp->name = n;
	temp->no = num;
	temp->next = NULL;


	Rollnumber *r = seachh(rn);

	if (r->beginn == NULL)
	{
		r->beginn = temp;
	}
	else
	{
		Biodata *curr = r->beginn;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
}

void print()
{
	Rollnumber *curr = start;
	while (curr != NULL)
	{
		cout <<"Roll number: " << curr->rno << "-->";
		while (curr->beginn != NULL)
		{
			cout << curr->beginn->name << "   ";
			cout << curr->beginn->no << endl;
			curr->beginn = curr->beginn->next;
		}
		//cout << endl;
		curr = curr->next;
	}

}


int main()
{
	insert_Rollnumber("156");
	insert_biodata("156","faraz", 0345);

	insert_Rollnumber("172");
	insert_biodata("172", "raza", 0322);

	insert_Rollnumber("165");
	insert_biodata("165", "mujtaba", 0343);

	insert_Rollnumber("03");
	insert_biodata("03", "haseeb", 0366);

	insert_Rollnumber("161");
	insert_biodata("161", "muaz", 0313);

	insert_Rollnumber("155");
	insert_biodata("155", "daniel", 0316);

	insert_Rollnumber("106");
	insert_biodata("106", "rasheed", 0311);

	print();
}



