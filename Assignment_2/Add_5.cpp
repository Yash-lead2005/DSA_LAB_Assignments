#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateTwos(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        // Count how many elements would be in expanded array
        for (int i = 0; i < n; i++) {
            if (arr[i] == 2) count += 2;
            else count += 1;
        }

        int i = n - 1;       // original array index
        int j = count - 1;   // virtual expanded index

        // Traverse backwards
        while (i >= 0 && j >= 0) {
            if (arr[i] == 2) {
                if (j < n) arr[j] = 2;
                j--;
                if (j < n) arr[j] = 2;
                j--;
            } else {
                if (j < n) arr[j] = arr[i];
                j--;
            }
            i--;
        }
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    obj.duplicateTwos(arr);

    cout << "Modified array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
