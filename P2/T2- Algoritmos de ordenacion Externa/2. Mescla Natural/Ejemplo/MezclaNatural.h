#pragma once
#include <vector>
#include <string>

void merge(std::vector<std::string>& names, int left, int middle, int right) {
	int n1 = middle - left + 1;
	int n2 = right - middle;
	
	std::vector<std::string> leftList(n1);
	std::vector<std::string> rightList(n2);
	
	for (int i = 0; i < n1; i++)
		leftList.at(i) = names[left + i];
	for (int j = 0; j < n2; j++)
		rightList.at(j) = names[middle + 1 + j];
	
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftList.at(i) <= rightList.at(j)) {
			names.at(k) = leftList.at(i);
			i++;
		}
		else {
			names.at(k) = rightList.at(j);
			j++;
		}
		k++;
	}
	while (i < n1) {
		names.at(k) = leftList.at(i);
		i++;
		k++;
	}
	while (j < n2) {
		names.at(k) = rightList.at(j);
		j++;
		k++;
	}
}

void externalMergeSort(std::vector<std::string>& names, int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		externalMergeSort(names, left, middle);
		externalMergeSort(names, middle + 1, right);
		merge(names, left, middle, right);
	}
}