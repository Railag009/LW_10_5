#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct Dlist
{

	int info;
	Dlist* next, * prev;

};


int main()
{

	Dlist* head, * p, * r;
	int x, k, y;
	int max, min, i, j, a, b, c;
	float sr;

	head = new Dlist;
	cin >> x;
	head->info = x;
	head->next = NULL;
	head->prev = NULL;
	p = head;

	b = 0;
	c = 0;
	k = 0;

	cin >> x;
	while (x)
	{

		r = new Dlist;
		r->info = x;
		r->next = NULL;
		r->prev = p;
		p->next = r;
		p = r;
		cin >> x;

	}

	p = head;

	min = p->info;
	max = p->info;

	while (p != NULL)
	{

		if (min > p->info) min = p->info;
		if (max < p->info) max = p->info;

		p = p->next;

	}

	p = head->next;

	while (p != NULL)
	{
		k = 0;
		i = 1;

		while ((i <= p->prev->info) || (i <= p->info))
		{

			if ((p->prev->info % i == 0) && (p->info % i == 0)) k++;
			i += 2;

		}
		
		if (k > 1)
		{

			r = new Dlist;
			r->info = max-min;
			r->next = p->next;
			r->prev = p;
			p->next = r;
			p = r;

			a = p->prev->info;
			p->prev->info = p->info;
			p->info = a;

		}

		p = p->next;
	}

	p = head;

	while (p != NULL)
	{

		cout << p->info << setw(3);
		p = p->next;
	}

}