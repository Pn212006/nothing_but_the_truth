#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool subsetSum(const vector<int>& nums, const vector<int>& indices, int target) {
    int sum = 0;
    for (int idx : indices) {
        if (idx < 0 || idx >= nums.size()) return false;
        sum += nums[idx];
    }
    return sum == target;
}

bool verifyPrimeFactorization(int number, const vector<int>& factors) {
    int product = 1;
    for (int factor : factors) {
        if (!isPrime(factor)) return false;
        product *= factor;
    }
    return product == number;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4};
    cout << "Is sorted? " << (isSorted(arr1) ? "Yes" : "No") << endl;

    vector<int> nums = {2, 3, 7, 8};
    vector<int> indices = {0, 2};
    int target = 9;
    cout << "Subset sum equals target? " << (subsetSum(nums, indices, target) ? "Yes" : "No") << endl;

    int number = 30;
    vector<int> factors = {2, 3, 5};
    cout << "Valid prime factorization? " << (verifyPrimeFactorization(number, factors) ? "Yes" : "No") << endl;

    return 0;
}
