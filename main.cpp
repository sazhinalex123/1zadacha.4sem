#include "CRatVector.h"
#include "CRatVector0.h"
#include "CRatVector1.h"
#include "AutoTest.hpp"
using namespace std;

int main() {
	if (!AutoTest()) {
		cout << "Ouch..." << endl;
		return 0;
	}
	cout << "Yeeeeeey!!!" << endl;
	ifstream in("input.txt");
	int n = 0;
	std::string tmp;
	while (getline(in, tmp)) {
		n++;
	}
	in.close();
	in.open("input.txt");
	CRatVector** arr = new CRatVector * [n];
	int j = 0;
	int s = 0;
	std::string filename;
	for (int i = 0; i < n; i++) {
		in >> j;
		in >> filename;
		in >> s;
		CRatVector* a;
		if (j == 0) {
			a = new CRatVector0(s);
		}
		else {
			a = new CRatVector1(s);
		}
		(*a).setFilename(filename.c_str());
			for (int k = 0; k < s; k++) {
				string cur;
				in >> cur;
				int l = cur.find('/');
				if (l != string::npos) {
					(*a)[k] = { atoi(cur.substr(0, l).c_str()), atoi(cur.substr(l + 1, cur.size() - l - 1).c_str()) };
				}
			}
			arr[i] = a;
	}
	for (int i = 0; i < n; i++) {
		arr[i]->output(arr[i]->getFilename());
	}
	for (int i = 0; i < n; i++) {
		delete arr[i];
	}
	delete[] arr;
	return 0;
}
