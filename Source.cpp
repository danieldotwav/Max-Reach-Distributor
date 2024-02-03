#include <iostream>
#include <vector>
using namespace std;

vector<bool> maxReachDistributor(vector<int>& assets, int extraAssets);
void print(const vector<bool>& container);

int main() {
	// Test 1: Standard Case
	vector<int> test1{ 2, 3, 5, 1, 3 };
	print(maxReachDistributor(test1, 3));

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