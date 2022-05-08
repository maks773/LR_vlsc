#include <stdio.h>
#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <string>
#include <windows.h>
#include <iterator>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	const int s = 15000;
	int sum = 0;

	int t0=clock();
	for (int i = 0; i < s; i++) {
		vector<int> a(s,1);
		for (int j = 0; j < s; j++) sum+=a[j];
		//copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
		sum = 0;
	}
	int t1=clock();
	cout << "vector: время работы = " << (float(t1-t0))/1000 << " секунды" << endl;
	// время работы составило около 1.9 секунд


	t0=clock();
	for (int i = 0; i < s; i++) {
		list<int> a;
		for (int j = 0; j < s; j++) a.push_back(1);
		for (list<int>::iterator it = a.begin(); it!=a.end(); it++) sum+=*it;
		//copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
		sum = 0;
	}
	t1=clock();
	cout << "list: время работы = " << (float(t1-t0))/1000 << " секунды" << endl;
	// время работы составило около 56.5 секунд


	t0=clock();
	for (int i = 0; i < s; i++) {
		int *a = new int[s];
		for (int j = 0; j < s; j++) a[j]=1;
		for (int j = 0; j < s; j++) sum+=a[j];
		sum = 0;
		delete[] a;
	}
	t1=clock();
	cout << "new int: время работы = " << (float(t1-t0))/1000 << " секунды" << endl;
	// время работы составило около 1.4 секунд

	t0=clock();
	for (int i = 0; i < s; i++) {
		string a(s, 'a');
		for (int j = 0; j < s; j++) if (a[j]=='a') sum++;
		sum = 0;
	}
	t1=clock();
	cout << "string: время работы = " << (float(t1-t0))/1000 << " секунды" << endl;
	// время работы составило около 1.5 секунд

	t0=clock();
	for (int i = 0; i < s; i++) {
		char *a = new char[s];
		for (int j = 0; j < s; j++) a[j]='a';
		for (int j = 0; j < s; j++) if (a[j]=='a') sum++;
		sum = 0;
		delete[] a;
	}
	t1=clock();
	cout << "new сhar: время работы = " << (float(t1-t0))/1000 << " секунды" << endl;
	// время работы составило около 1.4 секунд

	system("pause");
	return 0;
}
