## Introduction

This simple C++ program provides a solution to the problem of distributing extra assets among a group of individuals to determine who can potentially have the greatest number of assets. The core functionality of this project is encapsulated in the `maxReachDistributor` function. It analyzes an array of integers representing the assets each individual has and the number of extra assets available. The program returns a boolean array indicating which individuals could have the greatest number of assets when the extra assets are distributed.

## Algorithm

### **Max Reach Distributor**

#### Logic

- The algorithm begins by finding the maximum value within the provided array of assets, which represents the highest number of assets any individual currently possesses. It then iterates over the array, adding the number of extra assets to each individual's current assets. If an individual's total assets, after receiving the extra assets, are equal to or greater than the maximum value found, the function marks them as true in the resultant boolean array.

#### Complexity Analysis

- **Time Complexity:** O(n), where n is the number of individuals. The function requires two passes over the array: one to find the maximum value and another to evaluate each individual's total assets against this maximum.
- **Space Complexity:** O(n) for the output boolean array. The space required is directly proportional to the number of individuals.

### Code Snippet

```cpp
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
```