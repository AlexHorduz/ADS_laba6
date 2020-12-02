#include <vector>
#include <iostream>

#include "printer.h"
#include "sorts.h"
#include <algorithm>

using namespace std;

void bucketSort(vector<int>& v, int numOfBuckets) {
	int n = v.size();
	if (n == 1)
		return;
		
	int max = v[0], min = v[0];
	for (int x : v) {
		if (x > max)
			max = x;
		if (x < min)
			min = x;
	}
	if (max == min)
		return;
	int delta = max - min;
	vector< vector <int> > buckets(numOfBuckets, vector<int>(0));
	for (int x : v) {
		buckets[(int)((x - min) / (delta + 0.00000001) * numOfBuckets)].push_back(x); //added 0.00000001 to make even distribution of numbers in buckets
	}
	int k = 0;

	for (auto& bucket : buckets) {
		countingSort(bucket);
		for (auto num : bucket)
			v[k++] = num;
	}
}

void countingSort(vector<int>& v){
	if (v.size() < 2)
		return;
	int min = v[0], max = v[0];
	for (int x : v) {
		if (x > max)
			max = x;
		if (x < min)
			min = x;
	}
	
	max -= min;
	vector<int> count(max+1, 0);
	for (int x : v)
		count[x - min]++;
	int k = 0;
	for (int i = 0; i < max + 1; i++)
		if (count[i] > 0)
			while (count[i]--) {
				v[k++] = i + min;
			}
}

void stableCountingSortForDigits(vector<int>& v, int to_div) {
	vector<int> buckets(10, 0);
	for(int num : v) {
		int curr_digit = (num / to_div) % 10;
		buckets[curr_digit]++;
	}
	for (int i = 1; i < 10; i++)
		buckets[i] += buckets[i - 1];
	vector<int> temp(v.size(), -1);
	for (int i = v.size() - 1; i >= 0; i--)
		temp[--buckets[(v[i] / to_div) % 10]] = v[i];

	v = temp;
}

void radixSort(vector<int>& v){
	int max = v[0], min = v[0];
	for (int num : v) {
		if (num > max)
			max = num;
		if (num < min)
			min = num;
	}
	max -= min;
	for (int& num : v)
		num -= min;

	for (int i = 1; i <= max; i *= 10)
		stableCountingSortForDigits(v, i);

	for (int& num : v)
		num += min;
}

