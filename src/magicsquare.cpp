//============================================================================
// Name        : magicsquare.cpp
// Author      : Xiao Li
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include <vector>
#include <iomanip>
using namespace std;


class MagicSquare{

private:
	vector<vector<int> > data;
	int newN;
	int i,j;

public:
	MagicSquare(int n);
	void displaySquare();

};


MagicSquare::MagicSquare(int n)
{
	newN=n;
	i=0;   // put 1 in the middle of first row
	j=n/2;

	data.assign(newN, vector<int> (newN));

	for (int k=1; k<=n*n; k++)
	{
		data[i][j] = k;

				i--; //move up one row and
				j++; //to the right one column for storing the counter value

				if (k%n == 0)         // for condition 3
				{
					i += 2;
					j--;
				}
				else
				{
					if (i<0)         //for condition 1
						i += n;
					else if (j==n)   //for condition 2
						j -= n;
				}
	}
}

 void MagicSquare::displaySquare()
{
	cout<<"\n\n\n\n printing Magic Square:\n\n";
	for (int i=0; i<newN; i++)
	{
		for (int j=0; j<newN; j++)
			{
			cout << setw(4) <<data[i][j];
			}
		cout<<endl;
	}
}
 int main()
 {
 	MagicSquare test(5);
 	test.displaySquare();
 	MagicSquare test1(15);
 	test1.displaySquare();
    return 0;
 }
