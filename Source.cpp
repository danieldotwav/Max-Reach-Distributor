#include <iostream>
#include <vector>
using namespace std;

vector<bool> maxReachDistributor(vector<int>& assets, int extraAssets);
void print(const vector<bool>& container);

int main() {

	// Test 1: Standard Case
	vector<int> test1{ 2, 3, 5, 1, 3 };
	print(maxReachDistributor(test1, 3));

	// Test 2: All elements can become the greatest after adding extraAssets
	vector<int> test2{ 1, 2, 3, 4 };
	print(maxReachDistributor(test2, 3));

	// Test 3: No elements can become the greatest after adding extraAssets
	vector<int> test3{ 10, 20, 30, 40 };
	print(maxReachDistributor(test3, 5));

	// Test 4: Only one element can become the greatest after adding extraAssets
	vector<int> test4{ 5, 9, 3, 4 };
	print(maxReachDistributor(test4, 5));

	// Test 5: Multiple elements can become the greatest, but not all
	vector<int> test5{ 8, 2, 7, 3 };
	print(maxReachDistributor(test5, 6));

	// Test 6: Edge case with all elements being the same
	vector<int> test6{ 5, 5, 5, 5 };
	print(maxReachDistributor(test6, 0));

	// Test 7: Edge case with a single element
	vector<int> test7{ 10 };
	print(maxReachDistributor(test7, 10));

	return 0;
}

vector<bool> maxReachDistributor(vector<int>& assets, int extraAssets) {
	// First, determine the max element
	int maxVal = *max_element(assets.begin(), assets.end());

	// Next, we simply need to add the extraAssets to each index and if it exceeds the maxVal, we assign true in the vector of booleans
	vector<bool> result;
	for (int element : assets) {
		result.push_back(element + extraAssets >= maxVal);
	}

	return result;
}

void print(const vector<bool>& container) {
	if (!container.empty()) {
		int length = container.size();

		cout << "[";
		for (int i = 0; i < length; ++i) {
			string result = container[i] == true ? "true" : "false";
			cout << result;
			if (i < length - 1) {
				cout << ", ";
			}
		}
		cout << "]\n\n";
	}
}