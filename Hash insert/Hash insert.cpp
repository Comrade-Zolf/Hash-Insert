#include <iostream>
using namespace std;

/*----------------------------------------------------------------------------*/
struct dado
{
	int k; //Key
	int status; //0: empty  and 1: Occupied
};

/*----------------------------------------------------------------------------*/
//h'(k)
int hash_aux(int k, int m)
{
	if((k % m) < 0)
		return (k % m) + m;
	else
		return k % m;
}

//h(k,i,m)
int hash1(int k, int i, int m)
{
	return (hash_aux(k, m) + i) % m;

}
/*----------------------------------------------------------------------------*/
/*
Obs: before doing this you must initialize k = -1 in all positions and
status = 0 in all positions.
*/
/*----------------------------------------------------------------------------*/
int hash_insert(dado t[], int m, int k)
{
	int j;
	int i = 0;
	do
	{
		j = hash1(k, i, m);
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else
			i = i + 1;
	}
	while(i != m);

	return -1; //Table is full
}
/*----------------------------------------------------------------------------*/
int main()
{
	dado t[50]; //Hash table
	int m = 0; //Table size
	int i = 0; //Aux var
	int key; //Aux var for k input

	//Reading table size
	cin >> m;

	//Initializing table:
	/*--------------------------------------------------------------------------
	Before doing this you must initialize k = -1 in all positions and status = 0
	in all positions.
	--------------------------------------------------------------------------*/
	for(i = 0; i < m; i++)
	{
		t[i].status = 0;
		t[i].k = -1;
	}

	//Reading keys and putting on table
	cin >> key;
	while(key != 0)
	{
		hash_insert(t, m, key); //Struct array as parameter
		cin >> key;
	}

	//Showing table
	for(i = 0; i < m; i++)
		cout << t[i].k << " ";
	cout << endl;

	return 0;
}
