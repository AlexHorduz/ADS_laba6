#pragma once

#include <vector>

void bucketSort(std::vector<int>& v, int numOfBuckets = 2);

void countingSort(std::vector<int>& v);

void stableCountingSortForDigits(std::vector<int>& v, int digit);

void radixSort(std::vector<int>& v);