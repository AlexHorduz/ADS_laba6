#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
	os << "{ ";
	for (int i = 0; i < v.size(); i++)
		if (i == 0)
			os << v[i];
		else
			os << ", " << v[i];
	os << " }";
	return os;
}