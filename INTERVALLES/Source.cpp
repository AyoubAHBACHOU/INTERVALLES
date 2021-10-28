#include "intervalle.h"
#include <iostream>
using namespace std;
using namespace algo;

int main()
{
	intervalle i1(0.5, 5);
	intervalle i2(6, 7);
	intervalle i3 = i2;
	double x = 4.8;
	//if (i3[i1])
		//cout << "true" << endl;
	//cout << i1.min_interv() <<"\n";
	//cout <<i1.max_interv() << "\n";
	//i2.afficher();

	//if (i3[x])
		//cout << "true";
	intervalle i5(-4, 8);
	intervalle i4 = i1 - i2;

	i4.afficher();

}